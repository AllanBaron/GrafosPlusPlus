#include <iostream>
#include "Grafo.h"
#include "GrafoLista.h"
#include "GrafoMatriz.h"

using namespace std;
int main()
{
    GrafoMatriz matriz(false,true);
    matriz.inserirVertice("A");
    matriz.inserirVertice("B");
    matriz.inserirVertice("C");
    matriz.inserirVertice("D");
    matriz.inserirVertice("E");

    GrafoLista lista(false,true);
    lista.inserirVertice("A");
    lista.inserirVertice("B");
    lista.inserirVertice("C");
    lista.inserirVertice("D");
    lista.inserirVertice("E");


    matriz.inserirAresta(0,1,3);
    matriz.inserirAresta(0,2,5);
    matriz.inserirAresta(0,3,6);
    matriz.inserirAresta(0,4,8);
    matriz.inserirAresta(1,3,2);
    matriz.inserirAresta(1,4,11);
    matriz.inserirAresta(2,4,2);
    matriz.inserirAresta(3,1,2);

    lista.inserirAresta(0,1,3);
    lista.inserirAresta(0,2,5);
    lista.inserirAresta(0,3,6);
    lista.inserirAresta(0,4,8);
    lista.inserirAresta(1,3,2);
    lista.inserirAresta(1,4,11);
    lista.inserirAresta(2,4,2);
    lista.inserirAresta(3,1,2);

    matriz.imprimeGrafo();
    lista.imprimeGrafo();


//    GrafoMatriz teste(true,true);
//    teste.inserirVertice("A");
//    teste.inserirVertice("B");
//    teste.inserirVertice("C");
//    teste.inserirVertice("D");
//    teste.inserirVertice("D");
//    teste.inserirAresta(0,1,9);
//    teste.imprimeGrafo();
    //cout << teste.labelVertice(0) << endl;


/*
    GrafoLista tes(true,true);
    tes.inserirVertice("A");
    tes.inserirVertice("B");
    tes.inserirVertice("C");
    tes.inserirVertice("D");
    tes.inserirAresta(0,1,9);
    tes.inserirAresta(0,2,9);
    tes.inserirAresta(0,3,9);
    tes.inserirAresta(2,1,8);
    tes.imprimeGrafo();
*/

    /*GrafoMatriz *teste = new GrafoMatriz(true,true);
    teste->inserirVertice("A");
    teste->inserirVertice("B");
    teste->inserirVertice("C");
    teste->inserirVertice("D");
    teste->inserirAresta(0,1,8);
    teste->imprimeGrafo();
    return 0;*/
}

