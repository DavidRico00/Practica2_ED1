#include "Cola.h"

Cola::Cola()
{
    Inicio=NULL;
    Fin=NULL;
    ne=0;
}

Cola::~Cola()
{
    TNodo_Cola *Nodo_Borr;
    while (Inicio!=NULL)
    {
        Nodo_Borr=Inicio;
        Inicio=Nodo_Borr->Siguiente;
        delete Nodo_Borr;
    }
    Fin=NULL;
    ne=0;
}

void Cola::encolar(Jugador e)
{
    TNodo_Cola *Nodo_Aux=new TNodo_Cola;
    if (Nodo_Aux!=NULL)
    {
        Nodo_Aux->Datos=e;
        Nodo_Aux->Siguiente=NULL;
        if (Inicio!=NULL)
            Fin->Siguiente=Nodo_Aux;
        else
            Inicio=Nodo_Aux;
        Fin=Nodo_Aux;
        ne++;
    }
}

void Cola::desencolar()
{
    TNodo_Cola *Nodo_Aux=Inicio;
    Inicio=Nodo_Aux->Siguiente;
    delete Nodo_Aux;
    ne--;
    if (ne == 0)
        Fin = NULL;
}

Jugador Cola::primero()
{
    return Inicio->Datos;
}

bool Cola::esvacia()
{
    return Inicio==NULL;
}

int Cola::longitud()
{
    return ne;
}
