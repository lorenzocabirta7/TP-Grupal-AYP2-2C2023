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
#include <cstdlib>

const char ESPACIO_LIBRE = '-';

const size_t CANTIDAD_FILAS = 9;
const size_t CANTIDAD_COLUMNAS = 9;
const size_t COSTO_MOVIMIENTO = 10;
const size_t TABLERO_1 = 1;
const size_t TABLERO_2 = 2;

const char PARED = '#';
const char PYRAMID_HEAD = 'P';
const char JAMES = 'J';
const size_t FILA_ORIGEN = 8;
const size_t COLUMNA_ORIGEN = 0;
const size_t FILA_DESTINO = 0;
const size_t COLUMNA_DESTINO = 8;
const char ORIGEN = 'O';
const char DESTINO = 'D';
const char CASILLA_CAMINO_MINIMO = '^';

class Interfaz
{
private:
    std::vector<std::vector<char>> tablero;
    std::vector<std::vector<char>> tablero2;

    size_t niveles_completados = 0;

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

public:
    Interfaz();

    // Pre:
    // Post: Devuelve un numero aleatorio entre 1 y el largo pasado por parametro.
    int calcular_numero_aleatorio(int largo);

    // Pre:
    // Post: Inicializa el tablero con todos sus elementos cargados.
    void inicializar_tablero(size_t tipo_layout);

    // Pre:
    // Post: Imprime el tablero.
    void imprimir_tablero(size_t tipo_tablero);

    // Pre:
    // Post: Devuelve 0 si se esta jugando, 1 si el jugador gano y 2 si perdio.
    size_t estado_juego(size_t altura_arbol, bool tiene_arma);

    // Pre:
    // Post: Se modifica el tablero en la posicion pasada por parametro
    void actualizar_tablero(size_t filas, size_t columnas, char personaje);

    // Pre:
    // Post: Devuelve true si el personaje esta en la posicion pasada por parametro
    bool esta_ocupado(size_t filas, size_t columnas, char objeto);

    // Pre:
    // post: aumenta la cantidad de niveles completados
    void aumentar_niveles_completados();

    // Pre: El vector de vectores debe tener al menos un elemento.
    // Post: Muestra las coordenadas del camino minimo.
    void mostrar_coordenadas_camino_minimo(std::vector<std::vector<size_t>> coordenadas);

    // Pre: La posicion debe ser valida.
    // Post: Cambia la posicion de james en el tablero al casillero de salida.
    void terminar_nivel_automaticamente(std::vector<size_t> posicion_james);
};

#endif
