#include "../packet/Packet.h"
#include "Interface.h"

#ifndef __event_h
#define __event_h

struct Event {
    Event(Packet pkt, Interface intf) : pkt(pkt), intf(intf) {  }
    Packet pkt; 
    Interface intf;
};

#endif
