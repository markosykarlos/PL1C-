#include "Editorial.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

Cola colaIniciado, colaAlmacen, colaImprenta, colaListo;
Pila cajas[LIBRERIAS];
NodoStock* stockPun = NULL;

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

void generarPrede() {
    // Pedidos predeterminados
    pedido pedidosFijos[] = {
        {0, "P10001", "111A22", "Matematicas", 5, "Iniciado"},
        {1, "P10002", "333B44", "Fisica", 3, "Iniciado"},
        {2, "P10003", "555C67", "Historia", 8, "Almacen"},
        {3, "P10004", "777D88", "Lengua", 6, "Imprenta"},
        {4, "P10005", "999E00", "Tecnologia", 4, "Listo"}
    };

    for(int i = 0; i < 5; i++) {
        if (pedidosFijos[i].estado == "Iniciado") {
            colaIniciado.encolar(pedidosFijos[i]);
        } else if (pedidosFijos[i].estado == "Almacen") {
            colaAlmacen.encolar(pedidosFijos[i]);
        } else if (pedidosFijos[i].estado == "Imprenta") {
            colaImprenta.encolar(pedidosFijos[i]);
        } else if (pedidosFijos[i].estado == "Listo") {
            colaListo.encolar(pedidosFijos[i]);
        }
    }
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

// Función complementaria de MostrarEstadoSistema()
void mostrarCola(const Cola& cola, const string& nombre) {
    cout << endl << "COLA " << nombre << ":" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Lib|     Id|  Codigo|      Materia|  U|      Estado|" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    if (cola.estaVacia()) {
        cout << "                    VACIA" << endl;
    } else {
        pNodo actual = cola.primero;
        int contador = 0;

        while (actual != NULL) {
            pedido p = actual->valor;
            cout << p.id_editorial << " |  " << p.id_pedido << " |  " << p.cod_libro << " |  "
                 << p.materia;
            cout << "\t|  " << p.unidades << " |  " << p.estado << endl;

            actual = actual->siguiente;
            contador++;
        }
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Total: " << contador << " pedidos" << endl << endl;
    }
}

