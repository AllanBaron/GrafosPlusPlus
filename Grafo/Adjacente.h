#ifndef VERTICELIGACAO_H
#define VERTICELIGACAO_H

class Adjacente
{
    public:
        int indice;
        int peso;

        Adjacente(int indice, int peso) {
            this->indice = indice;
            this->peso = peso;
        }
};


#endif // VERTICELIGACAO_H
