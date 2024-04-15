#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
    long seed = time(NULL);
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

        if (no != nullptr) {
            cout << "O nó " << k << " está na lista" << endl;
        } else {
            cout << "O nó " << k << " nao está na lista" << endl;
        }
    }

    //Testando remoções
    Lista::imprimir(l);
    while (!Lista::isVazia(l)) {
        k = rand() % 20;
        cout << "Removendo chave " << k << endl;
        Lista::remover(k, l);
        Lista::imprimir(l);
    }

    delete l;

    cout << "TERMINADO" << endl;
    return 0;
}
