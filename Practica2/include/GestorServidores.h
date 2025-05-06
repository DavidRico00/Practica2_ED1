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
    //el m�todo intentar� desconectar (poner en estado INACTIVO) el servidor cuya direcci�n/hostname
    //coincide con el valor indicado en el par�metro de entrada dS. Si el servidor a desactivar estaba
    //ACTIVO, ser� necesario expulsar a los jugadores que estaban en espera, y redirigir a los que estaban
    //ya alojados en el servidor a otros nodos activos del sistema con el mismo juego instalado. El
    //proceso de redistribuci�n de los jugadores priorizar� aquellos con menor tiempo de respuesta (ping).
    //La distribuci�n se realizar� de forma equitativa entre los distintos servidores activos del sistema,
    //esto es, cada jugador considerado ser� alojado en el servidor con el mayor n�mero de espacios
    //disponibles en su correspondiente lista de jugadores conectados. El mismo criterio se seguir� en
    //caso de no poder alojar al jugador que toca al alguno de los servidores al estar todos llenos, y
    //tener que incluirlo en alguna cola de espera. Aquellos jugadores para los que no haya espacios
    //disponibles en alguno de los servidores, ni en ninguna de las colas de espera, ser�n expulsados
    //del sistema.

    bool conectarServidor(cadena dS);
    //el m�todo permite activas (poner en estado ACTIVO) el servidor cuya direcci�n/hostname coincide
    //con el valor indicado en el par�metro de entrada dS. Devolver� true en caso de activar exitosamente
    //el servidor indicado; false en caso contrario, bien porque el servidor ya estaba activo, o bien
    //porque directamente no exist�a ning�n nodo con la direcci�n/hostname indicado.

    bool realizarMantenimiento(cadena dS);
    //el m�todo permite poner en estado MANTENIMIENTO el servidor cuya direcci�n/hostname coincide con
    //el valor indicado en el par�metro de entrada dS. Devolver� true en caso de poner exitosamente el
    //servidor indicado en mantenimiento; false en caso contrario, bien porque el servidor ya estaba en
    //dicho estado, o bien porque directamente no exist�a ning�n nodo con la direcci�n/hostname indicado.

    bool eliminarServidor(cadena dS);
    //el m�todo eliminar� de la estructura de nodos enlazados el servidor cuya direcci�n/hostname coincide
    //con el valor indicado en el par�metro de entrada dS. Este m�todo es aplicable solamente sobre
    //aquellos servidores en estado INACTIVO o MANTENIMIENTO. El m�todo devolver� true en caso de
    //eliminarse de forma exitosa el servidor indicado; falso en caso contrario, esto es, cuando no
    //exista ning�n nodo con la direcci�n/hostname indicado, o bien el servidor afectado no est� INACTIVO
    //o en MANTENIMIENTO.

    bool alojarJugador(Jugador j, cadena nomJuego, cadena host, bool &enEspera);
    //el m�todo intentar� alojar al jugador (tipo Jugador) j en alg�n servidor ACTIVO para el juego de
    //nombre nomJuego. Si no se encuentra ning�n servidor activo del juego indicado, el m�todo finalizar�
    //devolviendo false, adem�s de otro false a trav�s del par�metro por referencia enEspera. En caso
    //contrario, criterio ser� el de alojar al jugador en el servidor cuya diferencia entre el n�mero
    //m�ximo de jugadores soportado y el n�mero de usuarios actualmente conectados sea la mayor. Si se
    //encuentra alg�n servidor con conexiones disponible el jugador ser� alojado en �ste a�adi�ndolo a
    //la lista jugadoresConectados correspondiente. El m�todo finalizar� devolviendo true, junto con la
    //direcci�n/hostname del servidor a trav�s del par�metro de entrada/salida host. Si por contra no
    //hay espacio disponible en ninguno de los servidores, se intentar� a�adir al jugador a alguna de
    //las colas de espera. El criterio ser� el de a�adir al jugador a aquella cola para la que la
    //diferencia entre el n�mero m�ximo de jugadores que pueden estar en espera, y el n�mero de elementos
    //ya encolados es la mayor. En caso de encolar al jugador en alguna cola de espera, el m�todo
    //devolver� un false, adem�s de un true a trav�s del par�metro por referencia enEspera, indicando
    //as� que el jugador no ha podido ser alojado en alguno de los servidores, y que se encuentra a la
    //espera de poder conectarse a alguno. Adem�s, en ese caso se indicar� el nombre/direcci�n del
    //servidor d�nde est� encolado a trav�s del par�metro de entrada/salida host. Si el jugador no ha
    //podido ser conectado ni encolado en una estructura de espera, el m�todo finalizar� nuevamente
    //devolviendo un false, junto con otro false a trav�s del par�metro por referencia enEspera.

     bool expulsarJugador(cadena nJ, cadena host);
    //el m�todo expulsar� al jugador de nombre nJ de cualquier servidor o cola de espera del sistema
    //en la que est� ubicado. El m�todo devolver� true en caso de localizar y expulsar al jugador
    //indicado, devolviendo adem�s la direcci�n/hostname del servidor en el que estaba conectado o bien
    //a la espera de acceso al mismo; false en caso contrario, al no encontrarse en el sistema el jugador
    //indicado. Si el jugador en cuesti�n estaba conectado a un servidor, al ser expulsado habr� que
    //garantizar que, en caso de haber jugadores en cola de espera para acceder al mismo, el primero de
    //dicha estructura pase a ser alojado en este servidor de forma autom�tica.

    int getPosicionServidor(cadena dS);
    //el m�todo devolver� la posici�n en la que se encuentra el servidor cuya direcci�n/hostname es igual
    //a dS dentro de la secuencia que forman el conjunto de nodos enlazados, siendo el primer nodo el
    //que ocupa la posici�n 1. Si no hay en la estructura de nodos enlazados ning�n servidor con la
    //direcci�n indicada, el m�todo devolver� un -1.

    void mostrarInformacionServidores(int pos);
    //muestra por pantalla informaci�n del servidor que se encuentra en la posici�n indicada por el
    //par�metro pos dentro de la secuencia de nodos-servidores, d�nde el primer servidor es el situado
    //en la posici�n 1. Si la posici�n indicada est� fuera de rango, deber� informarse al usuario de tal
    //circunstancia a trav�s de un mensaje de error. Si la posici�n indicada a trav�s de pos es -1,
    //deber� mostrarse por pantalla informaci�n sobre la totalidad de los servidores contenidos en la
    //estructura de nodos enlazados. Para servidores activos, ser� tambi�n necesario mostrar por pantalla
    //los datos de los jugadores conectados, as� como la de aquellos que est�n en la cola de acceso al
    //mismo.

    bool jugadorConectado(cadena nJ, cadena dS);
    bool jugadorEnEspera(cadena nJ, cadena dS);
    bool jugadorConectado(cadena nJ);
    bool jugadorEnEspera(cadena nJ);
};

#endif // GESTORSERVIDORES_H
