#pragma once
// MESSAGE ESC_RAW_SETTINGS PACKING

#define MAVLINK_MSG_ID_ESC_RAW_SETTINGS 292


typedef struct __mavlink_esc_raw_settings_t {
 uint8_t esc_type; /*<  ESC type (0=Unknown, 1=AM32, 2=BLHeli, 3=BlueJay)*/
 uint8_t fw_version_major; /*<  Firmware major version*/
 uint8_t fw_version_minor; /*<  Firmware minor version*/
 uint8_t index; /*<  Index of the ESC*/
 uint8_t length; /*<  Data length*/
 uint8_t data[64]; /*<  Raw data*/
} mavlink_esc_raw_settings_t;

#define MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN 69
#define MAVLINK_MSG_ID_ESC_RAW_SETTINGS_MIN_LEN 69
#define MAVLINK_MSG_ID_292_LEN 69
#define MAVLINK_MSG_ID_292_MIN_LEN 69

#define MAVLINK_MSG_ID_ESC_RAW_SETTINGS_CRC 171
#define MAVLINK_MSG_ID_292_CRC 171

#define MAVLINK_MSG_ESC_RAW_SETTINGS_FIELD_DATA_LEN 64

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ESC_RAW_SETTINGS { \
    292, \
    "ESC_RAW_SETTINGS", \
    6, \
    {  { "esc_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_esc_raw_settings_t, esc_type) }, \
         { "fw_version_major", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_esc_raw_settings_t, fw_version_major) }, \
         { "fw_version_minor", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_esc_raw_settings_t, fw_version_minor) }, \
         { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_esc_raw_settings_t, index) }, \
         { "length", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_esc_raw_settings_t, length) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 64, 5, offsetof(mavlink_esc_raw_settings_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ESC_RAW_SETTINGS { \
    "ESC_RAW_SETTINGS", \
    6, \
    {  { "esc_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_esc_raw_settings_t, esc_type) }, \
         { "fw_version_major", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_esc_raw_settings_t, fw_version_major) }, \
         { "fw_version_minor", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_esc_raw_settings_t, fw_version_minor) }, \
         { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_esc_raw_settings_t, index) }, \
         { "length", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_esc_raw_settings_t, length) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 64, 5, offsetof(mavlink_esc_raw_settings_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a esc_raw_settings message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param esc_type  ESC type (0=Unknown, 1=AM32, 2=BLHeli, 3=BlueJay)
 * @param fw_version_major  Firmware major version
 * @param fw_version_minor  Firmware minor version
 * @param index  Index of the ESC
 * @param length  Data length
 * @param data  Raw data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_raw_settings_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t esc_type, uint8_t fw_version_major, uint8_t fw_version_minor, uint8_t index, uint8_t length, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN];
    _mav_put_uint8_t(buf, 0, esc_type);
    _mav_put_uint8_t(buf, 1, fw_version_major);
    _mav_put_uint8_t(buf, 2, fw_version_minor);
    _mav_put_uint8_t(buf, 3, index);
    _mav_put_uint8_t(buf, 4, length);
    _mav_put_uint8_t_array(buf, 5, data, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN);
#else
    mavlink_esc_raw_settings_t packet;
    packet.esc_type = esc_type;
    packet.fw_version_major = fw_version_major;
    packet.fw_version_minor = fw_version_minor;
    packet.index = index;
    packet.length = length;
    mav_array_assign_uint8_t(packet.data, data, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_RAW_SETTINGS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_CRC);
}

