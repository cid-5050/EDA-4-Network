#ifndef GRAFO_H
#define GRAFO_H

#include <tipos.h>
#include <vector>
#include <map>
#include <set>
#include <funciones.h>


class Grafo {
  public:
    Grafo();

    void addVertice(const std::string & nombre, const std::string & IP, int valor);
    void addArista(const std::string & n1, const std::string & n2, int peso);

    void printVertices(void) const;

    std::map<std::string, Vertice *> & getVertices(void);
    std::map<std::string, std::map<std::string, std::pair<Vertice *, int>>> &
        getListaAdy(void);

    bool isolatedVertice(void) const;
    bool mesh(void) const;

    bool existeVertice(const std::string & nombre);
    bool sonVecinosDirectos(const std::string & nombreA, const std::string & nombreB);
    bool compartenRed(const std::string & nombreA, const std::string & nombreB);
    bool compartenRed(const std::string & nombreA, const std::string & nombreB,
                      std::set<std::string> & listaCheck, std::vector<std::string> & recorrido);

    std::vector<Vertice *> shortestPath(const std::string & nombreA,
                                        const std::string & nombreB);
    std::vector<Vertice *> shortestPath(const std::string & nombreA,
                                        const std::string & nombreB,
                                        std::set<std::string> & listaCheck,
                                        std::vector<Vertice *> & recorrido);


  private:
    std::map<std::string, Vertice *> vertices;
    std::vector<Arista *> aristas;

    std::map<std::string, std::map<std::string, std::pair<Vertice *, int>>> listaAdy;
};

#endif // GRAFO_H
