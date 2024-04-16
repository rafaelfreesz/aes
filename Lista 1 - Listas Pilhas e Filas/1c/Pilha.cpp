//
// Created by Rafael on 13/04/2024.
//

#include "Pilha.h"


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
Pilha::Pilha() {
    this->primeiro = this->ultimo = nullptr;
}

Pilha::~Pilha() {
    No *no = this->primeiro;
    while (no != nullptr) {
        no = this->primeiro;
        this->primeiro = this->primeiro->proximo;
        delete no;
    }
}

void Pilha::inserir(int k, Pilha *l) {
    No *novoNo = new No();
    novoNo->valor = k;

    if (isVazia(l)) {
        l->ultimo = novoNo;
    } else {
        novoNo->proximo = l->primeiro;
    }

    l->primeiro = novoNo;
}

No *Pilha::remover(Pilha *l) {
    if (!isVazia(l)) {
        No *no = l->primeiro;

        if (l->primeiro == l->ultimo) {
            l->primeiro = l->ultimo = nullptr;
        } else {
            l->primeiro = l->primeiro->proximo;
        }

        return no;
    } else {
        cout << "A pilha está vazia" << endl;
        return nullptr;
    }
}

void Pilha::imprimir(Pilha *l) {
    No *no = l->primeiro;

    cout << "I -> ";
    while (no != nullptr) {
        cout << no->valor << " | ";
        no = no->proximo;
    }
    cout << " F " << endl;
}

bool Pilha::isVazia(Pilha *l) {
    return l->primeiro == l->ultimo && l->primeiro == nullptr;
}
