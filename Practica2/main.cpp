#include "GestorServidores.h"

Jugador crearJugador(const char* nombre, int id, bool activo, int latencia, long puntuacion, const char* pais) {
    Jugador j;
    strcpy(j.nombreJugador, nombre);
    j.ID = id;
    j.activo = activo;
    j.latencia = latencia;
    j.puntuacion = puntuacion;
    strcpy(j.pais, pais);
    return j;
}

void pruebaServidor()
{
    cout << "===== INICIO DE PRUEBAS DE SERVIDOR =====" << endl;

    // Crear un servidor
    Servidor s("10.0.0.1", "JuegoPrueba", 100, 3, 2, 3000, "Argentina");

    // Mostrar estado inicial
    cout << "\n--- Estado Inicial ---" << endl;
    s.mostrarInformacion();

    // Activar servidor
    cout << "\nActivando servidor..." << endl;
    if (s.activar()) cout << "Servidor activado correctamente." << endl;
    else cout << "El servidor ya estaba activo." << endl;

    // Crear jugadores
    Jugador j1 = crearJugador("Ana", 1, true, 40, 1500, "Colombia");
    Jugador j2 = crearJugador("Luis", 2, true, 35, 1300, "Chile");
    Jugador j3 = crearJugador("Pedro", 3, true, 30, 1600, "Peru");
    Jugador j4 = crearJugador("Maria", 4, true, 50, 1100, "Ecuador");
    Jugador j5 = crearJugador("Jose", 5, true, 45, 1250, "Mexico");

    // Conectar jugadores
    cout << "\nConectando jugadores:" << endl;
    cout << "Ana: " << (s.conectarJugador(j1) ? "OK" : "Fallo") << endl;
    cout << "Luis: " << (s.conectarJugador(j2) ? "OK" : "Fallo") << endl;
    cout << "Pedro: " << (s.conectarJugador(j3) ? "OK" : "Fallo") << endl;

    // Jugadores en espera
    cout << "\nPoniendo jugadores en espera:" << endl;
    cout << "Maria: " << (s.ponerJugadorEnEspera(j4) ? "OK" : "Fallo") << endl;
    cout << "Jose: " << (s.ponerJugadorEnEspera(j5) ? "OK" : "Fallo") << endl;

    // Mostrar jugadores conectados
    cout << "\n--- Jugadores Conectados ---" << endl;
    s.mostrarJugadoresConectados();

    // Mostrar jugadores en espera
    cout << "\n--- Jugadores en Espera ---" << endl;
    s.mostrarJugadoresEnEspera();

    // Expulsar un jugador
    cout << "\nExpulsando a Luis..." << endl;
    if (s.expulsarJugador("Luis")) cout << "Luis expulsado correctamente." << endl;
    else cout << "No se encontro a Luis." << endl;

    // Mostrar despues de expulsion
    cout << "\n--- Jugadores Conectados Luego de Expulsion ---" << endl;
    s.mostrarJugadoresConectados();

    cout << "\n--- Jugadores en Espera Luego de Expulsion ---" << endl;
    s.mostrarJugadoresEnEspera();

    // Exportar jugadores conectados
    Jugador conectados[3];
    s.exportarJugadoresConectados(conectados);
    cout << "\nExportando jugadores conectados..." << endl;
    for (int i = 0; i < s.getNumJugadoresConectados(); i++) {
        cout << "- " << conectados[i].nombreJugador << endl;
    }

    // Exportar jugadores en espera
    Jugador enEspera[2];
    s.exportarJugadoresEnEspera(enEspera);
    cout << "\nExportando jugadores en espera..." << endl;
    for (int i = 0; i < s.getNumJugadoresEnEspera(); i++) {
        cout << "- " << enEspera[i].nombreJugador << endl;
    }

    // Mostrar estado antes de desactivar
    cout << "\n--- Estado Antes de Desactivar ---" << endl;
    s.mostrarInformacion();

    // Desactivar servidor
    cout << "\nDesactivando servidor..." << endl;
    if (s.desactivar()) cout << "Servidor desactivado correctamente." << endl;
    else cout << "Ya estaba inactivo." << endl;

    // Mostrar estado final
    cout << "\n--- Estado Final ---" << endl;
    s.mostrarInformacion();

    cout << "\n===== FIN DE PRUEBAS =====" << endl;
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
    int opc;

    do
    {
        opc = menu();

        switch(opc)
        {

        case 1:
        {
            pruebaServidor();
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
