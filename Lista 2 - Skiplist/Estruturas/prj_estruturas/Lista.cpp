//
// Created by Rafael on 18/04/2024.
//

#include "Lista.h"

//Funções do Nó
No::No(Passenger* valor, No *proximo) {
    this->valor = valor;
    this->proximo = proximo;
}

No::No() {
    this->valor = nullptr;
    this->proximo = nullptr;
}

//Funções da Lista
Lista::Lista() {
    this->primeiro = this->ultimo = nullptr;
}

Lista::~Lista() {
    No *no;
    while (this->primeiro != nullptr) {
        no = this->primeiro;
        this->primeiro = this->primeiro->proximo;
        delete no;
    }
}

void Lista::inserirInicio(Passenger *k, Lista *l) {
    No *novoNo = new No();
    novoNo->valor = k;
    novoNo->proximo = l->primeiro;

    if (isVazia(l)) {
        l->ultimo = novoNo;
    }

    l->primeiro = novoNo;
}

void Lista::inserirFinal(Passenger *k, Lista *l) {
    No *novoNo = new No();
    novoNo->valor = k;

    if (isVazia(l)) {
        l->primeiro = novoNo;
    } else {
        l->ultimo->proximo = novoNo;
    }

    l->ultimo = novoNo;
}

bool Lista::isVazia(Lista *l) {
    return l->primeiro == l->ultimo && l->primeiro == nullptr;
}

void Lista::imprimir(Lista *l) {
    No *no = l->primeiro;

    while (no != nullptr) {
        cout << no->valor <<" | ";
        no = no->proximo;
    }
    cout <<endl;
}