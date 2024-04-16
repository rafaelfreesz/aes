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
    No* anterior;
};

class Lista {

public:
    Lista();
    ~Lista();

    static void inserirInicio(int k, Lista* l);
    static void inserirFinal(int k, Lista* l);
    static Lista* somaListas(Lista* l1, Lista* l2);

    static void imprimir(Lista* l);
    static bool isVazia(Lista* l);

    static string stringfy(Lista* l);
private:
    No* primeiro;
    No* ultimo;
};



#endif //LISTA_H
