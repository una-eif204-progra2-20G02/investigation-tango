//
// Created by Steph on 19/10/2020.
//
#include<iostream>

#include "VectorNumero.h"

using namespace std;

int main() {

    VectorNumero* vector = new VectorNumero();
    VectorNumero* vectorImpares = NULL;
    VectorNumero* vectorPrimos = NULL;

    int cant, valor;
    cout << "Ingrese la cantidad de valores que va a contener el vector: ";
    cin >> cant;
    cout << endl;
    for (int i = 0; i < cant; i++) {
        cout << "Ingrese el Valor numerico: ";
        cin >> valor;
        vector->ingresaValor(*new Numero(valor));
        cout << endl;
    }
    cout << "----------------------------------------------\n";
    cout << "El contenedor original queda como: \n";
    cout << endl;
    cout << vector->toString();
    cout << "----------------------------------------------\n";
    cout << endl;

    // Estrategia de impares...
    vectorImpares = vector->activaClasificacion(new EstrategiaEstablecerImpares());
    cout << "----------------------------------------------\n";
    cout << "El contenedor con solo impares queda como: \n";
    cout << endl;
    cout << vectorImpares->toString();
    cout << "----------------------------------------------\n";
    cout << endl;

    // Estrategia de primos...
    vectorPrimos = vector->activaClasificacion(new EstrategiaEstablecerPrimos());
    cout << "----------------------------------------------\n";
    cout << "El contenedor con solo primos queda como: \n";
    cout << endl;
    cout << vectorPrimos->toString();
    cout << "----------------------------------------------\n";
    cout << endl;

    cout << endl;
    system("pause");
    return 0;




}