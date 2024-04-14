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

    static No* contido(int k, Lista* l);
    static void inserir(int k, Lista* l);
    static void remover(int k, Lista* l);

    static void imprimir(Lista* l);
    static bool isVazia(Lista* l);

private:
    No* primeiro;
    No* ultimo;
};



#endif //LISTA_H
