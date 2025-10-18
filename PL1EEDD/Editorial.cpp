#include "Editorial.h"

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
        return {"", "", "", "", "", 0};

    int v = primero->valor;
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
        return {"", 0};

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
    cout << "4) Paso COMPLETO (4fases)" << endl;
    cout << "5) Ver caja de una libreria" << endl;
    cout << "0) Salir\n" << endl;
    cout << "Opcion: ";
}

int calcularSecuenciaAleatoria(void)
{
    int numaleat;
    numaleat=rand()%7;
    return numaleat;
}

int calcularSecuenciaAleatoria2(void)
{
    int rando;
    rando=rand()%9999;
    return rando;
}
