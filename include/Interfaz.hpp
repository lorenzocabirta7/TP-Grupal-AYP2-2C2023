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

const size_t MOVER_PERSONAJE = 1;
const size_t MOSTRAR_MEJOR_RECORRIDO = 2;
const size_t RECORRER_MEJOR_CAMINO = 3;
const size_t MANEJO_ARMAS = 4;
const size_t MOSTRAR_PUNTAJE = 5;

const string ID = "ID";
const string POTENCIA = "Potencia";
const size_t CANTIDAD_FILAS = 9;
const size_t CANTIDAD_COLUMNAS = 9;
const size_t COSTO_MOVIMIENTO = 10;
const char ARRIBA = 'W';
const char ABAJO = 'S';
const char IZQUIERDA = 'A';
const char DERECHA = 'D';
const size_t ID_PLACA_MINIMO = 100;
const size_t ID_PLACA_MAXIMO = 666;
const size_t POTENCIA_ARMA_MINIMO = 10;
const size_t POTENCIA_ARMA_MAXIMO = 100;
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
    Inventario *inventario;
    ABB<Placa *, Placa::menor, Placa::igual> arbol_placas;
    size_t niveles_completados = 1;
    size_t puntaje = 0;
    bool tiene_arma = false;
    bool arma_equipada = false;

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
    // Post: Se equipa el arma mas fuerte.
    void equipar_arma();

    // Pre:
    // Post: Se desequipa el arma.
    void desequipar_arma();

    // Pre:
    // Post: Devuelve el layout correspondiente.
    size_t elegir_layout(size_t altura_arbol);

    // Pre:
    // Post: Devuelve el movimiento a realizar
    char pedir_movimiento();

    // Pre:
    // Post: Genera un arma.
    Arma *generar_arma();

    // Pre:
    // Post: Genera una placa.
    Placa *generar_placa();

    // Pre:
    // Post: Devuelve true si el tipo es valido.
    bool tipo_valido(std::string tipo);

    // Pre: El tipo debe ser valido.
    // Post: Genera un ID/Potencia aleatorio según el tipo.
    int generar_numero_aleatorio(std::string tipo);

    // Pre:
    // Post: Devuelve la posicion en la que esta ubicado James
    std::vector<size_t> obtener_posicion_james();

    // Pre: Debe tener un arma equipada.
    // Post: Elimina el arma del inventario y la desequipa.
    void romper_arma();

    // Pre:
    // Post: Equipa, desequipa o da de baja el arma segun corresponda.
    void interaccion_armas();

    // Pre: El movimiento debe ser valido.
    // Post: Realiza el movimiento elegido.
    void realizar_movimiento(char movimiento);

    // Pre:
    // Post: Devuelve true si el movimiento es valido.
    bool movimiento_es_valido(char movimiento);

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

    void flujo_juego(); // clase menu

    // Pre:
    // Post: Se realiza un movimiento o se interactua con un arma segin corresponda.
    void interaccion_personaje(size_t opcion);

    // Pre:
    // Post: Se muestra el mejor camino o se lo recorre segun corresponda.
    void interaccion_grafo(size_t opcion);

    // ~Interfaz();
};

#endif
