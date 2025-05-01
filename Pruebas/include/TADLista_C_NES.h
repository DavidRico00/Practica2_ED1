#ifndef TADLISTA_C_NES_H
#define TADLISTA_C_NES_H

//TAD Lista Circular implementado con Nodos Enlazados Simple


#include <iostream>
using namespace std;

struct TNodo_Lista
{
    float Datos;
    TNodo_Lista *Siguiente;
};

class Lista_C_NES
{
private:
    TNodo_Lista *elementos;
    int  numElementos;

public:
    Lista_C_NES();
    ~Lista_C_NES();
    Lista_C_NES(float e);
    bool esvacia();
    int longitud();
    void anadirIzq(float e);
    void anadirDch(float e);
    void eliminarIzq();
    void eliminarDch();
    float observarIzq();
    float observarDch();
    void concatenar(Lista_C_NES l);
    bool pertenece(float e);
    void insertar(int i, float e);
    void eliminar(int i);
    void modificar(int i, float e);
    float observar(int i);
    int posicion(float e);
};

#endif // TADLISTA_C_NES_H
