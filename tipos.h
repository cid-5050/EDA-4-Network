#ifndef TIPOS_H
#define TIPOS_H

#include <iostream>
#include <vector>


struct Vertice {
    std::string nombre;
    std::string IP;
    int valor;
    std::vector<std::pair<Vertice *, int>> salidas;

    Vertice(const std::string & n, const std::string & ip, int v) {
        nombre = n;
        IP = ip;
        valor = v;
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
