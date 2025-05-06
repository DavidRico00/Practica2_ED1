#include "GestorServidores.h"

GestorServidores::GestorServidores()
{
    primerServidor=NULL;
    numServidores=0;
}

GestorServidores::~GestorServidores()
{
    if(primerServidor != NULL)
    {
        while(primerServidor->getSiguienteServidor() != NULL)
        {
            Servidor *aux = primerServidor->getSiguienteServidor();
            primerServidor->setSiguienteServidor(aux->getSiguienteServidor());
            delete aux;
        }

        delete primerServidor;
        primerServidor = NULL;
        numServidores = 0;
    }
}

int GestorServidores::getNumServidores()
{
    return numServidores;
}

bool GestorServidores::desplegarServidor(cadena dS, cadena nJ, int i, int mxC, int mxE, int p, cadena lG)
{
    Servidor *servidor = new Servidor(dS, nJ, i, mxC, mxE, p, lG);
    if(servidor == NULL)
        return false;

    bool insertado=false;

    if(numServidores==0)
    {
        primerServidor=servidor;
        insertado=true;
    }
    else
    {
        Servidor *actual=primerServidor, *anterior=NULL;
        cadena direccionServer, localizacion;

        while(actual!=NULL)
        {
            actual->getDireccionServidor(direccionServer);
            if(actual->getId()==i || (strcmp(direccionServer, dS)==0))
                return false;
            actual=actual->getSiguienteServidor();
        }

        actual=primerServidor;
        while(actual!=NULL && !insertado)
        {
            actual->getLocalizacionGeografica(localizacion);
            if(strcmp(lG, localizacion) < 0)
            {
                if(anterior==NULL)
                {
                    servidor->setSiguienteServidor(primerServidor);
                    primerServidor=servidor;
                }
                else
                {
                    anterior->setSiguienteServidor(servidor);
                    servidor->setSiguienteServidor(actual);
                }
                insertado=true;
            }
            else
            {
                anterior=actual;
                actual=actual->getSiguienteServidor();
            }
        }

        if(!insertado)
        {
            anterior->setSiguienteServidor(servidor);
            insertado=true;
        }
    }

    if(insertado)
        numServidores++;
    return insertado;
}

bool GestorServidores::desconectarServidor(cadena dS)
{
    return false;
}

bool GestorServidores::conectarServidor(cadena dS)
{
    return false;
}

bool GestorServidores::realizarMantenimiento(cadena dS)
{
    return false;
}

bool GestorServidores::eliminarServidor(cadena dS)
{
    return false;
}

bool GestorServidores::alojarJugador(Jugador j, cadena nomJuego, cadena host, bool &enEspera)
{
    return false;
}

bool GestorServidores::expulsarJugador(cadena nJ, cadena host)
{
    return false;
}

int GestorServidores::getPosicionServidor(cadena dS)
{
    return 0;
}

void GestorServidores::mostrarInformacionServidores(int pos)
{
    if((pos<1 && pos!=-1) || pos>numServidores)
    {
        cout<<"\nLa posicion no es valida"<<endl;
        return;
    }

    Servidor *servidor=primerServidor;
    for(int i=1; i<=numServidores; i++)
    {
        if(pos==-1 || (pos!=-1 && pos==i))
        {
            servidor->mostrarInformacion();
            if(servidor->estaActivo())
            {
                servidor->mostrarJugadoresConectados();
                servidor->mostrarInformacion();
            }

            servidor=servidor->getSiguienteServidor();
        }
    }
}

bool GestorServidores::jugadorConectado(cadena nJ, cadena dS)
{
    cadena direccion;
    Servidor *servidor=primerServidor;

    while(servidor!=NULL)
    {
        servidor->getDireccionServidor(direccion);
        if(strcmp(dS, direccion)==0)
            return servidor->existeJugadorEnConectados(nJ);
        servidor=servidor->getSiguienteServidor();
    }

    return false;
}

bool GestorServidores::jugadorEnEspera(cadena nJ, cadena dS)
{
    cadena direccion;
    Servidor *servidor=primerServidor;

    while(servidor!=NULL)
    {
        servidor->getDireccionServidor(direccion);
        if(strcmp(dS, direccion)==0)
            return servidor->existeJugadorEnEspera(nJ);
        servidor=servidor->getSiguienteServidor();
    }

    return false;
}

bool GestorServidores::jugadorConectado(cadena nJ)
{
    Servidor *servidor=primerServidor;
    bool encontrado=false;

    while(servidor!=NULL && !encontrado)
    {
        encontrado = servidor->existeJugadorEnConectados(nJ);
        servidor=servidor->getSiguienteServidor();
    }

    return encontrado;
}

bool GestorServidores::jugadorEnEspera(cadena nJ)
{
    Servidor *servidor=primerServidor;
    bool encontrado=false;

    while(servidor!=NULL && !encontrado)
    {
        encontrado = servidor->existeJugadorEnEspera(nJ);
        servidor=servidor->getSiguienteServidor();
    }

    return encontrado;
}

