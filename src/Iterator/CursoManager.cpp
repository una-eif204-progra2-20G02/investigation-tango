//
// Created by Steph on 20/10/2020.
//

#include "CursoManager.h"

CursoManager::CursoManager(){ _cursos = new Lista<Curso>();}
//-------------------------------------------------
CursoManager::~CursoManager()
{
    _cursos->eliminarTodos();
    delete _cursos;
}
//-------------------------------------------------
void CursoManager::agregarCurso(Curso* c)
{
    _cursos->agregarFinal(c);
}

//-------------------------------------------------
string  CursoManager::mostrarCursos(){
    return  _cursos->toString();
}
//-------------------------------------------------
Curso* CursoManager::buscarCurso(int nrc)
{
// Este método  no lo metemos en la clase lista para no
// volverla específica.

// Aquí usamos el iterador, para que este sea el que desencapsule la lista y exponga lo que hay dentro

    if (!_cursos->vacio()) {
        IteradorLista <Curso>* i = _cursos->obtenerIterador();
        while (i->hayElementos()) {
            Curso* cur = (Curso*)i->obtenerElemento();
            i->proximoElemento();
            if(cur->getNRC()==nrc)
            {	return cur;}
        }
        delete i;
    }
    return NULL;
}