#include <string>

#ifndef __interface_h
#define __interface_h

/**
 * Interface on the physical router. Contains a name, hw addr, and ip addr
 */
struct Interface {
    Interface (
        std::string name,
        std::string hwaddr,
        std::string ipaddr
        ) : name(name), hwaddr(hwaddr), ipaddr(ipaddr) {  }

    friend bool operator==(const Interface& lhs, const Interface& rhs) {
        return lhs.name == rhs.name;
    }

    friend bool operator!=(const Interface& lhs, const Interface& rhs) {
        return lhs.name != rhs.name;
    }

    std::string name;
    std::string hwaddr;
    std::string ipaddr;
};

#endif
