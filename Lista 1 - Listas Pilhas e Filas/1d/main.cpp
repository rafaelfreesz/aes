#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
    long seed =1;// time(NULL);
    srand(seed);

    Lista *l = new Lista();

    //Testando Inserções
    int k;
    for (int i = 0; i < 10; i++) {
        k = rand() % 20;
        Lista::inserir(k, l);
        Lista::imprimir(l);
    }

    //Testando consultas

    No *no;
    for (int i = 0; i < 10; i++) {
        k = rand() % 20;
        no = Lista::contido(k, l);

        if (no->valor != DUMMY) {
            cout << "O nó " << k << " está na lista" << endl;
        } else {
            cout << "O nó " << k << " nao está na lista" << endl;
        }

    }

    //Testando remoções
    Lista::imprimir(l);
    while (!Lista::isVazia(l)) {
        k = rand() % 20;
        if (k==0) {
            cout<<"zero ";
        }
        cout << "Removendo chave " << k << endl;
        Lista::remover(k, l);
        Lista::imprimir(l);
    }

    delete l;

    //Sequencia aleatória de operações
    cout<<"Eventos aleatorios:"<<endl;
    l = new Lista();

    for(int i=0;i<100 || !Lista::isVazia(l);i++) {

        if(Lista::isVazia(l) || rand()%10<4) {
            k = rand()%100;
            cout << "Inserindo na lista chave " << k << endl;
            Lista::inserir(k,l);
        }else {
            Lista::remover(k,l);
        }

        Lista::imprimir(l);
    }

    delete l;

    cout << "TERMINADO" << endl;
    return 0;
}
