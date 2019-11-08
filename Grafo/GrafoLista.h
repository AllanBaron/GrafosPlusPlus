#ifndef GRAFOLISTA_H
#define GRAFOLISTA_H

#include "Grafo.h"
#include "Adjacente.h"

using namespace std;

class GrafoLista : public Grafo
{
    protected:
        vector<vector <Adjacente>> lista;

    public:
        GrafoLista(bool direcionado, bool ponderado);

        auto labelVertice(size_t indice) -> string;
        auto inserirVertice(string label) -> bool;
        auto inserirAresta(size_t origem, size_t destino, double peso = 1.0) -> bool;
        auto existeAresta(size_t origem, size_t destino) -> double;
        auto retornarVizinhos(size_t vertice) -> vector<size_t>;

        auto imprimeGrafo() -> void;
};

#endif // GRAFOLISTA_H
