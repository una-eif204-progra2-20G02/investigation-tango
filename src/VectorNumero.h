//
// Created by Steph on 19/10/2020.
//

#pragma once
#include "EstrategiaAlgoritmica.h"
using namespace std;

class VectorNumero {
private:
    Numero * vec[20];
    int cantidad;
    int tamano;

public:
    VectorNumero();
    VectorNumero(VectorNumero&);
    virtual~VectorNumero();
    bool ingresaValor(Numero&);
    string toString();
    VectorNumero* activaClasificacion(EstrategiaAlgoritmica*);

};

VectorNumero::VectorNumero() {
    cantidad = 0;
    tamano = 20;
    for (int i = 0; i < tamano; i++)
        vec[i] = NULL;
}

VectorNumero::~VectorNumero() {
    for (int i = 0; i < cantidad; i++)
        delete vec[i];
}

bool VectorNumero::ingresaValor(Numero& obj) {
    if (cantidad < tamano) {
        vec[cantidad++] = (Numero*)&obj;
        return true;
    }
    return false;
}

string VectorNumero::toString() {
    stringstream s;
    for (int i = 0; i < cantidad; i++)
        s << vec[i]->toString() << endl;
    return s.str();
}

VectorNumero* VectorNumero::activaClasificacion(EstrategiaAlgoritmica* estrategia) {
    VectorNumero* CO2 = new VectorNumero();
    for (int i = 0; i < cantidad; i++) {
        if (estrategia->evaluaNumero(vec[i]) == true) {
            Numero* n = new Numero(vec[i]->getValor()); // Copiar numero del Contenedor
            CO2->ingresaValor(*n);
        }
    }
    return CO2;
}