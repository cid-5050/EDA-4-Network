#include "Network.h"

Network::
Network() {

}

void Network::
nuevoRouter(const std::string & nombre) {
    red.addVertice(nombre, generarIP(), 0);
}

void Network::
conectarRouters(const std::string & nombreA, const std::string & nombreB, int tiempo) {
    red.addArista(nombreA, nombreB, tiempo);
}

void Network::
printNetwork(void) const {
    red.printVertices();
}

std::string Network::
generarIP(void) {
    return ("192.168.0." + std::to_string(red.getVertices().size() + 1));
}

bool Network::
existeRouter(const std::string & nombre) {
    return red.existeVertice(nombre);
}

bool Network::
compartenRed(const std::string & nombreA, const std::string & nombreB) {
    return red.compartenRed(nombreA, nombreB);
}

bool Network::
routerAislado(void) const {
    return red.isolatedVertice();
}

bool Network::
redMalla(void) const {
    return red.mesh();
}
