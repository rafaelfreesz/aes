//
// Created by Rafael on 13/04/2024.
//


#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

class No {

public:
    No(int valor, No *proximo, No *anterior);
    No();

    int valor;
    No* proximo;
};

class Lista {

public:
    Lista();
    ~Lista();

    static void inserirInicio(int k, Lista* l);
    static void inserirFinal(int k, Lista* l);
    static Lista* constroiListaMetade(Lista* l);

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
