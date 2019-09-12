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
