#include "Packet.h"
#include "Header.h"

#ifndef __FAC_H
#define __FAC_H

/**
 * Factory function to create a shared pointer to a new Ethheader
 *
 * @param src source MAC address of the header
 * @param dst destination MAC address of the header
 * @return std::shared_ptr<EthHeader>
 */
std::shared_ptr<EthHeader> createEthHeader(
        std::string src = "FF:FF:FF:FF:FF:FF",
        std::string dst = "FF:FF:FF:FF:FF:FF"
);

/**
 * Factory function to create a shared pointer to a new IPv4Header 
 *
 * @param src source IPv4 address of the header
 * @param dst destination IPv4 address of the header
 * @param ttl time to live of the packet
 * @return std::shared_ptr<IPv4Header>
 */
std::shared_ptr<IPv4Header> createIPv4Header(
    std::string src = "0.0.0.0",
    std::string dst = "0.0.0.0",
    unsigned int ttl = 0
);

/**
 * Create a payload header containing information regarding the class T
 * 
 * @param payload shared ptr to the class of type T
 * @return a shared ptr to a Payload header
 */
template<typename T>
auto createPayload(std::shared_ptr<T>& payload) {
    return std::make_shared<Payload<T>>(payload);
}

template<typename HT, typename... Ts>
auto createHeader(Ts&&... params) {
    return std::make_shared<HT>(std::forward<Ts>(params)...);
}

#endif