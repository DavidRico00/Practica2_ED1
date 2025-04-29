#ifndef LISTA_H
#define LISTA_H

#include "Comun.h"

struct TNodo_Lista
{
  Jugador Datos;            // Dato a almacenar en cada nodo
  TNodo_Lista *Siguiente;   // Puntero al siguiente nodo
};

class Lista
{
private:
    TNodo_Lista *elementos;         // Puntero al primer nodo de la lista.
    int  n;                         // nº de nodos que tiene la lista

    TNodo_Lista *Anterior(int i);   /* Devuelve un puntero al elemento anterior al elemento i
                                    Devuelve NULL si es el primero */

public:
    Lista();
    Lista(Jugador e);
    ~Lista();
    bool esvacia();
    int longitud();
    void anadirIzq(Jugador e);          //
    void anadirDch(Jugador e);          //
    void eliminarIzq();                 //
    void eliminarDch();                 //      FALTA
    Jugador observarIzq();              //
    Jugador observarDch();              //
    void concatenar(Lista l);           //
    bool pertenece(Jugador e);          //
    void insertar(int i, Jugador e);
    void eliminar(int i);
    void modificar(int i, Jugador e);
    Jugador observar(int i);
    int posicion(Jugador e);
};

#endif // LISTA_H
