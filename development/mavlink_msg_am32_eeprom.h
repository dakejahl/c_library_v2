#pragma once
// MESSAGE AM32_EEPROM PACKING

#define MAVLINK_MSG_ID_AM32_EEPROM 292


typedef struct __mavlink_am32_eeprom_t {
 uint32_t write_mask[7]; /*<  Bitmask indicating which bytes in the data array should be written (only used in write mode). Each bit corresponds to a byte index in the data array (bit 0 of write_mask[0] = data[0], bit 31 of write_mask[0] = data[31], bit 0 of write_mask[1] = data[32], etc.). Set bits indicate bytes to write, cleared bits indicate bytes to skip. This allows precise updates of individual parameters without overwriting the entire EEPROM.*/
 uint8_t index; /*<  Index of the ESC (0 = ESC1, 1 = ESC2, etc.).*/
 uint8_t mode; /*<  Operation mode: 0 = readout, 1 = write request.*/
 uint8_t length; /*<  Number of valid bytes in data array.*/
 uint8_t data[224]; /*<  Raw AM32 EEPROM data. Unused bytes should be set to zero. Note: the AM32 EEPROM is currently only 192 bytes long. This array has been sized to use the maximum payload length for a MAVLink message in an attempt to future-proof the message in case AM32 extends the EEPROM data length.*/
} mavlink_am32_eeprom_t;

#define MAVLINK_MSG_ID_AM32_EEPROM_LEN 255
#define MAVLINK_MSG_ID_AM32_EEPROM_MIN_LEN 255
#define MAVLINK_MSG_ID_292_LEN 255
#define MAVLINK_MSG_ID_292_MIN_LEN 255

#define MAVLINK_MSG_ID_AM32_EEPROM_CRC 206
#define MAVLINK_MSG_ID_292_CRC 206

#define MAVLINK_MSG_AM32_EEPROM_FIELD_WRITE_MASK_LEN 7
#define MAVLINK_MSG_AM32_EEPROM_FIELD_DATA_LEN 224

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AM32_EEPROM { \
    292, \
    "AM32_EEPROM", \
    5, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_am32_eeprom_t, index) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_am32_eeprom_t, mode) }, \
         { "write_mask", NULL, MAVLINK_TYPE_UINT32_T, 7, 0, offsetof(mavlink_am32_eeprom_t, write_mask) }, \
         { "length", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_am32_eeprom_t, length) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 224, 31, offsetof(mavlink_am32_eeprom_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AM32_EEPROM { \
    "AM32_EEPROM", \
    5, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_am32_eeprom_t, index) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_am32_eeprom_t, mode) }, \
         { "write_mask", NULL, MAVLINK_TYPE_UINT32_T, 7, 0, offsetof(mavlink_am32_eeprom_t, write_mask) }, \
         { "length", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_am32_eeprom_t, length) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 224, 31, offsetof(mavlink_am32_eeprom_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a am32_eeprom message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  Index of the ESC (0 = ESC1, 1 = ESC2, etc.).
 * @param mode  Operation mode: 0 = readout, 1 = write request.
 * @param write_mask  Bitmask indicating which bytes in the data array should be written (only used in write mode). Each bit corresponds to a byte index in the data array (bit 0 of write_mask[0] = data[0], bit 31 of write_mask[0] = data[31], bit 0 of write_mask[1] = data[32], etc.). Set bits indicate bytes to write, cleared bits indicate bytes to skip. This allows precise updates of individual parameters without overwriting the entire EEPROM.
 * @param length  Number of valid bytes in data array.
 * @param data  Raw AM32 EEPROM data. Unused bytes should be set to zero. Note: the AM32 EEPROM is currently only 192 bytes long. This array has been sized to use the maximum payload length for a MAVLink message in an attempt to future-proof the message in case AM32 extends the EEPROM data length.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_am32_eeprom_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t index, uint8_t mode, const uint32_t *write_mask, uint8_t length, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AM32_EEPROM_LEN];
    _mav_put_uint8_t(buf, 28, index);
    _mav_put_uint8_t(buf, 29, mode);
    _mav_put_uint8_t(buf, 30, length);
    _mav_put_uint32_t_array(buf, 0, write_mask, 7);
    _mav_put_uint8_t_array(buf, 31, data, 224);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AM32_EEPROM_LEN);
