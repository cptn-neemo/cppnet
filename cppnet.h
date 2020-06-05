#include "Packet.h"
#include "Header.h"

/**
 * Factory function to create a shared pointer to a new Ethheader
 *
 * @param src source MAC address of the header
 * @param dst destination MAC address of the header
 * @return std::shared_ptr<EthHeader>
 */
auto createEthHeader(
        std::string src = "FF:FF:FF:FF:FF:FF",
        std::string dst = "FF:FF:FF:FF:FF:FF"
    ) {
    return std::make_shared<EthHeader>(src, dst);
}

/**
 * Factory function to create a shared pointer to a new IPv4Header 
 *
 * @param src source IPv4 address of the header
 * @param dst destination IPv4 address of the header
 * @param ttl time to live of the packet
 * @return std::shared_ptr<IPv4Header>
 */
auto createIPv4Header(
    std::string src = "0.0.0.0",
    std::string dst = "0.0.0.0", 
    unsigned int ttl = 0
    ) {
    return std::make_shared<IPv4Header>(src, dst, ttl);
}

template<typename T>
auto createPayload(std::shared_ptr<T>& payload) {
    return std::make_shared<Payload<T>>(payload);
}

template<typename HT, typename... Ts>
auto createHeader(Ts&&... params) {
    return std::make_shared<HT>(std::forward<Ts>(params)...);
}
