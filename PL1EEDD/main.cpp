#include <iostream>
#include <ctime>
#include "editorial.h"

using namespace std;

int main()
{   srand(time(NULL));
    int x;
    int n;
//    string f;
//    generarPrede();
    CrearStock();
    do{
        ImprimirMenu();
        cin >> x;
        switch(x){
        case 1:
            cout << "Cuantos pedidos quiere generar?: ";
            cin >> n;
            MostrarPedidosCreados(n);
            break;
        case 2:
            pasarFase();
            break;
        case 3:
            cout << "Estado del sistema\n" << endl;
            mostrarEstadoSistema();
            mostrarStock();
            break;
        case 4:
            cout << "Ver caja de una libreria\n" << endl;
            VerCaja();
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
