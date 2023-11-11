#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H

#include "CaminoMinimo.hpp"

class Grafo {
private:
    Matriz matriz_adyacencia;
    CaminoMinimo* algoritmo_camino_minimo;
    size_t vertices;
    bool hay_cambios;

    // Pre: -
    // Post: Agranda la matriz de adyacencia en un vértice (es decir, una columna y una fila.)
    void agrandar_matriz_adyacencia();

    // Pre: -
    // Post: Calcula y devuelve el peso total del camino.
    int obtener_peso_camino(std::vector<size_t> camino);

public:
    // Constructores.
    Grafo();

    Grafo(size_t cantidad_vertices);

    // Pre: -
    // Post: Agrega un nuevo vértice al grafo.
    // NOTA: El número del vértice corresponde con el último índice agregado a la matriz.
    // Por ejemplo, si se tienen 5 vértices y se agrega uno mas, ese vértice es el 5.
    void agregar_vertice();

    // Pre: -
    // Post: Agrega (o modifica) la arista desde origen a destino. Si los vértices no son válidos, la matriz no cambia.
    void cambiar_arista(size_t origen, size_t destino, int peso);

    // Pre: -
    // Post: Elimina la arista desde origen a destino. Si los vértices no son válidos, la matriz no cambia.
    void eliminar_arista(size_t origen, size_t destino);

    // Pre: -
    // Post: Selecciona el algortimo de Floyd para calcular el camino mínimo.
    void usar_floyd();

    // Pre: -
    // Post: Selecciona el algortimo de Dijkstra para calcular el camino mínimo.
    void usar_dijkstra();

    // Pre: -
    // Post: Devuelve el camino minimo de origen a destino. Si los vértices no son válidos o no se seleccionó
    // un algoritmo, devuelve un camino vacío.
    std::pair<std::vector<size_t>, int> obtener_camino_minimo(size_t origen, size_t destino);

    // Constructor por copia.
    Grafo(const Grafo& grafo1);

    // Operador de asignación.
    Grafo& operator=(const Grafo& grafo1);

    ~Grafo();
};

#endif