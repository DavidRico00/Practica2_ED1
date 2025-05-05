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
            primerServidor->setSiguienteServidor(aux->Siguiente);
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
    //Estos nodos están ordenados por orden alfabético ascendente según el nombre del país en el que cada
    //servidor está ubicado (atributo localizacionGeografica). El nuevo nodo será añadido en dicha
    //estructura respetando este requisito. El método devolverá true si el despliegue del nuevo nodo es
    //completado con éxito; false en caso contrario, bien porque no haya sido posible reservar memoria
    //para crear el nuevo objeto, o bien porque ya existiese en la estructura de nodos otro Servidor con
    //el mismo nombre, o bien el mismo identificador que el nuevo elemento a integrar en la estructura

    return false;


}

bool GestorServidores::desconetarServidor(cadena dS)
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

}

bool GestorServidores::jugadorConectado(cadena nJ, cadena dS)
{
    return false;
}

bool GestorServidores::jugadorEnEspera(cadena nJ, cadena dS)
{
    return false;
}

bool GestorServidores::jugadorConectado(cadena nJ)
{
    return false;
}

bool GestorServidores::jugadorEnEspera(cadena nJ)
{
    return false;
}
