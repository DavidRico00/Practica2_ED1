#include "TADLista_C_NED.h"

Lista::Lista()
{
    elementos=NULL;
    numElementos=0;
}

Lista::Lista(Jugador e)
{
    TNodo_Lista *aux=new TNodo_Lista;

    aux->Datos=e;
    elementos=aux;
    aux->Siguiente=aux->Anterior=aux;

    numElementos=1;
}

Lista::~Lista()
{
    if(!esvacia())
    {
        while(elementos->Siguiente!=elementos)
        {
            TNodo_Lista *aux=elementos->Siguiente;
            elementos->Siguiente=aux->Siguiente;
            delete aux;
        }

        delete elementos;
        elementos=NULL;
        numElementos=0;
    }
}

bool Lista::esvacia()
{
    return numElementos==0;
}

int Lista::longitud()
{
    return numElementos;
}

void Lista::anadirIzq(Jugador e)
{
    TNodo_Lista *nodo = new TNodo_Lista;
    nodo->Datos=e;

    if(esvacia())
    {
        elementos=nodo;
        nodo->Siguiente=nodo->Anterior=nodo;
    }
    else
    {
        nodo->Anterior=elementos->Anterior;
        elementos->Anterior->Siguiente=nodo;

        elementos->Anterior=nodo;
        nodo->Siguiente=elementos;

        elementos=nodo;
    }
    numElementos++;
}

void Lista::anadirDch(Jugador e)
{
    TNodo_Lista *nodo = new TNodo_Lista;
    nodo->Datos=e;

    if(esvacia())
    {
        elementos=nodo;
        nodo->Anterior=nodo->Siguiente=nodo;
    }
    else
    {
        TNodo_Lista *ultimo=elementos->Anterior;

        elementos->Anterior=nodo;
        nodo->Siguiente=elementos;

        ultimo->Siguiente=nodo;
        nodo->Anterior=ultimo;
    }
    numElementos++;
}

void Lista::eliminarIzq()
{
    if(!esvacia())
    {
        TNodo_Lista *elim=elementos;

        if(numElementos==1)
            elementos=NULL;
        else
        {
            elim->Siguiente->Anterior=elim->Anterior;
            elim->Anterior->Siguiente=elim->Siguiente;
            elementos=elim->Siguiente;
        }
        delete elim;
        numElementos--;
    }
}

void Lista::eliminarDch()
{
    if(!esvacia())
    {
        TNodo_Lista *elim = elementos->Anterior;

        if(numElementos==1)
        {
            elementos=NULL;
        }
        else
        {
            elim->Anterior->Siguiente=elementos;
            elementos->Anterior=elim->Anterior;
        }
        delete elim;
        numElementos--;
    }
}

Jugador Lista::observarIzq()
{
    return elementos->Datos;
}

Jugador Lista::observarDch()
{
    return elementos->Anterior->Datos;
}

void Lista::concatenar(Lista l)
{
    int longitud = l.longitud();
    for(int i=1; i<=longitud; i++)
        anadirDch(l.observar(i));
}

bool Lista::pertenece(Jugador e)
{
    return posicion(e)!=-1;
}

void Lista::insertar(int i, Jugador e)
{
    if(i<1 || i>numElementos+1)
        return;

    if(i==1)
        anadirIzq(e);
    else if(i==numElementos+1)
        anadirDch(e);
    else
    {
        TNodo_Lista *nodo=elementos, *ins = new TNodo_Lista;
        ins->Datos=e;

        for(int j=1; j<i-1; j++)
            nodo=nodo->Siguiente;

        ins->Siguiente=nodo->Siguiente;
        nodo->Siguiente->Anterior=ins;

        nodo->Siguiente=ins;
        ins->Anterior=nodo;

        numElementos++;
    }
}

void Lista::eliminar(int i)
{
    if(i<1 || i>numElementos)
        return;

    if(i==1)
        eliminarIzq();
    else if(i==numElementos)
        eliminarDch();
    else
    {
        TNodo_Lista *elim=elementos;

        for(int j=1; j<i; j++)
            elim=elim->Siguiente;

        elim->Anterior->Siguiente=elim->Siguiente;
        elim->Siguiente->Anterior=elim->Anterior;

        delete elim;
        numElementos--;
    }
}

void Lista::modificar(int i, Jugador e)
{
    if(i<1 || i>numElementos)
        return;

    TNodo_Lista *nodo=elementos;

    for(int j=1; j<i; j++)
        nodo=nodo->Siguiente;

    nodo->Datos=e;
}

Jugador Lista::observar(int i)
{
    TNodo_Lista *nodo=elementos;

    for(int j=1; j<i; j++)
        nodo=nodo->Siguiente;

    return nodo->Datos;
}

int Lista::posicion(Jugador e)
{
    TNodo_Lista *nodo = elementos;

    for(int i=1; i<=numElementos; i++)
    {
        if(strcmp(nodo->Datos.nombreJugador, e.nombreJugador)==0)
            return i;
        else
            nodo=nodo->Siguiente;
    }

    return -1;
}