#else
    mavlink_am32_eeprom_t packet;
    packet.index = index;
    packet.mode = mode;
    packet.length = length;
    mav_array_assign_uint32_t(packet.write_mask, write_mask, 7);
    mav_array_assign_uint8_t(packet.data, data, 224);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AM32_EEPROM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AM32_EEPROM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AM32_EEPROM_MIN_LEN, MAVLINK_MSG_ID_AM32_EEPROM_LEN, MAVLINK_MSG_ID_AM32_EEPROM_CRC);
}

/**
 * @brief Pack a am32_eeprom message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  Index of the ESC (0 = ESC1, 1 = ESC2, etc.).
 * @param mode  Operation mode: 0 = readout, 1 = write request.
 * @param write_mask  Bitmask indicating which bytes in the data array should be written (only used in write mode). Each bit corresponds to a byte index in the data array (bit 0 of write_mask[0] = data[0], bit 31 of write_mask[0] = data[31], bit 0 of write_mask[1] = data[32], etc.). Set bits indicate bytes to write, cleared bits indicate bytes to skip. This allows precise updates of individual parameters without overwriting the entire EEPROM.
 * @param length  Number of valid bytes in data array.
 * @param data  Raw AM32 EEPROM data. Unused bytes should be set to zero. Note: the AM32 EEPROM is currently only 192 bytes long. This array has been sized to use the maximum payload length for a MAVLink message in an attempt to future-proof the message in case AM32 extends the EEPROM data length.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_am32_eeprom_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t index, uint8_t mode, const uint32_t *write_mask, uint8_t length, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AM32_EEPROM_LEN];
    _mav_put_uint8_t(buf, 28, index);
    _mav_put_uint8_t(buf, 29, mode);
    _mav_put_uint8_t(buf, 30, length);
    _mav_put_uint32_t_array(buf, 0, write_mask, 7);
    _mav_put_uint8_t_array(buf, 31, data, 224);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AM32_EEPROM_LEN);
#else
    mavlink_am32_eeprom_t packet;
    packet.index = index;
    packet.mode = mode;
    packet.length = length;
    mav_array_memcpy(packet.write_mask, write_mask, sizeof(uint32_t)*7);
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*224);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AM32_EEPROM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AM32_EEPROM;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_AM32_EEPROM_MIN_LEN, MAVLINK_MSG_ID_AM32_EEPROM_LEN, MAVLINK_MSG_ID_AM32_EEPROM_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_AM32_EEPROM_MIN_LEN, MAVLINK_MSG_ID_AM32_EEPROM_LEN);
#endif
}

/**
 * @brief Pack a am32_eeprom message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param index  Index of the ESC (0 = ESC1, 1 = ESC2, etc.).
 * @param mode  Operation mode: 0 = readout, 1 = write request.
 * @param write_mask  Bitmask indicating which bytes in the data array should be written (only used in write mode). Each bit corresponds to a byte index in the data array (bit 0 of write_mask[0] = data[0], bit 31 of write_mask[0] = data[31], bit 0 of write_mask[1] = data[32], etc.). Set bits indicate bytes to write, cleared bits indicate bytes to skip. This allows precise updates of individual parameters without overwriting the entire EEPROM.
 * @param length  Number of valid bytes in data array.
 * @param data  Raw AM32 EEPROM data. Unused bytes should be set to zero. Note: the AM32 EEPROM is currently only 192 bytes long. This array has been sized to use the maximum payload length for a MAVLink message in an attempt to future-proof the message in case AM32 extends the EEPROM data length.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_am32_eeprom_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t index,uint8_t mode,const uint32_t *write_mask,uint8_t length,const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AM32_EEPROM_LEN];
    _mav_put_uint8_t(buf, 28, index);
    _mav_put_uint8_t(buf, 29, mode);
    _mav_put_uint8_t(buf, 30, length);
    _mav_put_uint32_t_array(buf, 0, write_mask, 7);
    _mav_put_uint8_t_array(buf, 31, data, 224);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AM32_EEPROM_LEN);
#else
    mavlink_am32_eeprom_t packet;
    packet.index = index;
    packet.mode = mode;
    packet.length = length;
    mav_array_assign_uint32_t(packet.write_mask, write_mask, 7);
    mav_array_assign_uint8_t(packet.data, data, 224);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AM32_EEPROM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AM32_EEPROM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AM32_EEPROM_MIN_LEN, MAVLINK_MSG_ID_AM32_EEPROM_LEN, MAVLINK_MSG_ID_AM32_EEPROM_CRC);
}

/**
 * @brief Encode a am32_eeprom struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param am32_eeprom C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_am32_eeprom_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_am32_eeprom_t* am32_eeprom)
{
    return mavlink_msg_am32_eeprom_pack(system_id, component_id, msg, am32_eeprom->index, am32_eeprom->mode, am32_eeprom->write_mask, am32_eeprom->length, am32_eeprom->data);
}

/**
 * @brief Encode a am32_eeprom struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param am32_eeprom C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_am32_eeprom_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_am32_eeprom_t* am32_eeprom)
{
    return mavlink_msg_am32_eeprom_pack_chan(system_id, component_id, chan, msg, am32_eeprom->index, am32_eeprom->mode, am32_eeprom->write_mask, am32_eeprom->length, am32_eeprom->data);
}

/**
 * @brief Encode a am32_eeprom struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param am32_eeprom C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_am32_eeprom_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_am32_eeprom_t* am32_eeprom)
{
    return mavlink_msg_am32_eeprom_pack_status(system_id, component_id, _status, msg,  am32_eeprom->index, am32_eeprom->mode, am32_eeprom->write_mask, am32_eeprom->length, am32_eeprom->data);
}

/**
 * @brief Send a am32_eeprom message
 * @param chan MAVLink channel to send the message
 *
 * @param index  Index of the ESC (0 = ESC1, 1 = ESC2, etc.).
 * @param mode  Operation mode: 0 = readout, 1 = write request.
 * @param write_mask  Bitmask indicating which bytes in the data array should be written (only used in write mode). Each bit corresponds to a byte index in the data array (bit 0 of write_mask[0] = data[0], bit 31 of write_mask[0] = data[31], bit 0 of write_mask[1] = data[32], etc.). Set bits indicate bytes to write, cleared bits indicate bytes to skip. This allows precise updates of individual parameters without overwriting the entire EEPROM.
 * @param length  Number of valid bytes in data array.
 * @param data  Raw AM32 EEPROM data. Unused bytes should be set to zero. Note: the AM32 EEPROM is currently only 192 bytes long. This array has been sized to use the maximum payload length for a MAVLink message in an attempt to future-proof the message in case AM32 extends the EEPROM data length.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_am32_eeprom_send(mavlink_channel_t chan, uint8_t index, uint8_t mode, const uint32_t *write_mask, uint8_t length, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AM32_EEPROM_LEN];
    _mav_put_uint8_t(buf, 28, index);
    _mav_put_uint8_t(buf, 29, mode);
    _mav_put_uint8_t(buf, 30, length);
    _mav_put_uint32_t_array(buf, 0, write_mask, 7);
    _mav_put_uint8_t_array(buf, 31, data, 224);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_EEPROM, buf, MAVLINK_MSG_ID_AM32_EEPROM_MIN_LEN, MAVLINK_MSG_ID_AM32_EEPROM_LEN, MAVLINK_MSG_ID_AM32_EEPROM_CRC);
#else
    mavlink_am32_eeprom_t packet;
    packet.index = index;
    packet.mode = mode;
    packet.length = length;
    mav_array_assign_uint32_t(packet.write_mask, write_mask, 7);
    mav_array_assign_uint8_t(packet.data, data, 224);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_EEPROM, (const char *)&packet, MAVLINK_MSG_ID_AM32_EEPROM_MIN_LEN, MAVLINK_MSG_ID_AM32_EEPROM_LEN, MAVLINK_MSG_ID_AM32_EEPROM_CRC);
#endif
}

/**
 * @brief Send a am32_eeprom message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_am32_eeprom_send_struct(mavlink_channel_t chan, const mavlink_am32_eeprom_t* am32_eeprom)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_am32_eeprom_send(chan, am32_eeprom->index, am32_eeprom->mode, am32_eeprom->write_mask, am32_eeprom->length, am32_eeprom->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_EEPROM, (const char *)am32_eeprom, MAVLINK_MSG_ID_AM32_EEPROM_MIN_LEN, MAVLINK_MSG_ID_AM32_EEPROM_LEN, MAVLINK_MSG_ID_AM32_EEPROM_CRC);
#endif
}

#if MAVLINK_MSG_ID_AM32_EEPROM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_am32_eeprom_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t index, uint8_t mode, const uint32_t *write_mask, uint8_t length, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 28, index);
    _mav_put_uint8_t(buf, 29, mode);
    _mav_put_uint8_t(buf, 30, length);
    _mav_put_uint32_t_array(buf, 0, write_mask, 7);
    _mav_put_uint8_t_array(buf, 31, data, 224);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_EEPROM, buf, MAVLINK_MSG_ID_AM32_EEPROM_MIN_LEN, MAVLINK_MSG_ID_AM32_EEPROM_LEN, MAVLINK_MSG_ID_AM32_EEPROM_CRC);
#else
    mavlink_am32_eeprom_t *packet = (mavlink_am32_eeprom_t *)msgbuf;
    packet->index = index;
    packet->mode = mode;
    packet->length = length;
    mav_array_assign_uint32_t(packet->write_mask, write_mask, 7);
    mav_array_assign_uint8_t(packet->data, data, 224);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AM32_EEPROM, (const char *)packet, MAVLINK_MSG_ID_AM32_EEPROM_MIN_LEN, MAVLINK_MSG_ID_AM32_EEPROM_LEN, MAVLINK_MSG_ID_AM32_EEPROM_CRC);
#endif
}
#endif

#endif

// MESSAGE AM32_EEPROM UNPACKING


/**
 * @brief Get field index from am32_eeprom message
 *
 * @return  Index of the ESC (0 = ESC1, 1 = ESC2, etc.).
 */
