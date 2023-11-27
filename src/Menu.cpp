#include "Menu.hpp"
using namespace std;

void Menu::imprimir_opciones()
{
    cout << "1. Mover personaje." << endl;         // interaccion personaje
    cout << "2. Mostrar mejor recorrido." << endl; // interaccion grafo
    cout << "3. Recorrer mejor camino." << endl;   // interaccion grafo
    cout << "4. Manejo de armas." << endl;         // interaccion personaje
    cout << "5. Mostrar puntaje." << endl;
    cout << "6. Salir." << endl;
}

void Menu::flujo_juego()
{
    char opcion;
    size_t altura_arbol = arbol_placas.calcular_altura();
    // imprimir_opciones();
    interfaz.inicializar_tablero(altura_arbol);

    while (opcion != '6' && interfaz.estado_juego() == 0) // interfaz.estado_juego() == 0
    {
        imprimir_opciones();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case '1':
            // mover personaje
            personaje.interaccion_personaje(MOVER_PERSONAJE, interfaz);
            interfaz.imprimir_tablero(); // adentro de mover personaje

            if (personaje.nivel_terminado(interfaz))
            {
                interfaz.inicializar_tablero(altura_arbol);
                        }
            break;
        case '2':
            // mostrar mejor recorrido
            break;
        case '3':
            // recorrer mejor camino
            break;
        case '4':
            // manejo armas
            // personaje.interaccion_personaje(manejo_armas, interfaz);
            break;
        case '5':
            // interfaz.mostrar_puntaje();
            break;
        case '6':
            cout << "Gracias por jugar!" << endl;
            break;
        default:
            cout << "La opcion ingresada no es valida." << endl;
            break;
        }
    }

    /*
    switch (opcion)
    {
    case '1':
    case '4':
        // mover personaje
        personaje.interaccion_personaje(opcion, interfaz);
        interfaz.imprimir_tablero(); // adentro de mover personaje

        if (personaje.nivel_terminado(interfaz))
        {
            interfaz.inicializar_tablero(altura_arbol);
        }
        break;
    }
    case '2':
    case '3':
        interaccion_grafo(opcion)

    {
    case '5':
        interfaz.mostrar_puntaje();
        break;
    default:
        salir
    */

    //    if (interfaz.estado_juego() == 1)
    //    {
    //        cout << "Ganaste!" << endl;
    //        //interfaz.mostrar_puntaje();
    //    }
    //    else
    //    {
    //        cout << "Perdiste!" << endl;
    //    }

    // arma ya planteada
}
