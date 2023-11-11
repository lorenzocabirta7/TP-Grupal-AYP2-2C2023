#ifndef GRAFOS_DIJKSTRA_H
#define GRAFOS_DIJKSTRA_H

#include "CaminoMinimo.hpp"
#include <stack>

class Dijkstra : public CaminoMinimo {
private:
    bool* vertices_visitados;
    int* distancia;
    size_t* recorrido;

    // Pre: -
    // Post: Inicializa los tres arreglos necesarios para el algoritmo.
    void inicializar_arreglos(size_t origen);

    // Pre: -
    // Post: Devuelve el índice del vértice con menor distancia al origen.
    size_t vertice_minima_distancia();

    // Pre: -
    // Post: Actualiza el vector de distancias y el de recorrido con los valores que impone vértice.
    void actualizar_distancia(size_t vertice);

    // Pre: Se debe haber calculado el camino.
    // Post: Devuelve el camino desde origen a destino.
    std::vector<size_t> obtener_camino(size_t origen, size_t destino);

public:
    // Constructor.
    Dijkstra();

    std::vector<size_t>
    calcular_camino_minimo(Matriz adyacencia, size_t vertices, size_t origen, size_t destino,
                           bool hay_cambios) override;

    ~Dijkstra() override;
};

#endif