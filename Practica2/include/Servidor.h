#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "Comun.h"
#include "Lista.h"
#include "Cola.h"

class Servidor{
    cadena direccionServidor;       //direccion IP/hostname del servidor de juegos.
    cadena nombreJuego;             //nombre del juego jugado en el servidor.
    int id;                         /*c�digo num�rico (entero positivo) utilizado en el �mbito interno de la compa��a para
                                    identificar de forma un�voca cada servidor que �sta gestiona.*/
    Servidor *siguienteServidor;    //puntero al siguiente servidor del sistema.
    int maxJugadoresConectados;     //n�mero m�ximo de jugadores que pueden ser alojados en el servidor.
    int maxJugadoresEnEspera;       /*n�mero m�ximo de jugadores que pueden estar en espera para acceder al
                                    servidor.*/
    Lista jugadoresConectados;      /*lista de jugadores alojados en el servidor. Los jugadores aparecen
                                    ordenados en la lista seg�n su puntuaci�n, y de forma ascendente en
                                    relaci�n al valor de �sta.*/
    Cola jugadoresEnEspera;         //cola de jugadores en espera de poder acceder al servidor.
    cadena estado;                  /*estado actual del servidor. Para este atributo s�lo son posibles los valores que
                                    siguen: ACTIVO, INACTIVO o MANTENIMIENTO.*/
    int puerto;                     //n�mero del puerto de escucha del servidor;
    cadena localizacionGeografica;  //pa�s en el que se encuentra ubicado f�sicamente el servidor.

public:
    ~Servidor();

    Servidor(cadena dS, cadena nJ, int i, int mxL, int mxC, int p, cadena lG);
    //m�todo constructor que inicializa los atributos direccionServidor, nombreJuego, id,
    //maxJugadoresConectados, maxJugadoresEnEspera, puerto y localizacionGeografica con,
    //respectivamente, dS, nJ, i, mxL, mxC, p y lG. Adem�s, inicializa el atributo estado a �INACTIVO�.

    int getId();
    //devuelve el valor del atributo id.

    void getDireccionServidor(cadena dS);
    //devuelve el valor de direccionServidor a trav�s del par�metro de entrada/salida dS.

    void setSiguienteServidor(Servidor *pS);
    //asigna el valor recibido como par�metro al atributo siguienteServidor.

    Servidor* getSiguienteServidor();
    //devuelve el valor del atributo siguienteServidor.

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
    //muestra por pantalla el nombre, el identificador num�rico, el ping(latencia), la puntuaci�n global
    //y el pa�s desde el que se conecta cada uno de los jugadores alojados en el servidor.

    void mostrarJugadoresEnEspera();
    //muestra por pantalla el nombre, el identificador num�rico, el ping(latencia) y la puntuaci�n global
    //y el pa�s desde el que se conecta cada uno de los jugadores que se encuentran esperando poder
    //acceder al servidor.

    bool estaActivo();
    //devuelve true si el estado del servidor es ACTIVO; false en caso contrario.

    bool activar(); //activa un servidor en estado INACTIVO o MANTENIMIENTO. Si el servidor ya estaba
    //activado, el m�todo devolver� false; true en caso contrario, confirmando as� que el servidor ha
    //sido activado.

    bool desactivar();
    //desactiva un servidor en estado ACTIVO o MANTENIMIENTO. Si el servidor ya estaba desactivado, el
    //m�todo devolver� false; true en caso contrario, confirmando as� que el servidor ha sido desactivado.
    //Si el servidor a desactivar est� previamente activo, ser� necesario vaciar tanto la lista de
    //jugadores conectados como la cola de aquellos que est�n esperando poder conectarse.

    bool ponerEnMantenimiento();
    //pone un servidor en MANTENIMIENTO. S�lo es posible pasar al estado MANTENIMIENTO para aquellos
    //servidores que est�n INACTIVOS. El m�todo devolver� true en caso de poder poner al servidor en
    //MANTENIMIENTO; false en caso contrario, esto es, cuando el servidor est� previamente ACTIVO, o bien
    //ya est� en MANTENIMIENTO.

    void mostrarInformacion();
    //muestra por pantalla informaci�n de inter�s del servidor. En concreto, muestra la direcci�n y el
    //identificador del servidor, su estado, la relaci�n entre el m�ximo de jugadores que puede alojar y
    //el n�mero real de jugadores conectados. Tambi�n mostrar� el n�mero m�ximo de jugadores que pueden
    //estar esperando acceso, junto con el n�mero de elementos tipo Jugador encolados en jugadoresEnEspera
    //con dicho prop�sito. Finalmente, tambi�n mostrar� el puerto de escucha del servidor y la latencia
    //media de los jugadores conectados, y la localizaci�n geogr�fica del servidor (pa�s).

    bool expulsarJugador(cadena nombre);
    //expulsa el jugador cuyo nombreJugador coincide con el par�metro nombre de la lista de conectados,
    //o bien de la cola de espera, en funci�n de d�nde est� contenida la instancia de tipo Jugador
    //correspondiente. Si el jugador es localizado en alguna de estas estructuras y convenientemente
    //eliminado el m�todo devolver� true; false en caso contrario. Si el jugador a expulsar es localizado
    //en la lista de jugadores conectados, tras eliminarlo, ser� necesario comprobar si hay alguien en
    //la lista de espera. En caso positivo, el primero de la cola ser� autom�ticamente conectado
    //al servidor, pasando a la lista de conectados.

    void getNombreJuego(cadena nJ);
    //devuelve el valor del atributo nombreJuego a trav�s del par�metro de entrada/salida nJ.

    int getPuerto();
    //devuelve el valor del atributo puerto.

    void getLocalizacionGeografica(cadena lG);
    //devuelve el valor del atributo localizacionGeografica a trav�s del par�metro de entrada/salida lG.

    int getMaxJugadoresConectados();
    //devuelve el valor del atributo maxJugadoresConectados.

    int getMaxJugadoresEnEspera();
    //devuelve el valor del atributo maxJugadoresEnEspera.

    int getNumJugadoresConectados();
    //devuelve el n�mero de jugadores conectados al servidor.

    int getNumJugadoresEnEspera();
    //devuelve el n�mero de jugadores en la cola de espera de acceso al servidor.

    void exportarJugadoresConectados(Jugador *conectados);
    //el m�todo copiara todos los jugadores alojados en el servidor en el vector din�mico accesible desde
    //el puntero conectados, par�metro de entrada.

    void exportarJugadoresEnEspera(Jugador *enEspera);
    //el m�todo copiara todos los jugadores que est�n en la cola de espera para el acceso al servidor en
    //el vector din�mico accesible desde el puntero conectados, par�metro de entrada.
};

#endif // SERVIDOR_H
