#include "Factory.h"

std::shared_ptr<EthHeader> createEthHeader(
        std::string src,
        std::string dst
    ) {
    return std::make_shared<EthHeader>(src, dst);
}

std::shared_ptr<IPv4Header> createIPv4Header(
    std::string src,
    std::string dst, 
    unsigned int ttl
    ) {
    return std::make_shared<IPv4Header>(src, dst, ttl);
}