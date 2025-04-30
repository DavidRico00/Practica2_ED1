#include "Servidor.h"

Servidor::~Servidor()
{

}

Servidor::Servidor(cadena dS, cadena nJ, int i, int mxC, int mxE, int p, cadena lG)
{
    strcpy(direccionServidor, dS);
    strcpy(nombreJuego, nJ);
    id = i;
    maxJugadoresConectados = mxC;
    maxJugadoresEnEspera = mxE;
    puerto = p;
    strcpy(localizacionGeografica, lG);
    estado = INACTIVO;
}

int Servidor::getId()
{
    return id;
}

void Servidor::getDireccionServidor(cadena dS)
{
    strcpy(dS, direccionServidor);
}

void Servidor::setSiguienteServidor(Servidor *pS)
{
    siguienteServidor = pS;
}

Servidor* Servidor::getSiguienteServidor()
{
    return siguienteServidor;
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
    int l = jugadoresConectados.longitud();

    for(int i=1; i<=l; i++)
        mostrarJugadoresFormateado(jugadoresConectados.observar(i), i==1);
}

void Servidor::mostrarJugadoresEnEspera()
{
    int l = jugadoresEnEspera.longitud();

    for(int i=0; i<l; i++)
    {
        mostrarJugadoresFormateado(jugadoresEnEspera.primero(), i==0);
        jugadoresEnEspera.encolar(jugadoresEnEspera.primero());
        jugadoresEnEspera.desencolar();
    }
}

bool Servidor::estaActivo()
{
    return (strcmp(estado, ACTIVO) == 0);
}

bool Servidor::activar()
{
    if(estaActivo())
        return false;
    else
    {
        strcpy(estado, ACTIVO);
        return true;
    }
}

bool Servidor::desactivar()
{
    return false;
}

bool Servidor::ponerEnMantenimiento()
{
    if(strcmp(estado, INACTIVO)==0)
    {
        strcpy(estado, MANTENIMIENTO);
        return true;
    }
    return false;
}

void Servidor::mostrarInformacion()
{
    cout<<"\nInformacion del servidor"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"IP/hostname: "<<direccionServidor<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Estado: "<<estado<<endl;
    cout<<"Num Jugadores Disponibles: "<<(maxJugadoresConectados-jugadoresConectados.longitud())<<endl;
    cout<<"Num Jugadores Maximo en Espera: "<<maxJugadoresEnEspera<<endl;
    cout<<"Num Jugadores en Espera: "<<jugadoresEnEspera.longitud()<<endl;
    cout<<"Puerto: "<<puerto<<endl;
    cout<<"Localizacion Geografica: "<<localizacionGeografica<<endl;

    int l = jugadoresConectados.longitud(), latenciaMedia=0;
    for(int i = 1; i <= l; i++)
        latenciaMedia += jugadoresConectados.observar(i).latencia;
    latenciaMedia /= l;

    cout<<"Latencia media: "<<latenciaMedia<<endl;
}

bool Servidor::expulsarJugador(cadena nombre)
{
    return false;
}

void Servidor::getNombreJuego(cadena nJ)
{
    strcpy(nJ, nombreJuego);
}

int Servidor::getPuerto()
{
    return puerto;
}

void Servidor::getLocalizacionGeografica(cadena lG)
{
    strcpy(lG, localizacionGeografica);
}

int Servidor::getMaxJugadoresConectados()
{
    return maxJugadoresConectados;
}

int Servidor::getMaxJugadoresEnEspera()
{
    return maxJugadoresEnEspera;
}

int Servidor::getNumJugadoresConectados()
{
    return jugadoresConectados.longitud();
}

int Servidor::getNumJugadoresEnEspera()
{
    return jugadoresEnEspera.longitud();
}

void Servidor::exportarJugadoresConectados(Jugador *conectados)
{

}

void Servidor::exportarJugadoresEnEspera(Jugador *enEspera)
{

}


void Servidor::mostrarJugadoresFormateado(Jugador j, bool cabecera)
{
    if(cabecera)
    {
        cout << endl;
        cout << setw(20) << left << "Nombre"
             << setw(5) << left << "ID"
             << setw(10) << left << "Activo"
             << setw(12) << left << "Latencia"
             << setw(15) << left << "Puntuación"
             << setw(20) << left << "País" << endl;

        cout << string(87, '-') << endl;
    }

    cout << setw(20) << left << j.nombreJugador
         << setw(5) << left << j.ID
         << setw(10) << left << (j.activo ? "True" : "False")
         << setw(12) << left << j.latencia
         << setw(15) << left << j.puntuacion
         << setw(20) << left << j.pais << endl;
}

