//
// Created by Rafael on 13/04/2024.
//


#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

class No {

public:
    No(char valor, No *proximo, No *anterior);
    No();

    char valor;
    No* proximo;
};

class Lista {

public:
    Lista();
    ~Lista();

    static void inserirInicio(char k, Lista* l);
    static void inserirFinal(char k, Lista* l);
    static bool ehPalindromo(Lista *l);

    static void imprimir(Lista* l);
    static bool isVazia(Lista* l);

    static int *arrayfy(Lista *l);

    int getTam() {return this->tam;};

private:
    int tam;
    No* primeiro;
    No* ultimo;
};



#endif //LISTA_H
