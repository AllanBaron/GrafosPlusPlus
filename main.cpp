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

template <class T>
Grafo* lerArquivo(string caminhoArquivo){
    ifstream arquivo(caminhoArquivo);

    int qtdVertices = 0, qtdAresta = 0, direcionado = 0, ponderado = 0;
    arquivo >> qtdVertices >> qtdAresta >> direcionado >> ponderado;

    Grafo* grafo = new T(direcionado, ponderado);

    while (qtdVertices > 0) {
        string linha;
        arquivo >> linha;
        grafo->inserirVertice(linha);
        qtdVertices--;
    }

    while (qtdAresta > 0) {
        size_t origem = 0, destino = 0;
        double peso = 1.0;

        if (ponderado)
            arquivo >> origem >> destino >> peso;
        else
            arquivo >> origem >> destino;

        grafo->inserirAresta(origem, destino, peso);
        qtdAresta--;
    }
    return grafo;
}

int main() {
    /*
    Grafo *matriz = new GrafoMatriz(false, false);
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
        
        matriz->dsatur();
     */
        //matriz->imprimeGrafo();
    Grafo *matriz;
    matriz = lerArquivo<GrafoMatriz>("../assets/trabalho-28cores.txt");
    auto max = matriz->dsatur();
    cout << get<3>(*max_element(max.begin(), max.end(),[](tuple<size_t, int, int, int> &a, tuple<size_t, int, int, int> &b){ return get<3>(a) < get<3>(b); })) << endl;

    return 0;
}

