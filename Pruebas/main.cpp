#include <iostream>
#include "TADLista_C_NES.h"

using namespace std;

void pruebasTADLista_C_NES();

void comprobarValor(float obtenido, float esperado, const string& contexto) {
    cout << "Verificando: " << contexto << endl;
    if (obtenido == esperado)
        cout << "  [OK] Valor correcto: " << obtenido << endl;
    else
        cout << "  [ERROR] Valor incorrecto. Obtenido: " << obtenido << ", Esperado: " << esperado << endl;
}

void comprobarCondicion(bool condicion, const string& contexto) {
    cout << "Verificando: " << contexto << endl;
    if (condicion)
        cout << "  [OK] Condicion verdadera" << endl;
    else
        cout << "  [ERROR] Condicion falsa" << endl;
}

int main() {
    pruebasTADLista_C_NES();
    return 0;
}

void pruebasTADLista_C_NES()
{
    cout << "=== INICIO DE PRUEBAS PARA Lista_C_NES ===" << endl;

    Lista_C_NES lista;

    cout << "\nCreando lista vacia..." << endl;
    comprobarCondicion(lista.esvacia(), "Lista esta vacia");
    comprobarValor(lista.longitud(), 0, "Longitud inicial de la lista");

    cout << "\nAgregando elementos por la izquierda..." << endl;
    lista.anadirIzq(10); // Lista: 10
    lista.anadirIzq(20); // Lista: 20 -> 10
    comprobarValor(lista.longitud(), 2, "Longitud despues de anadirIzq(10), anadirIzq(20)");
    comprobarValor(lista.observarIzq(), 20, "observarIzq debe ser 20");
    comprobarValor(lista.observarDch(), 10, "observarDch debe ser 10");

    cout << "\nAgregando elemento por la derecha: 30" << endl;
    lista.anadirDch(30); // Lista: 20 -> 10 -> 30
    comprobarValor(lista.longitud(), 3, "Longitud tras anadirDch(30)");
    comprobarValor(lista.observarDch(), 30, "observarDch debe ser 30");

    cout << "\nMostrando todos los elementos con observar(i):" << endl;
    for (int i = 1; i <= lista.longitud(); i++) {
        cout << "  Elemento en posicion " << i << ": " << lista.observar(i) << endl;
    }

    cout << "\nModificando posicion 2 con valor 99" << endl;
    lista.modificar(2, 99); // Lista: 20 -> 99 -> 30
    comprobarValor(lista.observar(2), 99, "observar(2) despues de modificar debe ser 99");

    cout << "\nInsertando 77 en posicion 2" << endl;
    lista.insertar(2, 77); // Lista: 20 -> 77 -> 99 -> 30
    comprobarValor(lista.observar(2), 77, "observar(2) debe ser 77 tras insertar");
    comprobarValor(lista.longitud(), 4, "Longitud debe ser 4 tras insertar");

    cout << "\nEliminando primer elemento..." << endl;
    lista.eliminarIzq(); // Eliminar 20 -> Lista: 77 -> 99 -> 30
    comprobarValor(lista.observar(1), 77, "observar(1) despues de eliminar debe ser 77");

    cout << "\nEliminando ultimo elemento..." << endl;
    lista.eliminarDch(); // Eliminar 30 -> Lista: 77 -> 99
    comprobarValor(lista.longitud(), 2, "Longitud debe ser 2 tras eliminarDch");
    comprobarValor(lista.observarDch(), 99, "observarDch debe ser 99");

    cout << "\nVerificando pertenencia de valores..." << endl;
    comprobarCondicion(lista.pertenece(77), "77 pertenece a la lista");
    comprobarValor(lista.posicion(99), 2, "posicion de 99 debe ser 2");
    comprobarCondicion(!lista.pertenece(123), "123 no pertenece a la lista");
    comprobarValor(lista.posicion(123), -1, "posicion(123) debe devolver -1");

    cout << "\nConcatenando otra lista con elementos 5 y 6" << endl;
    Lista_C_NES otra;
    otra.anadirDch(5);
    otra.anadirDch(6);
    lista.concatenar(otra); // Lista: 77 -> 99 -> 5 -> 6
    comprobarValor(lista.longitud(), 4, "Longitud tras concatenar debe ser 4");
    comprobarValor(lista.observar(3), 5, "Elemento en posicion 3 debe ser 5");
    //comprobarCondicion(otra.esvacia(), "La lista 'otra' debe quedar vacia tras concatenar");

    cout << "\nEliminando todos los elementos uno por uno..." << endl;
    while (!lista.esvacia()) {
        cout << "  Eliminando elemento izquierdo: " << lista.observarIzq() << endl;
        lista.eliminarIzq();
    }
    comprobarCondicion(lista.esvacia(), "Lista debe estar vacia al final");
    comprobarValor(lista.longitud(), 0, "Longitud final debe ser 0");

    cout << "\n=== FIN DE PRUEBAS ===" << endl;
}
