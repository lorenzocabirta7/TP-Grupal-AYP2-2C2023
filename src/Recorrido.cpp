#include "Recorrido.hpp"
#include <vector>

#include <iostream>

Recorrido::Recorrido() {
    grafo_layout1 = Grafo(54);
    grafo_layout2 = Grafo(56);
    posicion_james = {8, 0};
    aristas_cargadas = false;
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

void Recorrido::cargar_aristas() {
    if (!aristas_cargadas) {
        agregar_artistas_layout1();
        agregar_artistas_layout2();
        aristas_cargadas = true;
    }
}

std::vector<std::vector<size_t>> Recorrido::encontrar_camino_minimo() {
    cargar_aristas();
    std::vector<std::vector<size_t>> coordenadas = COORDENADAS_LAYOUT2;
    std::pair<std::vector<size_t>, int> resultado;
    grafo_layout2.usar_dijkstra();
    resultado = grafo_layout2.obtener_camino_minimo(encontrar_arista_james(), 55);

    std::vector<std::vector<size_t>> coordenadas_camino_minimo;

    std::cout << "Camino mínimo: ";
    for (size_t i = 0; i < resultado.first.size(); ++i) {
        coordenadas_camino_minimo.push_back(coordenadas[resultado.first[i]]);
    }
    //std::cout << "\nDistancia mínima: " << resultado.second << std::endl;

//    for (size_t i = 0; i < coordenadas_camino_minimo.size(); ++i) {
//        std::cout << "Vector " << i << ": ";
//        for (size_t j = 0; j < coordenadas_camino_minimo[i].size(); ++j) {
//            std::cout << coordenadas_camino_minimo[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }

    return coordenadas_camino_minimo;
}
