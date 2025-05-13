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
    Servidor *actual=primerServidor;
    cadena host;

    while(actual!=NULL)
    {
        actual->getDireccionServidor(host);
        if(strcmp(dS, host)==0)
            return actual->activar();
        actual=actual->getSiguienteServidor();
    }
    return false;
}

bool GestorServidores::realizarMantenimiento(cadena dS)
{
    Servidor *actual=primerServidor;
    cadena host;

    while(actual!=NULL)
    {
        actual->getDireccionServidor(host);
        if(strcmp(dS, host)==0)
            return actual->ponerEnMantenimiento();
        actual=actual->getSiguienteServidor();
    }
    return false;
}

bool GestorServidores::eliminarServidor(cadena dS)
{
    if(numServidores==0)
        return false;

    Servidor *actual=primerServidor, *anterior=NULL;
    cadena host;
    bool eliminado=false;

    while(actual!=NULL && !eliminado)
    {
        actual->getDireccionServidor(host);
        if(strcmp(host, dS)==0)
        {
            if(!actual->estaActivo())
            {
                if(anterior==NULL)
                    primerServidor=actual->getSiguienteServidor();
                else
                    anterior->setSiguienteServidor(actual->getSiguienteServidor());
                eliminado=true;

                delete actual;
            }
            break;
        }

        anterior=actual;
        actual=actual->getSiguienteServidor();
    }

    if(eliminado)
        numServidores--;
    if(numServidores==0)
        primerServidor=NULL;
    return eliminado;
}

bool GestorServidores::alojarJugador(Jugador j, cadena nomJuego, cadena host, bool &enEspera)
{
    Servidor *actual=primerServidor, *servidorConectado=NULL, *servidorEspera=NULL;
    cadena nombreJuego;
    int maximoConectado=0, maximoEspera=0, auxCon, auxEsp;

    while(actual!=NULL)
    {
        actual->getNombreJuego(nombreJuego);
        if(strcmp(nombreJuego, nomJuego)==0 && actual->estaActivo())
        {
            auxCon = actual->getMaxJugadoresConectados() - actual->getNumJugadoresConectados();
            auxEsp = actual->getMaxJugadoresEnEspera() - actual->getNumJugadoresEnEspera();

            if(auxCon > maximoConectado)
            {
                maximoConectado = auxCon;
                servidorConectado = actual;
            }

            if(actual->getMaxJugadoresEnEspera()-actual->getNumJugadoresEnEspera() > maximoEspera)
            {
                maximoEspera = auxEsp;
                servidorEspera = actual;
            }
        }
        actual=actual->getSiguienteServidor();
    }

    if(servidorConectado!=NULL)
    {
        enEspera=false;
        servidorConectado->getDireccionServidor(host);
        servidorConectado->conectarJugador(j);
        return true;
    }
    else if(servidorEspera!=NULL)
    {
        enEspera=true;
        servidorEspera->getDireccionServidor(host);
        servidorEspera->ponerJugadorEnEspera(j);
    }
    else
        enEspera=false;

    return false;
}

bool GestorServidores::expulsarJugador(cadena nJ, cadena host)
{
    Servidor *servidor=primerServidor;

    while(servidor!=NULL)
    {
        if(servidor->expulsarJugador(nJ))
        {
            servidor->getDireccionServidor(host);
            return true;
        }
        else
            servidor=servidor->getSiguienteServidor();
    }

    return false;
}

int GestorServidores::getPosicionServidor(cadena dS)
{
    Servidor *actual=primerServidor;
    int i=1;
    cadena host;

    while(actual!=NULL)
    {
        actual->getDireccionServidor(host);
        if(strcmp(dS, host)==0)
            return i;

        actual=actual->getSiguienteServidor();
        i++;
    }

    return -1;
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
                servidor->mostrarJugadoresEnEspera();
            }

            servidor=servidor->getSiguienteServidor();
        }
    }
}


//MODIFICAR COSAS
bool GestorServidores::jugadorConectado(cadena nJ, cadena dS)
{
    cadena direccion;
    Servidor *servidor=primerServidor;

    while(servidor!=NULL)
    {
        servidor->getDireccionServidor(direccion);
        if(strcmp(dS, direccion)==0)
        {
            int tama = servidor->getNumJugadoresConectados();
            Jugador *tabla = new Jugador[tama];
            servidor->exportarJugadoresConectados(tabla);

            for(int i=0; i<tama; i++)
                if(strcmp(tabla[i].nombreJugador, nJ)==0)
                    return true;

            return false;
        }
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
        {
            int tama = servidor->getNumJugadoresEnEspera();
            Jugador *tabla = new Jugador[tama];
            servidor->exportarJugadoresEnEspera(tabla);

            for(int i=0; i<tama; i++)
                if(strcmp(tabla[i].nombreJugador, nJ)==0)
                    return true;

            return false;
        }
        servidor=servidor->getSiguienteServidor();
    }

    return false;
}

bool GestorServidores::jugadorConectado(cadena nJ)
{
    Servidor *servidor=primerServidor;
    bool encontrado=false;
    int tama;

    while(servidor!=NULL && !encontrado)
    {
        tama = servidor->getNumJugadoresConectados();
        Jugador *tabla = new Jugador[tama];
        servidor->exportarJugadoresConectados(tabla);

        for(int i=0; i<tama; i++)
            if(strcmp(tabla[i].nombreJugador, nJ)==0)
                encontrado=true;

        servidor=servidor->getSiguienteServidor();
    }

    return encontrado;
}

bool GestorServidores::jugadorEnEspera(cadena nJ)
{
    Servidor *servidor=primerServidor;
    bool encontrado=false;
    int tama;

    while(servidor!=NULL && !encontrado)
    {
        tama = servidor->getNumJugadoresEnEspera();
        Jugador *tabla = new Jugador[tama];
        servidor->exportarJugadoresEnEspera(tabla);

        for(int i=0; i<tama; i++)
            if(strcmp(tabla[i].nombreJugador, nJ)==0)
                encontrado=true;

        servidor=servidor->getSiguienteServidor();
    }

    return encontrado;
}

