#ifndef TIPOS_H
#define TIPOS_H

#include <iostream>
#include <vector>


struct Vertice {
    std::string nombre;
    std::vector<std::pair<Vertice *, int>> salidas;

    Vertice(std::string n) {
        nombre = n;
    }
};

struct Arista {
    Vertice * start;
    Vertice * end;
    int peso;

    Arista(Vertice * v1, Vertice * v2, int p) {
        start = v1;
        end = v2;
        peso = p;
    }
};

#endif // TIPOS_H
