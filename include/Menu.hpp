#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include "Interfaz.hpp"
#include "Personaje.hpp"

const size_t MOVER_PERSONAJE = 1;
const size_t MOSTRAR_MEJOR_RECORRIDO = 2;
const size_t RECORRER_MEJOR_CAMINO = 3;
const size_t MANEJO_ARMAS = 4;
const size_t MOSTRAR_PUNTAJE = 5;

class Menu
{
private:
    Interfaz interfaz;
    Personaje personaje;

public:
    // Pre:
    // Post: Muestra las opciones del juego y las ejecuta.
    void flujo_juego();
};

#endif
