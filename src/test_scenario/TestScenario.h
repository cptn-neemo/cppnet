#include <vector>
#include <memory>
#include <stdexcept>

#include "Router.h"
#include "Event.h"
#include "Interface.h"

#ifndef __test_scenario_h
#define __test_scenario_h

class TestScenario {
    public:
        /**
         * Create a new test scenario given a router/switch
         *
         * @param router router class to run events on
         */
        void addEvent(Event event);

        /**
         * Add an interface to this test scenario
         *
         * @throws invalid_argument if the name already exists
         * @param name the name of this interface, ex "eth0"
         * @param hwaddr the MAC address of this interface
         * @param ipaddr the IPv4 address of this interface
         */
        void addInterface(
            std::string name,
            std::string hwaddr,
            std::string ipaddr
        );

    private:
         std::vector<Event> events;
         std::vector<Interface> interfaces;
};

#endif
