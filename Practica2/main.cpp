#include "GestorServidores.h"

Jugador crearJugador(cadena nJ, int id, bool activo, int latencia, long puntuacion, cadena pais);
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
                if(pos>1)
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
    gestor.desplegarServidor("0.0.0.1", "SpaceWar", 1, 1, 2, 8080, "Huelva");
    gestor.desplegarServidor("0.0.0.2", "SpaceWar", 2, 2, 1, 8080, "Cadiz");
    gestor.desplegarServidor("0.0.0.3", "Call of Duty", 3, 2, 1, 8080, "Sevilla");
    gestor.desplegarServidor("0.0.0.4", "Call of Duty", 4, 1, 2, 8080, "Almeria");
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
