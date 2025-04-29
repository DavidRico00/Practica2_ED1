#include "Servidor.h"

Servidor::~Servidor()
{

}

Servidor::Servidor(cadena dS, cadena nJ, int i, int mxC, int mxE, int p, cadena lG)
{

}

int Servidor::getId()
{
    return 0;
}

void Servidor::getDireccionServidor(cadena dS)
{

}

void Servidor::setSiguienteServidor(Servidor *pS)
{

}

Servidor* Servidor::getSiguienteServidor()
{
    return nullptr;
}

bool Servidor::conectarJugador(Jugador j)
{
    return false;
}

bool Servidor::ponerJugadorEnEspera(Jugador j)
{
    return false;
}

void Servidor::mostrarJugadoresConectados()
{

}

void Servidor::mostrarJugadoresEnEspera()
{

}

bool Servidor::estaActivo()
{
    return false;
}

bool Servidor::activar()
{
    return false;
}

bool Servidor::desactivar()
{
    return false;
}

bool Servidor::ponerEnMantenimiento()
{
    return false;
}

void Servidor::mostrarInformacion()
{
}

bool Servidor::expulsarJugador(cadena nombre)
{
    return false;
}

void Servidor::getNombreJuego(cadena nJ)
{

}

int Servidor::getPuerto()
{
    return 0;
}

void Servidor::getLocalizacionGeografica(cadena lG)
{

}

int Servidor::getMaxJugadoresConectados()
{
    return 0;
}

int Servidor::getMaxJugadoresEnEspera()
{
    return 0;
}

int Servidor::getNumJugadoresConectados()
{
    return 0;
}

int Servidor::getNumJugadoresEnEspera()
{
    return 0;
}

void Servidor::exportarJugadoresConectados(Jugador *conectados)
{

}

void Servidor::exportarJugadoresEnEspera(Jugador *enEspera)
{

}
