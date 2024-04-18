//
// Created by Rafael on 18/04/2024.
//

#ifndef PASSENGER_H
#define PASSENGER_H
#define EMPTY_INT -1;
#define EMPTY_STRING '\0';
#define EMPTY_BOOL false;

#include <iostream>

using namespace std;


class Passenger {
public:

    Passenger();
    ~Passenger();

    int pclass;
    bool survived;
    string name;
    string sex;
    int age;
    int sibsp;
    int parch;
    string ticket;
    double fare;
    string cabin;
    char embarked;
    string boat;
    int body;
    string homeDest;


    void print();

};



#endif //PASSENGER_H
