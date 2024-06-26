#ifndef __PERSONAJE_H_
#define __PERSONAJE_H_

#include "Recorrido.hpp"
#include "ABB.hpp"
#include "Placa.hpp"
#include "Arma.hpp"
#include "Inventario.hpp"
#include "Interfaz.hpp"
const std::string ID = "ID";
const std::string POTENCIA = "Potencia";
const int ID_PLACA_MINIMO = 100;
const int ID_PLACA_MAXIMO = 666;
const int POTENCIA_ARMA_MINIMO = 10;
const int POTENCIA_ARMA_MAXIMO = 100;
const char ARRIBA = 'W';
const char ABAJO = 'S';
const char IZQUIERDA = 'A';
const char DERECHA = 'D';
const size_t MOVER_PERSONAJE = 1;

class Personaje
{
private:
    Inventario inventario;
    bool tiene_arma = false;
    bool arma_equipada = false;
    ABB<Placa, Placa::menor, Placa::igual> arbol_placas;
    size_t puntaje_total = 0;

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
    void generar_arma(Interfaz &interfaz);

    // Pre:
    // Post: Devuelve true si el tipo es valido.
    bool tipo_valido(std::string tipo);

    // Pre: El tipo debe ser valido.
    // Post: Genera un ID/Potencia aleatorio según el tipo.
    int generar_numero_aleatorio(std::string tipo);

    // Pre: Debe tener un arma equipada.
    // Post: Elimina el arma del inventario y la desequipa.
    void usar_arma();

    // Pre: El movimiento debe ser valido.
    // Post: Realiza el movimiento elegido.
    void realizar_movimiento(char movimiento, Interfaz &interfaz);

    // Pre:
    // Post: Devuelve true si el movimiento es valido.
    bool movimiento_es_valido(char movimiento);

    bool casilla_valida(size_t fila, size_t columna, Interfaz &interfaz);

    // Pre:
    // Post: Equipa, desequipa o da de baja el arma segun corresponda.
    void interaccion_armas();

    // Pre:
    // Post: Genera una placa.
    void generar_placa();

    // pre:
    // post: Verifica si los pyramid_head estan en una casilla contigua
    bool pyramid_head_cercano(std::vector<size_t> posicion_pyramid_head, std::vector<size_t> posicion_james);

    void actualizar_puntaje(Interfaz &interfaz);

    // PRE: Los parametros deben estar inicializados y cargados.
    // POST: Devuelve a la distancia manhattan que dos elementos se encuentran
    size_t distancia_manhattan(size_t fila1, size_t fila2, size_t columna1, size_t columna2);

public:
    Personaje();

    // Pre:
    // Post: Se realiza un movimiento o se interactua con un arma segin corresponda.
    void interaccion_personaje(size_t opcion, Interfaz &interfaz);

    // Pre:
    // Post: Devuelve la posicion en la que esta ubicado James
    std::vector<size_t> obtener_posicion_james(Interfaz &interfaz);

    // Pre:
    // Post: Devuelve true si el nivel esta terminado
    bool nivel_terminado(Interfaz &interfaz);

    // Pre:
    // Post: Devuelve la altura del arbol.
    size_t get_altura();

    // Pre:
    // Post: Devuelve true si el personaje tiene un arma.
    bool get_tiene_arma();

    // Pre: -
    // Post: Devuelve un vector con la posicion de los pyramid_head, si no estan devuelve [10, 10].
    std::vector<std::vector<size_t>> obtener_posicion_pyramidhead(Interfaz &interfaz);

    // Pre: -
    // Post: Devuelve true si hay un pyramidhead en una casilla contigua.
    bool eliminar_pyramid_head(Interfaz &interfaz);

    // Pre: -
    // Post: Devuelve el puntaje total.
    size_t obtener_puntaje_total();
};

#endif
