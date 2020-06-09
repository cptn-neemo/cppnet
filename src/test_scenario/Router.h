#ifndef __router_h
#define __router_h

#include "Event.h"
#include "Network.h"

class Router {
    public:
        virtual void main(Network &net) = 0;
};

#endif
