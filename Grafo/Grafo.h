#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <fstream>
#include <algorithm>
#include <utility>
#include <functional>
#include<tuple>
#include <map>

using namespace std;

class Grafo
{
    protected:
        vector<string> label;
        bool direcionado;
        bool ponderado;
        int qtdVertice;

    public:
        Grafo(bool direcionado, bool ponderado);

        bool getPonderado();
        bool getDirecionado();

        virtual string labelVertice(int indice) = 0;
        virtual bool validaLabel(string label) = 0;
        virtual bool inserirVertice(string label) = 0;
        virtual bool inserirAresta(int origem, int destino, int peso = 1) = 0;
        virtual double existeAresta(int origem, int destino) = 0;
        virtual vector<int> retornarVizinhos(int vertice) = 0;

        virtual void imprimeGrafo() = 0;

        vector<int> busca_Profundidade(int indice);
        vector<int> busca_Largura(int indice);

        int verticeGrau(string label);
        int verticeGrau(int index);
        auto welshPowell() -> vector<int>;
        auto dsatur() -> vector<int>;

        auto prim(size_t index) -> int;
        auto kruskal() -> int;

        virtual ~Grafo();
};

#endif // GRAFO_HPP
