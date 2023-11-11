#include "Floyd.hpp"

Floyd::Floyd() {}

void Floyd::inicializar_matrices() {
    matriz_caminos = Matriz(cantidad_vertices);
    for (size_t i = 0; i < cantidad_vertices; i++) {
        for (size_t j = 0; j < cantidad_vertices; j++) {
            matriz_caminos.elemento(i, j) = (int) j;
        }
    }

    matriz_costos = matriz_adyacencia;
}

std::vector<size_t> Floyd::obtener_camino(size_t origen, size_t destino) {
    std::vector<size_t> camino;

    // TODO: Escribir el código necesario, haciendo uso de los métodos existentes.

    return camino;
}

std::vector<size_t>
Floyd::calcular_camino_minimo(Matriz adyacencia, size_t vertices, size_t origen, size_t destino, bool hay_cambios) {
    if (hay_cambios) {
        matriz_adyacencia = adyacencia;
        cantidad_vertices = vertices;
        inicializar_matrices();

        // TODO: Escribir el código necesario, haciendo uso de los métodos existentes.

    }

    return obtener_camino(origen, destino);
}

Floyd::~Floyd() {}