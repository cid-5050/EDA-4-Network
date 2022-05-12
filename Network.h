#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <Grafo.h>


class Network {
 public:
    Network();

    void nuevoRouter(const std::string & nombre);
    void conectarRouters(const std::string & nombreA, const std::string & nombreB);
    void printNetwork(void) const;

    std::string generarIP(void);

 private:
    Grafo red;
};

#endif // NETWORK_H
