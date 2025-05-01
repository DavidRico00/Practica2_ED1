#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "Lista.h"
#include "Cola.h"

#define ACTIVO        "ACTIVO"
#define INACTIVO      "INACTIVO"
#define MANTENIMIENTO "MANTENIMIENTO"

class Servidor
{
private:
    cadena direccionServidor;       //direccion IP/hostname del servidor de juegos.
    cadena nombreJuego;             //nombre del juego jugado en el servidor.
    int id;                         /*código numérico (entero positivo) utilizado en el ámbito interno de la compañía para
                                    identificar de forma unívoca cada servidor que ésta gestiona.*/
    Servidor *siguienteServidor;    //puntero al siguiente servidor del sistema.
    int maxJugadoresConectados;     //número máximo de jugadores que pueden ser alojados en el servidor.
    int maxJugadoresEnEspera;       //número máximo de jugadores que pueden estar en espera para acceder al servidor.
    Lista jugadoresConectados;      /*lista de jugadores alojados en el servidor. Los jugadores aparecen
                                    ordenados en la lista según su puntuación, y de forma ascendente en
                                    relación al valor de ésta.*/
    Cola jugadoresEnEspera;         //cola de jugadores en espera de poder acceder al servidor.
    cadena estado;                  /*estado actual del servidor. Para este atributo sólo son posibles los valores que
                                    siguen: ACTIVO, INACTIVO o MANTENIMIENTO.*/
    int puerto;                     //número del puerto de escucha del servidor;
    cadena localizacionGeografica;  //país en el que se encuentra ubicado físicamente el servidor.

    void mostrarJugadoresFormateado(Jugador j, bool cabecera);

public:
    ~Servidor();
    Servidor(cadena dS, cadena nJ, int i, int mxC, int mxE, int p, cadena lG);
    int getId();
    void getDireccionServidor(cadena dS);
    void setSiguienteServidor(Servidor *pS);
    Servidor* getSiguienteServidor();
    bool conectarJugador(Jugador j);
    bool ponerJugadorEnEspera(Jugador j);
    void mostrarJugadoresConectados();
    void mostrarJugadoresEnEspera();
    bool estaActivo();
    bool activar();
    bool desactivar();
    bool ponerEnMantenimiento();
    void mostrarInformacion();
    bool expulsarJugador(cadena nombre);
    void getNombreJuego(cadena nJ);
    int getPuerto();
    void getLocalizacionGeografica(cadena lG);
    int getMaxJugadoresConectados();
    int getMaxJugadoresEnEspera();
    int getNumJugadoresConectados();
    int getNumJugadoresEnEspera();
    void exportarJugadoresConectados(Jugador *conectados);
    void exportarJugadoresEnEspera(Jugador *enEspera);
};

#endif // SERVIDOR_H
