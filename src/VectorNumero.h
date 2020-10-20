//
// Created by Steph on 19/10/2020.
//

#pragma once
#include "EstrategiaAlgoritmica.h"
using namespace std;

class VectorNumero {
private:
    Numero * vec[20];
    int can;
    int tam;

public:
    VectorNumero();
    VectorNumero(VectorNumero&);
    virtual~VectorNumero();
    bool ingresaValor(Numero&);
    string toString();
    VectorNumero* activaClasificacion(EstrategiaAlgoritmica*);

};

VectorNumero::VectorNumero() {
    can = 0;
    tam = 20;
    for (int i = 0; i < tam; i++)
        vec[i] = NULL;
}

VectorNumero::~VectorNumero() {
    for (int i = 0; i < can; i++)
        delete vec[i];
}

bool VectorNumero::ingresaValor(Numero& obj) {
    if (can < tam) {
        vec[can++] = (Numero*)&obj;
        return true;
    }
    return false;
}

string VectorNumero::toString() {
    stringstream s;
    for (int i = 0; i < can; i++)
        s << vec[i]->toString() << endl;
    return s.str();
}

VectorNumero* VectorNumero::activaClasificacion(EstrategiaAlgoritmica* est) {
    VectorNumero* CO2 = new VectorNumero();
    for (int i = 0; i < can; i++) {
        if (est->evaluaNumero(vec[i]) == true) {
            Numero* n = new Numero(vec[i]->getValor()); // Copiar numero del Contenedor
            CO2->ingresaValor(*n);
        }
    }
    return CO2;
}