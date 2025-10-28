#ifndef EDITORIAL_H_INCLUDED
#define EDITORIAL_H_INCLUDED

#include <string>
using namespace std;

#define MAX_TITULOS 10 // nº de títulos en catálogo
#define N_PEDIDOS_PASO 12 // nº de pedidos procesados por fase
#define TAM_LOTE 10 // incremento de stock desde imprenta
#define LIBRERIAS 6 // ids 0..LIBRERIAS-1
#define CAP_CAJA 5 // nº de pedidos por caja antes de enviar

struct pedido
{
    int id_editorial;
    string id_pedido;
    string cod_libro;
    string materia;
    int unidades;
    string estado;
};

struct StockLibro {
    string cod_libro;
    string materia;
    int unidades;
};

class Nodo
{
private:
    pedido valor;
    Nodo *siguiente;
    friend class Cola;
    friend class Pila;

public:
    Nodo(pedido v, Nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef Nodo *pNodo;

class Cola
{
private:
    pNodo primero, ultimo;

public:
    Cola() : primero(NULL), ultimo(NULL) {}
    ~Cola();
    void encolar(pedido v);
    pedido desencolar();
    int contarElementos() const;
    bool estaVacia() const { return primero == NULL; }
    void mostrarCola(const string& nombre);
};

class Pila
{
private:
    pNodo cima;

public:
    Pila() : cima(NULL) {} // Constructor
    ~Pila();
    void apilar(pedido v);
    pedido desapilar();
    int contarElementos() const;
    bool estaVacia() const { return cima == NULL; }
    void mostrarPila(const string& nombre);
};

// Declaración de Funciones
void ImprimirMenu();
void MostrarPedidosCreados(int n);
void mostrarEstadoSistema();
void pasarFase();
//void generarPrede();
void CrearStock();
StockLibro* buscarLibroEnStock(const string& cod_libro);
void mostrarStock();
void VerCaja();

#endif // EDITORIAL_H_INCLUDED
