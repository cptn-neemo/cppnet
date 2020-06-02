#include <iostream>
#include "cppnet.h"

struct Data {
    int dog{12};
    int cat{15};
};

int main() {
    auto iphdr = std::make_shared<IPv4Header>("192.168.1.1", "255.255.255.255", 64);
    auto ethhdr = std::make_shared<EthHeader>();

    auto data = std::make_shared<Data>();
    auto payload = CreatePayload<Data>(data);

    Packet p{  };
    p.add_header(iphdr);
    p.add_header(ethhdr);
    p.add_header(payload);
    std::cout << p; 

    std::shared_ptr<Header> data_h = p.get_header(HeaderType::Payload);
    //dynamic_cast<std::shared_ptr<Payload<Data>>>(data_h);
    //reinterpret_cast<std::shared_ptr<Payload<Data>>>(data_h);

    auto data_header = std::dynamic_pointer_cast<Payload<Data>>(data_h);

    std::cout << data_header->payload->dog << std::endl;
    //auto data_g = dynamic_cast<Payload<Data>>(*p.get_header(HeaderType::Payload));


}
