//
// Created by Rafael on 13/04/2024.
//


#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

class No {

public:
    No(int valor, No *proximo);
    No();

    int valor;
    No* proximo;
};

class Pilha {

public:
    Pilha();
    ~Pilha();

    static void inserir(int k, Pilha* l);
    static No *remover(Pilha *l);

    static void imprimir(Pilha* l);
    static bool isVazia(Pilha* l);

private:
    No* primeiro;
    No* ultimo;
};



#endif //LISTA_H
