#ifndef COLA_H
#define COLA_H

#include "Comun.h"

struct TNodo_Cola
{
   Jugador Datos;
   TNodo_Cola *Siguiente;
};

class Cola
{
private:
    TNodo_Cola *Inicio;
    TNodo_Cola *Fin;
    int ne;

public:
    Cola();
    ~Cola();
    void encolar(Jugador e);
    void desencolar();
    bool esvacia();
    Jugador primero();
    int longitud();
};

#endif // COLA_H
