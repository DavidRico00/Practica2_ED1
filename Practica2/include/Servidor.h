#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "TADLista_C_NED.h"
#include "Cola.h"

#define ACTIVO        "ACTIVO"
#define INACTIVO      "INACTIVO"
#define MANTENIMIENTO "MANTENIMIENTO"

class Servidor
{
private:
    cadena direccionServidor, nombreJuego, estado, localizacionGeografica;
    int id, maxJugadoresConectados, maxJugadoresEnEspera, puerto;

    Servidor *siguienteServidor;
    Lista jugadoresConectados;
    Cola jugadoresEnEspera;

    //METODOS AUXILIARES PRIVADOS
    void mostrarJugadoresFormateado(Jugador j, bool cabecera, char* titulo);

public:
    Servidor(cadena dS, cadena nJ, int i, int mxC, int mxE, int p, cadena lG);
    ~Servidor();

    bool activar();
    bool desactivar();
    bool ponerEnMantenimiento();
    bool conectarJugador(Jugador j);
    bool ponerJugadorEnEspera(Jugador j);
    bool expulsarJugador(cadena nombre);
    void exportarJugadoresConectados(Jugador *conectados);
    void exportarJugadoresEnEspera(Jugador *enEspera);

    void mostrarJugadoresConectados();
    void mostrarJugadoresEnEspera();
    void mostrarInformacion();

    Servidor* getSiguienteServidor();
    int getId();
    void getDireccionServidor(cadena dS);
    void getNombreJuego(cadena nJ);
    int getPuerto();
    void getLocalizacionGeografica(cadena lG);
    int getMaxJugadoresConectados();
    int getMaxJugadoresEnEspera();
    int getNumJugadoresConectados();
    int getNumJugadoresEnEspera();
    bool estaActivo();

    void setSiguienteServidor(Servidor *pS);
};

#endif // SERVIDOR_H
