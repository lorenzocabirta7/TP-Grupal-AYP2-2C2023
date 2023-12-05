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

    size_t altura_arbol = personaje.get_altura();
    interfaz.inicializar_tablero(altura_arbol);
    // imprimir_opciones();
    vector<size_t> posicion_james1;
    vector<vector<size_t>> posicion_pyramidheads;
    bool tiene_arma;

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
            interfaz.imprimir_tablero(); // adentro de mover personaje
            personaje.interaccion_personaje(MOVER_PERSONAJE, interfaz);


            if (personaje.nivel_terminado(interfaz))
            {
                altura_arbol = personaje.get_altura();
                if(altura_arbol == 0)
                {
                    altura_arbol ++;
                }
                interfaz.inicializar_tablero(altura_arbol);
                        }
            break;
        case '2':
            posicion_james1 = personaje.obtener_posicion_james(interfaz);
            posicion_pyramidheads = personaje.obtener_posicion_pyramidhead(interfaz);
            tiene_arma = personaje.get_tiene_arma();
            recorrido.encontrar_camino_minimo(posicion_james1, posicion_pyramidheads, altura_arbol, tiene_arma);
            break;
        case '3':
            // recorrer mejor camino
            break;
        case '4':
            //bool tiene_arma = personaje.get_tiene_arma();

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
