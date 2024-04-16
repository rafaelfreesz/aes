#include <iostream>
#include "Pilha.h"

using namespace std;

int main() {
    long seed =time(NULL);
    srand(seed);

    Pilha *l = new Pilha();

    //Testando Inserções
    int k;
    for (int i = 0; i < 10; i++) {
        k = rand() % 20;
        Pilha::inserir(k, l);
        Pilha::imprimir(l);
    }

    //Testando remoções
    Pilha::imprimir(l);
    No* no;
    while (!Pilha::isVazia(l)) {
        no = Pilha::remover(l);
        cout << "Removido da pilha chave " << no->valor << endl;
        delete no;
        Pilha::imprimir(l);
    }

    delete l;

    //Sequencia aleatória de operações
    cout<<"Eventos aleatorios:"<<endl;
    l = new Pilha();

    for(int i=0;i<100 || !Pilha::isVazia(l);i++) {

        if(Pilha::isVazia(l) || rand()%10<4) {
            k = rand()%100;
            cout << "Inserindo na pilha chave " << k << endl;
            Pilha::inserir(k,l);
        }else {
            no = Pilha::remover(l);
            cout << "Removido da pilha chave " << no->valor << endl;
            delete no;
        }

        Pilha::imprimir(l);
    }

    delete l;

    cout << "TERMINADO" << endl;
    return 0;
}
