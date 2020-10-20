//
// Created by Steph on 20/10/2020.
//

#pragma once
template <class T>

class Nodo {
private:
    T * info;
    Nodo<T>* siguiente;

public:
    Nodo(T*, Nodo<T>*);
    virtual ~Nodo();
    virtual T* obtenerInfo() const;
    virtual Nodo<T>* obtenerSiguiente() const;
    virtual void fijarSiguiente(Nodo<T>*);
};

template <class T>
Nodo<T>::Nodo(T* nuevaInfo, Nodo<T>* siguiente) {
    info = nuevaInfo;
    this->siguiente = siguiente;
}
//-------------------------------------------------
template <class T>
Nodo<T>::~Nodo() {}
//-------------------------------------------------
template <class T>
T* Nodo<T>::obtenerInfo() const { return info;}
//-------------------------------------------------
template <class T>
Nodo<T>* Nodo<T>::obtenerSiguiente() const { return siguiente;}
//-------------------------------------------------
template <class T>
void Nodo<T>::fijarSiguiente(Nodo<T>* siguiente)
{  this->siguiente = siguiente;}