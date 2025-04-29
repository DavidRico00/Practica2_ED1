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
    //HACER

    Servidor(cadena dS, cadena nJ, int i, int mxC, int mxE, int p, cadena lG);

    int getId();

    void getDireccionServidor(cadena dS);

    void setSiguienteServidor(Servidor *pS);

    Servidor* getSiguienteServidor();

    bool conectarJugador(Jugador j);
    //aloja al jugador j en el servidor, esto es, lo a�ade a la lista listaConectados siempre y cuando
    //no se haya alcanzado el n�mero m�ximo de jugadores. Devolver� true si el jugador finalmente es
    //alojado en el servidor; false en caso contrario. Los jugadores se almacenan en la lista por
    //puntuaci�n ascendente, por lo que el jugador deber� ser a�adido a aquella posici�n para la que
    //se garantice el cumplimiento de esta regla de negocio.

    bool ponerJugadorEnEspera(Jugador j);
    //encola al jugador j en la cola de espera jugadoresEnEspera, comprobando previamente que el servidor
    //ha alcanzado el n�mero m�ximo de conexiones, y de que por otra parte no se ha alcanzado el n�mero
    //m�ximo de jugadores que pueden estar en espera para acceder al servidor. Devolver� true en caso de
    //enconlar exitosamente al jugador; false en caso contrario.

    void mostrarJugadoresConectados();

    void mostrarJugadoresEnEspera();

    bool estaActivo();

    bool activar();

    bool desactivar();
    //desactiva un servidor en estado ACTIVO o MANTENIMIENTO. Si el servidor ya estaba desactivado, el
    //m�todo devolver� false; true en caso contrario, confirmando as� que el servidor ha sido desactivado.
    //Si el servidor a desactivar est� previamente activo, ser� necesario vaciar tanto la lista de
    //jugadores conectados como la cola de aquellos que est�n esperando poder conectarse.

    bool ponerEnMantenimiento();

    void mostrarInformacion();

    bool expulsarJugador(cadena nombre);
    //expulsa el jugador cuyo nombreJugador coincide con el par�metro nombre de la lista de conectados,
    //o bien de la cola de espera, en funci�n de d�nde est� contenida la instancia de tipo Jugador
    //correspondiente. Si el jugador es localizado en alguna de estas estructuras y convenientemente
    //eliminado el m�todo devolver� true; false en caso contrario. Si el jugador a expulsar es localizado
    //en la lista de jugadores conectados, tras eliminarlo, ser� necesario comprobar si hay alguien en
    //la lista de espera. En caso positivo, el primero de la cola ser� autom�ticamente conectado
    //al servidor, pasando a la lista de conectados.

    void getNombreJuego(cadena nJ);

    int getPuerto();

    void getLocalizacionGeografica(cadena lG);

    int getMaxJugadoresConectados();

    int getMaxJugadoresEnEspera();

    int getNumJugadoresConectados();

    int getNumJugadoresEnEspera();

    void exportarJugadoresConectados(Jugador *conectados);
    //el m�todo copiara todos los jugadores alojados en el servidor en el vector din�mico accesible desde
    //el puntero conectados, par�metro de entrada.

    void exportarJugadoresEnEspera(Jugador *enEspera);
    //el m�todo copiara todos los jugadores que est�n en la cola de espera para el acceso al servidor en
    //el vector din�mico accesible desde el puntero conectados, par�metro de entrada.
};

#endif // SERVIDOR_H
