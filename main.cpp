#include <iostream>
#include <Network.h>


int main() {

    Network network;

    try {
        network.nuevoRouter("TV");
        network.nuevoRouter("Nevera");
        network.nuevoRouter("Altavoces");
        network.nuevoRouter("Tostadora");
        network.nuevoRouter("Plancha");

        network.conectarRouters("TV", "Nevera");
        network.conectarRouters("TV", "Altavoces");
        network.conectarRouters("Nevera", "Altavoces");
        network.conectarRouters("Nevera", "TV");
        network.conectarRouters("Altavoces", "Tostadora");
        network.conectarRouters("Plancha", "TV");

    } catch (std::string e) {
        std::cout << e << std::endl;
    }

    network.printNetwork();

    std::cout << std::endl;
    return 0;
}
