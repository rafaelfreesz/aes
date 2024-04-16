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

class Fila {

public:
    Fila();
    ~Fila();

    static void inserir(int k, Fila* l);
    static No *remover(Fila *l);

    static void imprimir(Fila* l);
    static bool isVazia(Fila* l);

private:
    No* primeiro;
    No* ultimo;
};



#endif //LISTA_H
