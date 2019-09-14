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

        string labelVertice(int indice);
        bool inserirVertice(string label);
        bool inserirAresta(int origem, int destino, int peso = 1);
        double existeAresta(int origem, int destino);
        vector<int> retornarVizinhos(int vertice);
        bool validaLabel(string label);

        void imprimeGrafo();
};

#endif // GRAFOLISTA_H
