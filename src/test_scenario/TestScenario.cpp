#include "TestScenario.h"

void TestScenario::addEvent(Event event) {
    events.push_back(event);
}

bool intfRegistered(std::vector<Interface>& interfaces, std::string& name) {
    for (auto i = interfaces.cbegin(); i != interfaces.cend(); ++i) {
        if (name == i->name) {
            return true;
            throw std::invalid_argument("Interface already exists.");
        }
    }

    return false;
}

void TestScenario::addInterface(
    std::string name,
    std::string hwaddr,
    std::string ipaddr
    ) {
    addInterface(Interface(name, hwaddr, ipaddr));
}

void TestScenario::addInterface(Interface intf) {
    if (intfRegistered(interfaces, intf.name)) {
        throw std::invalid_argument("Interface already exists.");
    }

    interfaces.push_back(std::move(intf));
}

void TestScenario::run(Router& r) {
    std::cout << "Running test scenario..." << std::endl;

    r.main(net);
}
