//
// Created by Steph on 20/10/2020.
//

#include "Curso.h"
#include "curso.h"
Curso::Curso(int nrc, string codigo, string descripcion)
{
    _nrc = nrc;
    _codigo = codigo;
    _descripcion = descripcion;
}
//-------------------------------------------------
Curso::~Curso(){}
//-------------------------------------------------
int Curso::getNRC() const
{	return _nrc;}
//-------------------------------------------------
string Curso::toString() const
{
    stringstream r;
    r << "NRC : " << _nrc <<endl;
    r << "Codigo : " << _codigo <<endl;
    r << "Descripcion : " << _descripcion <<endl;
    return r.str();
}
