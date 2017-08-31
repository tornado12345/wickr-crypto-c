/*
 * Copyright © 2012-2017 Wickr Inc.  All rights reserved.
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

#ifndef transport_h
#define transport_h

#include "crypto_engine.h"
#include "node.h"
#include "stream_ctx.h"

/**
 @addtogroup wickr_transport_ctx
 */

/**
 @ingroup wickr_transport_ctx
 @struct wickr_transport_ctx
 
 @brief Transport context to manage the state machine of a point to point connection using fundamentals of the Wickr protocol as building blocks
 
 The transport context's operation consists of two phases, a handshake phase where a wickr_stream_ctx is established in the rx and tx direction
 using the key exchanges the Wickr messaging protocol operates on, followed by a data transmission phase encoding / decoding packets using the
 wickr_stream_ctx objects that are generated by the handshake. This structure does NOT handle the actual transport of data, as it's function is to be
 a state machine that backs a transport such as a TCP socket
 */
struct wickr_transport_ctx;
typedef struct wickr_transport_ctx wickr_transport_ctx_t;

typedef enum {
    TRANSPORT_STATUS_NONE, /* Transport has not been initialized */
    TRANSPORT_STATUS_SEEDED, /* Transport has generated and sent a seed handshake packet */
    TRANSPORT_STATUS_TX_INIT, /* Transport has processed an incoming seed handshake packet and responded */
    TRANSPORT_STATUS_ACTIVE, /* Transport has both rx and tx streams initialized and is able to send encrypted packets */
    TRANSPORT_STATUS_ERROR /* Transport has encountered an error, and communication is no longer possible */
} wickr_transport_status;

typedef enum {
    TRANSPORT_DATA_FLOW_BIDIRECTIONAL, /* Data flow can happen in both directions */
    TRANSPORT_DATA_FLOW_READ_ONLY, /* Non handshake packets can only flow in the rx direction */
    TRANSPORT_DATA_FLOW_WRITE_ONLY /* Non handshake packets can only flow in the tx direction */
} wickr_transport_data_flow;

/* Function callback to handle sending / receiving / errors via an actual transport, eg socket */
typedef void (*wickr_transport_tx_func)(const wickr_transport_ctx_t *ctx, const wickr_buffer_t *data, void *user);
typedef void (*wickr_transport_rx_func)(const wickr_transport_ctx_t *ctx, const wickr_buffer_t *data, void *user);
typedef void (*wickr_transport_state_change_func)(const wickr_transport_ctx_t *ctx, wickr_transport_status status, void *user);
typedef bool (*wickr_transport_validate_identity_func)(const wickr_transport_ctx_t *ctx, wickr_identity_chain_t *identity, void *user);
typedef wickr_buffer_t *(*wickr_transport_psk_func) (const wickr_transport_ctx_t *ctx, void *user);
typedef wickr_stream_ctx_t *(*wickr_transport_tx_stream_func) (const wickr_transport_ctx_t *ctx, wickr_stream_ctx_t *tx_stream, void *user);
/**
 @ingroup wickr_transport_ctx

 @struct wickr_transport_callbacks
 
 @brief callbacks to notify the user of events within the transport
 
 @var wickr_transport_callbacks::tx
 Called when a buffer passed to wickr_transport_ctx_process_tx_buffer is encoded and ready for sending
 @var wickr_transport_callbacks::rx
 Called when a buffer passed to wickr_transport_ctx_process_rx_buffer is decoded
 @var wickr_transport_callbacks::on_state
 Called whenever the state of the transport context is updated
 @var wickr_transport_callbacks::on_identity_verify
 Called when no remote data is provided for pinning, so the identity of the remote
 needs to be verified by the application
 @var wickr_transport_callbacks::on_psk_required
 Called when the inbound key exchange requires a psk
 @var wickr_transport_callbacks::on_tx_stream_gen
 Called when a tx stream is generated for a outbound key exchanges
 */
