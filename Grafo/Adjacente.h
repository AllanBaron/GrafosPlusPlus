#ifndef VERTICELIGACAO_H
#define VERTICELIGACAO_H
#include <vector>

class Adjacente
{
    public:
        size_t indice;
        double peso;

        Adjacente(size_t indice, double peso) {
            this->indice = indice;
            this->peso = peso;
        }
};


#endif // VERTICELIGACAO_H
