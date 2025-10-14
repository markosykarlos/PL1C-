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
