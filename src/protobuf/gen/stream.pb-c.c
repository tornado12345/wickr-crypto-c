/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: stream.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "stream.pb-c.h"
void   wickr__proto__handshake_v1__seed__init
                     (Wickr__Proto__HandshakeV1__Seed         *message)
{
  static const Wickr__Proto__HandshakeV1__Seed init_value = WICKR__PROTO__HANDSHAKE_V1__SEED__INIT;
  *message = init_value;
}
void   wickr__proto__handshake_v1__response__init
                     (Wickr__Proto__HandshakeV1__Response         *message)
{
  static const Wickr__Proto__HandshakeV1__Response init_value = WICKR__PROTO__HANDSHAKE_V1__RESPONSE__INIT;
  *message = init_value;
}
void   wickr__proto__handshake_v1__init
                     (Wickr__Proto__HandshakeV1         *message)
{
  static const Wickr__Proto__HandshakeV1 init_value = WICKR__PROTO__HANDSHAKE_V1__INIT;
  *message = init_value;
}
size_t wickr__proto__handshake_v1__get_packed_size
                     (const Wickr__Proto__HandshakeV1 *message)
{
  assert(message->base.descriptor == &wickr__proto__handshake_v1__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t wickr__proto__handshake_v1__pack
                     (const Wickr__Proto__HandshakeV1 *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &wickr__proto__handshake_v1__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t wickr__proto__handshake_v1__pack_to_buffer
                     (const Wickr__Proto__HandshakeV1 *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &wickr__proto__handshake_v1__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Wickr__Proto__HandshakeV1 *
       wickr__proto__handshake_v1__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Wickr__Proto__HandshakeV1 *)
     protobuf_c_message_unpack (&wickr__proto__handshake_v1__descriptor,
                                allocator, len, data);
}
void   wickr__proto__handshake_v1__free_unpacked
                     (Wickr__Proto__HandshakeV1 *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &wickr__proto__handshake_v1__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   wickr__proto__handshake_v1_response_data__init
                     (Wickr__Proto__HandshakeV1ResponseData         *message)
{
  static const Wickr__Proto__HandshakeV1ResponseData init_value = WICKR__PROTO__HANDSHAKE_V1_RESPONSE_DATA__INIT;
  *message = init_value;
}
size_t wickr__proto__handshake_v1_response_data__get_packed_size
                     (const Wickr__Proto__HandshakeV1ResponseData *message)
{
  assert(message->base.descriptor == &wickr__proto__handshake_v1_response_data__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t wickr__proto__handshake_v1_response_data__pack
                     (const Wickr__Proto__HandshakeV1ResponseData *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &wickr__proto__handshake_v1_response_data__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t wickr__proto__handshake_v1_response_data__pack_to_buffer
                     (const Wickr__Proto__HandshakeV1ResponseData *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &wickr__proto__handshake_v1_response_data__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Wickr__Proto__HandshakeV1ResponseData *
       wickr__proto__handshake_v1_response_data__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Wickr__Proto__HandshakeV1ResponseData *)
     protobuf_c_message_unpack (&wickr__proto__handshake_v1_response_data__descriptor,
                                allocator, len, data);
}
void   wickr__proto__handshake_v1_response_data__free_unpacked
                     (Wickr__Proto__HandshakeV1ResponseData *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &wickr__proto__handshake_v1_response_data__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   wickr__proto__transport_root_key__init
                     (Wickr__Proto__TransportRootKey         *message)
{
  static const Wickr__Proto__TransportRootKey init_value = WICKR__PROTO__TRANSPORT_ROOT_KEY__INIT;
  *message = init_value;
}
size_t wickr__proto__transport_root_key__get_packed_size
                     (const Wickr__Proto__TransportRootKey *message)
{
  assert(message->base.descriptor == &wickr__proto__transport_root_key__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t wickr__proto__transport_root_key__pack
                     (const Wickr__Proto__TransportRootKey *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &wickr__proto__transport_root_key__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t wickr__proto__transport_root_key__pack_to_buffer
                     (const Wickr__Proto__TransportRootKey *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &wickr__proto__transport_root_key__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Wickr__Proto__TransportRootKey *
       wickr__proto__transport_root_key__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Wickr__Proto__TransportRootKey *)
     protobuf_c_message_unpack (&wickr__proto__transport_root_key__descriptor,
                                allocator, len, data);
}
void   wickr__proto__transport_root_key__free_unpacked
                     (Wickr__Proto__TransportRootKey *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &wickr__proto__transport_root_key__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   wickr__proto__stream_key__init
                     (Wickr__Proto__StreamKey         *message)
{
  static const Wickr__Proto__StreamKey init_value = WICKR__PROTO__STREAM_KEY__INIT;
  *message = init_value;
}
size_t wickr__proto__stream_key__get_packed_size
                     (const Wickr__Proto__StreamKey *message)
{
  assert(message->base.descriptor == &wickr__proto__stream_key__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t wickr__proto__stream_key__pack
                     (const Wickr__Proto__StreamKey *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &wickr__proto__stream_key__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t wickr__proto__stream_key__pack_to_buffer
                     (const Wickr__Proto__StreamKey *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &wickr__proto__stream_key__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Wickr__Proto__StreamKey *
       wickr__proto__stream_key__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Wickr__Proto__StreamKey *)
     protobuf_c_message_unpack (&wickr__proto__stream_key__descriptor,
                                allocator, len, data);
}
void   wickr__proto__stream_key__free_unpacked
                     (Wickr__Proto__StreamKey *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &wickr__proto__stream_key__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor wickr__proto__handshake_v1__seed__field_descriptors[3] =
{
  {
    "id_chain",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Wickr__Proto__HandshakeV1__Seed, id_chain),
    &wickr__proto__identity_chain__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "ephemeral_pubkey",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    offsetof(Wickr__Proto__HandshakeV1__Seed, has_ephemeral_pubkey),
    offsetof(Wickr__Proto__HandshakeV1__Seed, ephemeral_pubkey),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "identity_required",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BOOL,
    offsetof(Wickr__Proto__HandshakeV1__Seed, has_identity_required),
    offsetof(Wickr__Proto__HandshakeV1__Seed, identity_required),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned wickr__proto__handshake_v1__seed__field_indices_by_name[] = {
  1,   /* field[1] = ephemeral_pubkey */
  0,   /* field[0] = id_chain */
  2,   /* field[2] = identity_required */
};
static const ProtobufCIntRange wickr__proto__handshake_v1__seed__number_ranges[1 + 1] =
{
  { 2, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor wickr__proto__handshake_v1__seed__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "wickr.proto.HandshakeV1.Seed",
  "Seed",
  "Wickr__Proto__HandshakeV1__Seed",
  "wickr.proto",
  sizeof(Wickr__Proto__HandshakeV1__Seed),
  3,
  wickr__proto__handshake_v1__seed__field_descriptors,
  wickr__proto__handshake_v1__seed__field_indices_by_name,
  1,  wickr__proto__handshake_v1__seed__number_ranges,
  (ProtobufCMessageInit) wickr__proto__handshake_v1__seed__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor wickr__proto__handshake_v1__response__field_descriptors[3] =
{
  {
    "ephemeral_pubkey",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    offsetof(Wickr__Proto__HandshakeV1__Response, has_ephemeral_pubkey),
    offsetof(Wickr__Proto__HandshakeV1__Response, ephemeral_pubkey),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "encrypted_response_data",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    offsetof(Wickr__Proto__HandshakeV1__Response, has_encrypted_response_data),
    offsetof(Wickr__Proto__HandshakeV1__Response, encrypted_response_data),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "id_chain",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Wickr__Proto__HandshakeV1__Response, id_chain),
    &wickr__proto__identity_chain__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned wickr__proto__handshake_v1__response__field_indices_by_name[] = {
  1,   /* field[1] = encrypted_response_data */
  0,   /* field[0] = ephemeral_pubkey */
  2,   /* field[2] = id_chain */
};
static const ProtobufCIntRange wickr__proto__handshake_v1__response__number_ranges[1 + 1] =
{
  { 2, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor wickr__proto__handshake_v1__response__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "wickr.proto.HandshakeV1.Response",
  "Response",
  "Wickr__Proto__HandshakeV1__Response",
  "wickr.proto",
  sizeof(Wickr__Proto__HandshakeV1__Response),
  3,
  wickr__proto__handshake_v1__response__field_descriptors,
  wickr__proto__handshake_v1__response__field_indices_by_name,
  1,  wickr__proto__handshake_v1__response__number_ranges,
  (ProtobufCMessageInit) wickr__proto__handshake_v1__response__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor wickr__proto__handshake_v1__field_descriptors[2] =
{
  {
    "seed",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Wickr__Proto__HandshakeV1, payload_case),
    offsetof(Wickr__Proto__HandshakeV1, seed),
    &wickr__proto__handshake_v1__seed__descriptor,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "response",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Wickr__Proto__HandshakeV1, payload_case),
    offsetof(Wickr__Proto__HandshakeV1, response),
    &wickr__proto__handshake_v1__response__descriptor,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned wickr__proto__handshake_v1__field_indices_by_name[] = {
  1,   /* field[1] = response */
  0,   /* field[0] = seed */
};
static const ProtobufCIntRange wickr__proto__handshake_v1__number_ranges[1 + 1] =
{
  { 2, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor wickr__proto__handshake_v1__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "wickr.proto.HandshakeV1",
  "HandshakeV1",
  "Wickr__Proto__HandshakeV1",
  "wickr.proto",
  sizeof(Wickr__Proto__HandshakeV1),
  2,
  wickr__proto__handshake_v1__field_descriptors,
  wickr__proto__handshake_v1__field_indices_by_name,
  1,  wickr__proto__handshake_v1__number_ranges,
  (ProtobufCMessageInit) wickr__proto__handshake_v1__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor wickr__proto__handshake_v1_response_data__field_descriptors[1] =
{
  {
    "root_key",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Wickr__Proto__HandshakeV1ResponseData, root_key),
    &wickr__proto__transport_root_key__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned wickr__proto__handshake_v1_response_data__field_indices_by_name[] = {
  0,   /* field[0] = root_key */
};
static const ProtobufCIntRange wickr__proto__handshake_v1_response_data__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor wickr__proto__handshake_v1_response_data__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "wickr.proto.HandshakeV1ResponseData",
  "HandshakeV1ResponseData",
  "Wickr__Proto__HandshakeV1ResponseData",
  "wickr.proto",
  sizeof(Wickr__Proto__HandshakeV1ResponseData),
  1,
  wickr__proto__handshake_v1_response_data__field_descriptors,
  wickr__proto__handshake_v1_response_data__field_indices_by_name,
  1,  wickr__proto__handshake_v1_response_data__number_ranges,
  (ProtobufCMessageInit) wickr__proto__handshake_v1_response_data__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor wickr__proto__transport_root_key__field_descriptors[4] =
{
  {
    "secret",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    offsetof(Wickr__Proto__TransportRootKey, has_secret),
    offsetof(Wickr__Proto__TransportRootKey, secret),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "cipher_id",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT32,
    offsetof(Wickr__Proto__TransportRootKey, has_cipher_id),
    offsetof(Wickr__Proto__TransportRootKey, cipher_id),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "packets_per_evo_send",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT32,
    offsetof(Wickr__Proto__TransportRootKey, has_packets_per_evo_send),
    offsetof(Wickr__Proto__TransportRootKey, packets_per_evo_send),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "packets_per_evo_recv",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT32,
    offsetof(Wickr__Proto__TransportRootKey, has_packets_per_evo_recv),
    offsetof(Wickr__Proto__TransportRootKey, packets_per_evo_recv),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned wickr__proto__transport_root_key__field_indices_by_name[] = {
  1,   /* field[1] = cipher_id */
  3,   /* field[3] = packets_per_evo_recv */
  2,   /* field[2] = packets_per_evo_send */
  0,   /* field[0] = secret */
};
static const ProtobufCIntRange wickr__proto__transport_root_key__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor wickr__proto__transport_root_key__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "wickr.proto.TransportRootKey",
  "TransportRootKey",
  "Wickr__Proto__TransportRootKey",
  "wickr.proto",
  sizeof(Wickr__Proto__TransportRootKey),
  4,
  wickr__proto__transport_root_key__field_descriptors,
  wickr__proto__transport_root_key__field_indices_by_name,
  1,  wickr__proto__transport_root_key__number_ranges,
  (ProtobufCMessageInit) wickr__proto__transport_root_key__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor wickr__proto__stream_key__field_descriptors[4] =
{
  {
    "cipher_key",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    offsetof(Wickr__Proto__StreamKey, has_cipher_key),
    offsetof(Wickr__Proto__StreamKey, cipher_key),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "evolution_key",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    offsetof(Wickr__Proto__StreamKey, has_evolution_key),
    offsetof(Wickr__Proto__StreamKey, evolution_key),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "packets_per_evo",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT32,
    offsetof(Wickr__Proto__StreamKey, has_packets_per_evo),
    offsetof(Wickr__Proto__StreamKey, packets_per_evo),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "user_data",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    offsetof(Wickr__Proto__StreamKey, has_user_data),
    offsetof(Wickr__Proto__StreamKey, user_data),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned wickr__proto__stream_key__field_indices_by_name[] = {
  0,   /* field[0] = cipher_key */
  1,   /* field[1] = evolution_key */
  2,   /* field[2] = packets_per_evo */
  3,   /* field[3] = user_data */
};
static const ProtobufCIntRange wickr__proto__stream_key__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor wickr__proto__stream_key__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "wickr.proto.StreamKey",
  "StreamKey",
  "Wickr__Proto__StreamKey",
  "wickr.proto",
  sizeof(Wickr__Proto__StreamKey),
  4,
  wickr__proto__stream_key__field_descriptors,
  wickr__proto__stream_key__field_indices_by_name,
  1,  wickr__proto__stream_key__number_ranges,
  (ProtobufCMessageInit) wickr__proto__stream_key__init,
  NULL,NULL,NULL    /* reserved[123] */
};
