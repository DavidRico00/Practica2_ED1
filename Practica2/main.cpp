#include "GestorServidores.h"

Jugador crearJugador(cadena nJ, int id, bool activo, cadena pais);
void cargarServidores(GestorServidores &gestor);
int menu(int num);

int main()
{
    int opc;
    GestorServidores gestor;
    cargarServidores(gestor);

    do
    {
        opc = menu(gestor.getNumServidores());
        cout<<endl;

        cadena host;

        switch(opc)
        {

        case 1:
        {
            cout<<"Dime la direccion de host del servidor o ALL para ver todos: ";
            cin>>host;
            if(strcmp(host, "ALL")==0)
            {
                if(gestor.getNumServidores()>0)
                    gestor.mostrarInformacionServidores(-1);
                else
                    cout<<"\nNo existe ningun servidor para mostrar"<<endl;
            }
            else
            {
                int pos = gestor.getPosicionServidor(host);
                if(pos>0)
                    gestor.mostrarInformacionServidores(pos);
                else
                    cout<<"\nNo existe ningun servidor con esa direccion"<<endl;
            }

        } break;

        case 2:
        {
            cadena nombreJuego, lGeo;
            int id, puerto, maxCon, maxEsp;

            cout<<"Dime la direccion de host: ";
            cin>>host;
            cout<<"Dime el identificador: ";
            cin>>id;
            cout<<"Dime nombre del juego: ";
            cin.ignore();
            cin.getline(nombreJuego, 50);
            cout<<"Dime el puerto: ";
            cin>>puerto;
            cout<<"Dime el numero maximo de jugadores conectados: ";
            cin>>maxCon;
            cout<<"Dime el numero maximo de jugadores en espera: ";
            cin>>maxEsp;
            cout<<"Dime la localizacion del servidor: ";
            cin.ignore();
            cin.getline(lGeo, 50);

            gestor.desplegarServidor(host, nombreJuego, id, maxCon, maxEsp, puerto, lGeo) ?
                cout<<"\nSe ha desplegado correctamente el nuevo servidor\n" : cout<<"\nNo se ha podido desplegar el nuevo servidor\n";

        } break;

        case 3:
        {
            cout<<"Dime la direccion del servidor a eliminar: ";
            cin>>host;

            int pos = gestor.getPosicionServidor(host);

            if(pos==-1)
                cout<<"\nNo existe ningun servidor con esa direccion"<<endl;
            else
            {
                gestor.desconectarServidor(host);
                gestor.eliminarServidor(host) ?
                    cout<<"\nServidor eliminado con exito\n" : cout<<"\nNo se ha podido eliminar el servidor\n";
            }

        } break;

        case 4:
        {
            cout<<"Dime la direccion del servidor a eliminar: ";
            cin>>host;

            int pos = gestor.getPosicionServidor(host);

            if(pos==-1)
                cout<<"\nNo existe ningun servidor con esa direccion"<<endl;
            else
            {
                if(gestor.conectarServidor(host))
                    cout<<"\nSe ha conectado el servidor correctamente"<<endl;
                else
                    cout<<"\nNo se ha podido conectar el servidor"<<endl;
            }

        } break;

        case 5:
        {
            cout<<"Dime la direccion del servidor a desactivar: ";
            cin>>host;

            int pos = gestor.getPosicionServidor(host);

            if(pos==-1)
                cout<<"\nNo existe ningun servidor con esa direccion"<<endl;
            else
            {
                if(gestor.desconectarServidor(host))
                    cout<<"\nSe ha desconectado el servidor correctamente"<<endl;
                else
                    cout<<"\nNo se ha podido desconectar el servidor"<<endl;
            }
        } break;

        case 6:
        {
            cout<<"Dime la direccion del servidor a poner en mantenimiento: ";
            cin>>host;

            int pos = gestor.getPosicionServidor(host);

            if(pos==-1)
                cout<<"\nNo existe ningun servidor con esa direccion"<<endl;
            else
            {
                if(gestor.realizarMantenimiento(host))
                    cout<<"\nEl servidor se ha puesto en mantenimiento correctamente"<<endl;
                else
                    cout<<"\nEl servidor no se ha podido poner en mantenimiento"<<endl;
            }
        } break;

        case 7:
        {
            Jugador jugador;
            cout<<"Dime el nick del nuevo jugador: ";
            cin.ignore();   cin.getline(jugador.nombreJugador, 50);

            if(gestor.jugadorConectado(jugador.nombreJugador))
                cout<<"\nEl nick ya esta utilizado en el sistema"<<endl;
            else
            {
                srand(time(0));

                cout<<"Dime el identificar del jugador: ";
                cin>>jugador.ID;
                cout<<"Dime el pais del jugador: ";
                cin.ignore();   cin.getline(jugador.pais, 50);
                jugador.latencia = rand() % 500 + 1;
                jugador.puntuacion = rand() % 100000;
                jugador.activo=true;

                cadena nombreJuego;
                cout<<"\nDime el nombre del juego al que quieres entrar: ";
                cin>>nombreJuego;

                bool enEspera, alojado;
                alojado = gestor.alojarJugador(jugador, nombreJuego, host, enEspera);

                if(alojado)
                    cout<<"\nEl jugado ha sido alojado correctamente en el servidor con direccion "<<host<<endl;
                else if(!alojado && enEspera)
                    cout<<"\nEl jugado esta en espera en el servidor con direccion "<<host<<endl;
                else
                    cout<<"\nEl jugador no se ha podido alojar en ningun servidor"<<endl;
            }
        } break;

        case 8:
        {
            cadena nombreJugador;
            cout<<"Dime el nombre del jugador a eliminar: ";
            cin.ignore();
            cin.getline(nombreJugador, 50);

            if(!gestor.jugadorConectado(nombreJugador))
                cout<<"\nEl jugador "<<nombreJugador<<" no esta en ningun servidor"<<endl;
            else
            {
                if(gestor.expulsarJugador(nombreJugador, host))
                    cout<<"\nJugador "<<nombreJugador<<" eliminado correctamente del servidor "<<host<<endl;
                else
                    cout<<"\nNo se ha podido eliminar al jugador "<<nombreJugador<<endl;
            }
        } break;

        case 9:
        {
            cout<<"Saliendo..."<<endl;
        } break;

        }//fin switch

        cout<<endl;
        PAUSE;
    }
    while(opc != 9);

    return 0;
}


