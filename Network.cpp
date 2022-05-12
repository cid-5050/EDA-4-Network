#include "Network.h"

Network::
Network() {

}

void Network::
nuevoRouter(const std::string & IP) {
    red.addVertice(IP);
}

void Network::
conectarRouters(const std::string & IP1, const std::string & IP2) {
    red.addArista(IP1, IP2, 0);
}

void Network::
printNetwork(void) const {
    red.printVertices();
}
