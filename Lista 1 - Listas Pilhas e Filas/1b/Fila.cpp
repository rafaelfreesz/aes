//
// Created by Rafael on 13/04/2024.
//

#include "Fila.h"


//Funções do Nó
No::No(int valor, No *proximo) {
    this->valor = valor;
    this->proximo = proximo;
}

No::No() {
    this->valor = -1;
    this->proximo = nullptr;
}

//Funções da Lista
Fila::Fila() {
    this->primeiro = this->ultimo = nullptr;
}

Fila::~Fila() {
    No *no = this->primeiro;
    while (no != nullptr) {
        no = this->primeiro;
        this->primeiro = this->primeiro->proximo;
        delete no;
    }
}

void Fila::inserir(int k, Fila *l) {
    No *novoNo = new No();
    novoNo->valor = k;

    if (isVazia(l)) {
        l->primeiro = novoNo;
    } else {
        l->ultimo->proximo = novoNo;
    }

    l->ultimo = novoNo;
}

No *Fila::remover(Fila *l) {
    if (!isVazia(l)) {
        No *no = l->primeiro;

        if (l->primeiro == l->ultimo) {
            l->primeiro = l->ultimo = nullptr;
        } else {
            l->primeiro = l->primeiro->proximo;
        }

        return no;
    } else {
        cout << "A fila está vazia" << endl;
        return nullptr;
    }
}

void Fila::imprimir(Fila *l) {
    No *no = l->primeiro;

    cout << "I -> ";
    while (no != nullptr) {
        cout << no->valor << " | ";
        no = no->proximo;
    }
    cout << " F " << endl;
}

bool Fila::isVazia(Fila *l) {
    return l->primeiro == l->ultimo && l->primeiro == nullptr;
}
