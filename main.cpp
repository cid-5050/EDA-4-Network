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
        network.nuevoRouter("IPad");

        network.conectarRouters("TV", "Nevera", 3);
        network.conectarRouters("TV", "Altavoces", 5);
        network.conectarRouters("Nevera", "Altavoces", 7);
        network.conectarRouters("Nevera", "TV", 2);
        network.conectarRouters("Altavoces", "Tostadora", 4);
        network.conectarRouters("Plancha", "TV", 6);

    } catch (std::string e) {
        std::cout << e << std::endl;
    }

    network.printNetwork();

    std::cout << network.compartenRed("TV", "Altavoces") << std::endl;

    std::cout << std::endl;
    return 0;
}