struct wickr_transport_callbacks {
    wickr_transport_tx_func tx;
    wickr_transport_rx_func rx;
    wickr_transport_state_change_func on_state;
    wickr_transport_validate_identity_func on_identity_verify;
    wickr_transport_psk_func on_psk_required;
    wickr_transport_tx_stream_func on_tx_stream_gen;
};

typedef struct wickr_transport_callbacks wickr_transport_callbacks_t;

/**
 @ingroup wickr_transport_ctx
 
 Create a transport context from components
 
 @param engine a crypto engine to be used for the underlying signature, and cipher operations
 @param local_identity the node information of the person creating the transport context. This should include private signature keys
 @param remote_identity the node information of the endpoint 'local_identity' is connecting too. This field is OPTIONAL. If this field is set,
 the signature keys provided inside this property will be pinned, and the 'on_identity_verify' callback will not be called during connection.
 The remote_identity passed in here does not need to contain an 'ephemeral_keypair' property, because it will be provided by the remote party during connection,
 and verified by the node / root signature keys inside the identity
 @param evo_count the evolution packet count to be passed to the creation of underlying 'wickr_stream_ctx_t' that are created by this transport internally,
 see 'wickr_stream_ctx_t' for more information
 @param callbacks a set of function pointers the 'wickr_transport_ctx_t' will use to pass data, state change information, and identity verification prompts
 up to the user for processing. This is the I/O of the transport_ctx
 @param user a pointer to be held and passed to all callbacks
 @return a newly allocated transport context owning the properties passed in
 */
wickr_transport_ctx_t *wickr_transport_ctx_create(const wickr_crypto_engine_t engine,
                                                  wickr_node_t *local_identity,
                                                  wickr_node_t *remote_identity,
                                                  uint32_t evo_count,
                                                  wickr_transport_callbacks_t callbacks,
                                                  void *user);

/**
 @ingroup wickr_transport_ctx
 
 Copy a transport context
 
 @param ctx the transport context to copy
 @return a newly allocated transport context holding a deep copy of properties from 'ctx'
 */
wickr_transport_ctx_t *wickr_transport_ctx_copy(const wickr_transport_ctx_t *ctx);

/**
 @ingroup wickr_transport_ctx
 
 Destroy a transport context
 
 @param ctx a pointer to the transport context to destroy. All properties of '*ctx' will also be destroyed
 */
void wickr_transport_ctx_destroy(wickr_transport_ctx_t **ctx);

/**
 @ingroup wickr_transport_ctx
 
 Start the transport 3 way handshake to establish stream cipher keys and begin secure communication.
 This function can also be used to reestablish a new set of cipher keys if a handshake had previously been completed.
 
 When handshake data is generated, the 'wickr_transport_tx_func' callback will be fired so that
 it can be forwarded via the proper communication channel. Handshake responses can be passed back into the transport context
 via the 'wickr_transport_ctx_process_rx_buffer' function. The 'on_state' callback of the transport will be fired to indicate
 the various stages of the handshake reaching completion, or an error occuring. User data may be passed into the 'wickr_transport_ctx_process_tx_buffer'
 function after the transport status reaches 'TRANSPORT_STATUS_ACTIVE'. If 'remote_identity' was not set during creation, and thus no remote key information
 is pinned, the 'on_identity_verify' callback will be called for the application to verify the integrity of the remote's identity via cached information, or
 whatever other means it has.
 
 Optional callbacks will also be called for when a pre-shared key is required for the key exchange to successfully complete, and
 when the tx stream is being generated to allow for customization of tx stream key generation and to update the user data field of the
 tx stream's key
 
 @param ctx the transport to start the handshake on
 */
void wickr_transport_ctx_start(wickr_transport_ctx_t *ctx);

/**
 
 @ingroup wickr_transport_ctx
 
 Process a buffer that should be sent to the remote party
 
 NOTE: This function requires the transport context to be in ACTIVE status, attempting to process a tx buffer in any other state will cause
 the transport to enter the error status. When the buffer has completed processing the encrypted payload will be passed back via the wickr_transport_tx_func
 callback.
 
 @param ctx the context to process the buffer with
 @param buffer the buffer to be encrypted and sent over the transport
 */
