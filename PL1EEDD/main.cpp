#include <iostream>

using namespace std;

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

struct pedido
{
    string id_editorial;
    string id_pedido;
    string cod_libro;
    string materia;
    string estado;
    int unidades;
};

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

int main()
{int x;
    int n;
    string f;
    do{
    ImprimirMenu();
    cin >> x;
    switch(x){
case 1:
    cout << "Cuantos pedidos quiere generar?: ";
    cin >> n;
    cout << "Se han generado " << n << " pedidos\n" << endl;
    break;
case 2:
    cout << "A que fase quiere pasar?: ";
    cin >> f;
    cout << "Se ha pasado a fase " << f << endl;
    break;
case 3:
    cout << "Estado del sistema\n" << endl;
    break;
case 4:
    cout << "Caja de reparto de una moto\n" << endl;
    break;
case 0:
    cout << "Sesion cerrada" << endl;
    return 0;
    }
}
}
