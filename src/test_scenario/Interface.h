#include <string>

#ifndef __interface_h
#define __interface_h

struct Interface {
    Interface (
        std::string name,
        std::string hwaddr,
        std::string ipaddr
        ) : name(name), hwaddr(hwaddr), ipaddr(ipaddr) {  }

    std::string name;
    std::string hwaddr;
    std::string ipaddr;
};

#endif
