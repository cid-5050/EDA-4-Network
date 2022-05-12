#include "Grafo.h"


Grafo::Grafo() {
}

std::map<std::string, Vertice *> & Grafo::
getVertices(void) {
    return vertices;
}


void Grafo::
addVertice(const std::string & nombre, const std::string & IP, int valor) {
    // Comprueba si el vertice existe ya
    if (vertices.find(nombre) == vertices.end())
        vertices.insert({nombre, new Vertice(nombre, IP, valor)});
    else
        throw std::string("Error: Vertice ya existe");
}


void Grafo::
addArista(const std::string & n1, const std::string & n2, int peso) {
    // Comprueba que el primer vertice existe
    if (vertices.find(n1) == vertices.end())
        throw std::string("Error: vertice \"") + n1 + std::string("\" no existe");
    // Comprueba que el segundo vertice existe
    if (vertices.find(n2) == vertices.end())
        throw std::string("Error: vertice \"") + n2 + std::string("\" no existe");

    // Saca los vertices del mapa
    Vertice * v1 = (vertices.find(n1)->second);
    Vertice * v2 = (vertices.find(n2)->second);

    // (Opcional) Añade nueva arista al vector de aristas
    aristas.push_back(new Arista(v1, v2, peso));

    // (Opcional) Añade v2 como vecino de v1 en la lista de adyacencia
    if (listaAdy.find(v1->nombre) == listaAdy.end())
        listaAdy.insert({v1->nombre, {std::make_pair(v2, peso)}});
    //{v2->nombre, std::make_pair(v2, peso)}
    else
        listaAdy.at(v1->nombre).push_back(std::make_pair(v2, peso));

    // (Opcional) Añade v1 como vecino de v2 en la lista de adyacencia
    if (listaAdy.find(v2->nombre) == listaAdy.end())
        listaAdy.insert({v2->nombre, {std::make_pair(v1, peso)}});
    else
        listaAdy.at(v2->nombre).push_back(std::make_pair(v1, peso));

    // Actualiza la salida de v1, que apunta a v2
    v1->salidas.push_back(std::make_pair(v2, peso));
}


void Grafo::
printVertices() const {
    for (const auto & [nombre, vecinos] : listaAdy) {
        std::cout << nombre << " --> ";
        for (const auto & [vecino, peso] : vecinos) {
            std::cout << vecino->nombre << " / ";
        }
        std::cout << std::endl;
    }
}
