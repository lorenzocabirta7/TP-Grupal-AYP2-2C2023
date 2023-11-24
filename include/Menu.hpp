#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include "Grafo.hpp"
#include "ABB.hpp"
#include "Placa.hpp"
#include "Arma.hpp"
#include "Inventario.hpp"
#include "Interfaz.hpp"

const size_t MOVER_PERSONAJE = 1;
const size_t MOSTRAR_MEJOR_RECORRIDO = 2;
const size_t RECORRER_MEJOR_CAMINO = 3;
const size_t MANEJO_ARMAS = 4;
const size_t MOSTRAR_PUNTAJE = 5;


class Menu {
    private:
        Interfaz interfaz;
        Personaje personaje;
    public:
        Menu(Interfaz interfaz,Personaje personaje);
        void flujo_juego();
};





#endif
