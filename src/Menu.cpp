#include "Menu.hpp"

Menu::Menu(Interfaz interfaz, Personaje personaje){
    this->interfaz=interfaz;
    this->personaje=personaje;
}


void::Menu flujo_juego( ){
    size_t opcion;
    // mostrar opciones
    while (estado_juego() == 0)
    {
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case MOVER_PERSONAJE:
        case MANEJO_ARMAS:
            personaje.interaccion_personaje(opcion);
            break;
        case MOSTRAR_MEJOR_RECORRIDO:
        case RECORRER_MEJOR_CAMINO:
            interaccion_grafo(opcion);// no sabemos en que clase enchufa grafo :(
            break;
        case MOSTRAR_PUNTAJE:
            interfaz.mostrar_puntaje();
            break;
        default:
            cout << "La opcion ingresada no es valida." << endl;
            break;
        }
    }
    if (estado_juego() == 1)
    {
        cout << "Ganaste!" << endl;
        mostrar_puntaje();
    }
    else
    {
        cout << "Perdiste!" << endl;
    }
}