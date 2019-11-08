#include "Grafo/GrafoMatriz.h"

GrafoMatriz::GrafoMatriz(bool direcionado, bool ponderado) : Grafo (direcionado, ponderado) {}

string GrafoMatriz::labelVertice(size_t indice){
    return this->label.at(indice);
}

bool GrafoMatriz::inserirAresta(size_t origem, size_t destino, double peso){
    if (existeAresta(origem, destino) == 0.0) {
        if((this->direcionado || (!this->direcionado && origem != destino)) && (origem < this->label.size()) && (destino < this->label.size())){
           this->matriz[origem][destino] = this->ponderado ? peso : 1;
           this->matriz[destino][origem] = this->ponderado ? peso : 1;

           return true;
        }
    }
    return false;
}

double GrafoMatriz::existeAresta(size_t origem, size_t destino){
    return this->matriz[origem][destino];
}

bool GrafoMatriz::inserirVertice(string label)
{
    if(validaLabel(label)){
        this->label.push_back(label);
        this->matriz.push_back(vector<double>(this->label.size(), 0));

        for (size_t var = 0; var < this->label.size(); var++)
            this->matriz[var].push_back(0);

        return true;
    }
    return false;
}

vector<size_t> GrafoMatriz::retornarVizinhos(size_t vertice){
    vector<size_t> retorno;
        for (size_t var = 0; var < matriz[vertice].size(); var++) {
            if(matriz.at(vertice).at(var) != 0.0){
                retorno.push_back(var);
            }
        }
    return retorno;
}

void GrafoMatriz::imprimeGrafo() {
    cout << " ";
    for (auto var: label)
        cout << "|" << var;

    cout << "|" << endl;
    size_t coluna = 0;
    for(string var: this->label){
        cout << var << "|";
        for (size_t var = 0; var < this->label.size(); var++)
            cout << matriz[var][coluna] << "|";
        coluna++;
        cout << endl;
    }
}
