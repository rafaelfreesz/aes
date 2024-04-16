#include <iostream>
#include "Fila.h"

using namespace std;

int main() {
    long seed =time(NULL);
    srand(seed);

    Fila *l = new Fila();

    //Testando Inserções
    int k;
    for (int i = 0; i < 10; i++) {
        k = rand() % 20;
        Fila::inserir(k, l);
        Fila::imprimir(l);
    }

    //Testando remoções
    Fila::imprimir(l);
    No* no;
    while (!Fila::isVazia(l)) {
        no = Fila::remover(l);
        cout << "Removido da fila chave " << no->valor << endl;
        delete no;
        Fila::imprimir(l);
    }

    delete l;

    //Sequencia aleatória de operações
    cout<<"Eventos aleatorios:"<<endl;
    l = new Fila();

    for(int i=0;i<100 || !Fila::isVazia(l);i++) {

        if(Fila::isVazia(l) || rand()%10<3) {
            k = rand()%100;
            cout << "Inserindo na fila chave " << k << endl;
            Fila::inserir(k,l);
        }else {
            no = Fila::remover(l);
            cout << "Removido da fila chave " << no->valor << endl;
            delete no;
        }

        Fila::imprimir(l);
    }

    delete l;

    cout << "TERMINADO" << endl;
    return 0;
}
