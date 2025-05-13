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
    strcpy(estado, INACTIVO);
    siguienteServidor=NULL;
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
    int longitud = jugadoresConectados.longitud();
    if(longitud == maxJugadoresConectados)
        return false;

    int pos = jugadoresConectados.posicion(j);
    if(pos != -1)
        return false;

    int i=1;
    while(i<=longitud && jugadoresConectados.observar(i).puntuacion < j.puntuacion)
        i++;

    jugadoresConectados.insertar(i, j);

    return true;
}

bool Servidor::ponerJugadorEnEspera(Jugador j)
{
    if(jugadoresConectados.longitud() == maxJugadoresConectados &&
       jugadoresEnEspera.longitud() < maxJugadoresEnEspera)
    {
        jugadoresEnEspera.encolar(j);
        return true;
    }
    else
        return false;
}

void Servidor::mostrarJugadoresConectados()
{
    int l = jugadoresConectados.longitud();

    for(int i=1; i<=l; i++)
        mostrarJugadoresFormateado(jugadoresConectados.observar(i), i==1, "JUGADORES CONECTADOS");
}

void Servidor::mostrarJugadoresEnEspera()
{
    int l = jugadoresEnEspera.longitud();

    for(int i=0; i<l; i++)
    {
        mostrarJugadoresFormateado(jugadoresEnEspera.primero(), i==0, "JUGADORES EN ESPERA");
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
    if(strcmp(estado, INACTIVO)==0)
        return false;

    if(strcmp(estado, ACTIVO)==0)
    {
        while(!jugadoresConectados.esvacia())
            jugadoresConectados.eliminar(1);

        while(!jugadoresEnEspera.esvacia())
            jugadoresEnEspera.desencolar();
    }

    strcpy(estado, INACTIVO);
    return true;
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
    cout<<"Nombre de juego: "<<nombreJuego<<endl;
    cout<<"Num Jugadores Maximo Conectados: "<<maxJugadoresConectados<<endl;
    cout<<"Num Jugadores Conectados: "<<jugadoresConectados.longitud()<<endl;
    cout<<"Num Jugadores Disponibles: "<<(maxJugadoresConectados-jugadoresConectados.longitud())<<endl;
    cout<<"Num Jugadores Maximo en Espera: "<<maxJugadoresEnEspera<<endl;
    cout<<"Num Jugadores en Espera: "<<jugadoresEnEspera.longitud()<<endl;
    cout<<"Puerto: "<<puerto<<endl;
    cout<<"Localizacion Geografica: "<<localizacionGeografica<<endl;

    int l = jugadoresConectados.longitud(), latenciaMedia=0;
    for(int i = 1; i <= l; i++)
        latenciaMedia += jugadoresConectados.observar(i).latencia;

    if(l>0)
        latenciaMedia = latenciaMedia/l;

    cout<<"Latencia media: "<<latenciaMedia<<endl;
}

bool Servidor::expulsarJugador(cadena nombre)
{
    bool expulsado=false;

    Jugador j, aux;
    strcpy(j.nombreJugador, nombre);

    int pos = jugadoresConectados.posicion(j);
    if(pos != -1)
    {
        jugadoresConectados.eliminar(pos);

        if(!jugadoresEnEspera.esvacia())
        {
            expulsado=conectarJugador(jugadoresEnEspera.primero());
            jugadoresEnEspera.desencolar();
        }
        else
            expulsado=true;
    }
    else
    {
        int longitud = jugadoresEnEspera.longitud();
        for(int i=0; i<longitud; i++)
        {
            aux = jugadoresEnEspera.primero();
            jugadoresEnEspera.desencolar();

            if(strcmp(nombre, aux.nombreJugador)==0)
                expulsado=true;
            else
                jugadoresEnEspera.encolar(aux);
        }
    }

    return expulsado;
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
    if(conectados==NULL)
        cout<<"El puntero pasado no esta inicializado"<<endl;
    else
    {
        int longitud = jugadoresConectados.longitud();

        for(int i=0; i<longitud; i++)
            conectados[i]=jugadoresConectados.observar(i+1);
    }
}

void Servidor::exportarJugadoresEnEspera(Jugador *enEspera)
{
    if(enEspera==NULL)
        cout<<"El puntero pasado no esta inicializado"<<endl;
    else
    {
        int longitud = jugadoresEnEspera.longitud();

        for(int i=0; i<longitud; i++)
        {
            Jugador aux = jugadoresEnEspera.primero();

            enEspera[i]= aux;
            jugadoresEnEspera.encolar(aux);
            jugadoresEnEspera.desencolar();
        }
    }
}


//METODOS AUXILIARES
void Servidor::mostrarJugadoresFormateado(Jugador j, bool cabecera, char* titulo)
{
    if(cabecera)
    {
        cout << endl << titulo << endl;
        cout << setw(20) << left << "Nombre"
             << setw(5) << left << "ID"
             << setw(10) << left << "Activo"
             << setw(12) << left << "Latencia"
             << setw(15) << left << "Puntuacion"
             << setw(20) << left << "Pais" << endl;

        cout << string(87, '-') << endl;
    }

    cout << setw(20) << left << j.nombreJugador
         << setw(5) << left << j.ID
         << setw(10) << left << (j.activo ? "True" : "False")
         << setw(12) << left << j.latencia
         << setw(15) << left << j.puntuacion
         << setw(20) << left << j.pais << endl;
}

