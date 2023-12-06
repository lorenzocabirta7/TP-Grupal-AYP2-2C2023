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
    vector<size_t> posicion_james1;
    vector<vector<size_t>> posicion_pyramidheads;
    bool tiene_arma;
    vector<vector<size_t>> coordenadas_camino_minimo;
    size_t puntaje_camino_minimo = 0;
    size_t puntaje_james = 0;
    size_t puntaje_total = 0;
    while (opcion != '6' && interfaz.estado_juego(altura_arbol, tiene_arma) == 0)
    {
        imprimir_opciones();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;
        if (personaje.nivel_terminado(interfaz))
        {
            altura_arbol = personaje.get_altura();
            if (altura_arbol == 0)
            {
                altura_arbol++;
            }
            interfaz.inicializar_tablero(altura_arbol);
        }
        switch (opcion)
        {

        case '1':
            // mover personaje
            interfaz.imprimir_tablero(TABLERO_1); // adentro de mover personaje
            personaje.interaccion_personaje(MOVER_JUGADOR, interfaz);

            if (personaje.eliminar_pyramid_head(interfaz))
            {
                posicion_pyramidheads = personaje.obtener_posicion_pyramidhead(interfaz);
                interfaz.actualizar_tablero(posicion_pyramidheads[0][0], posicion_pyramidheads[0][1], ESPACIO_LIBRE);
                interfaz.actualizar_tablero(posicion_pyramidheads[1][0], posicion_pyramidheads[1][1], ESPACIO_LIBRE);
            }

            break;
        case '2':
            posicion_james1 = personaje.obtener_posicion_james(interfaz);
            posicion_pyramidheads = personaje.obtener_posicion_pyramidhead(interfaz);
            tiene_arma = false; // personaje.get_tiene_arma();
            coordenadas_camino_minimo = recorrido.encontrar_camino_minimo(posicion_james1, posicion_pyramidheads, altura_arbol, tiene_arma).first;
            interfaz.mostrar_coordenadas_camino_minimo(coordenadas_camino_minimo);

            break;
        case '3':
             posicion_james1 = personaje.obtener_posicion_james(interfaz);
             posicion_pyramidheads = personaje.obtener_posicion_pyramidhead(interfaz);
             puntaje_camino_minimo = recorrido.encontrar_camino_minimo(posicion_james1, posicion_pyramidheads, altura_arbol, tiene_arma).second;
             puntaje_james = personaje.obtener_puntaje_total();
             puntaje_total += puntaje_camino_minimo + puntaje_james;
             interfaz.cambiar_posicion_james(posicion_james1);
             break;
        case '4':
            personaje.interaccion_personaje(MANEJO_ARMAS, interfaz);
            tiene_arma = personaje.get_tiene_arma();
            break;
        case '5':
            puntaje_james = personaje.obtener_puntaje_total();
            puntaje_total = puntaje_camino_minimo + puntaje_james;
            cout << "El puntaje actual es " << puntaje_total << endl;
            break;
        case '6':
            cout << "Gracias por jugar!" << endl;
            break;
        default:
            cout << "La opcion ingresada no es valida." << endl;
            break;
        }
    }
    if (interfaz.estado_juego(altura_arbol, tiene_arma) == 1)
    {
        cout << "Ganaste!" << endl;
    }
    else
    {
        cout << "Perdiste!" << endl;
    }
}
