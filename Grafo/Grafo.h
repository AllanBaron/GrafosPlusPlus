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
#include <numeric>
#include <tuple>
#include <map>
#include <chrono>
#include <ctime>

using namespace std;

class Grafo
{
    protected:
        vector<string> label;
        bool direcionado;
        bool ponderado;

    public:
        Grafo(bool direcionado, bool ponderado);

        auto getPonderado() -> bool;
        auto getDirecionado() -> bool;

        auto labelVertice(size_t indice) -> string;
        auto validaLabel(string label) -> bool;
        virtual auto inserirVertice(string label) -> bool = 0;
        virtual auto inserirAresta(size_t origem, size_t destino, double peso = 1.0) -> bool = 0;
        virtual auto existeAresta(size_t origem, size_t destino) -> double = 0;
        virtual auto retornarVizinhos(size_t vertice) -> vector<size_t> = 0;
        virtual auto imprimeGrafo() -> void = 0;

        auto busca_Profundidade(size_t indice) -> vector<size_t>;
        auto busca_Largura(size_t indice) -> vector<size_t>;

        auto verticeGrau(size_t index) -> size_t;
        auto welshPowell() -> vector<tuple<size_t, int, int>>;
        auto dsatur() -> vector<tuple<size_t, int, int, int>>;

        auto prim(size_t index) -> vector<tuple<size_t, size_t, double>>;
        auto kruskal() -> vector<tuple<size_t, size_t, double>>;

        virtual ~Grafo();
};

#endif // GRAFO_HPP
