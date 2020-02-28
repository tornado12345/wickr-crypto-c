/*
 * Copyright © 2012-2020 Wickr Inc.  All rights reserved.
 *
 * This code is being released for EDUCATIONAL, ACADEMIC, AND CODE REVIEW PURPOSES
 * ONLY.  COMMERCIAL USE OF THE CODE IS EXPRESSLY PROHIBITED.  For additional details,
 * please see LICENSE
 *
 * THE CODE IS MADE AVAILABLE "AS-IS" AND WITHOUT ANY EXPRESS OR
 * IMPLIED GUARANTEES AS TO FITNESS, MERCHANTABILITY, NON-
 * INFRINGEMENT OR OTHERWISE. IT IS NOT BEING PROVIDED IN TRADE BUT ON
 * A VOLUNTARY BASIS ON BEHALF OF THE AUTHOR’S PART FOR THE BENEFIT
 * OF THE LICENSEE AND IS NOT MADE AVAILABLE FOR CONSUMER USE OR ANY
 * OTHER USE OUTSIDE THE TERMS OF THIS LICENSE. ANYONE ACCESSING THE
 * CODE SHOULD HAVE THE REQUISITE EXPERTISE TO SECURE THEIR SYSTEM
 * AND DEVICES AND TO ACCESS AND USE THE CODE FOR REVIEW PURPOSES
 * ONLY. LICENSEE BEARS THE RISK OF ACCESSING AND USING THE CODE. IN
 * PARTICULAR, AUTHOR BEARS NO LIABILITY FOR ANY INTERFERENCE WITH OR
 * ADVERSE EFFECT THAT MAY OCCUR AS A RESULT OF THE LICENSEE
 * ACCESSING AND/OR USING THE CODE ON LICENSEE’S SYSTEM.
 */

#ifndef wickr_ctx_h
#define wickr_ctx_h

#include "eckey.h"
#include "devinfo.h"
#include "root_keys.h"
#include "ephemeral_keypair.h"
#include "storage.h"
#include "identity.h"
#include "protocol.h"
#include "encoder_result.h"

