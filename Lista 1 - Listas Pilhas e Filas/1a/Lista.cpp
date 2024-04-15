//
// Created by Rafael on 13/04/2024.
//

#include "Lista.h"


//Funções do Nó
No::No(int valor, No *proximo, No *anterior) {
    this->valor=valor;
    this->proximo=proximo;
    this->anterior=anterior;
}

No::No() {
    this->valor=-1;
    this->proximo=nullptr;
    this->anterior=nullptr;
}

//Funções da Lista
Lista::Lista() {
    this->primeiro=this->ultimo=nullptr;
}

Lista::~Lista() {
    No* no=this->primeiro;
    while(no!=nullptr) {
        no = this->primeiro;
        this->primeiro = this->primeiro->proximo;
        delete no;
    }
}

No* Lista::contido(int k, Lista *l) {
    No* no = l->primeiro;

    while(no!=nullptr && no->valor!=k) {
        no=no->proximo;
    }

    return no;
}

void Lista::inserir(int k, Lista *l) {

    No* no = contido(k,l);

    if(no==nullptr) {

        No* novoNo = new No();
        novoNo->valor = k;
        novoNo->anterior = l->ultimo;

        if(isVazia(l)) {
            l->primeiro = novoNo;
        }else {
            l->ultimo->proximo = novoNo;
        }

        l->ultimo = novoNo;

    }else {
        cout<<"A chave já está na lista"<<endl;
    }

}

void Lista::remover(int k, Lista *l) {

    if(!isVazia(l)) {

        No* no = contido(k,l);

        if(no!=nullptr) {

            if(no->anterior == nullptr && no->proximo == nullptr) {
                l->primeiro = l->ultimo = nullptr;

            }else {

                if(no->anterior!=nullptr) {
                    no->anterior->proximo = no->proximo;
                }else {
                    l->primeiro = l->primeiro->proximo;
                    l->primeiro->anterior = nullptr;
                }

                if(no->proximo!=nullptr) {
                    no->proximo->anterior = no->anterior;
                }else {
                    l->ultimo = l->ultimo->anterior;
                    l->ultimo->proximo = nullptr;
                }

            }

            delete no;

            cout<<"Chave "<<k<<"  removida"<<endl;

        }else {
            cout<<"A chave não está na lista"<<endl;
        }
    }else {
        cout<<"A lista está vazia"<<endl;
    }
}

void Lista::imprimir(Lista *l) {
    No* no = l->primeiro;

    cout<<"I -> ";
    while(no!=nullptr) {
        cout<<no->valor<<" | ";
        no = no->proximo;
    }
    cout<<" F "<<endl;
}

bool Lista::isVazia(Lista *l) {
    return l->primeiro == l->ultimo && l->primeiro == nullptr;
}


