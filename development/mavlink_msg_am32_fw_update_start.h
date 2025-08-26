#pragma once
// MESSAGE AM32_FW_UPDATE_START PACKING

#define MAVLINK_MSG_ID_AM32_FW_UPDATE_START 293


typedef struct __mavlink_am32_fw_update_start_t {
 uint8_t index; /*<  Index of the ESC. Index 0 corresponds to ESC1.*/
 uint8_t filepath[128]; /*<  Null-terminated file path of firmware binary to upload. Maximum 127 characters plus terminator.*/
} mavlink_am32_fw_update_start_t;

#define MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN 129
#define MAVLINK_MSG_ID_AM32_FW_UPDATE_START_MIN_LEN 129
#define MAVLINK_MSG_ID_293_LEN 129
#define MAVLINK_MSG_ID_293_MIN_LEN 129

#define MAVLINK_MSG_ID_AM32_FW_UPDATE_START_CRC 229
#define MAVLINK_MSG_ID_293_CRC 229

#define MAVLINK_MSG_AM32_FW_UPDATE_START_FIELD_FILEPATH_LEN 128

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AM32_FW_UPDATE_START { \
    293, \
    "AM32_FW_UPDATE_START", \
    2, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_am32_fw_update_start_t, index) }, \
         { "filepath", NULL, MAVLINK_TYPE_UINT8_T, 128, 1, offsetof(mavlink_am32_fw_update_start_t, filepath) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AM32_FW_UPDATE_START { \
    "AM32_FW_UPDATE_START", \
    2, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_am32_fw_update_start_t, index) }, \
         { "filepath", NULL, MAVLINK_TYPE_UINT8_T, 128, 1, offsetof(mavlink_am32_fw_update_start_t, filepath) }, \
         } \
}
#endif

/**
 * @brief Pack a am32_fw_update_start message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  Index of the ESC. Index 0 corresponds to ESC1.
 * @param filepath  Null-terminated file path of firmware binary to upload. Maximum 127 characters plus terminator.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_am32_fw_update_start_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t index, const uint8_t *filepath)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t_array(buf, 1, filepath, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN);
#else
    mavlink_am32_fw_update_start_t packet;
    packet.index = index;
    mav_array_assign_uint8_t(packet.filepath, filepath, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AM32_FW_UPDATE_START;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_CRC);
}

/**
 * @brief Pack a am32_fw_update_start message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  Index of the ESC. Index 0 corresponds to ESC1.
 * @param filepath  Null-terminated file path of firmware binary to upload. Maximum 127 characters plus terminator.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_am32_fw_update_start_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t index, const uint8_t *filepath)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t_array(buf, 1, filepath, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN);
#else
    mavlink_am32_fw_update_start_t packet;
    packet.index = index;
    mav_array_memcpy(packet.filepath, filepath, sizeof(uint8_t)*128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AM32_FW_UPDATE_START;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN);
#endif
}

/**
 * @brief Pack a am32_fw_update_start message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param index  Index of the ESC. Index 0 corresponds to ESC1.
 * @param filepath  Null-terminated file path of firmware binary to upload. Maximum 127 characters plus terminator.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_am32_fw_update_start_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t index,const uint8_t *filepath)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t_array(buf, 1, filepath, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN);
#else
    mavlink_am32_fw_update_start_t packet;
    packet.index = index;
    mav_array_assign_uint8_t(packet.filepath, filepath, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AM32_FW_UPDATE_START;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_CRC);
}

/**
 * @brief Encode a am32_fw_update_start struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param am32_fw_update_start C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_am32_fw_update_start_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_am32_fw_update_start_t* am32_fw_update_start)
{
    return mavlink_msg_am32_fw_update_start_pack(system_id, component_id, msg, am32_fw_update_start->index, am32_fw_update_start->filepath);
}

/**
 * @brief Encode a am32_fw_update_start struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param am32_fw_update_start C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_am32_fw_update_start_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_am32_fw_update_start_t* am32_fw_update_start)
{
    return mavlink_msg_am32_fw_update_start_pack_chan(system_id, component_id, chan, msg, am32_fw_update_start->index, am32_fw_update_start->filepath);
}

/**
 * @brief Encode a am32_fw_update_start struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param am32_fw_update_start C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_am32_fw_update_start_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_am32_fw_update_start_t* am32_fw_update_start)
{
    return mavlink_msg_am32_fw_update_start_pack_status(system_id, component_id, _status, msg,  am32_fw_update_start->index, am32_fw_update_start->filepath);
}

/**
 * @brief Send a am32_fw_update_start message
 * @param chan MAVLink channel to send the message
 *
 * @param index  Index of the ESC. Index 0 corresponds to ESC1.
 * @param filepath  Null-terminated file path of firmware binary to upload. Maximum 127 characters plus terminator.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_am32_fw_update_start_send(mavlink_channel_t chan, uint8_t index, const uint8_t *filepath)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t_array(buf, 1, filepath, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_FW_UPDATE_START, buf, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_CRC);
#else
    mavlink_am32_fw_update_start_t packet;
    packet.index = index;
    mav_array_assign_uint8_t(packet.filepath, filepath, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_FW_UPDATE_START, (const char *)&packet, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_CRC);
#endif
}

/**
 * @brief Send a am32_fw_update_start message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_am32_fw_update_start_send_struct(mavlink_channel_t chan, const mavlink_am32_fw_update_start_t* am32_fw_update_start)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_am32_fw_update_start_send(chan, am32_fw_update_start->index, am32_fw_update_start->filepath);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_FW_UPDATE_START, (const char *)am32_fw_update_start, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_CRC);
#endif
}

#if MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_am32_fw_update_start_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t index, const uint8_t *filepath)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t_array(buf, 1, filepath, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_FW_UPDATE_START, buf, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_CRC);
#else
    mavlink_am32_fw_update_start_t *packet = (mavlink_am32_fw_update_start_t *)msgbuf;
    packet->index = index;
    mav_array_assign_uint8_t(packet->filepath, filepath, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_FW_UPDATE_START, (const char *)packet, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_CRC);
#endif
}
#endif

#endif

// MESSAGE AM32_FW_UPDATE_START UNPACKING


/**
 * @brief Get field index from am32_fw_update_start message
 *
 * @return  Index of the ESC. Index 0 corresponds to ESC1.
 */
static inline uint8_t mavlink_msg_am32_fw_update_start_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field filepath from am32_fw_update_start message
 *
 * @return  Null-terminated file path of firmware binary to upload. Maximum 127 characters plus terminator.
 */
static inline uint16_t mavlink_msg_am32_fw_update_start_get_filepath(const mavlink_message_t* msg, uint8_t *filepath)
{
    return _MAV_RETURN_uint8_t_array(msg, filepath, 128,  1);
}

/**
 * @brief Decode a am32_fw_update_start message into a struct
 *
 * @param msg The message to decode
 * @param am32_fw_update_start C-struct to decode the message contents into
 */
static inline void mavlink_msg_am32_fw_update_start_decode(const mavlink_message_t* msg, mavlink_am32_fw_update_start_t* am32_fw_update_start)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    am32_fw_update_start->index = mavlink_msg_am32_fw_update_start_get_index(msg);
    mavlink_msg_am32_fw_update_start_get_filepath(msg, am32_fw_update_start->filepath);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN? msg->len : MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN;
        memset(am32_fw_update_start, 0, MAVLINK_MSG_ID_AM32_FW_UPDATE_START_LEN);
    memcpy(am32_fw_update_start, _MAV_PAYLOAD(msg), len);
#endif
}
