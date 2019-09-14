#include "Grafo/Grafo.h"

Grafo::Grafo(bool direcionado, bool ponderado)
{
    this->direcionado = direcionado;
    this->ponderado = ponderado;
    this->qtdVertice = 0;
}

string Grafo::labelVertice(int indice){
    return this->label[indice];
}

bool Grafo::validaLabel(string label){
    for (int var = 0; var < qtdVertice; ++var)
        return !(this->label[var] == label);

    return true;
}

bool Grafo::getDirecionado()
{
    return direcionado;
}

bool Grafo::getPonderado()
{
    return ponderado;
}

vector<int> Grafo::busca_Profundidade(int indice)
{
    vector<int> resultado;
    vector<int> visitados(this->label.size(),0);
    int qtdVisitados = 0;
    stack<int> pilha;
    pilha.push(indice);

    while (!pilha.empty()) {
        int nodo = pilha.top();

        if (visitados.at(nodo) == 0) {
            resultado.push_back(nodo);
            visitados.at(nodo) = ++qtdVisitados;
        }

        int qtd_visinhos = 0;
        vector<int> vizinho = retornarVizinhos(nodo);

        for (int var = 0; var < vizinho.size(); var++) {
            if(visitados[vizinho[var]] == 0){
                pilha.push(vizinho[var]);
                break;
            }
            qtd_visinhos++;
        }

        if(qtd_visinhos == vizinho.size())
           pilha.pop();
    }

    return resultado;
}

vector<int> Grafo::busca_Largura(int indice){
    vector<int> resultado;
    vector<int> visitados(this->label.size(),0);
    int qtdVisitados = 0;
    queue<int> fila;
    fila.push(indice);

    while (!fila.empty()) {
        int nodo = fila.front();

        if (visitados[nodo] == 0) {
            resultado.push_back(nodo);
            visitados[nodo] = ++qtdVisitados;
        }

        vector<int> vizinho = retornarVizinhos(nodo);

        for (int var = 0; var < vizinho.size(); ++var) {
            if(visitados[vizinho[var]] == 0){
                fila.push(vizinho[var]);

            }

        }
           fila.pop();
    }
    return resultado;
}