// Opcion 3 del menu
void mostrarEstadoSistema() {
    cout << "\n=== ESTADO DEL SISTEMA ===" << endl;

    // Mostrar pedidos
    mostrarCola(colaIniciado, "INICIADO");
    mostrarCola(colaAlmacen, "ALMACEN");
    mostrarCola(colaImprenta, "IMPRENTA");
    mostrarCola(colaListo, "LISTO");

    // Mostrar cajas
    cout << "\n=== CAJAS ===" << endl;
    for(int i = 0; i < LIBRERIAS; i++) {
        cout << "Libreria " << i << ": " << cajas[i].contarElementos()
             << "/" << CAP_CAJA << " pedidos" << endl;
    }
    cout << "================\n" << endl;
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

// Genera una Número aleatori0 (0-5)
int GenerarLib(void)
{
    int numaleat;
    numaleat=rand()%6;
    return numaleat;
}

//Genera un número de pedido aleatorio (0-99998)
string GenerarNumPedido(void)
{
    int numaleat;
    numaleat= 10000 + rand() % 90000; // 10000 a 99999 en vez de 0 a 99999 para que siempre tenga 5 cifras
    return "P" + to_string(numaleat);
}

// Genera un código de libro al azar
string GenerarCodLibro(void)
{
    int numaleat;
    int numaleat2;
    int indaleat;
    char letras[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    numaleat=rand()%1000; // Habria que cambia para que genere 000 en vez de 0 en el menor de los casos, así siempre tendría 3 num + 1 letra + 2 num
    indaleat=rand()%26;
    numaleat2=rand()%100; // igual a arriba
    return to_string(numaleat) + letras[indaleat] + to_string(numaleat2);
}

// Genera una materia aleatoria
string GenerarMateria(){
    int numaleat;
    numaleat=rand()%6;
    string Materias[] = {"Matematicas","Fisica","Tecnologia","Musica","Historia","Lengua"};
    return Materias[numaleat];
}

// Genera una unidad aleatoria
int GenerarUnidades(){
    int numaleat;
    numaleat=rand()%21;
    return numaleat;
}

// En base a la variable Indicre se decide el estado del pedido
string GenerarEstado(int indice){
    string Estados[] = {"Iniciado", "Almacén", "Imprenta", "Listo", "Caja"};
    return Estados[indice];
}

// A partir de las funciones de generación al azar anteriores genera un pedido
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

// Muestra el pedido creado
void MostrarPedidosCreados(int n){
    int i;
    cout << "-----------------------------------------------" << endl;
    cout << "Lib|     Id|  Codigo|      Materia|  U|      Estado|" << endl;
    cout << "-----------------------------------------------" << endl;
    for(i=0; i<n; i++){
        pedido p = GenerarPedido();
        colaIniciado.encolar(p);
        cout << p.id_editorial << "|  " << p.id_pedido << "|  " << p.cod_libro << "|  "
        << p.materia << "|  " << p.unidades << "|  " << p.estado << "|  " << endl;
    }
}

// Función que incializa el Stock :v
void inicializarStock() {
    string materias[] = {"Matematicas", "Fisica", "Tecnologia", "Musica", "Historia", "Lengua"};

    int cantidadLibros = 6 + rand() % 3; // Modificar en función del stock inicial deseado, aka no se que hacer con esto por ahora

    StockLibro librosBase[] = {
        {"111A22", "Matematicas", 20},
        {"333B44", "Fisica", 15},
        {"555C67", "Historia", 9},
        {"777D88", "Lengua", 18},
        {"999E00", "Tecnologia", 12}
    };
    for(int i = 0; i < 5; i++) {
        agregarLibroStock(librosBase[i]);
    }
    for(int i = 0; i < cantidadLibros; i++) {
        StockLibro nuevoLibro;
        nuevoLibro.cod_libro = GenerarCodLibro();
        nuevoLibro.materia = materias[rand() % 6];
        nuevoLibro.unidades = rand() % 21;
        agregarLibroStock(nuevoLibro);
    }
}

// Agrega un libro a la lista se stock
void agregarLibroStock(const StockLibro& libro) {
    NodoStock* nuevo = new NodoStock;
    nuevo->libro = libro;
    nuevo->siguiente = stockPun;
    stockPun = nuevo;
}

// Busca un libro en stock
StockLibro* buscarLibroEnStock(const string& cod_libro) {
    NodoStock* actual = stockPun;
    while(actual != NULL) {
        if(actual->libro.cod_libro == cod_libro) {
            return &(actual->libro); // Encotro el libro en stock
        }
        actual = actual->siguiente;
    }
    return NULL;  // No encotro el libro en stock
}

// Se encarga de mostrar exclusivamente el stock, complementario a mostrarEstado()
void mostrarStock() {
    cout << "\n=== STOCK ACTUAL ===" << endl;
    cout << "Codigo Libro | Materia      | Unidades" << endl;
    cout << "-------------------------------------" << endl;

    NodoStock* actual = stockPun;
    while(actual != NULL) {
        cout << actual->libro.cod_libro << "   | "
             << actual->libro.materia;
        if(actual->libro.materia.length() < 8) cout << "\t";
        cout << "\t| " << actual->libro.unidades << endl;
        actual = actual->siguiente;
    }
    cout << "-------------------------------------" << endl;
}

void pasarFase() {
    cout << "=== EJECUTANDO PASO COMPLETO DE SIMULACION ===" << endl;
    int totalProcesados = 0;

    // FASE 1: INICIADO -> ALMACEN
    int pedidosProcesados = 0;
    while (!colaIniciado.estaVacia() && pedidosProcesados < N_PEDIDOS_PASO) {
        pedido p = colaIniciado.desencolar();
        p.estado = "Almacen";
        colaAlmacen.encolar(p);
        pedidosProcesados++;
        cout << "Pedido " << p.id_pedido << " movido: INICIADO -> ALMACEN" << endl;
    }
    totalProcesados += pedidosProcesados;
    cout << "FASE 1 completada. " << pedidosProcesados << " pedidos procesados." << endl;

    // FASE 2: ALMACEN -> IMPRENTA o LISTO
    pedidosProcesados = 0;
    while (!colaAlmacen.estaVacia() && pedidosProcesados < N_PEDIDOS_PASO) {
        pedido p = colaAlmacen.desencolar();

        StockLibro* libroStock = buscarLibroEnStock(p.cod_libro);

        if (libroStock != NULL && libroStock->unidades >= p.unidades) {
            libroStock->unidades -= p.unidades;
            p.estado = "Listo";
            colaListo.encolar(p);
            cout << "Pedido " << p.id_pedido << " movido: ALMACEN -> LISTO (Stock suficiente)" << endl;
        } else {
            p.estado = "Imprenta";
            colaImprenta.encolar(p);
            cout << "Pedido " << p.id_pedido << " movido: ALMACEN -> IMPRENTA (Falta stock)" << endl;
        }
        pedidosProcesados++;
    }
    totalProcesados += pedidosProcesados;
    cout << "FASE 2 completada. " << pedidosProcesados << " pedidos procesados." << endl;

    // FASE 3: IMPRENTA -> LISTO
    pedidosProcesados = 0;
    while (!colaImprenta.estaVacia() && pedidosProcesados < N_PEDIDOS_PASO) {
        pedido p = colaImprenta.desencolar();

        StockLibro* libroStock = buscarLibroEnStock(p.cod_libro);
        if (libroStock == NULL) {
            StockLibro nuevoLibro;
            nuevoLibro.cod_libro = p.cod_libro;
            nuevoLibro.materia = p.materia;
            nuevoLibro.unidades = TAM_LOTE;
            agregarLibroStock(nuevoLibro);
            cout << "Nuevo libro añadido al stock: " << p.cod_libro << endl;
        } else {
            libroStock->unidades += TAM_LOTE;
            cout << "Stock aumentado para " << p.cod_libro << ": +" << TAM_LOTE << " unidades" << endl;
        }

        p.estado = "Listo";
        colaListo.encolar(p);
        cout << "Pedido " << p.id_pedido << " movido: IMPRENTA -> LISTO" << endl;
        pedidosProcesados++;
    }
    totalProcesados += pedidosProcesados;
    cout << "FASE 3 completada. " << pedidosProcesados << " pedidos procesados." << endl;

    // FASE 4: LISTO -> CAJAS
    pedidosProcesados = 0;
    while (!colaListo.estaVacia() && pedidosProcesados < N_PEDIDOS_PASO) {
        pedido p = colaListo.desencolar();
        p.estado = "Caja";

        int libreria = p.id_editorial;

        if (cajas[libreria].contarElementos() >= CAP_CAJA) {
            cout << "¡Caja de libreria " << libreria << " enviada! ("
                 << cajas[libreria].contarElementos() << " pedidos)" << endl;
            while (!cajas[libreria].estaVacia()) {
                cajas[libreria].desapilar();
            }
        }

        cajas[libreria].apilar(p);
        cout << "Pedido " << p.id_pedido << " movido: LISTO -> CAJA (Libreria " << libreria << ")" << endl;
        pedidosProcesados++;
    }
    totalProcesados += pedidosProcesados;
    cout << "FASE 4 completada. " << pedidosProcesados << " pedidos procesados." << endl;

    cout << "=== PASO COMPLETO FINALIZADO ===" << endl;
    cout << "Total general: " << totalProcesados << " pedidos procesados en todas las fases." << endl << endl;
}
