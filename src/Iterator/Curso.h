//
// Created by Steph on 20/10/2020.
//

#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Curso
{
private:
    int _nrc;
    string _codigo;
    string _descripcion;
public:
    Curso(int = 0,string= " ",string = " ");
    virtual ~Curso();
    virtual string toString() const;
    virtual int getNRC() const;

};

