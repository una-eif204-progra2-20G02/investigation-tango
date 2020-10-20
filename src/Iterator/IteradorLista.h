//
// Created by Steph on 20/10/2020.
//

#pragma once
#include "Nodo.h"
#include "Iterador.h"

template <class T>
class IteradorLista : public Iterador <T>{

private:
    Nodo<T>* cursor;
    Nodo<T>* primero;
public:
    IteradorLista(Nodo<T>*);
    bool hayElementos() const;
    void proximoElemento();
    T*  obtenerElemento();
    void irPrimero() ;
};
//-------------------------------------------------
template <class T>
IteradorLista<T>::IteradorLista(Nodo<T>* primerNodo){
    cursor = primerNodo;
    primero = primerNodo;
}
//-------------------------------------------------
template <class T>
bool IteradorLista<T>::hayElementos() const {
    return (cursor != NULL);// retorna true  si hay mas elementos
    // retorna false si no
}
//-------------------------------------------------
template <class T>
void IteradorLista<T>::proximoElemento() {
    cursor = cursor->obtenerSiguiente();
}

//-------------------------------------------------
template <class T>
T* IteradorLista<T>::obtenerElemento() {
    T* r = NULL;
    if (hayElementos()) { // si hay mas elementos
        r = cursor->obtenerInfo();
    }
    return r;
}
//-------------------------------------------------
template <class T>
void IteradorLista<T>::irPrimero() {
    cursor = primero;
}