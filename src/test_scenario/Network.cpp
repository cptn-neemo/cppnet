#include "Network.h"

void Network::sendPacket(std::string intf, Packet pkt) const { 
    std::cout << "Sent packet on interface: " << intf << std::endl;
}

Event Network::recvPacket() {
    if (event_idx == events->size()) {
        throw EventsEmptyException();
    }

    return (*events)[event_idx++];
}

std::vector<Interface> Network::ports() const {
    return std::vector<Interface>(*interfaces);
}
