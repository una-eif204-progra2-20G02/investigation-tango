//
// Created by Steph on 19/10/2020.
//

#pragma once
// ---- Declaracion de la Jerarquia.

#include "Numero.h"
using namespace std;

class EstrategiaAlgoritmica { // Clase Abstracta
public:
    EstrategiaAlgoritmica() {}
    virtual ~EstrategiaAlgoritmica() {}
    virtual bool evaluaNumero(Numero*) = 0; // M.V.P
};

// Herencias:

class EstrategiaEstablecerPrimos : public EstrategiaAlgoritmica {
public:
    EstrategiaEstablecerPrimos() {}
    bool evaluaNumero(Numero* Numptr) { // Determina si es primo...
        for (int i = 2; i < Numptr->getValor() - 1; i++)
            if (Numptr->getValor() % i == 0)
                return false;
        return true;
    }
};

class EstrategiaEstablecerImpares : public EstrategiaAlgoritmica {
public:
    EstrategiaEstablecerImpares() {}
    bool evaluaNumero(Numero* Numptr) { // Determina si es impar...
        if (Numptr->getValor() % 2 != 0)
            return true;
        return false;
    }
};