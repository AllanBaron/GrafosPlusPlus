#include <iostream>
#include "Grafo/Grafo.h"
#include "Grafo/GrafoLista.h"
#include "Grafo/GrafoMatriz.h"

using namespace std;

void exemploGrafoMatriz() {
    GrafoMatriz *matriz = new GrafoMatriz(false, true);
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


    matriz->imprimeGrafo();
}

void exemploGrafoLista() {
    GrafoLista *lista = new GrafoLista(false, true);
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


    lista->imprimeGrafo();
}

int main() {
    exemploGrafoMatriz();
    exemploGrafoLista();

    return 0;
}

