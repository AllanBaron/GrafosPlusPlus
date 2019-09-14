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

        string labelVertice(int indice);
        bool inserirVertice(string label);
        bool inserirAresta(int origem, int destino, int peso = 1);
        double existeAresta(int origem, int destino);
        vector<int> retornarVizinhos(int vertice);
        bool validaLabel(string label);

        void imprimeGrafo();
};

#endif // GRAFOMATRIZ_HPP
