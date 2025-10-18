#include <iostream>
#include <ctime>
#include "Editorial.h"

using namespace std;

Cola colaIniciado, colaAlmacen, colaImprenta, colaListo;
Pila cajas[LIBRERIAS];

int main()
{   srand(time(NULL));
    int x;
    int n;
    string f;
    string Materias[] = {"Matematicas","Fisica","Tecnologia","Musica","Historia","Lengua"};
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
