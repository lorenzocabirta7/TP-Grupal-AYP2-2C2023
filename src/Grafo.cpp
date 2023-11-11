#include "Grafo.hpp"
#include "Floyd.hpp"
#include "Dijkstra.hpp"
#include <iostream>

Grafo::Grafo() {
    matriz_adyacencia = Matriz(0);
    algoritmo_camino_minimo = nullptr;
    vertices = 0;
    hay_cambios = true;
}

Grafo::Grafo(size_t cantidad_vertices) {
    matriz_adyacencia = Matriz(cantidad_vertices, INFINITO);
    vertices = cantidad_vertices;
    algoritmo_camino_minimo = nullptr;
    hay_cambios = true;
    for (size_t i = 0; i < vertices; i++) {
        matriz_adyacencia.elemento(i, i) = 0;
    }
}

void Grafo::agrandar_matriz_adyacencia() {
    matriz_adyacencia.expandir();
    for (size_t i = 0; i < vertices - 1; i++) {
        matriz_adyacencia.elemento(vertices - 1, i) = INFINITO;
        matriz_adyacencia.elemento(i, vertices - 1) = INFINITO;
    }
}

int Grafo::obtener_peso_camino(std::vector<size_t> camino) {
    int peso = 0;
    if (camino.size() > 1) {
        for (size_t i = 0; i < camino.size() - 1; i++) {
            peso += matriz_adyacencia.elemento(camino[i], camino[i + 1]);
        }
    }
    return peso;
}

void Grafo::agregar_vertice() {
    agrandar_matriz_adyacencia();
    vertices++;
    hay_cambios = true;
}

void Grafo::cambiar_arista(size_t origen, size_t destino, int peso) {
    if (origen < vertices && destino < vertices) {
        matriz_adyacencia.elemento(origen, destino) = peso;
        hay_cambios = true;
    } else {
        std::cout << "ERROR: Los vertices no son válidos. No se cambió el camino." << std::endl;
    }
}

void Grafo::eliminar_arista(size_t origen, size_t destino) {
    cambiar_arista(origen, destino, INFINITO);
}

void Grafo::usar_floyd() {
    delete algoritmo_camino_minimo;
    algoritmo_camino_minimo = new Floyd();
    hay_cambios = true;
}

void Grafo::usar_dijkstra() {
    delete algoritmo_camino_minimo;
    algoritmo_camino_minimo = new Dijkstra();
    hay_cambios = true;
}

std::pair<std::vector<size_t>, int> Grafo::obtener_camino_minimo(size_t origen, size_t destino) {
    std::pair<std::vector<size_t>, int> camino;
    if (algoritmo_camino_minimo) {
        if (origen < vertices && destino < vertices) {
            camino.first = algoritmo_camino_minimo->calcular_camino_minimo(matriz_adyacencia, vertices, origen,
                                                                           destino, hay_cambios);
            camino.second = obtener_peso_camino(camino.first);
            hay_cambios = false;
        } else {
            std::cout << "ERROR: Los vértices no son válidos." << std::endl;
        }
    } else {
        std::cout << "ERROR: No se indicó el algoritmo a usar." << std::endl;
    }
    return camino;
}

Grafo::Grafo(const Grafo& grafo1) {
    matriz_adyacencia = grafo1.matriz_adyacencia;
    vertices = grafo1.vertices;
    hay_cambios = grafo1.hay_cambios;
    algoritmo_camino_minimo = nullptr;
}

Grafo& Grafo::operator=(const Grafo& grafo1) {
    if (this != &grafo1) {
        delete algoritmo_camino_minimo;
        algoritmo_camino_minimo = nullptr;
        matriz_adyacencia = grafo1.matriz_adyacencia;
        vertices = grafo1.vertices;
        hay_cambios = grafo1.hay_cambios;
    }
    return *this;
}

Grafo::~Grafo() {
    delete algoritmo_camino_minimo;
}