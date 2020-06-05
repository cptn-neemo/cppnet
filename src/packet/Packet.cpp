#include "Packet.h"

std::ostream& operator<<(std::ostream& os, const Packet& p) {
    for (auto &hdr : p.headers) {
        os << *hdr;
    }

    return os;
}


void Packet::add_header(std::shared_ptr<Header> h) { 
    headers.push_back(h);
}

std::shared_ptr<Header> Packet::get_header(HeaderType h) {
    for (auto i = headers.begin(); i != headers.end(); ++i) {
        if ((*i)->type == h)
            return *i;
    }

    return nullptr; 
}

