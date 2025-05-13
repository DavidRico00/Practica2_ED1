#include "GestorServidores.h"

void mostrarServidores(GestorServidores &gestor)
{
    cout<<"\nMOSTRAR INFORMACION DE TODOS LOS SERVIDORES"<<endl;
    cout<<"Numero de servidores: "<<gestor.getNumServidores()<<endl;
    gestor.mostrarInformacionServidores(-1);
    cout<<endl;
}

Jugador crearJugador(cadena nJ, int id, bool activo, int latencia, long puntuacion, cadena pais)
{
    Jugador j;
    strcpy(j.nombreJugador, nJ);
    j.ID=id;
    j.activo=activo;
    j.latencia=latencia;
    j.puntuacion=puntuacion;
    strcpy(j.pais, pais);

    return j;
}

void prueba()
{
    cadena host;
    bool enEspera;

    cout<<"PRUEBAS DE GESTOR DE SERVIDORES"<<endl;
    GestorServidores gestor;

    //AÑADO ZARAGOZA
    gestor.desplegarServidor("192.168.1.1", "SpaceWar", 1, 30, 5, 8080, "Zaragoza") ?
        cout << "[OK] Servidor ID:1 desplegado correctamente. Zaragoza (no existe)\n" : cout << "[EROR] Error al desplegar Servidor ID:1. Zaragoza\n";

    //AÑADO SEVILLA
    gestor.desplegarServidor("192.168.1.2", "SpaceWar", 2, 20, 10, 8080, "Sevilla") ?
        cout << "[OK] Servidor ID:2 desplegado correctamente. Sevilla (no existe)\n" : cout << "[EROR] Error al desplegar Servidor ID:2. Sevilla\n";

    //AÑADO ALMERIA
    gestor.desplegarServidor("192.168.1.3", "SpaceWar", 3, 15, 7, 8080, "Almeria") ?
        cout << "[OK] Servidor ID:3 desplegado correctamente. Almeria (no existe)\n" : cout << "[EROR] Error al desplegar Servidor ID:3. Almeria\n";

    //ELIMINO SEVILLA
    gestor.eliminarServidor("192.168.1.2") ?
        cout << "[OK] Servidor Sevilla eliminado correctamente (existe)\n" : cout << "[ERROR] Error al borrar servidor en Sevilla\n";

    //AÑADO BARCELONA
    gestor.desplegarServidor("192.168.1.4", "SpaceWar", 4, 10, 8, 8080, "Barcelona") ?
        cout << "[OK] Servidor ID:4 desplegado correctamente. Barcelona (no existe)\n" : cout << "[EROR] Error al desplegar Servidor ID:4. Barcelona\n";

    //AÑADO A (ERROR)
    gestor.desplegarServidor("0.0.0.0", "Prueba", 1, 0, 0, 0, "A") ?
        cout << "[EROR] Servidor ID:1 desplegado correctamente\n" : cout << "[OK] Error al desplegar Servidor ID:1 (copia id ID:1)\n";

    //AÑADO B (ERROR)
    gestor.desplegarServidor("192.168.1.1", "Prueba", -1, 0, 0, 0, "B") ?
        cout << "[EROR] Servidor ID:-1 desplegado correctamente\n" : cout << "[OK] Error al desplegar Servidor ID:-1 (copia host ID:1)\n";

    //POSICION DE BARCELONA
    int pos = gestor.getPosicionServidor("192.168.1.4");
        pos!=-1 ? cout<<"[OK] Barcelona -> Posicion: "<<pos<<" (pos=2)"<<endl : cout<<"[ERROR] Barcelona -> Posicion: "<<pos<<endl;

    //ELIMINO BARCELONA
    gestor.eliminarServidor("192.168.1.4") ?
        cout << "[OK] Servidor Barcelona eliminado correctamente (existe)\n" : cout << "[ERROR] Error al borrar servidor en Barcelona\n";

    //ELIMINO SEVILLA (ERROR)
    gestor.eliminarServidor("192.168.1.2") ?
        cout << "[ERROR] Servidor Sevilla eliminado correctamente\n" : cout << "[OK] Error al borrar servidor en Sevilla (no existe)\n";

    //POSICION DE SEVILLA
    pos = gestor.getPosicionServidor("192.168.1.2");
        pos!=-1 ? cout<<"[ERROR] Sevilla -> Posicion: "<<pos<<endl : cout<<"[OK] Sevilla -> Posicion: "<<pos<<" (pos=-1)"<<endl;

    //PONER ALMERIA EN MANTENIMIENTO
    gestor.realizarMantenimiento("192.168.1.3") ?
        cout<<"[OK] Servidor Almeria puesto en mantenimiento (esta inactivo)\n" : cout<<"[ERROR] Error al poner servidor Almeria puesto en mantenimiento\n";

    //PONER ALMERIA EN ACTIVO
    gestor.conectarServidor("192.168.1.3") ?
        cout<<"[OK] Servidor Almeria activado (esta en mantenimiento)\n" : cout<<"[ERROR] Error al activar servidor Almeria\n";



    //PONER ZARAGOZA EN ACTIVO
    gestor.conectarServidor("192.168.1.1");

    Jugador j1 = crearJugador("David", 1, true, 20, 1000, "Huelva");

    //ALOJAR JUGADOR
    gestor.alojarJugador(j1, "SpaceWar", host, enEspera);

    gestor.jugadorConectado("David") ?
        cout<<"[OK] David si esta\n" : cout<<"[ERROR] David no esta\n";

    gestor.desconectarServidor("192.168.1.1");

    mostrarServidores(gestor);
}



int menu()
{
    int opcion;
    do
    {
        CLS;
        cout<<"GESTOR DE SERVIDORES   v1.0"<<endl;
        cout<<"================================"<<endl;
        cout<<"1. Mostrar Servidor\n2. Crear Servidor\n3. Eliminar servidor\n4. ActivarServidor"<<endl;
        cout<<"5. Desactivar Servidor\n6. Programar mantenimiento de servidor\n7. Conectar jugador"<<endl;
        cout<<"8. Expulsar jugador\n9. Salir\n"<<endl;
        cout<<"> Seleccione una opcion: ";
        cin>>opcion;
        if(opcion<1 || opcion>9)
        {
            cout<<"Opcion no valida, intentelo de nuevo\n\n";
            PAUSE;
        }
    }
    while(opcion<1 || opcion>9);

    return opcion;
}

int main()
{
    int opc;
    GestorServidores gestor;

    do
    {
        opc = menu();

        switch(opc)
        {

        case 1:
        {

        } break;

        case 2:
        {

        } break;

        case 3:
        {

        } break;

        case 4:
        {

        } break;

        case 5:
        {

        } break;

        case 6:
        {

        } break;

        case 7:
        {

        } break;

        case 8:
        {

        } break;

        case 9:
        {
            prueba();
        } break;

        }//fin switch

        cout<<endl;
        PAUSE;
    }
    while(opc != 9);

    return 0;
}
