#ifndef COMUN_H
#define COMUN_H

#define PAUSE system("pause");
#define CLS system("cls");

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef char cadena[50];

struct Jugador{
    cadena nombreJugador;   //nombre de usuario del un jugador. Es �nico en el sistema.
    int ID;                 //c�digo num�rico (entero positivo) identificador de un jugador. Es �nico en el sistema.
    bool activo;            //valor l�gico que indica si el jugador est� o no conectado a un servidor.
    int latencia;           /*tiempo de respuesta del jugador calculado por el sistema cuando recibe una petici�n
                            de conexi�n. Se mide en milisegundos*/
    long puntuacion;        /*puntuaci�n acumulada por el jugador a lo largo de todas las temporadas en las que
                            �ste ha participado en el juego*/
    cadena pais;            //nombre del pa�s desde el que se conecta el jugador.
};

#endif // COMUN_H
