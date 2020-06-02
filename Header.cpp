/**
 * Max Huddleston
 *
 * Header code implementations
 */

#include <iostream>
#include "Header.h"

// ---------------- Header Implementations ---------------

Header::~Header() {  }

std::ostream& operator<<(std::ostream& os, const Header& add) {
    add.print(os);
    return os;
}


// ---------------- EthHeader Implementations ---------------

EthHeader::~EthHeader() {

}

EthHeader& EthHeader::operator=(EthHeader&& rhs) {
    src = rhs.src;
    dst = rhs.dst;

    rhs.src = "";
    rhs.dst = "";
}

std::string EthHeader::getName() {
    return "EthHeader";
}

void EthHeader::print(std::ostream& out) const {
    out << "----------EthHeader----------" << std::endl;
    out << "SRC: " << src << std::endl;
    out << "DST: " << dst << std::endl;
}

 
// ---------------- IPv4Header Implementations ---------------

IPv4Header& IPv4Header::operator=(IPv4Header&& rhs) {
    src = rhs.src;
    dst = rhs.dst;
    ttl = rhs.ttl;

    rhs.src = "";
    rhs.dst = "";
    rhs.ttl = 0;

    return *this;
}

IPv4Header::~IPv4Header() {

}

std::string IPv4Header::getName() { 
    return "IPv4Header";
}

void IPv4Header::print(std::ostream& out) const {
    out << "----------IPv4 Header----------" << std::endl;
    out << "SRC: " << src << std::endl;
    out << "DST: " << dst << std::endl;
    out << "TTL: " << ttl << std::endl;
}
