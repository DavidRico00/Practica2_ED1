#include "GestorServidores.h"

void prueba()
{
    cout<<"PRUEBAS DE GESTOR DE SERVIDORES"<<endl;
    GestorServidores gestor;

    gestor.desplegarServidor("192.168.1.1", "SpaceWar", 1, 10, 5, 8080, "Zaragoza") ?
        cout << "[OK] Servidor ID:1 desplegado correctamente\n" : cout << "[EROR] Error al desplegar Servidor ID:1\n";

    gestor.desplegarServidor("192.168.1.2", "SpaceWar", 2, 20, 10, 8080, "Sevilla") ?
        cout << "[OK] Servidor ID:2 desplegado correctamente\n" : cout << "[EROR] Error al desplegar Servidor ID:2\n";

    gestor.desplegarServidor("192.168.1.3", "SpaceWar", 3, 15, 7, 8080, "Almeria") ?
        cout << "[OK] Servidor ID:3 desplegado correctamente\n" : cout << "[EROR] Error al desplegar Servidor ID:3\n";

    gestor.desplegarServidor("192.168.2.1", "Call Of Duty", 1, 10, 5, 1111, "A") ?
        cout << "[EROR] Servidor ID:1 (copia id) desplegado correctamente\n" : cout << "[OK] Error al desplegar Servidor ID:1 (copia id)\n";

    gestor.desplegarServidor("192.168.1.1", "Call Of Duty", -1, 10, 5, 1111, "A") ?
        cout << "[EROR] Servidor ID:-1 (copia host ID 1) desplegado correctamente\n" : cout << "[OK] Error al desplegar Servidor ID:-1 (copia host ID1)\n";


    cout<<"\nMOSTRAR INFORMACION DE TODOS LOS SERVIDORES"<<endl;
    cout<<"Numero de servidores: "<<gestor.getNumServidores()<<endl;
    gestor.mostrarInformacionServidores(-1);
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
        cout<<"Indique la opcion deseada: ";
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
    prueba();

    int opc;

    do
    {
        //opc = menu();
        opc=9;

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

        }//fin switch

        cout<<endl;
        PAUSE;
    }
    while(opc != 9);

    return 0;
}
