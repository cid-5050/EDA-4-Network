#include <iostream>
#include <Network.h>


int main() {

    Network network;

    try {
        network.nuevoRouter("192.168.0.1");
        network.nuevoRouter("192.168.0.2");
        network.nuevoRouter("192.168.0.3");
        network.nuevoRouter("192.168.0.4");
        network.nuevoRouter("192.168.0.5");

        network.conectarRouters("192.168.0.1", "192.168.0.2");
        network.conectarRouters("192.168.0.1", "192.168.0.3");
        network.conectarRouters("192.168.0.2", "192.168.0.3");
        network.conectarRouters("192.168.0.2", "192.168.0.1");
        network.conectarRouters("192.168.0.3", "192.168.0.4");
        network.conectarRouters("192.168.0.5", "192.168.0.1");

    } catch (std::string e) {
        std::cout << e << std::endl;
    }

    network.printNetwork();

    std::cout << std::endl;
    return 0;
}
