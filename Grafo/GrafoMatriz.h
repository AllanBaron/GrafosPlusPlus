#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include "Grafo.h"

using namespace std;

class GrafoMatriz : public Grafo
{
    protected:
        vector<vector <double>> matriz;

    public:
        GrafoMatriz(bool direcionado, bool ponderado);

        auto labelVertice(size_t indice) -> string;
        auto inserirVertice(string label) -> bool;
        auto inserirAresta(size_t origem, size_t destino, double peso = 1.0) -> bool;
        auto existeAresta(size_t origem, size_t destino) -> double;
        auto retornarVizinhos(size_t vertice) -> vector<size_t>;

        auto imprimeGrafo() -> void;
};

#endif // GRAFOMATRIZ_HPP
