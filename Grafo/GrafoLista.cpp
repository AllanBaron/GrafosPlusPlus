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

string GrafoLista::labelVertice(int indice){
    return this->label[indice];
}

bool GrafoLista::validaLabel(string label){
    for (int var = 0; var < qtdVertice; ++var)
        return !(this->label[var] == label);

    return true;
}

bool GrafoLista::inserirAresta(int origem, int destino, int peso ){
    if (existeAresta(origem,destino) == 0.0) {
        if((this->direcionado || (!this->direcionado && origem != destino)) && (origem < this->label.size()) && (destino < this->label.size())){
            if (!this->direcionado)
               this->lista[destino].push_back(Adjacente(origem,peso));
               this->lista[origem].push_back(Adjacente(destino,peso));
               return true;
        }
    }
    return false;
}

void GrafoLista::imprimeGrafo(){
    int coluna = 0;
    for (string aux : this->label) {
      cout << aux << " -> ";
      for (Adjacente var : this->lista[coluna]) {
          cout << "[ " << var.indice  << " : " << var.peso << " ] ";
       }
      cout << endl;
      ++coluna;
    }
}

double GrafoLista::existeAresta(int origem, int destino){
    if(origem < label.size() && label.size() > destino){
        for (Adjacente aux : lista[origem]) {
            if(aux.indice == destino){
                return aux.peso;
            }
        }
     }
    return 0.0;
}

vector<int> GrafoLista::retornarVizinhos(int vertice){
    vector<int> retorno;
    for (Adjacente aux : lista[vertice] ) {
        if(aux.indice != 0){
            retorno.push_back(aux.indice);
        }
    }

    return retorno;
}
