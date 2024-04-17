#include <iostream>
#include "Lista.h"

using namespace std;


void testar(Lista* l1, Lista* l2);

int main() {
    long seed = time(NULL);
    srand(seed);

    for(int j=0;j<10000;j++) {
        Lista *l1 = new Lista();

        for(int i=0;i<10;i++) {
            Lista::inserirFinal(rand()%10,l1);
        }
        Lista* l2 = Lista::inverteLista(l1);

        Lista::imprimir(l1);
        Lista::imprimir(l2);

        testar(l1,l2);

        delete l1;
        delete l2;
    }

    cout << "TERMINADO" << endl;
    return 0;
}

void testar(Lista* l1, Lista* l2) {

    if(l1->getTam() == l2->getTam()) {
        int* vL1 = Lista::arrayfy(l1);
        int* vL2 = Lista::arrayfy(l2);

        for (int i=0;i<l1->getTam();i++) {
            if(vL1[i]!=vL2[l1->getTam()-1-i]) {
                cout<<"Deu diferença"<<endl;
                exit(100);
            }
        }

    }else {
        cout<<"tamanhos diferentes"<<endl;
        exit(101);
    }

    cout<<"Deu certo"<<endl;


}