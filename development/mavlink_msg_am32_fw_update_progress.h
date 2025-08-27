#pragma once
// MESSAGE AM32_FW_UPDATE_PROGRESS PACKING

#define MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS 293


typedef struct __mavlink_am32_fw_update_progress_t {
 uint8_t index; /*<  Index of the ESC. Index 0 corresponds to ESC1.*/
 uint8_t progress; /*<  Update progress as percentage (0-100). 255 indicates update failure.*/
} mavlink_am32_fw_update_progress_t;

#define MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN 2
#define MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_MIN_LEN 2
#define MAVLINK_MSG_ID_293_LEN 2
#define MAVLINK_MSG_ID_293_MIN_LEN 2

#define MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_CRC 5
#define MAVLINK_MSG_ID_293_CRC 5



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AM32_FW_UPDATE_PROGRESS { \
    293, \
    "AM32_FW_UPDATE_PROGRESS", \
    2, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_am32_fw_update_progress_t, index) }, \
         { "progress", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_am32_fw_update_progress_t, progress) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AM32_FW_UPDATE_PROGRESS { \
    "AM32_FW_UPDATE_PROGRESS", \
    2, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_am32_fw_update_progress_t, index) }, \
         { "progress", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_am32_fw_update_progress_t, progress) }, \
         } \
}
#endif

/**
 * @brief Pack a am32_fw_update_progress message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  Index of the ESC. Index 0 corresponds to ESC1.
 * @param progress  Update progress as percentage (0-100). 255 indicates update failure.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_am32_fw_update_progress_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t index, uint8_t progress)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t(buf, 1, progress);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN);
#else
    mavlink_am32_fw_update_progress_t packet;
    packet.index = index;
    packet.progress = progress;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_CRC);
}

/**
 * @brief Pack a am32_fw_update_progress message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  Index of the ESC. Index 0 corresponds to ESC1.
 * @param progress  Update progress as percentage (0-100). 255 indicates update failure.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_am32_fw_update_progress_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t index, uint8_t progress)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t(buf, 1, progress);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN);
#else
    mavlink_am32_fw_update_progress_t packet;
    packet.index = index;
    packet.progress = progress;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN);
#endif
}

/**
 * @brief Pack a am32_fw_update_progress message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param index  Index of the ESC. Index 0 corresponds to ESC1.
 * @param progress  Update progress as percentage (0-100). 255 indicates update failure.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_am32_fw_update_progress_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t index,uint8_t progress)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t(buf, 1, progress);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN);
#else
    mavlink_am32_fw_update_progress_t packet;
    packet.index = index;
    packet.progress = progress;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_CRC);
}

/**
 * @brief Encode a am32_fw_update_progress struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param am32_fw_update_progress C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_am32_fw_update_progress_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_am32_fw_update_progress_t* am32_fw_update_progress)
{
    return mavlink_msg_am32_fw_update_progress_pack(system_id, component_id, msg, am32_fw_update_progress->index, am32_fw_update_progress->progress);
}

/**
 * @brief Encode a am32_fw_update_progress struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param am32_fw_update_progress C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_am32_fw_update_progress_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_am32_fw_update_progress_t* am32_fw_update_progress)
{
    return mavlink_msg_am32_fw_update_progress_pack_chan(system_id, component_id, chan, msg, am32_fw_update_progress->index, am32_fw_update_progress->progress);
}

/**
 * @brief Encode a am32_fw_update_progress struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param am32_fw_update_progress C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_am32_fw_update_progress_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_am32_fw_update_progress_t* am32_fw_update_progress)
{
    return mavlink_msg_am32_fw_update_progress_pack_status(system_id, component_id, _status, msg,  am32_fw_update_progress->index, am32_fw_update_progress->progress);
}

/**
 * @brief Send a am32_fw_update_progress message
 * @param chan MAVLink channel to send the message
 *
 * @param index  Index of the ESC. Index 0 corresponds to ESC1.
 * @param progress  Update progress as percentage (0-100). 255 indicates update failure.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_am32_fw_update_progress_send(mavlink_channel_t chan, uint8_t index, uint8_t progress)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t(buf, 1, progress);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS, buf, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_CRC);
#else
    mavlink_am32_fw_update_progress_t packet;
    packet.index = index;
    packet.progress = progress;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS, (const char *)&packet, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_CRC);
#endif
}

/**
 * @brief Send a am32_fw_update_progress message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_am32_fw_update_progress_send_struct(mavlink_channel_t chan, const mavlink_am32_fw_update_progress_t* am32_fw_update_progress)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_am32_fw_update_progress_send(chan, am32_fw_update_progress->index, am32_fw_update_progress->progress);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS, (const char *)am32_fw_update_progress, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_CRC);
#endif
}

#if MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_am32_fw_update_progress_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t index, uint8_t progress)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t(buf, 1, progress);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS, buf, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_CRC);
#else
    mavlink_am32_fw_update_progress_t *packet = (mavlink_am32_fw_update_progress_t *)msgbuf;
    packet->index = index;
    packet->progress = progress;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS, (const char *)packet, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_MIN_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_CRC);
#endif
}
#endif

#endif

// MESSAGE AM32_FW_UPDATE_PROGRESS UNPACKING


/**
 * @brief Get field index from am32_fw_update_progress message
 *
 * @return  Index of the ESC. Index 0 corresponds to ESC1.
 */
static inline uint8_t mavlink_msg_am32_fw_update_progress_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field progress from am32_fw_update_progress message
 *
 * @return  Update progress as percentage (0-100). 255 indicates update failure.
 */
static inline uint8_t mavlink_msg_am32_fw_update_progress_get_progress(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a am32_fw_update_progress message into a struct
 *
 * @param msg The message to decode
 * @param am32_fw_update_progress C-struct to decode the message contents into
 */
static inline void mavlink_msg_am32_fw_update_progress_decode(const mavlink_message_t* msg, mavlink_am32_fw_update_progress_t* am32_fw_update_progress)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    am32_fw_update_progress->index = mavlink_msg_am32_fw_update_progress_get_index(msg);
    am32_fw_update_progress->progress = mavlink_msg_am32_fw_update_progress_get_progress(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN? msg->len : MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN;
        memset(am32_fw_update_progress, 0, MAVLINK_MSG_ID_AM32_FW_UPDATE_PROGRESS_LEN);
    memcpy(am32_fw_update_progress, _MAV_PAYLOAD(msg), len);
#endif
}
