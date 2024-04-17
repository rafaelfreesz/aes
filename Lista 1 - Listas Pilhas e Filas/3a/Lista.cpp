//
// Created by Rafael on 13/04/2024.
//

#include "Lista.h"


//Funções do Nó
No::No(int valor, No *proximo, No *anterior) {
    this->valor = valor;
    this->proximo = proximo;
}

No::No() {
    this->valor = -1;
    this->proximo = nullptr;
}

//Funções da Lista
Lista::Lista() {
    this->primeiro = this->ultimo = nullptr;
    this->tam=0;
}

Lista::~Lista() {
    No *no = this->primeiro;
    while (this->primeiro != nullptr) {
        no = this->primeiro;
        this->primeiro = this->primeiro->proximo;
        delete no;
    }
}

void Lista::inserirInicio(int k, Lista *l) {
    No *novoNo = new No();
    novoNo->valor = k;
    novoNo->proximo = l->primeiro;

    if (isVazia(l)) {
        l->ultimo = novoNo;
    }

    l->primeiro = novoNo;
    l->tam++;
}

void Lista::inserirFinal(int k, Lista *l) {
    No *novoNo = new No();
    novoNo->valor = k;

    if (isVazia(l)) {
        l->primeiro = novoNo;
    } else {
        l->ultimo->proximo = novoNo;
    }

    l->ultimo = novoNo;
    l->tam++;
}

Lista *Lista::inverteLista(Lista *l) {
    Lista *l2 = new Lista();

    No* no = l->primeiro;

    while(no!=nullptr) {
        inserirInicio(no->valor,l2);
        no = no->proximo;
    }

    return l2;
}

void Lista::imprimir(Lista *l) {
    No *no = l->primeiro;

    while (no != nullptr) {
        cout << no->valor<<" | ";
        no = no->proximo;
    }
    cout <<endl;
}

bool Lista::isVazia(Lista *l) {
    return l->primeiro == l->ultimo && l->primeiro == nullptr;
}

int *Lista::arrayfy(Lista *l) {
    int* vL = new int[l->getTam()];


    No* no = l->primeiro;
    int i=0;
    while(no!=nullptr) { vL[i++]=no->valor; no = no->proximo; }

    return vL;
}
