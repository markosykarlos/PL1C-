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

struct Alumno
{
    string id_editorial;
    string id_pedido;
    string cod_libro;
    string materia;
    string estado;
    int unidades;
};

int main()
{
    return 0;
}
