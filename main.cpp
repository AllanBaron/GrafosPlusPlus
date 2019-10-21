#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cmath>
#include <fstream>

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

void buscaLargura(Grafo *grafo, int indice = 0) {
    vector<int> resultado = grafo->busca_Largura(indice);

    for(int x: resultado)
          cout<< x <<"-";

    cout << endl;
}

void buscaProfundidade(Grafo *grafo, int indice = 0) {
    vector<int> resultado = grafo->busca_Profundidade(indice);

    for(int x: resultado)
          cout<< x <<"-";

    cout << endl;
}

template <class T>
T* lerArquivo(T *grafo, string caminhoArquivo){
    ifstream arquivo(caminhoArquivo);

    int qtdVertices = 0, qtdAresta = 0, direcionado = 0, ponderado = 0;
    arquivo >> qtdVertices >> qtdAresta >> direcionado >> ponderado;

    grafo = new T(direcionado, ponderado);

    while (qtdVertices > 0) {
        string linha;
        arquivo >> linha;
        grafo->inserirVertice(linha);
        qtdVertices--;
    }

    while (qtdAresta > 0) {
        int origem = 0, destino = 0, peso = 1;

        if (ponderado)
            arquivo >> origem >> destino >> peso;
        else
            arquivo >> origem >> destino;

        grafo->inserirAresta(origem, destino, peso);
        qtdAresta--;
    }
    return grafo;
}

void exemploWelshPowell(){
    GrafoLista *matriz = new GrafoLista(false, false);
    matriz->inserirVertice("A");
    matriz->inserirVertice("B");
    matriz->inserirVertice("C");
    matriz->inserirVertice("D");
    matriz->inserirVertice("E");

    matriz->inserirAresta(0,1);
    matriz->inserirAresta(0,3);
    matriz->inserirAresta(1,3);
    matriz->inserirAresta(1,4);
    matriz->inserirAresta(1,2);
    matriz->inserirAresta(2,4);
    matriz->inserirAresta(3,4);

    //matriz->imprimeGrafo();

    vector<int> r = matriz->welshPowell();

    cout << "|";
    for(int var : r)
        cout<< var << "|";
    cout << endl;
}

void exemploDsatur(){
    GrafoMatriz *matriz = new GrafoMatriz(false, false);
    matriz->inserirVertice("A");
    matriz->inserirVertice("B");
    matriz->inserirVertice("C");
    matriz->inserirVertice("D");
    matriz->inserirVertice("E");

    matriz->inserirAresta(0,1);
    matriz->inserirAresta(0,3);
    matriz->inserirAresta(1,4);
    matriz->inserirAresta(1,2);
    matriz->inserirAresta(2,4);
    matriz->inserirAresta(3,4);

    //matriz->imprimeGrafo();

    vector<int> r = matriz->dsatur();

    cout << "|";
    for(int var : r)
        cout<< var << "|";
    cout << endl;
}

void exemploPrim(){
    GrafoMatriz * matriz = new  GrafoMatriz(false, true);
    matriz->inserirVertice("A");
    matriz->inserirVertice("B");
    matriz->inserirVertice("C");
    matriz->inserirVertice("D");
    matriz->inserirVertice("E");
    matriz->inserirVertice("F");

    matriz->inserirAresta(0,2,7);
    matriz->inserirAresta(0,4,10);
    matriz->inserirAresta(0,3,2);
    matriz->inserirAresta(2,4,9);
    matriz->inserirAresta(2,1,3);
    matriz->inserirAresta(2,5,3);
    matriz->inserirAresta(1,5,2);
    matriz->inserirAresta(4,5,8);
    matriz->inserirAresta(4,3,7);
    matriz->inserirAresta(3,5,4);

    cout << matriz->kruskal() << endl;
    //cout << matriz->prim(2) << endl;
    //matriz->imprimeGrafo();
}

int main() {
    exemploPrim();
    return 0;
}

