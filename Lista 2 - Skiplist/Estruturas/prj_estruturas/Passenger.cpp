//
// Created by Rafael on 18/04/2024.
//

#include "Passenger.h"

Passenger::Passenger() {
    this->pclass = EMPTY_INT;
    this->age = EMPTY_INT;
    this->sibsp = EMPTY_INT;
    this->parch = EMPTY_INT;
    this->body = EMPTY_INT;
    this->name = EMPTY_STRING;
    this->sex = EMPTY_STRING;
    this->ticket = EMPTY_STRING;
    this->cabin = EMPTY_STRING;
    this->boat = EMPTY_STRING;
    this->homeDest = EMPTY_STRING;
    this->embarked = EMPTY_STRING;
    this->survived = EMPTY_BOOL;
    this->fare = EMPTY_INT;
}

Passenger::~Passenger() {
}

void Passenger::print() {

    cout<<"{"<<endl;
    cout<<"         "<<"pclass: "<<this->pclass<<endl;
    cout<<"         "<<"survived: "<<this->survived<<endl;
    cout<<"         "<<"name: "<<this->name<<endl;
    cout<<"         "<<"sex: "<<this->sex<<endl;
    cout<<"         "<<"age: "<<this->age<<endl;
    cout<<"         "<<"sibsp: "<<this->sibsp<<endl;
    cout<<"         "<<"parch: "<<this->parch<<endl;
    cout<<"         "<<"ticket: "<<this->ticket<<endl;
    cout<<"         "<<"fare: "<<this->fare<<endl;
    cout<<"         "<<"cabin: "<<this->cabin<<endl;
    cout<<"         "<<"embarked: "<<this->embarked<<endl;
    cout<<"         "<<"boat: "<<this->boat<<endl;
    cout<<"         "<<"body: "<<this->body<<endl;
    cout<<"         "<<"homeDest: "<<this->homeDest<<endl;
    cout<<"}"<<endl;
}
