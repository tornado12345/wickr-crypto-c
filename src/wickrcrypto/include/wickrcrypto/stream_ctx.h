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

#ifndef stream_ctx_h
#define stream_ctx_h

#include "crypto_engine.h"
#include "stream_iv.h"
#include "stream_key.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 @addtogroup wickr_stream wickr_stream
 */

typedef enum { STREAM_DIRECTION_ENCODE, STREAM_DIRECTION_DECODE } wickr_stream_direction;

/**
 @ingroup wickr_stream
 
 @struct wickr_stream_ctx
 
 @brief A context that is used for encrypting or decrypting a sequenced stream of data packets
 The stream context manages the state of stream operations including key evolution management based on the
 sequence number of the being encrypted / decrypted. The stream context is assigned a direction, and can only be used for
 encoding OR decoding of packets, and not both.
 
 Key evolution happens based on sequence number. Keyn+1 is generated by HMAC(Keyn, evolution_key). Gaps in sequence numbers are allowed
 and if the key needs to evolove multiple times, it will do so in a loop until the key is current, and data ciphering is possible. Sequence
 numbers can NOT go backwards due to the evolution's use of HMAC. Once Keyn+1 is generated, it is not possible to go back and calculate Keyn.
 
 @var wickr_stream_ctx::engine
 crypto engine to be used for cipher operations, as well as key evolution using HMAC
 @var wickr_stream_ctx::key
 the current stream key that the stream context is using for encryption or decryption depending on direction
 the stream key will change over the course of packet encoding due to it's evolutions
 @var wickr_stream_ctx::iv_factory
 the iv generator that this stream is using to create IVs
 @var wickr_stream_ctx::last_seq
 the most recent sequence number that successfully encrypted or decrypted a packet
 @var wickr_stream_ctx::direction
 the direction of this stream context. direction can either be encoding or decoding
 @var wickr_stream_ctx::ref_count
 current reference count of the stream
 */
struct wickr_stream_ctx {
    wickr_crypto_engine_t engine;
    wickr_stream_key_t *key;
    wickr_stream_iv_t *iv_factory;
    uint64_t last_seq;
    wickr_stream_direction direction;
    size_t ref_count;
};

typedef struct wickr_stream_ctx wickr_stream_ctx_t;

/**
 @ingroup wickr_stream
 
 Create a stream context

 @param engine see wickr_stream_ctx documentation
 @param stream_key see wickr_stream_ctx documentation
 @param direction see wickr_stream_ctx documentation
 @return a newly allocated stream context owning the properties passed in
 */
wickr_stream_ctx_t *wickr_stream_ctx_create(const wickr_crypto_engine_t engine, wickr_stream_key_t *stream_key, wickr_stream_direction direction);

/**
 @ingroup wickr_stream
 
 Copy a stream context

 @param ctx the stream context to copy
 @return a newly allocated stream context holding a deep copy of properties from 'ctx'
 */
wickr_stream_ctx_t *wickr_stream_ctx_copy(const wickr_stream_ctx_t *ctx);

/**
 @ingroup wickr_stream
 
 Encode a packet

 @param ctx context to use for encoding
 @param data the data to encode using the context's key
 @param aad additional data to authenticate with the ciphertext
 @param seq_num the sequence number assoiciated with 'data'
 @return a cipher result representing 'data' encrypted with 'ctx->key'
 */
wickr_cipher_result_t *wickr_stream_ctx_encode(wickr_stream_ctx_t *ctx, const wickr_buffer_t *data, const wickr_buffer_t *aad, uint64_t seq_num);

/**
 @ingroup wickr_stream
 
 Encode a packet
 
 @param ctx context to use for decoding
 @param data the data to decode using the context's key
 @param aad additional data to authenticate with the ciphertext
 @param seq_num the sequence number assoiciated with 'data'
 @return a buffer representing 'data' decrypted with 'ctx->key'
 */
wickr_buffer_t *wickr_stream_ctx_decode(wickr_stream_ctx_t *ctx, const wickr_cipher_result_t *data, const wickr_buffer_t *aad, uint64_t seq_num);

/**
 @ingroup wickr_stream
 
 Destroy a stream context

 @param ctx a pointer to the stream context to destroy. All properties of '*ctx' will also be destroyed
 */
void wickr_stream_ctx_destroy(wickr_stream_ctx_t **ctx);

/**
 @ingroup wickr_stream
 
 Increment the reference count of a stream
 
 @param ctx the context to bump the reference count of
 */
bool wickr_stream_ctx_ref_up(wickr_stream_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif /* stream_ctx_h */
