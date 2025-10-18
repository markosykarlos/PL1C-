#ifndef EDITORIAL_H_INCLUDED
#define EDITORIAL_H_INCLUDED

#define MAX_TITULOS 10 // n� de t�tulos en cat�logo
#define N_PEDIDOS_PASO 12 // n� de pedidos procesados por fase
#define TAM_LOTE 10 // incremento de stock desde imprenta
#define LIBRERIAS 6 // ids 0..LIBRERIAS-1
#define CAP_CAJA 5 // n� de pedidos por caja antes de enviar

class Nodo
{
private:
    pedido valor;
    Nodo *siguiente;
    friend class Cola;


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
    int desencolar();
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
};

struct pedido
{
    int id_editorial;
    string id_pedido;
    string cod_libro;
    string materia;
    int unidades;
    string estado;
};

#endif // EDITORIAL_H_INCLUDED
