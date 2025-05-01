#include "TADLista_C_NES.h"

Lista_C_NES::Lista_C_NES()
{
    elementos=NULL;
    numElementos=0;
}

Lista_C_NES::~Lista_C_NES()
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

Lista_C_NES::Lista_C_NES(float e)
{
    TNodo_Lista *temp=new TNodo_Lista;

    elementos=temp;
    temp->Siguiente=temp;
    temp->Datos=e;

    numElementos=1;
}

bool Lista_C_NES::esvacia()
{
    return elementos==NULL;
}

int Lista_C_NES::longitud()
{
    return numElementos;
}

void Lista_C_NES::anadirIzq(float e)
{
    TNodo_Lista *nodo=new TNodo_Lista;

    nodo->Datos=e;

    if(esvacia())
        nodo->Siguiente=nodo;
    else
    {
        TNodo_Lista *temp=elementos;

        while(temp->Siguiente!=elementos)
            temp=temp->Siguiente;

        nodo->Siguiente=elementos;
        temp->Siguiente=nodo;
    }

    elementos=nodo;
    numElementos++;
}

void Lista_C_NES::anadirDch(float e)
{
    TNodo_Lista *nodo=new TNodo_Lista;

    nodo->Datos=e;

    if(esvacia())
    {
        elementos=nodo;
    }
    else
    {
        TNodo_Lista *temp=elementos;

        while(temp->Siguiente!=elementos)
            temp=temp->Siguiente;

        temp->Siguiente=nodo;
    }

    nodo->Siguiente=elementos;
    numElementos++;
}

void Lista_C_NES::eliminarIzq()
{

    if(!esvacia())
    {
        if(numElementos == 1)
        {
            delete elementos;
            elementos=NULL;
        }
        else
        {
            TNodo_Lista *ini=elementos, *fin=elementos;

            while(fin->Siguiente!=elementos)
                fin=fin->Siguiente;

            elementos=elementos->Siguiente;
            fin->Siguiente=elementos;
            delete ini;
        }

        numElementos--;
    }

}

void Lista_C_NES::eliminarDch()
{
    if(!esvacia())
    {
        if(numElementos==1)
        {
            delete elementos;
            elementos=NULL;
        }
        else
        {
            TNodo_Lista *ultimo=elementos, *penultimo;

            while(ultimo->Siguiente!=elementos)
            {
                penultimo=ultimo;
                ultimo=ultimo->Siguiente;
            }

            delete ultimo;
            penultimo->Siguiente=elementos;
        }

        numElementos--;
    }
}

float Lista_C_NES::observarIzq()
{
    return (!esvacia() ? elementos->Datos : -1);
}

float Lista_C_NES::observarDch()
{
    if(!esvacia())
    {
        TNodo_Lista *nodo=elementos;

        while(nodo->Siguiente!=elementos)
            nodo=nodo->Siguiente;

        return nodo->Datos;
    }
    else
        return -1;
}

void Lista_C_NES::concatenar(Lista_C_NES l)
{
    while(!l.esvacia())
    {
        anadirDch(l.observarIzq());
        l.eliminarIzq();
    }
}

bool Lista_C_NES::pertenece(float e)
{
    return posicion(e)!=-1;
}

void Lista_C_NES::insertar(int i, float e)
{
    if(i<1 || i>numElementos+1)
        cout<<"\nLa posicion pasada no es una posicion valida"<<endl;
    else
    {
        if(i==1)
            anadirIzq(e);
        else if(i==numElementos+1)
            anadirDch(e);
        else
        {
            TNodo_Lista *aux=elementos, *nodoI=new TNodo_Lista;

            for(int pos=1; pos<i-1; pos++)
                aux=aux->Siguiente;

            nodoI->Datos=e;
            nodoI->Siguiente=aux->Siguiente;
            aux->Siguiente=nodoI;

            numElementos++;
        }
    }
}

void Lista_C_NES::eliminar(int i)
{
    if(i<1 || i>numElementos)
        cout<<"La posicion no es valida"<<endl;
    else
    {
        if(i==1)
            eliminarIzq();
        else if(i==numElementos)
            eliminarDch();
        else
        {
            TNodo_Lista *nodo=elementos, *anterior;

            for(int pos=1; pos<i; pos++)
            {
                anterior=nodo;
                nodo=nodo->Siguiente;
            }

            anterior->Siguiente=nodo->Siguiente;
            delete nodo;
            numElementos--;
        }
    }
}

void Lista_C_NES::modificar(int i, float e)
{
    if(i<1 || i>numElementos)
        cout<<"La posicion no es valida"<<endl;
    else
    {
        TNodo_Lista *nodo=elementos;

        for(int pos=1; pos<i; pos++)
            nodo=nodo->Siguiente;

        nodo->Datos=e;
    }
}

float Lista_C_NES::observar(int i)
{
    if(i<1 || i>numElementos)
    {
        cout<<"La posicion no es valida"<<endl;
        return -1;
    }
    else
    {
        TNodo_Lista *nodo=elementos;

        for(int pos=1; pos<i; pos++)
            nodo=nodo->Siguiente;

        float e = nodo->Datos;
        return e;
    }
}

int Lista_C_NES::posicion(float e)
{
    if(esvacia())
        return -1;

    int i=1;
    TNodo_Lista *nodo=elementos;

    do
    {
        if(nodo->Datos==e)
            return i;

        nodo=nodo->Siguiente;
        i++;
    }while(nodo!=elementos);

    return -1;
}
