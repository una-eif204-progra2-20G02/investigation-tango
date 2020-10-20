//
// Created by Steph on 20/10/2020.
//

#pragma once
#include <iostream>
#include "Nodo.h"
#include "IteradorLista.h"
#include<sstream>

using namespace std;

template <class T>
class Lista{
private:
    Nodo<T>* primerNodo;
    Nodo<T>* ultimoNodo;
    int k;
public:
    Lista();
    virtual ~Lista();
    virtual bool vacio() const;
    virtual int numElementos() const;
    virtual void eliminarTodos();
    virtual void agregarInicio(T*);
    virtual void agregarFinal(T*);
    virtual IteradorLista <T>* obtenerIterador() const;// crea el itererador especifico
    virtual string toString() const;
};

template <class T>
Lista<T>::Lista() {
    primerNodo = NULL;
    ultimoNodo = NULL;
    k = 0;
}
//-------------------------------------------------

template <class T>
bool Lista<T>::vacio() const {
    return primerNodo == NULL;
}
//-------------------------------------------------
template <class T>
int Lista<T>::numElementos() const { return k;}
//-------------------------------------------------
template <class T>
IteradorLista <T>* Lista<T>::obtenerIterador() const{
    return new IteradorLista <T>(primerNodo);
}
//-------------------------------------------------
template <class T>
void Lista<T>::agregarInicio(T* nuevaInfo) {// agrega al inicio
    // Cuando se agrega un elemento a una lista
    // que está inicialmente vacía, hay que fijar
    // el apuntador al último nodo.
    bool iniciandoLista = vacio();
    primerNodo = new Nodo<T>(nuevaInfo, primerNodo);
    if (iniciandoLista) { ultimoNodo = primerNodo; }
    k++;
}
//-------------------------------------------------
template <class T>
void Lista<T>::eliminarTodos() //Elimina todos los elementos de la lista
{
    if (!vacio()) {
        IteradorLista<T>* i = obtenerIterador(); // aqui usamos el iterador para recorrer la lista
        while (i->hayElementos()) {
            T* e = i->obtenerElemento();
            i->proximoElemento();
            delete e;
        }
        delete i;
        primerNodo = NULL;
        ultimoNodo = NULL;
    }
}
//-------------------------------------------------
// No hace falta recorrer la lista, pues ya se tiene un puntero al nodo final
// Si tuvieramos que recorrer la lista, lo hariamos con el iterador
template <class T>
void Lista<T>::agregarFinal(T* nuevaInfo) {
    if (!vacio()) {
        // Si la lista no está vacía, la operación no afecta al primer nodo, pero se
        //debe actualizar el apuntador al último nodo.
        ultimoNodo->fijarSiguiente(new Nodo <T>(nuevaInfo, NULL));
        ultimoNodo = ultimoNodo->obtenerSiguiente();
        k++;

    } else {
        // Si la lista está vacía, agregar al inicio o al final es la misma operación.
        agregarInicio(nuevaInfo);
    }
}

template <class T>
string Lista<T>::toString() const {
    stringstream output;

    IteradorLista <T>* i = obtenerIterador();
    while (i->hayElementos()) {
        T* e = i->obtenerElemento();
        output << e->toString();
        i->proximoElemento();
    }
    return output.str();
    delete i;
}
//-------------------------------------------------
template <class T>
Lista<T>::~Lista() { eliminarTodos(); }
//-------------------------------------------------