/**
 * @brief Pack a esc_raw_settings message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param esc_type  ESC type (0=Unknown, 1=AM32, 2=BLHeli, 3=BlueJay)
 * @param fw_version_major  Firmware major version
 * @param fw_version_minor  Firmware minor version
 * @param index  Index of the ESC
 * @param length  Data length
 * @param data  Raw data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_raw_settings_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t esc_type, uint8_t fw_version_major, uint8_t fw_version_minor, uint8_t index, uint8_t length, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN];
    _mav_put_uint8_t(buf, 0, esc_type);
    _mav_put_uint8_t(buf, 1, fw_version_major);
    _mav_put_uint8_t(buf, 2, fw_version_minor);
    _mav_put_uint8_t(buf, 3, index);
    _mav_put_uint8_t(buf, 4, length);
    _mav_put_uint8_t_array(buf, 5, data, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN);
#else
    mavlink_esc_raw_settings_t packet;
    packet.esc_type = esc_type;
    packet.fw_version_major = fw_version_major;
    packet.fw_version_minor = fw_version_minor;
    packet.index = index;
    packet.length = length;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_RAW_SETTINGS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN);
#endif
}

/**
 * @brief Pack a esc_raw_settings message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param esc_type  ESC type (0=Unknown, 1=AM32, 2=BLHeli, 3=BlueJay)
 * @param fw_version_major  Firmware major version
 * @param fw_version_minor  Firmware minor version
 * @param index  Index of the ESC
 * @param length  Data length
 * @param data  Raw data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_raw_settings_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t esc_type,uint8_t fw_version_major,uint8_t fw_version_minor,uint8_t index,uint8_t length,const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN];
    _mav_put_uint8_t(buf, 0, esc_type);
    _mav_put_uint8_t(buf, 1, fw_version_major);
    _mav_put_uint8_t(buf, 2, fw_version_minor);
    _mav_put_uint8_t(buf, 3, index);
    _mav_put_uint8_t(buf, 4, length);
    _mav_put_uint8_t_array(buf, 5, data, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN);
#else
    mavlink_esc_raw_settings_t packet;
    packet.esc_type = esc_type;
    packet.fw_version_major = fw_version_major;
    packet.fw_version_minor = fw_version_minor;
    packet.index = index;
    packet.length = length;
    mav_array_assign_uint8_t(packet.data, data, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_RAW_SETTINGS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_CRC);
}

/**
 * @brief Encode a esc_raw_settings struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param esc_raw_settings C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_raw_settings_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_esc_raw_settings_t* esc_raw_settings)
{
    return mavlink_msg_esc_raw_settings_pack(system_id, component_id, msg, esc_raw_settings->esc_type, esc_raw_settings->fw_version_major, esc_raw_settings->fw_version_minor, esc_raw_settings->index, esc_raw_settings->length, esc_raw_settings->data);
}

/**
 * @brief Encode a esc_raw_settings struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param esc_raw_settings C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_raw_settings_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_esc_raw_settings_t* esc_raw_settings)
{
    return mavlink_msg_esc_raw_settings_pack_chan(system_id, component_id, chan, msg, esc_raw_settings->esc_type, esc_raw_settings->fw_version_major, esc_raw_settings->fw_version_minor, esc_raw_settings->index, esc_raw_settings->length, esc_raw_settings->data);
}

/**
 * @brief Encode a esc_raw_settings struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param esc_raw_settings C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_raw_settings_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_esc_raw_settings_t* esc_raw_settings)
{
    return mavlink_msg_esc_raw_settings_pack_status(system_id, component_id, _status, msg,  esc_raw_settings->esc_type, esc_raw_settings->fw_version_major, esc_raw_settings->fw_version_minor, esc_raw_settings->index, esc_raw_settings->length, esc_raw_settings->data);
}

/**
 * @brief Send a esc_raw_settings message
 * @param chan MAVLink channel to send the message
 *
 * @param esc_type  ESC type (0=Unknown, 1=AM32, 2=BLHeli, 3=BlueJay)
 * @param fw_version_major  Firmware major version
 * @param fw_version_minor  Firmware minor version
 * @param index  Index of the ESC
 * @param length  Data length
 * @param data  Raw data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_esc_raw_settings_send(mavlink_channel_t chan, uint8_t esc_type, uint8_t fw_version_major, uint8_t fw_version_minor, uint8_t index, uint8_t length, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN];
    _mav_put_uint8_t(buf, 0, esc_type);
    _mav_put_uint8_t(buf, 1, fw_version_major);
    _mav_put_uint8_t(buf, 2, fw_version_minor);
    _mav_put_uint8_t(buf, 3, index);
    _mav_put_uint8_t(buf, 4, length);
    _mav_put_uint8_t_array(buf, 5, data, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_RAW_SETTINGS, buf, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_CRC);
#else
    mavlink_esc_raw_settings_t packet;
    packet.esc_type = esc_type;
    packet.fw_version_major = fw_version_major;
    packet.fw_version_minor = fw_version_minor;
    packet.index = index;
    packet.length = length;
    mav_array_assign_uint8_t(packet.data, data, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_RAW_SETTINGS, (const char *)&packet, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_CRC);
#endif
}

/**
 * @brief Send a esc_raw_settings message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_esc_raw_settings_send_struct(mavlink_channel_t chan, const mavlink_esc_raw_settings_t* esc_raw_settings)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_esc_raw_settings_send(chan, esc_raw_settings->esc_type, esc_raw_settings->fw_version_major, esc_raw_settings->fw_version_minor, esc_raw_settings->index, esc_raw_settings->length, esc_raw_settings->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_RAW_SETTINGS, (const char *)esc_raw_settings, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_CRC);
#endif
}

#if MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_esc_raw_settings_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t esc_type, uint8_t fw_version_major, uint8_t fw_version_minor, uint8_t index, uint8_t length, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, esc_type);
    _mav_put_uint8_t(buf, 1, fw_version_major);
    _mav_put_uint8_t(buf, 2, fw_version_minor);
    _mav_put_uint8_t(buf, 3, index);
    _mav_put_uint8_t(buf, 4, length);
    _mav_put_uint8_t_array(buf, 5, data, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_RAW_SETTINGS, buf, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_CRC);
#else
    mavlink_esc_raw_settings_t *packet = (mavlink_esc_raw_settings_t *)msgbuf;
    packet->esc_type = esc_type;
    packet->fw_version_major = fw_version_major;
    packet->fw_version_minor = fw_version_minor;
    packet->index = index;
    packet->length = length;
    mav_array_assign_uint8_t(packet->data, data, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_RAW_SETTINGS, (const char *)packet, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_CRC);
#endif
}
#endif

#endif

// MESSAGE ESC_RAW_SETTINGS UNPACKING


/**
 * @brief Get field esc_type from esc_raw_settings message
 *
 * @return  ESC type (0=Unknown, 1=AM32, 2=BLHeli, 3=BlueJay)
 */
