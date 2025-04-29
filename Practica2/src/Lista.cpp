#include "Lista.h"

Lista::Lista()
{
    elementos = NULL;
    n=0;
}

Lista::Lista(Jugador e)
{
    elementos=new TNodo_Lista;
    elementos->Datos=e;
    elementos->Siguiente=NULL;
    n=1;
}

Lista::~Lista()
{
    TNodo_Lista *Nodo_Borr=elementos,*Nodo_Sig;

    while (Nodo_Borr!=NULL)
    {
        Nodo_Sig=Nodo_Borr->Siguiente;
        delete Nodo_Borr;
        Nodo_Borr=Nodo_Sig;
    }
    elementos=NULL;
    n=0;
}

TNodo_Lista *Lista::Anterior(int i)
{
    TNodo_Lista *Nodo_Aux=elementos,*Nodo_Ant=NULL;
    int v=1;
    if (Nodo_Aux!=NULL)
        while (Nodo_Aux!=NULL && v<i)
        {
            Nodo_Ant=Nodo_Aux;
            Nodo_Aux=Nodo_Aux->Siguiente;
            v++;
        }
    return Nodo_Ant;
};

bool Lista::esvacia ()
{
    return (n == 0);
}

int Lista::longitud ()
{
    return n;
}

//ADD
void Lista::anadirIzq(Jugador e)
{
    TNodo_Lista *nuevo = new TNodo_Lista;
    nuevo->Datos = e;
    nuevo->Siguiente = elementos;
    elementos = nuevo;
    n++;
}

//ADD
void Lista::anadirDch(Jugador e)
{
    TNodo_Lista *nuevo = new TNodo_Lista;
    nuevo->Datos = e;
    nuevo->Siguiente = NULL;

    if (elementos == NULL)
        elementos = nuevo;
    else
    {
        TNodo_Lista *ultimo = Anterior(n + 1);
        ultimo->Siguiente = nuevo;
    }

    n++;
}

//ADD
void Lista::eliminarIzq()
{
    if(elementos != NULL)
    {
        TNodo_Lista *temp;
        temp = elementos;
        elementos = elementos->Siguiente;
        delete temp;
        n--;
    }
}

//ADD
void Lista::eliminarDch()
{
    if(elementos != NULL)
    {
        if(elementos->Siguiente == NULL)
        {
            delete elementos;
            elementos = NULL;
        }
        else
        {
            TNodo_Lista *temp = Anterior(n);
            delete temp->Siguiente;
            temp->Siguiente = NULL;
        }
        n--;
    }
}

//ADD
Jugador Lista::observarIzq()
{
    if(elementos != NULL)
        return elementos->Datos;
    else
        return Jugador();
}

//ADD
Jugador Lista::observarDch()
{
    if(elementos != NULL)
    {
        TNodo_Lista *nodo = Anterior(n+1);
        return nodo->Datos;
    }
    else
        return Jugador();
}

//ADD
void Lista::concatenar(Lista l)
{
    Jugador aux;

    while(!l.esvacia())
    {
        aux = l.observarIzq();
        l.eliminarIzq();
        anadirDch(aux);
    }
}

//ADD
bool Lista::pertenece(Jugador e)
{
    return (posicion(e)!=-1);
}

void Lista::insertar(int i, Jugador e)
{
    TNodo_Lista *Nodo_Aux=new TNodo_Lista, *Nodo_Ant;
    if (Nodo_Aux!=NULL)
    {
        Nodo_Aux->Datos=e;
        Nodo_Aux->Siguiente=NULL;
        Nodo_Ant = Anterior(i);
        if (Nodo_Ant==NULL)
        {
            Nodo_Aux->Siguiente=elementos;
            elementos=Nodo_Aux;
        }
        else
        {
            Nodo_Aux->Siguiente=Nodo_Ant->Siguiente;
            Nodo_Ant->Siguiente=Nodo_Aux;
        }
        n++;
    }
}

void Lista::eliminar(int i)
{
    TNodo_Lista *Nodo_Ant,*Nodo_Aux;
    Nodo_Ant=Anterior(i);

    if (Nodo_Ant==NULL)
    {
        Nodo_Aux=elementos;
        elementos=Nodo_Aux->Siguiente;
    }
    else
    {
        Nodo_Aux=Nodo_Ant->Siguiente;
        Nodo_Ant->Siguiente=Nodo_Aux->Siguiente;
    }
    delete Nodo_Aux;
    n--;
}

void Lista::modificar(int i, Jugador e)
{
    TNodo_Lista *Nodo_Ant=Anterior(i),*Nodo_Aux;
    if (Nodo_Ant==NULL)
        Nodo_Aux=elementos;
    else
        Nodo_Aux=Nodo_Ant->Siguiente;
    Nodo_Aux->Datos=e;
}

Jugador Lista::observar(int i)
{
    TNodo_Lista *Nodo_Ant=Anterior(i),*Nodo_Aux;
    if (Nodo_Ant==NULL)
        Nodo_Aux=elementos;
    else
        Nodo_Aux=Nodo_Ant->Siguiente;
    return Nodo_Aux->Datos;
}

int Lista::posicion(Jugador e)
{
    TNodo_Lista *Nodo_Aux=elementos;
    bool encontrado=false;
    int v=1;
    while (Nodo_Aux!=NULL && !encontrado)
        if (Nodo_Aux->Datos.ID!=e.ID)
        {
            Nodo_Aux=Nodo_Aux->Siguiente;
            v++;
        }
        else
            encontrado=true;

    return (encontrado?v:-1);
}

