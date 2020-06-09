#include <vector>
#include <memory>
#include <stdexcept>

#include "Router.h"
#include "Event.h"
#include "Interface.h"

#ifndef __network_h
#define __network_h

class EventsEmptyException : std::exception {

};

/**
 * Class that allows the user-defined router to interact with the network.
 * The TestScenario defined by the user will populate this class with the packet input
 * events and interfaces, then this object will be passed to the main function of the router
 */
class Network {
    public:
        /**
         * Construct a new network object
         *
         * @param events pointer to a vector of packet input events
         * @param interfaces pointer to a vector containing the interfaces for the router
         */
        Network(std::vector<Event>* events, std::vector<Interface>* interfaces) :
            events(events), interfaces(interfaces) {  }

        /**
         * Send a packet out to the network on an interface
         *
         * @param intf interface name to send the packet out of
         * @param pkt the packet to send
         */
        void sendPacket(std::string intf, Packet pkt) const;

        /**
         * Router calls this function when it is ready to receive another packet
         *
         * @return the next Event in the queue
         */
        Event recvPacket();
        /**
         * Return a deep copy of the interfaces vector
         *
         * @return a deep copy of events
         */
        std::vector<Interface> ports() const;

    private:
        const std::vector<Event>* events{};
        const std::vector<Interface>* interfaces{};
        unsigned int event_idx{0};
};

#endif
