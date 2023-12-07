#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include "Interfaz.hpp"
#include "Personaje.hpp"
#include "Recorrido.hpp"


#define MOVER_JUGADOR '1'
#define MOSTRAR_MEJOR_RECORRIDO  '2'
#define RECORRER_MEJOR_CAMINO  '3'
#define MANEJO_ARMAS  '4'
#define MOSTRAR_PUNTAJE '5'
#define SALIR  '6'

class Menu
{
private:
    Interfaz interfaz;
    Personaje personaje;
    Recorrido recorrido;


    void imprimir_opciones();

public:
    // Pre:
    // Post: Muestra las opciones del juego y las ejecuta.
    void flujo_juego();
};

#endif
