#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
#include "Grafo.hpp"
#include "ABB.hpp"
#include "Placa.hpp"
#include "Arma.hpp"
#include "Inventario.hpp"
#include <time.h>
#include <vector>
#include <string>

const char ESPACIO_LIBRE = '-';

const size_t CANTIDAD_FILAS = 9;
const size_t CANTIDAD_COLUMNAS = 9;
const size_t COSTO_MOVIMIENTO = 10;

const char PARED = '#';
const char PYRAMID_HEAD = 'P';
const char JAMES = 'J';
const size_t FILA_ORIGEN = 8;
const size_t COLUMNA_ORIGEN = 0;
const size_t FILA_DESTINO = 0;
const size_t COLUMNA_DESTINO = 8;
const char ORIGEN = 'O';
const char DESTINO = 'D';

class Interfaz
{
private:
    std::vector<std::vector<char>> tablero;
    Grafo *grafo;

    ABB<Placa *, Placa::menor, Placa::igual> arbol_placas;
    size_t niveles_completados = 1;
    size_t puntaje = 0;

    // Pre:
    // Post: Genera una coordenada aleatoria.
    size_t generar_coordenada_aleatoria();

    // Pre:
    // Post: Devuelve true si la posicion es valida.
    bool posicion_valida(size_t fila, size_t columna);

    // Pre:
    // Post: Asigna posiciones a los personajes.
    void inicializar_personajes();

    // Pre: El tipo de layout debe ser valido.
    // Post: Asigna posiciones a las paredes segun el tipo de layout.
    void inicializar_paredes(size_t tipo_layout);

    // Pre:
    // Post: Devuelve el layout correspondiente.
    size_t elegir_layout(size_t altura_arbol);

    // Pre:
    // Post: Genera una placa.
    Placa *generar_placa();

    // Pre:
    // Post: Muestra el recorrido con menor coste.
    void mostrar_mejor_recorrido();

    // Pre:
    // Post: Realiza el recorrido con menor coste.
    void recorrer_mejor_camino();

public:
    Interfaz();

    // Pre:
    // Post: Inicializa el tablero con todos sus elementos cargados.
    void inicializar_tablero(size_t tipo_layout);

    // Pre:
    // Post: Imprime el tablero.
    void imprimir_tablero();

    // Pre:
    // Post: Se imprime el puntaje.
    void mostrar_puntaje();

    // Pre:
    // Post: Devuelve 0 si se esta jugando, 1 si el jugador gano y 2 si perdio.
    size_t estado_juego();

    // Pre:
    // Post: Se muestra el mejor camino o se lo recorre segun corresponda.
    void interaccion_grafo(size_t opcion);

    // Pre:
    // Post: Se modifica el tablero en la posicion pasada por parametro
    void actualizar_tablero(size_t filas, size_t columnas, char personaje);

    // Pre:
    // Post: Devuelve true si el personaje esta en la posicion pasada por parametro
    bool esta_ocupado(size_t filas, size_t columnas, char objeto);

    // Pre:
    // Post: Devuelve true si hay una pared en la posicion pasada por parametro
    bool hay_pared(size_t filas, size_t columnas);

    // ~Interfaz();
};

#endif
