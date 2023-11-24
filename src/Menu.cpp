#include "Menu.hpp"
using namespace std;

void Menu::flujo_juego()
{
    size_t opcion;
    // mostrar opciones
    while (interfaz.estado_juego() == 0)
    {
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case MOVER_PERSONAJE:
        case MANEJO_ARMAS:
            personaje.interaccion_personaje(opcion, interfaz);

            break;
        case MOSTRAR_MEJOR_RECORRIDO:
        case RECORRER_MEJOR_CAMINO:
            // interaccion_grafo(opcion); // no sabemos en que clase enchufa grafo :(
            break;
        case MOSTRAR_PUNTAJE:
            interfaz.mostrar_puntaje();
            break;
        default:
            cout << "La opcion ingresada no es valida." << endl;
            break;
        }
    }
    if (interfaz.estado_juego() == 1)
    {
        cout << "Ganaste!" << endl;
        interfaz.mostrar_puntaje();
    }
    else
    {
        cout << "Perdiste!" << endl;
    }
}
