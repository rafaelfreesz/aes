//
// Created by Rafael on 18/04/2024.
//

#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Passenger.h"

using namespace std;
class No {

public:
    No(Passenger* valor, No *proximo);
    No();

    Passenger* valor;
    No* proximo;
};

class Lista {
public:
    Lista();
    ~Lista();

    static void inserirInicio(Passenger *k, Lista* l);
    static void inserirFinal(Passenger *k, Lista* l);

    static void imprimir(Lista* l);
    static bool isVazia(Lista* l);

private:
    No* primeiro;
    No* ultimo;
    int tam;
};



#endif //LISTA_H
