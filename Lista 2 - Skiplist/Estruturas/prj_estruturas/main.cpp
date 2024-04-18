#include <iostream>
#include <fstream>
#include <vector>

#include "Lista.h"

using namespace std;

Lista *importarDados();

int main() {
    importarDados();
    return 0;
}

Lista *importarDados() {
    Lista *l = new Lista();

    ifstream arq;
    string s = "titanic3.csv";

    arq.open(s.c_str());

    vector<string> termos;

    while (getline(arq, s, ';')) {
        termos.push_back(s);
    }

    for (int i = 14; i < termos.size(); i += 14) {
        Passenger *p = new Passenger();
        p->pclass = stoi(termos.at(i));
        p->survived = stoi(termos.at(i + 1));
        p->name = termos.at(i + 2);
        p->sex = termos.at(i + 3);
        if (termos.at(i + 4) != "") {
            p->age = stoi(termos.at(i + 4));
        }
        if (termos.at(i + 5) != "") {
            p->sibsp = stoi(termos.at(i + 5));
        }
        if (termos.at(i + 6) != "") {
            p->parch = stoi(termos.at(i + 6));
        }
        if (termos.at(i + 7) != "") {
            p->ticket = termos.at(i + 7);
        }
        if (termos.at(i + 8) != "") {
            p->fare = stod(termos.at(i + 8));
        }
        p->cabin = termos.at(i + 9);
        p->embarked = termos.at(i + 10)[0];
        p->boat = termos.at(i + 11);
        if (termos.at(i + 12) != "") {
            p->body = stoi(termos.at(i + 12));
        }
        p->homeDest = termos.at(i + 13);

    p->print();

        Lista::inserirFinal(p, l);
    }


    arq.close();


    return l;
}
