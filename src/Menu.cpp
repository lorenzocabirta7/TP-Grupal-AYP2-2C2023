#include "Menu.hpp"
using namespace std;

void Menu::imprimir_opciones()
{
    cout << "1. Mover personaje." << endl;
    cout << "2. Mostrar mejor recorrido." << endl;
    cout << "3. Recorrer mejor camino." << endl;
    cout << "4. Manejo de armas." << endl;
    cout << "5. Mostrar puntaje." << endl;
    cout << "6. Salir." << endl;
}


void Menu::flujo_juego()
{
    char opcion;
    imprimir_opciones();
    interfaz.inicializar_tablero(1);

    while (opcion != '6') //interfaz.estado_juego() == 0
    {
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case '1':
            //mover personaje
            interfaz.imprimir_tablero();

            break;
        case '2':
            //mostrar mejor recorrido
            break;
        case '3':
            //recorrer mejor camino
            break;
        case '4':
            // interaccion_grafo(opcion); // no sabemos en que clase enchufa grafo :(
            break;
        case '5':
            //interfaz.mostrar_puntaje();
            break;
        case '6':
            cout << "Gracias por jugar!" << endl;
            break;
        default:
            cout << "La opcion ingresada no es valida." << endl;
            break;
        }
    }
//    if (interfaz.estado_juego() == 1)
//    {
//        cout << "Ganaste!" << endl;
//        //interfaz.mostrar_puntaje();
//    }
//    else
//    {
//        cout << "Perdiste!" << endl;
//    }
}
