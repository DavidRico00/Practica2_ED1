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
    int id;                         /*c�digo num�rico (entero positivo) utilizado en el �mbito interno de la compa��a para
                                    identificar de forma un�voca cada servidor que �sta gestiona.*/
    Servidor *siguienteServidor;    //puntero al siguiente servidor del sistema.
    int maxJugadoresConectados;     //n�mero m�ximo de jugadores que pueden ser alojados en el servidor.
    int maxJugadoresEnEspera;       //n�mero m�ximo de jugadores que pueden estar en espera para acceder al servidor.
    Lista jugadoresConectados;      /*lista de jugadores alojados en el servidor. Los jugadores aparecen
                                    ordenados en la lista seg�n su puntuaci�n, y de forma ascendente en
                                    relaci�n al valor de �sta.*/
    Cola jugadoresEnEspera;         //cola de jugadores en espera de poder acceder al servidor.
    cadena estado;                  /*estado actual del servidor. Para este atributo s�lo son posibles los valores que
                                    siguen: ACTIVO, INACTIVO o MANTENIMIENTO.*/
    int puerto;                     //n�mero del puerto de escucha del servidor;
    cadena localizacionGeografica;  //pa�s en el que se encuentra ubicado f�sicamente el servidor.

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
