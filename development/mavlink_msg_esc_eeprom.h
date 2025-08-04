#pragma once
// MESSAGE ESC_EEPROM PACKING

#define MAVLINK_MSG_ID_ESC_EEPROM 292


typedef struct __mavlink_esc_eeprom_t {
 uint8_t index; /*<  Index of the ESC*/
 uint8_t length; /*<  Length of the data*/
 uint8_t data[128]; /*<  EEPROM data (TODO: how long? AM32 EEPROM settings region is 48 Bytes)*/
} mavlink_esc_eeprom_t;

#define MAVLINK_MSG_ID_ESC_EEPROM_LEN 130
#define MAVLINK_MSG_ID_ESC_EEPROM_MIN_LEN 130
#define MAVLINK_MSG_ID_292_LEN 130
#define MAVLINK_MSG_ID_292_MIN_LEN 130

#define MAVLINK_MSG_ID_ESC_EEPROM_CRC 61
#define MAVLINK_MSG_ID_292_CRC 61

#define MAVLINK_MSG_ESC_EEPROM_FIELD_DATA_LEN 128

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ESC_EEPROM { \
    292, \
    "ESC_EEPROM", \
    3, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_esc_eeprom_t, index) }, \
         { "length", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_esc_eeprom_t, length) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 128, 2, offsetof(mavlink_esc_eeprom_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ESC_EEPROM { \
    "ESC_EEPROM", \
    3, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_esc_eeprom_t, index) }, \
         { "length", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_esc_eeprom_t, length) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 128, 2, offsetof(mavlink_esc_eeprom_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a esc_eeprom message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  Index of the ESC
 * @param length  Length of the data
 * @param data  EEPROM data (TODO: how long? AM32 EEPROM settings region is 48 Bytes)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_eeprom_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t index, uint8_t length, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_EEPROM_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t(buf, 1, length);
    _mav_put_uint8_t_array(buf, 2, data, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_EEPROM_LEN);
#else
    mavlink_esc_eeprom_t packet;
    packet.index = index;
    packet.length = length;
    mav_array_assign_uint8_t(packet.data, data, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_EEPROM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_EEPROM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ESC_EEPROM_MIN_LEN, MAVLINK_MSG_ID_ESC_EEPROM_LEN, MAVLINK_MSG_ID_ESC_EEPROM_CRC);
}

