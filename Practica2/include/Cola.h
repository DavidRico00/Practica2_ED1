#ifndef COLA_H
#define COLA_H

#include "Comun.h"

struct TNodo_Cola
{
   Jugador Datos;           //Datos a almacenar en cada nodo
   TNodo_Cola *Siguiente;   //Puntero al siguiente nodo
};

class Cola
{
private:
    TNodo_Cola *Inicio; //Puntero al inicio de la cola.
    TNodo_Cola *Fin;    //Puntero al fin de la cola.
    int ne;             //nº de nodos que tiene la lista

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
