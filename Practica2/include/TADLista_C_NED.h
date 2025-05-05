#ifndef TADLISTA_C_NED_H
#define TADLISTA_C_NED_H

#include "Comun.h"

struct TNodo_Lista
{
  Jugador Datos;
  TNodo_Lista *Anterior;
  TNodo_Lista *Siguiente;
};

class Lista
{
private:
    TNodo_Lista *elementos;
    int numElementos;

public:
    Lista();
    Lista(Jugador e);
    ~Lista();
    bool esvacia();
    int longitud();
    void anadirIzq(Jugador e);
    void anadirDch(Jugador e);
    void eliminarIzq();
    void eliminarDch();
    Jugador observarIzq();
    Jugador observarDch();
    void concatenar(Lista l);
    bool pertenece(Jugador e);
    void insertar(int i, Jugador e);
    void eliminar(int i);
    void modificar(int i, Jugador e);
    Jugador observar(int i);
    int posicion(Jugador e);
};


#endif // TADLISTA_C_NED_H
