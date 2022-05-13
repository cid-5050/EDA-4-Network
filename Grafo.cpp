#include "Grafo.h"


Grafo::Grafo() {
}

std::map<std::string, Vertice *> & Grafo::
getVertices(void) {
    return vertices;
}


std::map<std::string, std::map<std::string, std::pair<Vertice *, int>>> & Grafo::
getListaAdy(void) {
    return listaAdy;
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
    // Comprueba que el vertice no se conecte a el mismo
    if (n1 == n2)
        throw std::string("Error: vertice \"" + n1 + "\" no se puede conectar a si mismo");
    // Comprueba que el primer vertice existe
    if (vertices.find(n1) == vertices.end())
        throw std::string("Error: vertice \"") + n1 + std::string("\" no existe");
    // Comprueba que el segundo vertice existe
    if (vertices.find(n2) == vertices.end())
        throw std::string("Error: vertice \"") + n2 + std::string("\" no existe");

    // Saca los vertices del mapa
    Vertice * v1 = (vertices.find(n1)->second);
    Vertice * v2 = (vertices.find(n2)->second);

    // Añade nueva arista al vector de aristas
    aristas.push_back(new Arista(v1, v2, peso));

    // Añade v1 a la lista de adyacencia
    if (listaAdy.find(v1->nombre) == listaAdy.end())
        listaAdy.insert({v1->nombre, std::map<std::string, std::pair<Vertice *, int>>()});

    // Añade v2 como vecino de v1 en la lista de adyacencia
    if (listaAdy.find(v1->nombre)->second.find(v2->nombre)
            == listaAdy.find(v1->nombre)->second.end())
        listaAdy.find(v1->nombre)->second.insert({v2->nombre, std::make_pair(v2, peso)});

    // Añade v2 a la lista de adyacencia
    if (listaAdy.find(v2->nombre) == listaAdy.end())
        listaAdy.insert({v2->nombre, std::map<std::string, std::pair<Vertice *, int>>()});

    // Añade v1 como vecino de v2 en la lista de adyacencia
    if (listaAdy.find(v2->nombre)->second.find(v1->nombre)
            == listaAdy.find(v2->nombre)->second.end())
        listaAdy.find(v2->nombre)->second.insert({v1->nombre, std::make_pair(v1, peso)});

    // Actualiza la salida de v1, que apunta a v2
    v1->salidas.push_back(std::make_pair(v2, peso));

    // Actualiza la salida de v2, que apunta a v1
    v2->salidas.push_back(std::make_pair(v1, peso));
}


void Grafo::
printVertices() const {
    for (const auto & [nombreVertice, vecinos] : listaAdy) {
        std::cout << nombreVertice << " --> ";
        for (const auto & [nombreVecino, pairVecino] : vecinos) {
            std::cout << nombreVecino << " / ";
        }
        std::cout << std::endl;
    }
}

bool Grafo::
existeVertice(const std::string & nombre) {
    return vertices.find(nombre) != vertices.end();
}

bool Grafo::
sonVecinosDirectos(const std::string & nombreA, const std::string & nombreB) {
    if (listaAdy.find(nombreA) == listaAdy.end()
            or
            listaAdy.find(nombreB) == listaAdy.end())
        return false;

    for (const auto & vecino : listaAdy.find(nombreA)->second) {
        if (vecino.second.first->nombre == nombreB)
            return true;
    }
    return false;
}

bool Grafo::
compartenRed(const std::string & nombreA, const std::string & nombreB) {
    if (not existeVertice(nombreA) or not existeVertice(nombreB))
        return false;

    std::set<std::string> listaCheck;
    std::vector<std::string> recorrido {nombreA};

    return compartenRed(nombreA, nombreB, listaCheck, recorrido);
}

bool Grafo::
compartenRed(const std::string & nombreA, const std::string & nombreB,
             std::set<std::string> & listaCheck, std::vector<std::string> & recorrido) {

    if (sonVecinosDirectos(nombreA, nombreB))
        return true;

    for (const auto & vecino : listaAdy.find(nombreA)->second) {
        if (listaCheck.find(vecino.second.first->nombre) == listaCheck.end()
                and
                not enLista(vecino.second.first->nombre, recorrido)) {

            recorrido.push_back(vecino.second.first->nombre);
            return compartenRed(vecino.second.first->nombre, nombreB, listaCheck, recorrido);
        }
    }

    listaCheck.insert(nombreA);
    recorrido.pop_back();

    if (not recorrido.empty())
        return compartenRed(recorrido.back(), nombreB, listaCheck, recorrido);

    else
        return false;
}

bool Grafo::
isolatedVertice() const {
    for(auto elem: vertices){
        if(elem.second->salidas.empty())
            return true;
    }
    return false;
}

bool Grafo::
mesh() const {
    for(auto elem: vertices){
        if(elem.second->salidas.size()!=vertices.size()-1)
            return false;
    }
    return true;
}

/*std::vector<Vertice *> Grafo::
shortestPath(const std::string & nombreA, const std::string & nombreB) {
    if (not existeVertice(nombreA) or not existeVertice(nombreB))
        return {};

    if (not compartenRed(nombreA, nombreB))
        return {};

    std::set<std::string> listaCheck;
    std::vector<Vertice *> recorrido {vertices.find(nombreA)->second};

    return shortestPath(nombreA, nombreB, listaCheck, recorrido);
}*/

/*std::vector<Vertice *> Grafo::
shortestPath(const std::string & nombreA, const std::string & nombreB,
             std::set<std::string> & listaCheck, std::vector<Vertice *> & recorrido) {

    if (sonVecinosDirectos(nombreA, nombreB)) {
        recorrido.push_back(vertices.find(nombreB)->second);
        return recorrido;
    }

    for (const auto & vecino : listaAdy.find(nombreA)->second) {
        if (listaCheck.find(vecino.second.first->nombre) == listaCheck.end()
                and
                not enLista(vecino.second.first->nombre, recorrido)) {

            recorrido.push_back(vecino.second.first->nombre);
            return compartenRed(vecino.second.first->nombre, nombreB, listaCheck, recorrido);
        }
    }

    listaCheck.insert(nombreA);
    recorrido.pop_back();

    if (not recorrido.empty())
        return compartenRed(recorrido.back(), nombreB, listaCheck, recorrido);

    else
        return false;
}*/