void cargarServidores(GestorServidores &gestor)
{
    cadena host;    bool enEspera;

    gestor.desplegarServidor("0.0.0.1", "gta",  1, 1, 2, 8080, "Huelva");
    gestor.desplegarServidor("0.0.0.2", "gta",  2, 2, 1, 8080, "Cadiz");
    //gestor.desplegarServidor("0.0.0.3", "cod",  3, 2, 1, 8080, "Sevilla");
    //gestor.desplegarServidor("0.0.0.4", "cod",  4, 1, 2, 8080, "Almeria");

    gestor.conectarServidor("0.0.0.1");gestor.conectarServidor("0.0.0.2");
    gestor.conectarServidor("0.0.0.3");gestor.conectarServidor("0.0.0.4");

    gestor.alojarJugador(crearJugador("david 1", 1, true, "huelva"), "gta", host, enEspera);
    //gestor.alojarJugador(crearJugador("david 2", 2, true, "huelva"), "gta", host, enEspera);
    //gestor.alojarJugador(crearJugador("david 3", 3, true, "huelva"), "gta", host, enEspera);

}

int menu(int num)
{
    int opcion;
    do
    {
        CLS;
        cout<<"GESTOR DE SERVIDORES   v1.0\t\tNum Servidores: "<<num<<endl;
        cout<<"================================"<<endl;
        cout<<"1. Mostrar Servidor\n2. Crear Servidor\n3. Eliminar servidor\n4. Activar Servidor"<<endl;
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

Jugador crearJugador(cadena nJ, int id, bool activo, cadena pais)
{
    srand(time(0));
    Jugador j;
    strcpy(j.nombreJugador, nJ);
    j.ID=id;
    j.activo=activo;
    j.latencia = rand() % 500 + 1;
    j.puntuacion = rand() % 100000;
    strcpy(j.pais, pais);

    return j;
}
