//
// Created by Rafael on 13/04/2024.
//

#include "Lista.h"


//Funções do Nó
No::No(int valor, No *proximo, No *anterior) {
    this->valor = valor;
    this->proximo = proximo;
    this->anterior = anterior;
}

No::No() {
    this->valor = -1;
    this->proximo = nullptr;
    this->anterior = nullptr;
}

//Funções da Lista
Lista::Lista() {
    this->primeiro = this->ultimo = nullptr;
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
    } else {
        l->primeiro->anterior = novoNo;
    }

    l->primeiro = novoNo;
}

void Lista::inserirFinal(int k, Lista *l) {
    No *novoNo = new No();
    novoNo->valor = k;
    novoNo->anterior = l->ultimo;

    if (isVazia(l)) {
        l->primeiro = novoNo;
    } else {
        l->ultimo->proximo = novoNo;
    }

    l->ultimo = novoNo;
}

Lista *Lista::somaListas(Lista *l1, Lista *l2) {
    Lista *l3 = new Lista();

    int vaiUm = 0;

    No *no1 = l1->ultimo;
    No *no2 = l2->ultimo;

    int soma;
    while (no1 != nullptr && no2 != nullptr) {
        soma = no1->valor + no2->valor + vaiUm;

        if (soma >= 10) {
            soma -= 10;
            vaiUm = 1;
        } else {
            vaiUm = 0;
        }

        inserirInicio(soma,l3);
        no1 = no1->anterior;
        no2 = no2->anterior;
    }

    while (no1 != nullptr) {
        soma = no1->valor + vaiUm;

        if (soma >= 10) {
            soma -= 10;
            vaiUm = 1;
        } else {
            vaiUm = 0;
        }

        inserirInicio(soma,l3);
        no1 = no1->anterior;
    }

    while (no2 != nullptr) {
        soma = no2->valor + vaiUm;

        if (soma >= 10) {
            soma -= 10;
            vaiUm = 1;
        } else {
            vaiUm = 0;
        }

        inserirInicio(soma,l3);
        no2 = no2->anterior;
    }

    if(vaiUm==1) {
        inserirInicio(1,l3);
    }


    return l3;
}

void Lista::imprimir(Lista *l) {
    No *no = l->primeiro;

    while (no != nullptr) {
        cout << no->valor;
        no = no->proximo;
    }
    cout <<endl;
}

bool Lista::isVazia(Lista *l) {
    return l->primeiro == l->ultimo && l->primeiro == nullptr;
}

string Lista::stringfy(Lista *l) {
    No* no = l->primeiro;
    string s = "";
    while(no!=nullptr) {
        s+=to_string(no->valor);
        no=no->proximo;
    }
    return s;
}
