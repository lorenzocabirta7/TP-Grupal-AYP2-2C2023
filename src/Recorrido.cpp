#include "Recorrido.hpp"
#include <vector>

#include <iostream>

Recorrido::Recorrido() {
    grafo_layout1 = Grafo(54);
    grafo_layout2 = Grafo(56);
    posicion_james = {0, 7};
}

void Recorrido::agregar_artistas_layout1() {
    for (std::vector<size_t> vertice1: VERTICES_LAYOUT1) {
        for (size_t i = 1; i < vertice1.size(); ++i) {
            grafo_layout1.cambiar_arista(vertice1[0], vertice1[i], PESO_ARISTA);
        }
    }
}

void Recorrido::agregar_artistas_layout2() {
    for (std::vector<size_t> vertice2: VERTICES_LAYOUT2) {
        for (size_t i = 1; i < vertice2.size(); ++i) {
            grafo_layout2.cambiar_arista(vertice2[0], vertice2[i], PESO_ARISTA);
        }
    }
}

void Recorrido::acutalizar_posicion_james(std::vector<size_t> posicion) {
    posicion_james = posicion;
}

size_t Recorrido::encontrar_arista_james() {
    bool coordenada_encontrada = false;
    size_t vertice = 0;
    std::vector<std::vector<size_t>> coordenadas = COORDENADAS_LAYOUT2;
    size_t tamano_vector = coordenadas.size();
    
    while (!coordenada_encontrada && vertice < tamano_vector) {
        if (coordenadas[vertice][0] == posicion_james[0] && coordenadas[vertice][1] == posicion_james[1]) {
            coordenada_encontrada = true;
        } else {
            vertice ++;
        }
    }
    
    return vertice;
}

void Recorrido::encontrar_camino_minimo() {
    std::pair<std::vector<size_t>, int> resultado;
    grafo_layout2.usar_dijkstra();
    resultado = grafo_layout2.obtener_camino_minimo(encontrar_arista_james(), 55);

    std::cout << "Camino mínimo: ";
    for (size_t i = 0; i < resultado.first.size(); ++i) {
        std::cout << resultado.first[i];
        if (i != resultado.first.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << "\nDistancia mínima: " << resultado.second << std::endl;
}