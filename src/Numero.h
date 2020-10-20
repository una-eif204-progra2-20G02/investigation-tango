//
// Created by Steph on 19/10/2020.
//

#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Numero {
private:
    int valor;
public:
    Numero();
    Numero(int);
    Numero(Numero&);
    virtual ~Numero();
    int getValor();
    string toString();

};

Numero::Numero() { valor = 0; }

Numero::Numero(int x) { valor = x; }

Numero::Numero(Numero& ref) { valor = ref.getValor(); }

Numero::~Numero() {}

int Numero::getValor() { return valor; }

string Numero::toString() {
    stringstream s;
    s << "Valor = " << valor << endl;
    return s.str();
}
