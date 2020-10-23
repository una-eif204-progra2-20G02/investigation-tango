//
// Created by Steph on 20/10/2020.
//

#pragma once

template <class T>
class Iterador {

public:
    virtual bool hayElementos() const = 0;
    virtual  void proximoElemento() = 0;
    virtual  T* obtenerElemento() = 0;
    virtual  void irPrimero() = 0;
};