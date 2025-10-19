#include "Editorial.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

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

int GenerarLib(void)
{
    int numaleat;
    numaleat=rand()%6;
    return numaleat;
}

string GenerarNumPedido(void)
{
    int numaleat;
    numaleat=rand()%99999;
    return "P" + to_string(numaleat);
}

string GenerarCodLibro(void)
{
    int numaleat;
    int numaleat2;
    int indaleat;
    char letras[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    numaleat=rand()%999;
    indaleat=rand()%26;
    numaleat=rand()%99;
    return to_string(numaleat) + letras[indaleat] + to_string(numaleat2);
}

string GenerarMateria(){
    int numaleat;
    numaleat=rand()%6;
    string Materias[] = {"Matematicas","Fisica","Tecnologia","Musica","Historia","Lengua"};
    return Materias[numaleat];
}

int GenerarUnidades(){
    int numaleat;
    numaleat=rand()%21;
    return numaleat;
}

string GenerarEstado(int indice){
    string Estados[] = {"Iniciado", "Almacén", "Imprenta", "Listo", "Caja"};
    return Estados[indice];
}

pedido GenerarPedido(){
    int lib = GenerarLib();
    string id = GenerarNumPedido();
    string codigo = GenerarCodLibro();
    string materia = GenerarMateria();
    int unidades = GenerarUnidades();
    string estado = GenerarEstado(0);
    pedido p = {lib, id, codigo, materia, unidades, estado};
    return p;
}

void CrearPedidos(int n){

}

void MostrarPedidosCreados(int n){
    int i;
    for(i=0; i<n; i++){
        pedido p = GenerarPedido();
        colaIniciado.encolar(p);
    }
    Cola aux = colaIniciado;
    cout << "-----------------------------------------------" << endl;
    cout << "Lib|     Id|  Codigo|      Materia|  U|      Estado|" << endl;
    cout << "-----------------------------------------------" << endl;
    while(!aux.estaVacia()) {
            pedido p = aux.primero->valor;
        cout << p.id_editorial << "|  " << p.id_pedido << "|  " << p.cod_libro << "|  "
        << p.materia << "|  " << p.unidades << "|  " << p.estado << "|  " << endl;
        aux.desencolar();
    }
}
