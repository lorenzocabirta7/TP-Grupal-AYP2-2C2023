#ifndef __PERSONAJE_H_
#define __PERSONAJE_H_


#include <iostream>
#include "Grafo.hpp"
#include "ABB.hpp"
#include "Placa.hpp"
#include "Arma.hpp"
#include "Inventario.hpp"
#include "Interfaz.hpp"

const string ID = "ID";
const string POTENCIA = "Potencia";
const size_t ID_PLACA_MINIMO = 100;
const size_t ID_PLACA_MAXIMO = 666;
const size_t POTENCIA_ARMA_MINIMO = 10;
const size_t POTENCIA_ARMA_MAXIMO = 100;
const char ARRIBA = 'W';
const char ABAJO = 'S';
const char IZQUIERDA = 'A';
const char DERECHA = 'D';


class Personaje {
    private:
    Inventario *inventario;


    // Pre:
    // Post: Se equipa el arma mas fuerte.
    void equipar_arma();

    // Pre:
    // Post: Se desequipa el arma.
    void desequipar_arma();

    // Pre:
    // Post: Devuelve el movimiento a realizar
    char pedir_movimiento();

    // Pre:
    // Post: Genera un arma.
    Arma *generar_arma();

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


    // Pre: El movimiento debe ser valido.
    // Post: Realiza el movimiento elegido.
    void realizar_movimiento(char movimiento);

    // Pre:
    // Post: Devuelve true si el movimiento es valido.
    bool movimiento_es_valido(char movimiento);

    // Pre:
    // Post: Equipa, desequipa o da de baja el arma segun corresponda.
    void interaccion_armas();


    public:    
    Personaje();

    // Pre:
    // Post: Se realiza un movimiento o se interactua con un arma segin corresponda.
    void interaccion_personaje(size_t opcion);
};





#endif 