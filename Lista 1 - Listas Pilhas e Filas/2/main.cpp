#include <iostream>
#include "Lista.h"

using namespace std;


void testarSoma(Lista* l1, Lista* l2, Lista* l3);

int main() {
    long seed = time(NULL);
    srand(seed);

    for(int j=0;j<10000;j++) {
        Lista *l1 = new Lista();
        Lista *l2 = new Lista();

        for(int i=0;i<8;i++) {
            Lista::inserirFinal(rand()%10,l1);
        }
        for(int i=0;i<8;i++) {
            Lista::inserirFinal(rand()%10,l2);
        }

        Lista::imprimir(l1);
        cout<<"+"<<endl;
        Lista::imprimir(l2);

        Lista* l3 = Lista::somaListas(l1,l2);

        for(int i=0;i<10;i++) {
            cout<<"_";
        }
        cout<<endl;
        Lista::imprimir(l3);

        testarSoma(l1,l2,l3);

        delete l1;
        delete l2;
        delete l3;
    }

    cout << "TERMINADO" << endl;
    return 0;
}

void testarSoma(Lista* l1, Lista* l2, Lista* l3) {

    long v1 = stol(Lista::stringfy(l1));
    long v2 = stol(Lista::stringfy(l2));
    long v3 = stol(Lista::stringfy(l3));

    long resultado = v1 + v2;

    if(resultado == v3) {
        cout<<"Soma Correta"<<endl;
    }else {
        cout<<"Soma errada"<<endl;
        exit(11);
    }

}