#include <iostream>
#include "Grafo/Grafo.h"
#include "Grafo/GrafoLista.h"
#include "Grafo/GrafoMatriz.h"

using namespace std;

void printHeader(string text) {
    for(int i = 0; i < text.length(); i++)
        cout << "-";
    cout << endl;

    cout << text << endl;

    for(int i = 0; i < text.length(); i++)
        cout << "-";
    cout << "\n" << endl;
}

GrafoMatriz* exemploGrafoMatriz() {
    GrafoMatriz *matriz = new GrafoMatriz(false, false);
    matriz->inserirVertice("A");
    matriz->inserirVertice("B");
    matriz->inserirVertice("C");
    matriz->inserirVertice("D");
    matriz->inserirVertice("E");

    matriz->inserirAresta(0,1,3);
    matriz->inserirAresta(0,2,5);
    matriz->inserirAresta(0,3,6);
    matriz->inserirAresta(0,4,8);
    matriz->inserirAresta(1,3,2);
    matriz->inserirAresta(1,4,11);
    matriz->inserirAresta(2,4,2);
    matriz->inserirAresta(3,1,2);

    return matriz;
}

GrafoLista* exemploGrafoLista() {
    GrafoLista *lista = new GrafoLista(false, false);
    lista->inserirVertice("A");
    lista->inserirVertice("B");
    lista->inserirVertice("C");
    lista->inserirVertice("D");
    lista->inserirVertice("E");

    lista->inserirAresta(0,1,3);
    lista->inserirAresta(0,2,5);
    lista->inserirAresta(0,3,6);
    lista->inserirAresta(0,4,8);
    lista->inserirAresta(1,3,2);
    lista->inserirAresta(1,4,11);
    lista->inserirAresta(2,4,2);
    lista->inserirAresta(3,1,2);

    return lista;
}

void buscaLargura(Grafo *gafo, int indice = 0) {
    vector<int> resultado = gafo->busca_Largura(indice);

    for(int x: resultado)
          cout<< x <<"-";

    cout << endl;
}

void buscaProfundidade(Grafo *gafo, int indice = 0) {
    vector<int> resultado = gafo->busca_Profundidade(indice);

    for(int x: resultado)
          cout<< x <<"-";

    cout << endl;
}

int main() {
    printHeader("Grafo Matriz");
    exemploGrafoMatriz()->imprimeGrafo();
    cout << "\n" << endl;

    printHeader("Grafo Lista");
    exemploGrafoLista()->imprimeGrafo();
    cout << "\n" << endl;

    printHeader("Busca em Largura com Grafo Matriz");
    buscaLargura(exemploGrafoMatriz());
    cout << "\n" << endl;

    printHeader("Busca em Largura com Grafo Lista");
    buscaLargura(exemploGrafoLista());
    cout << "\n" << endl;

    printHeader("Busca em Profundidade com Grafo Matriz");
    buscaProfundidade(exemploGrafoMatriz());
    cout << "\n" << endl;

    printHeader("Busca em Profundidade com Grafo Lista");
    buscaProfundidade(exemploGrafoLista());
    cout << "\n" << endl;

    return 0;
}

