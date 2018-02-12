/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: stream.proto */

#ifndef PROTOBUF_C_stream_2eproto__INCLUDED
#define PROTOBUF_C_stream_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003000 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "node.pb-c.h"

typedef struct _Wickr__Proto__Handshake Wickr__Proto__Handshake;
typedef struct _Wickr__Proto__Handshake__Seed Wickr__Proto__Handshake__Seed;
typedef struct _Wickr__Proto__Handshake__KeyExchange Wickr__Proto__Handshake__KeyExchange;
typedef struct _Wickr__Proto__Handshake__Response Wickr__Proto__Handshake__Response;
typedef struct _Wickr__Proto__Handshake__Finish Wickr__Proto__Handshake__Finish;
typedef struct _Wickr__Proto__StreamKey Wickr__Proto__StreamKey;


/* --- enums --- */


/* --- messages --- */

struct  _Wickr__Proto__Handshake__Seed
{
  ProtobufCMessage base;
  Wickr__Proto__Node *node_info;
};
#define WICKR__PROTO__HANDSHAKE__SEED__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&wickr__proto__handshake__seed__descriptor) \
    , NULL }


struct  _Wickr__Proto__Handshake__KeyExchange
{
  ProtobufCMessage base;
  protobuf_c_boolean has_sender_pub;
  ProtobufCBinaryData sender_pub;
  protobuf_c_boolean has_exchange_data;
  ProtobufCBinaryData exchange_data;
};
#define WICKR__PROTO__HANDSHAKE__KEY_EXCHANGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&wickr__proto__handshake__key_exchange__descriptor) \
    , 0, {0,NULL}, 0, {0,NULL} }


struct  _Wickr__Proto__Handshake__Response
{
  ProtobufCMessage base;
  Wickr__Proto__Handshake__KeyExchange *key_exchange;
  Wickr__Proto__Handshake__Seed *response_key;
};
#define WICKR__PROTO__HANDSHAKE__RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&wickr__proto__handshake__response__descriptor) \
    , NULL, NULL }


struct  _Wickr__Proto__Handshake__Finish
{
  ProtobufCMessage base;
  Wickr__Proto__Handshake__KeyExchange *key_exchange;
};
#define WICKR__PROTO__HANDSHAKE__FINISH__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&wickr__proto__handshake__finish__descriptor) \
    , NULL }


typedef enum {
  WICKR__PROTO__HANDSHAKE__PAYLOAD__NOT_SET = 0,
  WICKR__PROTO__HANDSHAKE__PAYLOAD_SEED = 2,
  WICKR__PROTO__HANDSHAKE__PAYLOAD_RESPONSE = 3,
  WICKR__PROTO__HANDSHAKE__PAYLOAD_FINISH = 4
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(WICKR__PROTO__HANDSHAKE__PAYLOAD)
} Wickr__Proto__Handshake__PayloadCase;

struct  _Wickr__Proto__Handshake
{
  ProtobufCMessage base;
  uint32_t version;
  Wickr__Proto__Handshake__PayloadCase payload_case;
  union {
    Wickr__Proto__Handshake__Seed *seed;
    Wickr__Proto__Handshake__Response *response;
    Wickr__Proto__Handshake__Finish *finish;
  };
};
#define WICKR__PROTO__HANDSHAKE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&wickr__proto__handshake__descriptor) \
    , 0, WICKR__PROTO__HANDSHAKE__PAYLOAD__NOT_SET, {0} }


struct  _Wickr__Proto__StreamKey
{
  ProtobufCMessage base;
  protobuf_c_boolean has_cipher_key;
  ProtobufCBinaryData cipher_key;
  protobuf_c_boolean has_evolution_key;
  ProtobufCBinaryData evolution_key;
  protobuf_c_boolean has_packets_per_evo;
  uint32_t packets_per_evo;
  protobuf_c_boolean has_user_data;
  ProtobufCBinaryData user_data;
};
#define WICKR__PROTO__STREAM_KEY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&wickr__proto__stream_key__descriptor) \
    , 0, {0,NULL}, 0, {0,NULL}, 0, 0, 0, {0,NULL} }


/* Wickr__Proto__Handshake__Seed methods */
void   wickr__proto__handshake__seed__init
                     (Wickr__Proto__Handshake__Seed         *message);
/* Wickr__Proto__Handshake__KeyExchange methods */
void   wickr__proto__handshake__key_exchange__init
                     (Wickr__Proto__Handshake__KeyExchange         *message);
/* Wickr__Proto__Handshake__Response methods */
void   wickr__proto__handshake__response__init
                     (Wickr__Proto__Handshake__Response         *message);
/* Wickr__Proto__Handshake__Finish methods */
void   wickr__proto__handshake__finish__init
                     (Wickr__Proto__Handshake__Finish         *message);
/* Wickr__Proto__Handshake methods */
void   wickr__proto__handshake__init
                     (Wickr__Proto__Handshake         *message);
size_t wickr__proto__handshake__get_packed_size
                     (const Wickr__Proto__Handshake   *message);
size_t wickr__proto__handshake__pack
                     (const Wickr__Proto__Handshake   *message,
                      uint8_t             *out);
size_t wickr__proto__handshake__pack_to_buffer
                     (const Wickr__Proto__Handshake   *message,
                      ProtobufCBuffer     *buffer);
Wickr__Proto__Handshake *
       wickr__proto__handshake__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   wickr__proto__handshake__free_unpacked
                     (Wickr__Proto__Handshake *message,
                      ProtobufCAllocator *allocator);
/* Wickr__Proto__StreamKey methods */
void   wickr__proto__stream_key__init
                     (Wickr__Proto__StreamKey         *message);
size_t wickr__proto__stream_key__get_packed_size
                     (const Wickr__Proto__StreamKey   *message);
size_t wickr__proto__stream_key__pack
                     (const Wickr__Proto__StreamKey   *message,
                      uint8_t             *out);
size_t wickr__proto__stream_key__pack_to_buffer
                     (const Wickr__Proto__StreamKey   *message,
                      ProtobufCBuffer     *buffer);
Wickr__Proto__StreamKey *
       wickr__proto__stream_key__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   wickr__proto__stream_key__free_unpacked
                     (Wickr__Proto__StreamKey *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Wickr__Proto__Handshake__Seed_Closure)
                 (const Wickr__Proto__Handshake__Seed *message,
                  void *closure_data);
typedef void (*Wickr__Proto__Handshake__KeyExchange_Closure)
                 (const Wickr__Proto__Handshake__KeyExchange *message,
                  void *closure_data);
typedef void (*Wickr__Proto__Handshake__Response_Closure)
                 (const Wickr__Proto__Handshake__Response *message,
                  void *closure_data);
typedef void (*Wickr__Proto__Handshake__Finish_Closure)
                 (const Wickr__Proto__Handshake__Finish *message,
                  void *closure_data);
typedef void (*Wickr__Proto__Handshake_Closure)
                 (const Wickr__Proto__Handshake *message,
                  void *closure_data);
typedef void (*Wickr__Proto__StreamKey_Closure)
                 (const Wickr__Proto__StreamKey *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor wickr__proto__handshake__descriptor;
extern const ProtobufCMessageDescriptor wickr__proto__handshake__seed__descriptor;
extern const ProtobufCMessageDescriptor wickr__proto__handshake__key_exchange__descriptor;
extern const ProtobufCMessageDescriptor wickr__proto__handshake__response__descriptor;
extern const ProtobufCMessageDescriptor wickr__proto__handshake__finish__descriptor;
extern const ProtobufCMessageDescriptor wickr__proto__stream_key__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_stream_2eproto__INCLUDED */
