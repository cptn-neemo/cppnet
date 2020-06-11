#include <iostream>
#include <vector>
#include <memory>

#include "Header.h"

#ifndef PACKET_H
#define PACKET_H


/**
 * Packet class. Contains an array of shared ptrs to headers
 */
class Packet {
    public:
        Packet() { }

        friend std::ostream& operator<<(std::ostream& os, const Packet& p);

        /**
         * Add a header to the packet. Pushes the header to the back
         * of the header array. 
         *
         * @throws invalid argument exception if the header type already exists in the packet
         *
         * @param h shared ptr to a header class. Can use the factory functions
         * to easily create the shared ptr
         */
        void add_header(std::shared_ptr<Header> h);

        /**
         * Get the header of type ht
         *
         * @param ht type of header to get
         * @return a pointer to the header of type ht
         */
        std::shared_ptr<Header> get_header(HeaderType ht);

    private:
        std::vector<std::shared_ptr<Header>> headers{};
};

#endif
