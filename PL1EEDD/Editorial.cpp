#include "Editorial.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Cola colaIniciado, colaAlmacen, colaImprenta, colaListo;
Pila cajas[LIBRERIAS];

// Destructor
Cola::~Cola()
{
    while (primero)
        desencolar();
}

// Encolar (añadir al final)
void Cola::encolar(pedido v)
{
    pNodo nuevo = new Nodo(v);
    if (ultimo)
        ultimo->siguiente = nuevo;
    ultimo = nuevo;
    if (!primero)
        primero = nuevo;
}

// Desencolar (sacar del frente)
pedido Cola::desencolar()
{
    if (!primero)
        return {-1, "", "", "", 0, ""};

    pedido v = primero->valor;
    pNodo nodo = primero;
    primero = nodo->siguiente;
    if (!primero)
        ultimo = NULL;
    delete nodo;
    return v;
}

// Destructor
Pila::~Pila()
{
    while (cima)
        desapilar();
}

// Apilar
void Pila::apilar(pedido v)
{
    pNodo nuevo = new Nodo(v, cima);
    cima = nuevo;
}

// Desapilar
pedido Pila::desapilar()
{
    if (!cima)
        return {-1, "", "", "", 0, ""};

    pNodo nodo = cima;
    pedido v = nodo->valor;
    cima = nodo->siguiente;
    delete nodo;
    return v;
}

void ImprimirMenu(void)
{
    cout << "=== MENU ===" << endl;
    cout << "1) Generar N pedidos" << endl;
    cout << "2) Paso (Una FASE)" << endl;
    cout << "3) Mostrar estado" << endl;
    cout << "4) Ver caja de una libreria" << endl;
    cout << "0) Salir\n" << endl;
    cout << "Opcion: ";
}

int calcularSecuenciaAleatoria(void)
{
    int numaleat;
    numaleat=rand()%6;
    return numaleat;
}

int calcularSecuenciaAleatoria2(void)
{
    return 10000 + rand() % 90000;
}

// Función complementaria de MostrarEstadoSistema(), aka "3"
void mostrarCola(const Cola& cola, const string& nombre) {
    cout << "COLA " << nombre << ":" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "| " << cola.contarElementos() << " pedidos en espera" << endl;
    cout << "-----------------------------------------------" << endl;
}

void mostrarEstadoSistema() {
    cout << "\n=== ESTADO DEL SISTEMA ===" << endl;

    // Mostrar todas las colas
    mostrarCola(colaIniciado, "INICIADO");
    mostrarCola(colaAlmacen, "ALMACEN");
    mostrarCola(colaImprenta, "IMPRENTA");
    mostrarCola(colaListo, "LISTO");

    // Mostrar cajas
    cout << "\n=== CAJAS ==============" << endl;
    for(int i = 0; i < LIBRERIAS; i++) {
        cout << "Libreria " << i << ": " << cajas[i].contarElementos()
             << "/" << CAP_CAJA << " pedidos" << endl;
    }
    cout << "==========================\n" << endl;
}
// Contar elementos en Cola
int Cola::contarElementos() const {
    int contador = 0;
    pNodo actual = primero;

    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

// Contar elementos en Pila
int Pila::contarElementos() const {
    int contador = 0;
    pNodo actual = cima;

    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}
