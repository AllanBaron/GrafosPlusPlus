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

int main() {
    /*
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
    */
    /*
    exemploGrafoMatriz()->imprimeGrafo();
    cout << endl;

    exemploGrafoLista()->imprimeGrafo();
    cout << endl;
    */


    GrafoMatriz *matriz;// = new GrafoMatriz(false, false);
    matriz = lerArquivo<GrafoMatriz>(matriz, "../assets/trabalho-28cores.txt");
    vector<int> r = matriz->welshPowell();
    //int max = max_element(r.begin(),r.end());

    cout << "|";
    for(int var : r)
        cout<< var << "|";
    cout << endl << "total de cores: " << *max_element(r.begin(), r.end()) << endl;;

    //matriz->imprimeGrafo();


    /*
    vector<double> predictions{ 1.22, 3.22, 2.22, 4.22 };
    vector<int> indices{ 0, 1, 2, 3 };

    std::sort(indices.begin(), indices.end(),[&predictions](int &a, int &b) {return predictions[a] > predictions[b];});
    for (auto i: indices) {
            cout << i << "\t" << predictions[i] << endl;
    }
    */

    //exemploWelshPowell();

    //exemploDsatur();

    return 0;
}

