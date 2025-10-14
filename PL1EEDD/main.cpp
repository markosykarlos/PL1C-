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

int main()
{
    int x;
    int n;
    string f;
    do{
        ImprimirMenu();
        cin >> x;
        switch(x){
        case 1:
            cout << "Cuantos pedidos quiere generar?: ";
            cin >> n;
            // funciones
            cout << "Se han generado " << n << " pedidos\n" << endl;
            break;
        case 2:
            cout << "A que fase quiere pasar?: ";
            cin >> f;
            // funciones
            cout << "Se ha pasado a fase " << f << endl;
            break;
        case 3:
            cout << "Estado del sistema\n" << endl;
            // funciones
            break;
        case 4:
            // funciones
            cout << "Han pasado todas las fases\n" << endl;
            break;
        case 5:
            cout << "Caja de una libreria\n" << endl;
            // funciones
            break;
        case 0:
            cout << "Sesion cerrada" << endl;
            break;
        default:
            cout << "Opción no valida" << endl;
        }
    }while (x != 0);
    return 0;
}
