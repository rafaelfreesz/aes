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
    this->primeiro = new No();
    this->primeiro->valor = DUMMY;
    this->primeiro->proximo = this->primeiro->anterior = this->primeiro;


    this->ultimo=this->primeiro;
}

Lista::~Lista() {
    No* no=this->primeiro->proximo;
    while(no!=this->primeiro) {
        no = this->primeiro;
        this->primeiro = this->primeiro->proximo;
        delete no;
    }
    delete this->primeiro;
}


bool Lista::isVazia(Lista *l) {
    return l->primeiro->proximo == l->primeiro;
}

No* Lista::contido(int k, Lista *l) {
    l->primeiro->valor = k;
    No* no = l->primeiro->proximo;

    while(no->valor!=k) {
        no=no->proximo;
    }

    l->primeiro->valor = DUMMY;

    return no;
}

void Lista::inserir(int k, Lista *l) {

    No* no = contido(k,l);

    if(no->valor==DUMMY) {
        No *novoNo = new No();
        novoNo->valor = k;
        novoNo->anterior = l->ultimo;
        novoNo->proximo = l->ultimo->proximo;

        l->ultimo->proximo = novoNo;
        l->ultimo = novoNo;
    } else {
        l->primeiro->valor = DUMMY;
        cout << "A chave já está na lista" << endl;
    }
}

void Lista::remover(int k, Lista *l) {

    if(!isVazia(l)) {

        No* no = contido(k,l);

        if(no->valor!=DUMMY) {

            no->anterior->proximo = no->proximo;
            no->proximo->anterior = no->anterior;

            if(no->anterior == l->primeiro && no->proximo == l->primeiro) { //É o unico nó?
                l->ultimo = l->primeiro;
            }else {
                if(no == l->ultimo) { //É o ultimo nó?
                    l->ultimo = no->anterior;
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

    cout<<"I -> "<<no->valor <<" | ";
    no=no->proximo;
    while(no!=l->primeiro) {
        cout<<no->valor<<" | ";
        no = no->proximo;
    }
    cout<<" F "<<endl;
}



