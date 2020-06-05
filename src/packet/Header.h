#include <string>
#include <memory>
#include <iostream>

#ifndef HEADER_H
#define HEADER_H

/**
 * Possible header types
 */
enum class HeaderType { 
    Header,
    IPv4,
    Eth,
    Payload
};

/**
 * Base header class
 */
struct Header {
    /**
     * Initialize the header with a given type
     *
     * @param type type of header defined by the HeaderType enum
     */
    Header(HeaderType type) : type(type) {  }

    // Make each class define a destructor
    virtual ~Header() = 0;

    /**
     * Allow user to output the header with the << operator
     */
    friend std::ostream& operator<<(std::ostream& os, const Header& add);

    friend class Packet;

    /**
     * Get the name of the header
     *
     * @return name of the header
     */
    virtual std::string getName() = 0;

    /**
     * Print function for each header to override
     * Needed to print off the packet for debugging purposes
     * Called with the << operator function
     *
     * @param out ostream
     */
    virtual void print(std::ostream& out) const = 0;

    private:
        HeaderType type{HeaderType::Header};
};

struct EthHeader : public Header {
    /**
     * Create a new Ethernet header. Contains the SRC and DST MAC addresses
     * If the default constructor is called, will set the MAC addresses to be
     * the default 00 address
     *
     * @param src source MAC address
     * @param dst destination MAC address
     */
    EthHeader(std::string src, std::string dst) 
        : Header(HeaderType::Eth), src(src), dst(dst) {  }
    EthHeader() : EthHeader("00:00:00:00:00:00", "00:00:00:00:00:00") {  }
    ~EthHeader() override;

    friend class Packet;

    /**
     * Move operator. Copy over the string values
     *
     * @param rhs EthHeader to move
     * @return this
     */
    EthHeader& operator=(EthHeader&& rhs);

    std::string getName() override;
    void print(std::ostream& out) const override;

    // Keep src/dst public for easy get/set for client
    std::string src; 
    std::string dst;
};

/**
 * Simple IPv4 Header, only contains src/dst ip addresses and ttl
 */
struct IPv4Header : public Header {
    /**
     * Create a new IPv4 Header
     *
     * @param src source IP address
     * @param dst destination IP address
     * @param ttl Time To Live of packet
     */
    IPv4Header(std::string src, std::string dst, unsigned int ttl) : 
        Header(HeaderType::IPv4), src(src), dst(dst), ttl(ttl) {  }

    IPv4Header(std::string src, std::string dst) : IPv4Header(src, dst, 0) {  }
    IPv4Header() : IPv4Header("0.0.0.0", "0.0.0.0", 0) {  }
    ~IPv4Header() override;

    friend class Packet;

    IPv4Header& operator=(IPv4Header&& rhs);

    std::string getName() override;
    void print(std::ostream& out) const override;

    std::string src;
    std::string dst;
    unsigned int ttl;
};

template <typename T>
struct Payload : public Header { 
    Payload(std::shared_ptr<T> payload) 
        : Header(HeaderType::Payload), payload(payload), length(sizeof(T)){  }

    ~Payload() override;

    Payload<T>& operator=(Payload<T>&& rhs);

    std::string getName() override;
    void print(std::ostream& out) const override;

    friend class Packet;

    std::shared_ptr<T> payload;
    size_t length;
};


template<typename T>
Payload<T>::~Payload() {  }

template<typename T>
Payload<T>& Payload<T>::operator=(Payload<T>&& rhs) {
    payload = std::move(rhs.payload);
    return *this;
}

template<typename T>
std::string Payload<T>::getName() {
    return "Payload";
}
template<typename T>
void Payload<T>::print(std::ostream& out) const {
    out << "---------- Payload ----------" << std::endl;
    out << "ADDR: " << payload << std::endl;
}

#endif
