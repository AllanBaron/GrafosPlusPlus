#include "Grafo/GrafoMatriz.h"

GrafoMatriz::GrafoMatriz(bool direcionado, bool ponderado) : Grafo (direcionado, ponderado) {}

string GrafoMatriz::labelVertice(int indice){
    return this->label.at(indice);
}

bool GrafoMatriz::validaLabel(string label){
    for (int var = 0; var < qtdVertice; ++var)
        return !(this->label[var] == label);

    return true;
}

bool GrafoMatriz::inserirAresta(int origem, int destino, int peso){
    if (existeAresta(origem,destino) == 0) {
        if((this->direcionado || (!this->direcionado && origem != destino)) && (origem < this->label.size()) && (destino < this->label.size())){
           this->matriz[origem][destino] = this->ponderado ? peso : 1;
           this->matriz[destino][origem] = this->ponderado ? peso : 1;

           return true;
        }
    }
    return false;
}

double GrafoMatriz::existeAresta(int origem, int destino){
    return this->matriz[origem][destino];
}

double GrafoMatriz::existeAresta(size_t origem, size_t destino){
    return this->matriz[origem][destino];
}

bool GrafoMatriz::inserirVertice(string label){
    if(validaLabel(label)){
        this->label.push_back(label);
        this->matriz.push_back(vector<double>(qtdVertice+1, 0));

        for (int var = 0; var <= qtdVertice; var++) {
            this->matriz[var].push_back(0);
        }
        ++qtdVertice;
        return true;
    }
    return false;
}

vector<int> GrafoMatriz::retornarVizinhos(int vertice){
    vector<int> retorno;
        for (int var = 0; var < matriz[vertice].size(); var++) {
            if(matriz.at(vertice).at(var) != 0.0){
                retorno.push_back(var);
            }
        }
    return retorno;
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
    for (string var: label)
        cout << "|" << var;

    cout << "|" << endl;
    int coluna = 0;
    for(string var: label){
        cout << var << "|";
        for (int var = 0; var < qtdVertice; ++var)
            cout << matriz[var][coluna] << "|";
        ++coluna;
        cout << endl;
    }
}
