#include "Network.h"

Network::
Network() {

}

void Network::
nuevoRouter(const std::string & nombre) {
    red.addVertice(nombre, generarIP(), 0);
}

void Network::
conectarRouters(const std::string & nombreA, const std::string & nombreB) {
    red.addArista(nombreA, nombreB, 0);
}

void Network::
printNetwork(void) const {
    red.printVertices();
}

std::string Network::
generarIP(void) {
    return ("192.168.0." + std::to_string(red.getVertices().size() + 1));
}
