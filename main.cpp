#include <iostream>
#include <Network.h>


int main() {

    Network network, lan;

    std::cout << "Network" << std::endl << std::endl;
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
    std::cout << std::endl;

    std::cout << "LAN" << std::endl << std::endl;
    try {
        lan.nuevoRouter("Router");
        lan.nuevoRouter("Ordenador");
        lan.nuevoRouter("Impresora");

        lan.conectarRouters("Router", "Ordenador", 3);
        lan.conectarRouters("Ordenador", "Impresora", 5);
        lan.conectarRouters("Impresora", "Router", 7);

    } catch (std::string e) {
        std::cout << e << std::endl;
    }

    lan.printNetwork();
    std::cout << std::endl;

    std::cout << "Los dispositivos TV y Altavoces estan en la misma red: " << network.compartenRed("TV", "Altavoces") << std::endl;

    std::cout << "Existe algun dispositivo no conectado a la Network: " << network.routerAislado() << std::endl;

    std::cout << "Existe algun dispositivo no conectado a la red LAN: " << lan.routerAislado() << std::endl;

    std::cout << "La Network es de topologia Malla: " << network.redMalla() << std::endl;

    std::cout << "La LAN es de topologia Malla: " << lan.redMalla() << std::endl;


    return 0;
}