#ifdef __cplusplus
extern "C" {
#endif

/****************************************
 ****************************************
 **  __          ___      _            **
 **  \ \        / (_)    | |           **
 **   \ \  /\  / / _  ___| | ___ __    **
 **    \ \/  \/ / | |/ __| |/ / '__|   **
 **     \  /\  /  | | (__|   <| |      **
 **      \/  \/   |_|\___|_|\_\_|      **
 **                                    **
 ****************************************
 ***************************************/

/**
 @addtogroup wickr_ctx
 */
    
/**
 @ingroup wickr_ctx
 @struct wickr_ctx
 
 @brief Wickr encryption context for high level management of sending / receiving packets using the Wickr protocol
 
 @var wickr_ctx::engine 
 crypto engine to use by default for all cryptographic operations required by the Wickr protocol
 @var wickr_ctx::dev_info
 set of device identifiers to use for messaging and server communication, storage keys and message key exchanges are bound to the dev_info identifiers
 @var wickr_ctx::id_chain
 the identity chain for this context, it contains the node and root level signature chains
 @var wickr_ctx::storage_keys
 active remote and local storage keys for this context
 @var wickr_ctx::packet_header_key
 the active header key to use on all outbound packets
 @var wickr_ctx::pkt_enc_version
 the packet version to use for encoding, this is useful for supporting older clients
 */
struct wickr_ctx {
    wickr_crypto_engine_t engine;
    wickr_dev_info_t *dev_info;
    wickr_identity_chain_t *id_chain;
    wickr_storage_keys_t *storage_keys;
    wickr_cipher_key_t *packet_header_key;
    uint8_t pkt_enc_version;
};

typedef struct wickr_ctx wickr_ctx_t;

#define DEFAULT_PKT_ENC_VERSION 4
    
/**
 @ingroup wickr_ctx
 @struct wickr_ctx_gen_result
 @brief the output of a context generation
 
 @var wickr_ctx_gen_result::ctx
 the context that was generated
 @var wickr_ctx_gen_result::recovery_key
 the randomly generated recovery key that can be used to optionally recovery secure the root keys of this context for storage
 @var wickr_ctx_gen_result::root_keys
 the root keys either generated by, or imported by this context generation
 */
struct wickr_ctx_gen_result {
    wickr_ctx_t *ctx;
    wickr_cipher_key_t *recovery_key;
    wickr_root_keys_t *root_keys;
};

typedef struct wickr_ctx_gen_result wickr_ctx_gen_result_t;

/* Generation Functions */

/**
 @ingroup wickr_ctx
 Makes a new root and random node identity + context with random keys
 
 NOTE: The resulting wickr_ctx_gen_result does not gain ownership over the parameters to this function

 @param engine the crypto engine to use for all context operations
 @param dev_info the device info for which to bind this context to
 @param identifier a system unique identifier that will represent the root identity that is being generated
 @return a generation result containing a root identity represented by 'identifier' and a node identity signed by 'root' with a random set of keys
 */
wickr_ctx_gen_result_t *wickr_ctx_gen_new(const wickr_crypto_engine_t engine,
                                          wickr_dev_info_t *dev_info,
                                          wickr_buffer_t *identifier);

/**
 @ingroup wickr_ctx
 Makes a new root and random node identity + context with random keys except for a provided root signing key

 NOTE: The resulting wickr_ctx_gen_result does not gain ownership over the parameters to this function
 
 @param engine the crypto engine to use for all context operations
 @param dev_info the device info for which to bind this context to
 @param sig_key a signature key to associate with the generated root identity
 @param identifier a system unique identifier that will represent the root identity that is being generated
 @return a generation result containing a root identity represented by 'identifier' and a node identity signed by 'root' with 'sig_key' as the root signing key
 */
wickr_ctx_gen_result_t *wickr_ctx_gen_new_with_sig_key(const wickr_crypto_engine_t engine,
                                                       wickr_dev_info_t *dev_info,
                                                       wickr_ec_key_t *sig_key,
                                                       wickr_buffer_t *identifier);

/**
 @ingroup wickr_ctx
 Makes a new context using an existing root keys set

 NOTE: The resulting wickr_ctx_gen_result does not gain ownership over the parameters to this function
 
 This function is used to provision a new node identity onto the system given an existing root identity
 
 @param engine the crypto engine to use for all context operations
 @param dev_info the device info for which to bind this context to
 @param root_keys the root keys to use for the generation, the generated node will be signed by the root key's signing key, and the storage keys will be derived from the root remote / local cipher keys
 @param identifier the system unique identifier that was previously associated with root_keys
 @return a generation result containing an existing root identity represented by 'identifier' and a node identity signed by the existing root
 */
wickr_ctx_gen_result_t *wickr_ctx_gen_with_root_keys(const wickr_crypto_engine_t engine,
                                                     wickr_dev_info_t *dev_info,
                                                     wickr_root_keys_t *root_keys,
                                                     wickr_buffer_t *identifier);

/**
 @ingroup wickr_ctx
 
 Makes a new context using an existing root identity's exported recovery key and a passphrase
 
 NOTE: The resulting wickr_ctx_gen_result does not gain ownership over the parameters to this function


 @param engine the crypto engine to use for all context operations
 @param dev_info the device info for which to bind this context to
 @param exported_recovery_key a previously exported random recovery key that was protected with a KDF using 'passphrase' as the key. See 'wickr_ctx_gen_export_recovery_key_passphrase' for more information
 @param passphrase the passphrase to decode exported_recovery_key with
 @param recovery_data an export of 'root_keys' from a previous context encrypted with recovery_key
 @param identifier identifier the system unique identifier that was previously associated with the root keys held in 'recovery'
 @return a generation result containing an existing root identity represented by 'identifier' and a node identity signed by the existing root. NULL if decoding 'exported_recovery_key' or 'recovery' fails due to an invalid passphrase
 */
wickr_ctx_gen_result_t *wickr_ctx_gen_with_passphrase(const wickr_crypto_engine_t engine,
                                                      wickr_dev_info_t *dev_info,
                                                      wickr_buffer_t *exported_recovery_key,
                                                      wickr_buffer_t *passphrase,
                                                      wickr_buffer_t *recovery_data,
                                                      wickr_buffer_t *identifier);

/**
 @ingroup wickr_ctx
 
 Makes a new context using an existing exported root keys and a provided recovery key

 NOTE: The resulting wickr_ctx_gen_result does not gain ownership over the parameters to this function
 
 @param engine the crypto engine to use for all context operations
 @param dev_info the device info for which to bind this context to
 @param recovery_data an recovery containing exported root_keys from a previous context using 'recovery_key'
 @param recovery_key the key to decrypt 'recovery' with to attempt recovery of root_keys to use for context generation
 @param identifier identifier the system unique identifier that was previously associated with the root keys held in 'recovery'
 @return a generation result containing an existing root identity represented by 'identifier' and a node identity signed by the existing root. NULL if decoding 'recovery' fails due to an incorrect key
 */
wickr_ctx_gen_result_t *wickr_ctx_gen_with_recovery(const wickr_crypto_engine_t engine,
                                                  wickr_dev_info_t *dev_info,
                                                  wickr_buffer_t *recovery_data,
                                                  wickr_cipher_key_t *recovery_key,
                                                  wickr_buffer_t *identifier);

/**
 
 @ingroup wickr_ctx
 
 Exports the recovery key using a KDF + CIPHER function
 
 For more information on the KDF + CIPHER functionality, review documentation for 'wickr_crypto_engine_kdf_cipher'
 
 Defaults are currently using KDF_SCRYPT_2_17 for a KDF and CIPHER_AES256_GCM for a cipher

 @param result a context generation result to export the recovery key from
 @param passphrase the passphrase to use as input to the KDF function
 @return a buffer that was created by first taking KDF(randomSalt || passphrase) and then using that output as a key that encrypted
 */
wickr_buffer_t *wickr_ctx_gen_export_recovery_key_passphrase(const wickr_ctx_gen_result_t *result, const wickr_buffer_t *passphrase);

/**
 @ingroup wickt_ctx

 @param engine a crypto engine that supports the KDF and cipher used to originally export an recovery key
 @param exported_recovery_key an exported recovery key from 'wickr_ctx_gen_export_recovery_key_passphrase'
 @param passphrase the passphrase used during the original export
 @return a decoded recovery key or NULL if the passphrase is incorrect
 */
wickr_cipher_key_t *wickr_ctx_gen_import_recovery_key_passphrase(const wickr_crypto_engine_t engine, const wickr_buffer_t *exported_recovery_key, const wickr_buffer_t *passphrase);

/**
 @ingroup wickr_ctx
 Serializes root keys and ciphers them with the recovery key

 @param result the context generation result to make an recovery from
 @return a buffer with a serialized cipher_result generated by encrypting 'root_keys' with the 'recovery_key' held in 'result'.
 */
wickr_buffer_t *wickr_ctx_gen_result_make_recovery(const wickr_ctx_gen_result_t *result);

/**
 @ingroup wickr_ctx

 @param engine a crypto engine that was used to call 'wickr_ctx_gen_result_make_recovery'
 @param recovery_data an encrypted recovery as created by 'wickr_ctx_gen_result_make_recovery'
 @param recovery_key the recovery key from the 'wickr_ctx_gen_result' that called 'wickr_ctx_gen_result_make_recovery' to make 'recovery'
 @return root keys created from decoding 'recovery' with 'recovery_key' or NULL if the decryption operation failed
 */
wickr_root_keys_t *wickr_ctx_gen_import_recovery(const wickr_crypto_engine_t engine,
                                                 const wickr_buffer_t *recovery_data,
                                                 const wickr_cipher_key_t *recovery_key);

/**
 
 @ingroup wickr_ctx
 
 Copy a context generation result
 
 @param source the context generation result to copy
 @return a newly allocated context generation result holding a deep copy of the properties of 'source'
 */
wickr_ctx_gen_result_t *wickr_ctx_gen_result_copy(const wickr_ctx_gen_result_t *source);


/**
 
 @ingroup wickr_ctx
 
 Destroy a context generation result
 
 @param result a pointer to the context generation result to destroy. All properties of '*result' will also be destroyed
 */
void wickr_ctx_gen_result_destroy(wickr_ctx_gen_result_t **result);

/* Context Functions */

/**
 
 @ingroup wickr_ctx
 Create a context from components

 @param engine a crypto engine to support context operations
 @param dev_info the device information the context should be bound to
 @param id_chain the identity chain that belongs to this context and will be used for encoding / decoding messages
 @param storage_keys the storage keys used for local and remote ciphers of this context
 @return a newly allocated context owning the passed in parameters
 */
wickr_ctx_t *wickr_ctx_create(const wickr_crypto_engine_t engine,
                              wickr_dev_info_t *dev_info,
                              wickr_identity_chain_t *id_chain,
                              wickr_storage_keys_t *storage_keys);

/**
 
 @ingroup wickr_ctx
 
 Copy a context
 
 @param ctx the context to copy
 @return a newly allocated context holding a deep copy of the properties of 'ctx'
 */
wickr_ctx_t *wickr_ctx_copy(const wickr_ctx_t *ctx);

/**
 
 @ingroup wickr_ctx
 
 Destroy a context
 
 @param ctx a pointer to the context to destroy. All properties of '*ctx' will also be destroyed
 */
void wickr_ctx_destroy(wickr_ctx_t **ctx);
    
/**
 
 @ingroup wickr_ctx
 
 Serialize a context
 
 @param ctx the context to serialize to bytes
 @return bytes representing a combination of the storage keys and id chain from 'ctx'
 */
wickr_buffer_t *wickr_ctx_serialize(const wickr_ctx_t *ctx);
    
/**
 
 @ingroup wickr_ctx
 
 Recreate a context from a serizlied representation
 
 @param engine a crypto engine to support context operations
 @param dev_info the device information the context should be bound to
 @param buffer data created with 'wickr_ctx_serialize'
 @return a context restored from 'buffer' or NULL if parsing fails
 */
wickr_ctx_t *wickr_ctx_create_from_buffer(const wickr_crypto_engine_t engine,
                                          wickr_dev_info_t *dev_info,
                                          const wickr_buffer_t *buffer);

/**
 @ingroup wickr_ctx
 
 Serialize and encrypt a context with a passphrase
 
 @param ctx the context to serialize and encrypt
 @return bytes representing an scrypt encrypted context
 */
wickr_buffer_t *wickr_ctx_export(const wickr_ctx_t *ctx, const wickr_buffer_t *passphrase);
    
/**
 @ingroup wickr_ctx
 
 Import a ctx exported by 'wickr_ctx_export'
 
 @param engine the crypto engine to use for decryption and the resulting context
 @param dev_info the device information the context should be bound to
 @param exported the result of the call to 'wickr_ctx_export'
 @param passphase the passphrase used to export the context
*/
wickr_ctx_t *wickr_ctx_import(const wickr_crypto_engine_t engine,
                              wickr_dev_info_t *dev_info,
                              const wickr_buffer_t *exported,
                              const wickr_buffer_t *passphrase);

/**
 @ingroup wickr_ctx
 Exports storage keys for a context using a KDF + CIPHER function
 
 For more information on the KDF + CIPHER functionality, review documentation for 'wickr_crypto_engine_kdf_cipher'
 
 Defaults are currently using KDF_SCRYPT_2_17 for a KDF and CIPHER_AES256_GCM for a cipher

 @param ctx the context to export storage keys from
 @param passphrase the passphrase to use as input to a KDF that will generated a key to protect storage keys
 @return a buffer containing exported storage keys
 */
wickr_buffer_t *wickr_ctx_export_storage_keys(const wickr_ctx_t *ctx, const wickr_buffer_t *passphrase);

/**
 @ingroup wickr_ctx
 Import storage keys exported with 'wickr_ctx_export_storage_keys'

 @param engine a crypto engine supporting KDF based encryption
 @param exported keys exported with 'wickr_ctx_export_storage_keys'
 @param passphrase the passphrase used to export storage keys
 @return decoded storage keys or NULL if the passphrase is invalid
 */
wickr_storage_keys_t *wickr_ctx_import_storage_keys(const wickr_crypto_engine_t engine,
                                                    const wickr_buffer_t *exported,
                                                    const wickr_buffer_t *passphrase);

/**
 @ingroup wickr_ctx
 
 Encrypts data using the local storage key

 @param ctx the context to use for encryption
 @param plaintext the bytes to encrypt for local storage
 @return 'plaintext' encrypted with the context's local storage key
 */
wickr_cipher_result_t *wickr_ctx_cipher_local(const wickr_ctx_t *ctx, const wickr_buffer_t *plaintext);

/**
 Decrypts data using the local storage key

 @param ctx the context to use for decryption
 @param cipher_text a cipher result from 'wickr_ctx_cipher_local'
 @return 'cipher_text' decoded with local storage key
 */
wickr_buffer_t *wickr_ctx_decipher_local(const wickr_ctx_t *ctx, const wickr_cipher_result_t *cipher_text);

/**
 @ingroup wickr_ctx
 Encrypts data using the remote storage key

 @param ctx the context to use for encryption
 @param plaintext plaintext the bytes to encrypt for remote storage
 @return 'plaintext' encrypted with the context's remote storage key
 */
wickr_cipher_result_t *wickr_ctx_cipher_remote(const wickr_ctx_t *ctx, const wickr_buffer_t *plaintext);

/**
 @ingroup wickr_ctx
 Decrypts data using the local storage key
 

 @param ctx the context to use for decryption
 @param cipher_text a cipher result from 'wickr_ctx_cipher_remote'
 @return 'cipher_text' decoded with remote storage key
 */
wickr_buffer_t *wickr_ctx_decipher_remote(const wickr_ctx_t *ctx, const wickr_cipher_result_t *cipher_text);

/**
 @ingroup wickr_ctx
 Generate ephemeral message keypairs
 
 NOTE: the result of this function should be kept in a local cache to allow for decoding a message that was created with it's public components.
 The public buffer of the contained EC key, along with the key_id, and the key signature should be published to a pool for consumption and use by a sender looking to addresss a message to this context

 @param ctx the context to use for ephemeral key pair generation
 @param key_id the identifier to assign to the generated keypair
 @return an ephemeral key pair containing the private and public components, signed by the ctx node signing identity
 */
wickr_ephemeral_keypair_t *wickr_ctx_ephemeral_keypair_gen(const wickr_ctx_t *ctx, uint64_t key_id);

/**
 @ingroup wickr_ctx
 @struct wickr_ctx_packet
 @brief a parsed inbound wickr packet that has yet to be decoded by this context
 
 @var wickr_ctx_packet::packet
 the packet metadata that has been parsed
 @var wickr_ctx_packet::sender
 the identity information of the sender of this packet
 @var wickr_ctx_packet::parse_result
 additional information about the parse, disclosing discovered key destined for this context, as well as signature status and error status
 */
struct wickr_ctx_packet {
    wickr_packet_t *packet;
    wickr_identity_chain_t *sender;
    wickr_parse_result_t *parse_result;
};

typedef struct wickr_ctx_packet wickr_ctx_packet_t;

/**
 @ingroup wickr_ctx
 
 Create a context packet parse result from components

 @param packet see property description from 'wickr_ctx_packet'
 @param sender see property description from 'wickr_ctx_packet'
 @param parse_result see property description from 'wickr_ctx_packet'
 @return a newly allocated context packet parse result owning the parameters passed in
 */
wickr_ctx_packet_t *wickr_ctx_packet_create(wickr_packet_t *packet,
                                            wickr_identity_chain_t *sender,
                                            wickr_parse_result_t *parse_result);

/**
 @ingroup wickr_ctx

 Destroy a packet parse result
 
 @param packet a pointer to a context packet parse result to destroy. Will destroy the sub properties of '*packet' as well
 */
void wickr_ctx_packet_destroy(wickr_ctx_packet_t **packet);

/* Message Encode / Decode */

/**
 @ingroup wickr_ctx
 
 Encode a Wickr packet to a set of nodes

 @param ctx the context to use to encode 'payload' to 'nodes'
 @param payload the metadata and body information to send to 'nodes'
 @param nodes the recipient nodes for this packet
 @return an encode result containing an encrypted Wickr packet that transfers 'payload' to 'nodes'
 */
wickr_encoder_result_t *wickr_ctx_encode_packet(const wickr_ctx_t *ctx,
                                                const wickr_payload_t *payload,
                                                const wickr_node_array_t *nodes);

/**
 @ingroup wickr_ctx
 
 Parse a Wickr packet into components, fail if the current node's key exchange is not found

 @param ctx the context to use for parsing
 @param packet_buffer the buffer representing the serialized packet that was delivered to 'ctx'
 @param sender the sender of the 'packet_buffer'
 @return a parse result holding the parsed information from 'packet_buffer' as well as a discovered key exchange from the current ctx node_id. If the packet was not addressed to this context, an error is generated
 */
wickr_ctx_packet_t *wickr_ctx_parse_packet(const wickr_ctx_t *ctx,
                                           const wickr_buffer_t *packet_buffer,
                                           const wickr_identity_chain_t *sender);

/**
 Parse a packet into components, do not fail if the current node's key exchange is not found

 @param ctx ctx the context to use for parsing
 @param packet_buffer the buffer representing the serialized packet that was delivered to 'ctx'
 @param sender the sender of the 'packet_buffer'
 @return a parse result holding the parsed information from 'packet_buffer' with a NULL key exchange
 */
wickr_ctx_packet_t *wickr_ctx_parse_packet_no_decode(const wickr_ctx_t *ctx,
                                                     const wickr_buffer_t *packet_buffer,
                                                     const wickr_identity_chain_t *sender);

/**
 Decode a parsed packet using the provided keypair
 
 NOTE: this will fail if the packet was parsed using wickr_ctx_parse_packet_no_decode

 @param ctx ctx the context to use for decoding
 @param packet a previously parsed packet using 'wickr_ctx_parse_packet'
 @param keypair a key pair containing the private key associated with the identifier contained within the key exchange within the packet parse result
 @return a decode result containing an error status as well as the decoded packet payload, and the payload_key that was derived via the key exchange operations if the key pair presented is correct
 */
wickr_decode_result_t *wickr_ctx_decode_packet(const wickr_ctx_t *ctx,
                                               const wickr_ctx_packet_t *packet,
                                               wickr_ec_key_t *keypair);

#ifdef __cplusplus
}
#endif

#endif /* wickr_ctx_h */
