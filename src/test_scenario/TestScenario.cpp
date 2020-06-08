#include "TestScenario.h"

void TestScenario::addEvent(Event event) {
    events.push_back(event);
}


void TestScenario::addInterface(
    std::string name,
    std::string hwaddr,
    std::string ipaddr
    ) {
    Interface intf{name, hwaddr, ipaddr};

    // Check to make sure the interface name does not already exist on the
    // router
    for (auto i = interfaces.cbegin(); i != interfaces.cend(); ++i) {
        if (name == i->name) {
            throw std::invalid_argument("Interface already exists.");
        }
    }

    interfaces.push_back(std::move(intf));
}
