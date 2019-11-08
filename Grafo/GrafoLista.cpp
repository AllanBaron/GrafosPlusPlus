#include "Grafo/GrafoLista.h"

GrafoLista::GrafoLista(bool direcionado, bool ponderado) : Grafo (direcionado, ponderado),lista(vector<vector<Adjacente>>()){}

bool GrafoLista::inserirVertice(string label){
    if(validaLabel(label)){
        this->label.push_back(label);
        this->lista.push_back(vector<Adjacente>());
        return true;
    }
    return false;
}

string GrafoLista::labelVertice(size_t indice){
    return this->label[indice];
}

bool GrafoLista::inserirAresta(size_t origem, size_t destino, double peso){
    if (!(existeAresta(origem, destino) == 0.0)) {
        if((this->direcionado || (!this->direcionado && origem != destino)) && (origem < this->label.size()) && (destino < this->label.size())){
           this->lista[destino].push_back(Adjacente(origem, this->ponderado ? peso : 1));
           this->lista[origem].push_back(Adjacente(destino, this->ponderado ? peso : 1));

           return true;
        }
    }
    return false;
}

void GrafoLista::imprimeGrafo(){
    size_t coluna = 0;
    for (auto aux : this->label) {
      cout << aux << " -> ";
      for (Adjacente var : this->lista[coluna]) {
          cout << "[" << var.indice  << ":" << var.peso << "]";
       }
      cout << endl;
      coluna++;
    }
}

double GrafoLista::existeAresta(size_t origem, size_t destino){
    if(origem < label.size() && label.size() > destino){
        for (Adjacente aux : lista[origem]) {
            if(aux.indice == destino){
                return aux.peso;
            }
        }
     }
    return 0;
}

vector<size_t> GrafoLista::retornarVizinhos(size_t vertice){
    vector<size_t> retorno;
    for (Adjacente aux : lista[vertice] ) {
        if(aux.peso != 0.0){
            retorno.push_back(aux.indice);
        }
    }

    return retorno;
}