static inline uint8_t mavlink_msg_esc_raw_settings_get_esc_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field fw_version_major from esc_raw_settings message
 *
 * @return  Firmware major version
 */
static inline uint8_t mavlink_msg_esc_raw_settings_get_fw_version_major(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field fw_version_minor from esc_raw_settings message
 *
 * @return  Firmware minor version
 */
static inline uint8_t mavlink_msg_esc_raw_settings_get_fw_version_minor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field index from esc_raw_settings message
 *
 * @return  Index of the ESC
 */
static inline uint8_t mavlink_msg_esc_raw_settings_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field length from esc_raw_settings message
 *
 * @return  Data length
 */
static inline uint8_t mavlink_msg_esc_raw_settings_get_length(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field data from esc_raw_settings message
 *
 * @return  Raw data
 */
static inline uint16_t mavlink_msg_esc_raw_settings_get_data(const mavlink_message_t* msg, uint8_t *data)
{
    return _MAV_RETURN_uint8_t_array(msg, data, 64,  5);
}

/**
 * @brief Decode a esc_raw_settings message into a struct
 *
 * @param msg The message to decode
 * @param esc_raw_settings C-struct to decode the message contents into
 */
static inline void mavlink_msg_esc_raw_settings_decode(const mavlink_message_t* msg, mavlink_esc_raw_settings_t* esc_raw_settings)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    esc_raw_settings->esc_type = mavlink_msg_esc_raw_settings_get_esc_type(msg);
    esc_raw_settings->fw_version_major = mavlink_msg_esc_raw_settings_get_fw_version_major(msg);
    esc_raw_settings->fw_version_minor = mavlink_msg_esc_raw_settings_get_fw_version_minor(msg);
    esc_raw_settings->index = mavlink_msg_esc_raw_settings_get_index(msg);
    esc_raw_settings->length = mavlink_msg_esc_raw_settings_get_length(msg);
    mavlink_msg_esc_raw_settings_get_data(msg, esc_raw_settings->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN? msg->len : MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN;
        memset(esc_raw_settings, 0, MAVLINK_MSG_ID_ESC_RAW_SETTINGS_LEN);
    memcpy(esc_raw_settings, _MAV_PAYLOAD(msg), len);
#endif
}
