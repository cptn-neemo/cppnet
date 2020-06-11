#include "./src/cppnet.h"

Packet createPacket(
    std::string ipsrc,
    std::string ipdst,
    unsigned int ttl,
    std::string hwsrc,
    std::string hwdst
    ) {
    
    Packet pkt;
    auto iphdr = createIPv4Header(ipsrc, ipdst, ttl);
    auto hwhdr = createEthHeader(hwsrc, hwdst);
    pkt.add_header(hwhdr);
    pkt.add_header(iphdr);

    return pkt;
}

class BroadcastSwitch : public Router {
    public:
        void main(Network& net) override {
            std::cout << "Main called" << std::endl;
            Event event = net.recvPacket();

            std::cout << event.pkt << std::endl;

            // Broadcast the packet out of every port except the incoming port
            for (const Interface& intf : net.ports()) {
                if (intf != event.intf) {
                    net.sendPacket(intf.name, event.pkt);
                }
            }
        }
};

int main() { 
    TestScenario ts;

    Interface eth0("eth0", "00:00:00:00:00:00", "127.0.0.0");
    Interface eth1("eth1", "00:00:00:00:00:10", "127.0.0.1");
    Interface eth2("eth2", "00:00:00:00:00:20", "127.0.0.2");

    Packet pkt = createPacket(
        "192.1.1.1",
        "192.1.2.3",
        64,
        "00:00:00:00:00:01",
        "00:00:00:00:00:02"
    );

    ts.addInterface(eth0);
    ts.addInterface(eth1);
    ts.addInterface(eth2);

    ts.addEvent(Event(pkt, eth0));

    BroadcastSwitch r{};

    ts.run(r);

    return 0;
}
