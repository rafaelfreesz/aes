//
// Created by Rafael on 18/04/2024.
//

#include "Skiplist.h"

//Funções do No;
No::No() {
    this->desce = nullptr;
    this->prox = nullptr;
    this->x = DUMMY;
}


//Funções da Lista;
Skiplist::Skiplist() {
    this->head = nullptr;
}

Skiplist::~Skiplist() {
    if(this->head!=nullptr) {
        delete this->head;
    }
}

bool Skiplist::contido(No *head, int k) {

    No* no = head;
    while(no->desce!=nullptr) {

        if (no->prox->x < k) {
            no = no->prox;
        }else {
            no = no->desce;
        }

    }

    no = no->prox;
    if(no->x == k) {
        return true;
    }else {
        return false;
    }
}

int Skiplist::contaMenores(No *head, int x) {

    No* no = head;
    int count = 0;
    while(no->desce!=nullptr) {

        if (no->prox->x < k) {
            no = no->prox;
        }else {
            no = no->desce;
        }

    }


}


