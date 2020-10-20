set(BINARY ${Project-01})

# add_executable(ExampleProject main.cpp file1.cpp file1.h)
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp) #simplification

set(SOURCES ${SOURCES})

add_executable(${BINARY}investigacion ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES} VectorNumero.h EstrategiaAlgoritmica.h Numero.h Iterator/ Iterator/Curso.cpp Iterator/Curso.h Iterator/Iterador.h Iterator/Lista.h Iterator/Nodo.h Iterator/IteradorLista.h Iterator/CursoManager.cpp Iterator/CursoManager.h)

