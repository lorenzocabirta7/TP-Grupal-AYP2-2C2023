#include "Recorrido.hpp"
#include <vector>

#include <iostream>

Recorrido::Recorrido() {
    grafo_layout1 = Grafo(54);
    grafo_layout2 = Grafo(56);
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
    posicion_james2 = posicion;
}

size_t Recorrido::encontrar_vertice_james() {
    bool coordenada_encontrada = false;
    size_t vertice = 0;
    std::vector<std::vector<size_t>> coordenadas = COORDENADAS_LAYOUT2;
    size_t tamano_vector = coordenadas.size();
    
    while (!coordenada_encontrada && vertice < tamano_vector) {
        if (coordenadas[vertice][0] == posicion_james2[0] && coordenadas[vertice][1] == posicion_james2[1]) {
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

void Recorrido::descifrar_tipo_layout(size_t altura_arbol) {
    if(altura_arbol % 2 == 0){
        layout_actual = COORDENADAS_LAYOUT1;
        numero_layout = 1;
    } else {
        layout_actual = COORDENADAS_LAYOUT2;
        numero_layout = 2;
    }
}

//std::vector<std::vector<size_t>> Recorrido::asignar_tipo_layout() {
//    std::vector<std::vector<size_t>> coordenadas;
//    if (tipo_layout_actual == 1) {
//        coordenadas = COORDENADAS_LAYOUT1;
//    } else {
//        coordenadas = COORDENADAS_LAYOUT2;
//    }
//    return coordenadas;
//}

void Recorrido::asignar_grafo_correspondiente() {
    if (numero_layout == 1){
        grafo_a_utilizar = grafo_layout1;
    } else {
        grafo_a_utilizar = grafo_layout2;
    }
}

void Recorrido::modificar_posicion_personajes(std::vector<size_t> &posicion_actual_james, std::vector<std::vector<size_t>> posiciones_pyramidheads) {
    acutalizar_posicion_james(posicion_actual_james);

    if (posiciones_pyramidheads[0][0] == 10) {
        posicion_pyramid1 = {10,10};
    } else {
        posicion_pyramid1 = posiciones_pyramidheads[0];
    }

    if (posiciones_pyramidheads[1][0] == 10) {
        posicion_pyramid2 = {10,10};
    } else {
        posicion_pyramid2 = posiciones_pyramidheads[1];
    }
}

size_t Recorrido::encontrar_vertice_pyramid(int numero_pyramid) {
    bool coordenada_encontrada = false;
    size_t vertice = 0;
    //std::vector<std::vector<size_t>> layout_actual = tipo_layout_actual % 2 == 0 ? COORDENADAS_LAYOUT1 : COORDENADAS_LAYOUT2;
    std::vector<size_t> pyramidhead = numero_pyramid == 1 ? posicion_pyramid1 : posicion_pyramid2;
    size_t tamano_vector = layout_actual.size();

    while (!coordenada_encontrada && vertice < tamano_vector) {
        if (layout_actual[vertice][0] == pyramidhead[0] && layout_actual[vertice][1] == pyramidhead[1]) {
            coordenada_encontrada = true;
        } else {
            vertice ++;
        }
    }

    return vertice;
}

void Recorrido::actualizar_valor_arista_pyramidhead(size_t vertice_pyramid) {
    if(numero_layout == 1) {
        std::vector<size_t> coordenada_pyramid = VERTICES_LAYOUT1[vertice_pyramid];
        for (size_t i = 0; i < coordenada_pyramid.size(); ++i) {
            grafo_a_utilizar.cambiar_arista(coordenada_pyramid[0], coordenada_pyramid[i], PESO_ARISTA_PYRAMID);
        }
    }
    else{
        std::vector<size_t> coordenada_pyramid = VERTICES_LAYOUT2[vertice_pyramid];
        for (size_t i = 0; i < coordenada_pyramid.size(); ++i) {
            grafo_a_utilizar.cambiar_arista(coordenada_pyramid[0], coordenada_pyramid[i], PESO_ARISTA_PYRAMID);
        }
    }
}

void Recorrido::modificar_aristas_pyramidheads() {
    if(posicion_pyramid1[0] == 10 && posicion_pyramid2[0] == 10){
        return;
    }
    else if(posicion_pyramid1[0] != 10){
        size_t vertice_pyramid1 = encontrar_vertice_pyramid(1);
        actualizar_valor_arista_pyramidhead(vertice_pyramid1);
    }
    else if(posicion_pyramid2[0] != 10){
        size_t vertice_pyramid2 = encontrar_vertice_pyramid(2);
        actualizar_valor_arista_pyramidhead(vertice_pyramid2);
    }
}

std::vector<std::vector<size_t>> Recorrido::encontrar_camino_minimo(std::vector<size_t> posicion_actual_james, std::vector<std::vector<size_t>> posiciones_pyramidheads,size_t altura_arbol, bool tiene_arma) {
    cargar_aristas();
    descifrar_tipo_layout(altura_arbol);
    modificar_posicion_personajes(posicion_actual_james, posiciones_pyramidheads);

    //std::vector<std::vector<size_t>> coordenadas = asignar_tipo_layout();
    //Grafo grafo_a_utilizar = asignar_grafo_correspondiente();
    asignar_grafo_correspondiente();

    modificar_aristas_pyramidheads();

    std::pair<std::vector<size_t>, int> resultado;
    grafo_a_utilizar.usar_dijkstra();

    size_t cantidad_vertices = numero_layout == 1 ? 53 : 55;

    resultado = grafo_a_utilizar.obtener_camino_minimo(encontrar_vertice_james(), cantidad_vertices);

    std::vector<std::vector<size_t>> coordenadas_camino_minimo;

    std::cout << "Camino mínimo: ";
    for (size_t i = 0; i < resultado.first.size(); ++i) {
        coordenadas_camino_minimo.push_back(layout_actual[resultado.first[i]]);
    }
    std::cout << "\nDistancia mínima: " << resultado.second << std::endl;

    for (size_t i = 0; i < coordenadas_camino_minimo.size(); ++i) {
        std::cout << "Vector " << i << ": ";
        for (size_t j = 0; j < coordenadas_camino_minimo[i].size(); ++j) {
            std::cout << coordenadas_camino_minimo[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return coordenadas_camino_minimo;
}
