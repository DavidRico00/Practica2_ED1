#include "GestorServidores.h"

GestorServidores::GestorServidores()
{

}

GestorServidores::~GestorServidores()
{

}

int GestorServidores::getNumServidores()
{
    return 0;
}

bool GestorServidores::desplegarServidor(cadena dS, cadena nJ, int i, int mxL, int mxC, int p, cadena lG)
{
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
