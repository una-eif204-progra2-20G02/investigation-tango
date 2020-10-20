//
// Created by Steph on 20/10/2020.
//

#pragma once
#include "Lista.h"
#include "Curso.h"

class CursoManager
{
private:
    Lista<Curso>* _cursos;
public:
    CursoManager();
    virtual ~CursoManager();
    virtual void agregarCurso(Curso*);
    virtual Curso* buscarCurso(int);
    virtual string  mostrarCursos();

};