static inline uint8_t mavlink_msg_am32_eeprom_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field mode from am32_eeprom message
 *
 * @return  Operation mode: 0 = readout, 1 = write request.
 */
static inline uint8_t mavlink_msg_am32_eeprom_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  29);
}

/**
 * @brief Get field write_mask from am32_eeprom message
 *
 * @return  Bitmask indicating which bytes in the data array should be written (only used in write mode). Each bit corresponds to a byte index in the data array (bit 0 of write_mask[0] = data[0], bit 31 of write_mask[0] = data[31], bit 0 of write_mask[1] = data[32], etc.). Set bits indicate bytes to write, cleared bits indicate bytes to skip. This allows precise updates of individual parameters without overwriting the entire EEPROM.
 */
static inline uint16_t mavlink_msg_am32_eeprom_get_write_mask(const mavlink_message_t* msg, uint32_t *write_mask)
{
    return _MAV_RETURN_uint32_t_array(msg, write_mask, 7,  0);
}

/**
 * @brief Get field length from am32_eeprom message
 *
 * @return  Number of valid bytes in data array.
 */
static inline uint8_t mavlink_msg_am32_eeprom_get_length(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Get field data from am32_eeprom message
 *
 * @return  Raw AM32 EEPROM data. Unused bytes should be set to zero. Note: the AM32 EEPROM is currently only 192 bytes long. This array has been sized to use the maximum payload length for a MAVLink message in an attempt to future-proof the message in case AM32 extends the EEPROM data length.
 */
static inline uint16_t mavlink_msg_am32_eeprom_get_data(const mavlink_message_t* msg, uint8_t *data)
{
    return _MAV_RETURN_uint8_t_array(msg, data, 224,  31);
}

/**
 * @brief Decode a am32_eeprom message into a struct
 *
 * @param msg The message to decode
 * @param am32_eeprom C-struct to decode the message contents into
 */
static inline void mavlink_msg_am32_eeprom_decode(const mavlink_message_t* msg, mavlink_am32_eeprom_t* am32_eeprom)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_am32_eeprom_get_write_mask(msg, am32_eeprom->write_mask);
    am32_eeprom->index = mavlink_msg_am32_eeprom_get_index(msg);
    am32_eeprom->mode = mavlink_msg_am32_eeprom_get_mode(msg);
    am32_eeprom->length = mavlink_msg_am32_eeprom_get_length(msg);
    mavlink_msg_am32_eeprom_get_data(msg, am32_eeprom->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AM32_EEPROM_LEN? msg->len : MAVLINK_MSG_ID_AM32_EEPROM_LEN;
        memset(am32_eeprom, 0, MAVLINK_MSG_ID_AM32_EEPROM_LEN);
    memcpy(am32_eeprom, _MAV_PAYLOAD(msg), len);
#endif
}