void wickr_transport_ctx_process_tx_buffer(wickr_transport_ctx_t *ctx, const wickr_buffer_t *buffer);

/**
 
 @ingroup wickr_transport_ctx
 
 Process a buffer that was received from the remote via a transport layer. This may include handshake data or encrypted content
 
 @param ctx the context to process the buffer with
 @param buffer the buffer to be processed by by 'ctx'
 */
void wickr_transport_ctx_process_rx_buffer(wickr_transport_ctx_t *ctx, const wickr_buffer_t *buffer);


/* GETTERS AND SETTERS */

/**
 
 @ingroup wickr_transport_ctx
 
 Get the current status of a transport context

 @param ctx the transport context to get the status of
 @return the current status of 'ctx'
 */
wickr_transport_status wickr_transport_ctx_get_status(const wickr_transport_ctx_t *ctx);

/**
 @ingroup wickr_transport_ctx
 
 Get the user data associated with the current rx stream's stream key

 @param ctx the transport context to get the rx stream user data of
 @return the current rx stream key's user data field, or NULL if no data is available
 */
const wickr_buffer_t *wickr_transport_ctx_get_rxstream_user_data(const wickr_transport_ctx_t *ctx);

/**
 @ingroup wickr_transport_ctx
 
 Get the local node information

 @param ctx the transport context to get the local node information of
 @return local node information or NULL if no information is available due to the state of the transport context
 */
const wickr_node_t *wickr_transport_ctx_get_local_node_ptr(const wickr_transport_ctx_t *ctx);

/**
 @ingroup wickr_transport_ctx
 
 Get the remote node information
 
 @param ctx the transport context to get the remote node information of
 @return remote node information or NULL if no information is available due to the state of the transport context
 */
const wickr_node_t *wickr_transport_ctx_get_remote_node_ptr(const wickr_transport_ctx_t *ctx);

/**
 @ingroup wickr_transport_ctx
 
 Get the current user context pointer

 @param ctx the context to get the user context pointer of
 @return the current user context pointer
 */
const void *wickr_transport_ctx_get_user_ctx(const wickr_transport_ctx_t *ctx);

/**
 @ingroup wickr_transport_ctx
 
 Set a user context pointer

 @param ctx the transport context to set the user supplied context info to
 @param user the pointer for the transport context to hold and be passed back in callbacks
 */
void wickr_transport_ctx_set_user_ctx(wickr_transport_ctx_t *ctx, void *user);

/**
 @ingroup wickr_transport_ctx
 
 Get the current user PSK, see 'wickr_transport_ctx_set_user_psk' for more information
 
 @param ctx the transport context to get the psk data from
 @return the current psk data for 'ctx'
 */
const wickr_buffer_t *wickr_transport_ctx_get_user_psk(const wickr_transport_ctx_t *ctx);

/**
 @ingroup wickr_transport_ctx
 
 Get the current data flow mode
 
 @param ctx the transport context to get the data flow mode of
 @return the current data flow mode for 'ctx', see 'wickr_transport_data_flow' for more info
 */
wickr_transport_data_flow wickr_transport_ctx_get_data_flow_mode(const wickr_transport_ctx_t *ctx);

/**
 @ingroup wickr_transport_ctx
 
 Set the the data flow mode. This change will be applied immediatly
 
 If the mode is READ_ONLY, attempting to write a packet will silently fail
 If the mode iw WRITE_ONLY, any incoming packets will be silently dropped
 
 @param ctx the transport context to set the data flow mode of
 @param flow_mode the flow mode you would like to enact
 @return the current data flow mode for 'ctx', see 'wickr_transport_data_flow' for more info
 */
void wickr_transport_ctx_set_data_flow_mode(wickr_transport_ctx_t *ctx , wickr_transport_data_flow flow_mode);

#endif /* transport_h */
