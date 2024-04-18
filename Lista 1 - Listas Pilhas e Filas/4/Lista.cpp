//
// Created by Rafael on 13/04/2024.
//

#include "Lista.h"


//Funções do Nó
No::No(char valor, No *proximo, No *anterior) {
    this->valor = valor;
    this->proximo = proximo;
}

No::No() {
    this->valor = '\0';
    this->proximo = nullptr;
}

//Funções da Lista
Lista::Lista() {
    this->primeiro = this->ultimo = nullptr;
    this->tam=0;
}

Lista::~Lista() {
    No *no;
    while (this->primeiro != nullptr) {
        no = this->primeiro;
        this->primeiro = this->primeiro->proximo;
        delete no;
    }
}

void Lista::inserirInicio(char k, Lista *l) {
    No *novoNo = new No();
    novoNo->valor = k;
    novoNo->proximo = l->primeiro;

    if (isVazia(l)) {
        l->ultimo = novoNo;
    }

    l->primeiro = novoNo;
    l->tam++;
}

void Lista::inserirFinal(char k, Lista *l) {
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

bool Lista::ehPalindromo(Lista *l) {
    Lista *l2 = new Lista();
    Lista* l3 = new Lista();

    //Passando a primeira metade de L1 para a lista de retorno
    No* no = l->primeiro;
    for(int i = 0; i < l->getTam()/2; i++) {
        inserirFinal(no->valor,l2);
        no = no->proximo;
    }

    bool par = l->getTam()%2 == 0;

    if(!par) {
        no = no->proximo;
    }

    //Passando a segunda metade de L1 para uma lista auxiliar em ordem infertida arara
    for(int i = par ? l->getTam()/2 : l->getTam()/2+1 ; i < l->getTam() ; i++) {
        inserirInicio(no->valor,l3);
        no = no -> proximo;
    }

    No* no2 = l2->primeiro;
    no = l3->primeiro;

    //Somando o conteudo invertido da lista auxiliar para a lista de retorno
    while(no2!=nullptr) {
        if(no->valor != no2->valor) {
            delete l2;
            delete l3;
            return false;
        }
        no2 = no2->proximo;
        no = no->proximo;
    }

    delete l2;
    delete l3;
    return true;
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
