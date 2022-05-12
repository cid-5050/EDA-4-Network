#ifndef GRAFO_H
#define GRAFO_H

#include <tipos.h>
#include <vector>
#include <map>


class Grafo {
  public:
    Grafo();

    void addVertice(const std::string & nombre, const std::string & IP, int valor);
    void addArista(const std::string & n1, const std::string & n2, int peso);

    void printVertices(void) const;

    std::map<std::string, Vertice *> & getVertices(void);

  private:
    std::map<std::string, Vertice *> vertices;
    std::vector<Arista *> aristas;

    std::map<std::string, std::map<std::string, std::pair<Vertice *, int>>> listaAdy;
};

#endif // GRAFO_H