/**
 * @brief Pack a esc_eeprom message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  Index of the ESC
 * @param length  Length of the data
 * @param data  EEPROM data (TODO: how long? AM32 EEPROM settings region is 48 Bytes)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_eeprom_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t index, uint8_t length, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_EEPROM_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t(buf, 1, length);
    _mav_put_uint8_t_array(buf, 2, data, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_EEPROM_LEN);
#else
    mavlink_esc_eeprom_t packet;
    packet.index = index;
    packet.length = length;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_EEPROM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_EEPROM;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ESC_EEPROM_MIN_LEN, MAVLINK_MSG_ID_ESC_EEPROM_LEN, MAVLINK_MSG_ID_ESC_EEPROM_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ESC_EEPROM_MIN_LEN, MAVLINK_MSG_ID_ESC_EEPROM_LEN);
#endif
}

/**
 * @brief Pack a esc_eeprom message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param index  Index of the ESC
 * @param length  Length of the data
 * @param data  EEPROM data (TODO: how long? AM32 EEPROM settings region is 48 Bytes)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_eeprom_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t index,uint8_t length,const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_EEPROM_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t(buf, 1, length);
    _mav_put_uint8_t_array(buf, 2, data, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_EEPROM_LEN);
#else
    mavlink_esc_eeprom_t packet;
    packet.index = index;
    packet.length = length;
    mav_array_assign_uint8_t(packet.data, data, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_EEPROM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_EEPROM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ESC_EEPROM_MIN_LEN, MAVLINK_MSG_ID_ESC_EEPROM_LEN, MAVLINK_MSG_ID_ESC_EEPROM_CRC);
}

/**
 * @brief Encode a esc_eeprom struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param esc_eeprom C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_eeprom_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_esc_eeprom_t* esc_eeprom)
{
    return mavlink_msg_esc_eeprom_pack(system_id, component_id, msg, esc_eeprom->index, esc_eeprom->length, esc_eeprom->data);
}

/**
 * @brief Encode a esc_eeprom struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param esc_eeprom C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_eeprom_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_esc_eeprom_t* esc_eeprom)
{
    return mavlink_msg_esc_eeprom_pack_chan(system_id, component_id, chan, msg, esc_eeprom->index, esc_eeprom->length, esc_eeprom->data);
}

/**
 * @brief Encode a esc_eeprom struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param esc_eeprom C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_eeprom_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_esc_eeprom_t* esc_eeprom)
{
    return mavlink_msg_esc_eeprom_pack_status(system_id, component_id, _status, msg,  esc_eeprom->index, esc_eeprom->length, esc_eeprom->data);
}

/**
 * @brief Send a esc_eeprom message
 * @param chan MAVLink channel to send the message
 *
 * @param index  Index of the ESC
 * @param length  Length of the data
 * @param data  EEPROM data (TODO: how long? AM32 EEPROM settings region is 48 Bytes)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_esc_eeprom_send(mavlink_channel_t chan, uint8_t index, uint8_t length, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_EEPROM_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t(buf, 1, length);
    _mav_put_uint8_t_array(buf, 2, data, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_EEPROM, buf, MAVLINK_MSG_ID_ESC_EEPROM_MIN_LEN, MAVLINK_MSG_ID_ESC_EEPROM_LEN, MAVLINK_MSG_ID_ESC_EEPROM_CRC);
#else
    mavlink_esc_eeprom_t packet;
    packet.index = index;
    packet.length = length;
    mav_array_assign_uint8_t(packet.data, data, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_EEPROM, (const char *)&packet, MAVLINK_MSG_ID_ESC_EEPROM_MIN_LEN, MAVLINK_MSG_ID_ESC_EEPROM_LEN, MAVLINK_MSG_ID_ESC_EEPROM_CRC);
#endif
}

/**
 * @brief Send a esc_eeprom message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_esc_eeprom_send_struct(mavlink_channel_t chan, const mavlink_esc_eeprom_t* esc_eeprom)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_esc_eeprom_send(chan, esc_eeprom->index, esc_eeprom->length, esc_eeprom->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_EEPROM, (const char *)esc_eeprom, MAVLINK_MSG_ID_ESC_EEPROM_MIN_LEN, MAVLINK_MSG_ID_ESC_EEPROM_LEN, MAVLINK_MSG_ID_ESC_EEPROM_CRC);
#endif
}

#if MAVLINK_MSG_ID_ESC_EEPROM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_esc_eeprom_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t index, uint8_t length, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t(buf, 1, length);
    _mav_put_uint8_t_array(buf, 2, data, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_EEPROM, buf, MAVLINK_MSG_ID_ESC_EEPROM_MIN_LEN, MAVLINK_MSG_ID_ESC_EEPROM_LEN, MAVLINK_MSG_ID_ESC_EEPROM_CRC);
#else
    mavlink_esc_eeprom_t *packet = (mavlink_esc_eeprom_t *)msgbuf;
    packet->index = index;
    packet->length = length;
    mav_array_assign_uint8_t(packet->data, data, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_EEPROM, (const char *)packet, MAVLINK_MSG_ID_ESC_EEPROM_MIN_LEN, MAVLINK_MSG_ID_ESC_EEPROM_LEN, MAVLINK_MSG_ID_ESC_EEPROM_CRC);
#endif
}
#endif

#endif

// MESSAGE ESC_EEPROM UNPACKING


/**
 * @brief Get field index from esc_eeprom message
 *
 * @return  Index of the ESC
 */
static inline uint8_t mavlink_msg_esc_eeprom_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field length from esc_eeprom message
 *
 * @return  Length of the data
 */
static inline uint8_t mavlink_msg_esc_eeprom_get_length(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field data from esc_eeprom message
 *
 * @return  EEPROM data (TODO: how long? AM32 EEPROM settings region is 48 Bytes)
 */
static inline uint16_t mavlink_msg_esc_eeprom_get_data(const mavlink_message_t* msg, uint8_t *data)
{
    return _MAV_RETURN_uint8_t_array(msg, data, 128,  2);
}

/**
 * @brief Decode a esc_eeprom message into a struct
 *
 * @param msg The message to decode
 * @param esc_eeprom C-struct to decode the message contents into
 */
static inline void mavlink_msg_esc_eeprom_decode(const mavlink_message_t* msg, mavlink_esc_eeprom_t* esc_eeprom)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    esc_eeprom->index = mavlink_msg_esc_eeprom_get_index(msg);
    esc_eeprom->length = mavlink_msg_esc_eeprom_get_length(msg);
    mavlink_msg_esc_eeprom_get_data(msg, esc_eeprom->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ESC_EEPROM_LEN? msg->len : MAVLINK_MSG_ID_ESC_EEPROM_LEN;
        memset(esc_eeprom, 0, MAVLINK_MSG_ID_ESC_EEPROM_LEN);
    memcpy(esc_eeprom, _MAV_PAYLOAD(msg), len);
#endif
}
