//
// Created by Rafael on 18/04/2024.
//

#ifndef SKIPLIST_H
#define SKIPLIST_H
#define DUMMY -1

class No {
public:
    No();
    ~No();

    No* prox;
    No* desce;
    int x;

};

class Skiplist {
public:
    Skiplist();
    ~Skiplist();

    No* head;

    static bool contido(No* head, int k);
    static int contaMenores(No* head, int x);
};



#endif //SKIPLIST_H
