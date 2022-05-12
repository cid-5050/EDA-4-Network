#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <Grafo.h>


class Network {
 public:
    Network();

    void nuevoRouter(const std::string & IP);
    void conectarRouters(const std::string & IP1, const std::string & IP2);
    void printNetwork(void) const;

 private:
    Grafo red;
};

#endif // NETWORK_H
