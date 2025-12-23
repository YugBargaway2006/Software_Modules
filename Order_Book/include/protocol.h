#pragma once

#include <cstdint>

#pragma pack(push, 1)


class MessageHeader {
public:
    uint16_t msgLength;
    uint8_t msgType;     // 1 for Add order to book, 2 for Trade
};


class OrderMessage {
public:
    MessageHeader header;
    uint32_t orderID;
    uint32_t price;    // (Ticks = price * 100)
    uint32_t quantity;
    char side;    // B / S
};


#pragma pack(pop)