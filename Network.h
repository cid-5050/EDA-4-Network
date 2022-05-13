#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <set>
#include <Grafo.h>
#include <funciones.h>


class Network {
 public:
    Network();

    void nuevoRouter(const std::string & nombre);
    void conectarRouters(const std::string & nombreA, const std::string & nombreB, int tiempo);
    void printNetwork(void) const;

    std::string generarIP(void);

    bool existeRouter(const std::string & nombre);
    bool compartenRed(const std::string & nombreA, const std::string & nombreB);

 private:
    Grafo red;
};

#endif // NETWORK_H
