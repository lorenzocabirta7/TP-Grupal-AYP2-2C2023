#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
#include "Grafo.hpp"
#include "ABB.hpp"
#include "Placa.hpp"
#include "Arma.hpp"
#include <time.h>
#include "Matriz.hpp"


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
    Matriz tablero;
    Grafo* grafo;
    size_t niveles_completados = 1;
    size_t puntaje = 0;
    bool tiene_arma = false;
    bool arma_equipada = false;

    //Pre:
    //Post: Genera una coordenada aleatoria.
    size_t generar_coordenada_aleatoria();

    //Pre:
    //Post: Devuelve true si la posicion es valida.
    bool posicion_valida(size_t fila, size_t columna);

    //Pre:
    //Post: Asigna posiciones a los personajes.
    void inicializar_personajes();
    
    //Pre: El tipo de layout debe ser valido.
    //Post: Asigna posiciones a las paredes segun el tipo de layout.
    void inicializar_paredes(size_t tipo_layout);
    
    //Pre:
    //Post: Se equipa el arma mas fuerte.
    void equipar_arma();

    //Pre:
    //Post: Se desequipa el arma.
    void desequipar_arma();

    //Pre:
    //Post: Devuelve el layout correspondiente.
    size_t elegir_layout(size_t altura_arbol);

    //Pre:
    //Post: Devuelve true si el movimiento es valido.
    bool movimiento_es_valido(char movimiento);

    //Pre:
    //Post: Devuelve el movimiento a realizar
    char pedir_movimiento();

    //Pre:
    //Post: Genera un arma.
    Arma* generar_arma();

    //Pre:
    //Post: Genera una placa.
    Placa* generar_placa();

    //Pre:
    //Post: Devuelve true si el tipo es valido.
    bool tipo_valido(std::string tipo);

    //Pre: El tipo debe ser valido.
    //Post: Genera un ID/Potencia aleatorio según el tipo.
    size_t generar_numero_aleatorio(std::string tipo);

    //Pre:
    //Post: Devuelve 0 si se esta jugando, 1 si el jugador gano y 2 si perdio.
    size_t estado_juego();

public:
    //Pre:
    //Post: Inicializa el tablero con todos sus elementos cargados.
    void inicializar_tablero();

    //Pre:
    //Post: Imprime el tablero.
    void imprimir_tablero();

    //Pre: El movimiento debe ser valido.
    //Post: Realiza el movimiento elegido.
    void realizar_movimiento(char movimiento);

    //Pre:
    //Post: Equipa o desequipa el arma.
    void interaccion_armas();

    //Pre:
    //Post: Muestra el recorrido con menor coste.
    void mostrar_mejor_recorrido();

    //Pre:
    //Post: Realiza el recorrido con menor coste.
    void recorrer_mejor_camino();

    //Pre:
    //Post: Se imprime el puntaje.
    void mostrar_puntaje();
    

    
   // ~Interfaz();
};





#endif

