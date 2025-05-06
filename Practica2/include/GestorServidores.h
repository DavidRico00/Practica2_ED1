#ifndef GESTORSERVIDORES_H
#define GESTORSERVIDORES_H

#include "Servidor.h"

class GestorServidores{

    Servidor *primerServidor;
    int numServidores;

public:
    GestorServidores();
    ~GestorServidores();
    int getNumServidores();
    bool desplegarServidor(cadena dS, cadena nJ, int i, int mxC, int mxE, int p, cadena lG);

    bool desconectarServidor(cadena dS);
    //el método intentará desconectar (poner en estado INACTIVO) el servidor cuya dirección/hostname
    //coincide con el valor indicado en el parámetro de entrada dS. Si el servidor a desactivar estaba
    //ACTIVO, será necesario expulsar a los jugadores que estaban en espera, y redirigir a los que estaban
    //ya alojados en el servidor a otros nodos activos del sistema con el mismo juego instalado. El
    //proceso de redistribución de los jugadores priorizará aquellos con menor tiempo de respuesta (ping).
    //La distribución se realizará de forma equitativa entre los distintos servidores activos del sistema,
    //esto es, cada jugador considerado será alojado en el servidor con el mayor número de espacios
    //disponibles en su correspondiente lista de jugadores conectados. El mismo criterio se seguirá en
    //caso de no poder alojar al jugador que toca al alguno de los servidores al estar todos llenos, y
    //tener que incluirlo en alguna cola de espera. Aquellos jugadores para los que no haya espacios
    //disponibles en alguno de los servidores, ni en ninguna de las colas de espera, serán expulsados
    //del sistema.

    bool conectarServidor(cadena dS);
    bool realizarMantenimiento(cadena dS);
    bool eliminarServidor(cadena dS);

    bool alojarJugador(Jugador j, cadena nomJuego, cadena host, bool &enEspera);
    //el método intentará alojar al jugador (tipo Jugador) j en algún servidor ACTIVO para el juego de
    //nombre nomJuego. Si no se encuentra ningún servidor activo del juego indicado, el método finalizará
    //devolviendo false, además de otro false a través del parámetro por referencia enEspera. En caso
    //contrario, criterio será el de alojar al jugador en el servidor cuya diferencia entre el número
    //máximo de jugadores soportado y el número de usuarios actualmente conectados sea la mayor. Si se
    //encuentra algún servidor con conexiones disponible el jugador será alojado en éste añadiéndolo a
    //la lista jugadoresConectados correspondiente. El método finalizará devolviendo true, junto con la
    //dirección/hostname del servidor a través del parámetro de entrada/salida host. Si por contra no
    //hay espacio disponible en ninguno de los servidores, se intentará añadir al jugador a alguna de
    //las colas de espera. El criterio será el de añadir al jugador a aquella cola para la que la
    //diferencia entre el número máximo de jugadores que pueden estar en espera, y el número de elementos
    //ya encolados es la mayor. En caso de encolar al jugador en alguna cola de espera, el método
    //devolverá un false, además de un true a través del parámetro por referencia enEspera, indicando
    //así que el jugador no ha podido ser alojado en alguno de los servidores, y que se encuentra a la
    //espera de poder conectarse a alguno. Además, en ese caso se indicará el nombre/dirección del
    //servidor dónde está encolado a través del parámetro de entrada/salida host. Si el jugador no ha
    //podido ser conectado ni encolado en una estructura de espera, el método finalizará nuevamente
    //devolviendo un false, junto con otro false a través del parámetro por referencia enEspera.

     bool expulsarJugador(cadena nJ, cadena host);
    //el método expulsará al jugador de nombre nJ de cualquier servidor o cola de espera del sistema
    //en la que esté ubicado. El método devolverá true en caso de localizar y expulsar al jugador
    //indicado, devolviendo además la dirección/hostname del servidor en el que estaba conectado o bien
    //a la espera de acceso al mismo; false en caso contrario, al no encontrarse en el sistema el jugador
    //indicado. Si el jugador en cuestión estaba conectado a un servidor, al ser expulsado habrá que
    //garantizar que, en caso de haber jugadores en cola de espera para acceder al mismo, el primero de
    //dicha estructura pase a ser alojado en este servidor de forma automática.

    int getPosicionServidor(cadena dS);
    void mostrarInformacionServidores(int pos);
    bool jugadorConectado(cadena nJ, cadena dS);
    bool jugadorEnEspera(cadena nJ, cadena dS);
    bool jugadorConectado(cadena nJ);
    bool jugadorEnEspera(cadena nJ);
};

#endif // GESTORSERVIDORES_H
