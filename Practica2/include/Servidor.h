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
    //HACER

    Servidor(cadena dS, cadena nJ, int i, int mxC, int mxE, int p, cadena lG);

    int getId();

    void getDireccionServidor(cadena dS);

    void setSiguienteServidor(Servidor *pS);

    Servidor* getSiguienteServidor();

    bool conectarJugador(Jugador j);
    //aloja al jugador j en el servidor, esto es, lo añade a la lista listaConectados siempre y cuando
    //no se haya alcanzado el número máximo de jugadores. Devolverá true si el jugador finalmente es
    //alojado en el servidor; false en caso contrario. Los jugadores se almacenan en la lista por
    //puntuación ascendente, por lo que el jugador deberá ser añadido a aquella posición para la que
    //se garantice el cumplimiento de esta regla de negocio.

    bool ponerJugadorEnEspera(Jugador j);
    //encola al jugador j en la cola de espera jugadoresEnEspera, comprobando previamente que el servidor
    //ha alcanzado el número máximo de conexiones, y de que por otra parte no se ha alcanzado el número
    //máximo de jugadores que pueden estar en espera para acceder al servidor. Devolverá true en caso de
    //enconlar exitosamente al jugador; false en caso contrario.

    void mostrarJugadoresConectados();

    void mostrarJugadoresEnEspera();

    bool estaActivo();

    bool activar();

    bool desactivar();
    //desactiva un servidor en estado ACTIVO o MANTENIMIENTO. Si el servidor ya estaba desactivado, el
    //método devolverá false; true en caso contrario, confirmando así que el servidor ha sido desactivado.
    //Si el servidor a desactivar está previamente activo, será necesario vaciar tanto la lista de
    //jugadores conectados como la cola de aquellos que están esperando poder conectarse.

    bool ponerEnMantenimiento();

    void mostrarInformacion();

    bool expulsarJugador(cadena nombre);
    //expulsa el jugador cuyo nombreJugador coincide con el parámetro nombre de la lista de conectados,
    //o bien de la cola de espera, en función de dónde esté contenida la instancia de tipo Jugador
    //correspondiente. Si el jugador es localizado en alguna de estas estructuras y convenientemente
    //eliminado el método devolverá true; false en caso contrario. Si el jugador a expulsar es localizado
    //en la lista de jugadores conectados, tras eliminarlo, será necesario comprobar si hay alguien en
    //la lista de espera. En caso positivo, el primero de la cola será automáticamente conectado
    //al servidor, pasando a la lista de conectados.

    void getNombreJuego(cadena nJ);

    int getPuerto();

    void getLocalizacionGeografica(cadena lG);

    int getMaxJugadoresConectados();

    int getMaxJugadoresEnEspera();

    int getNumJugadoresConectados();

    int getNumJugadoresEnEspera();

    void exportarJugadoresConectados(Jugador *conectados);
    //el método copiara todos los jugadores alojados en el servidor en el vector dinámico accesible desde
    //el puntero conectados, parámetro de entrada.

    void exportarJugadoresEnEspera(Jugador *enEspera);
    //el método copiara todos los jugadores que están en la cola de espera para el acceso al servidor en
    //el vector dinámico accesible desde el puntero conectados, parámetro de entrada.
};

#endif // SERVIDOR_H
