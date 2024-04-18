#include <iostream>
#include "Lista.h"

using namespace std;


Lista *construirPalindromo(bool *ehPalindromo);

int main() {
    long seed = time(NULL);
    srand(seed);
    char frase[] = {'a','r','a','r','a'};

    bool deveSerPalindromo, ehPalindromo = false;

    //Lista *l1 = construirPalindromo(&deveSerPalindromo);
    Lista *l1 = new Lista();

    for(int i=0;i<5;i++) {
        l1->inserirInicio(frase[i], l1);
    }

    ehPalindromo = Lista::ehPalindromo(l1);

    if (ehPalindromo) {
        cout << "De fato é palindromo" << endl;
    } else {
        cout << "Não é palindromo" << endl;
    }


    Lista::imprimir(l1);


    delete l1;

    for (int j = 0; j < 10000; j++) {
    }

    cout << "TERMINADO" << endl;
    return 0;
}

