#include <iostream>
#include "./src/cppnet.h"

struct Data {
    int dog{12};
    int cat{15};
};

int main() {
    // Use of the template factory function
    auto iphdr = createHeader<IPv4Header, std::string, std::string, unsigned int>(
        "192.168.1.1",
        "255.255.255.255",
        64
    );

    // Use of the specific eth function
    auto ethhdr = createEthHeader("AB:CD:EF:00:11:22");

    auto data = std::make_shared<Data>();
    auto payload = createPayload<Data>(data);

    Packet p{  };
    p.add_header(iphdr);
    p.add_header(ethhdr);
    p.add_header(payload);
    std::cout << p; 

    std::shared_ptr<Header> data_h = p.get_header(HeaderType::Payload);

    auto data_header = std::dynamic_pointer_cast<Payload<Data>>(data_h);

    std::cout << data_header->payload->dog << std::endl;
}