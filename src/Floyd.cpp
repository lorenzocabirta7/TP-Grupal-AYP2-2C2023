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
    size_t vertice_actual=origen;
    while (vertice_actual != destino)
    {
       camino.push_back(vertice_actual);
       vertice_actual=matriz_caminos.elemento(vertice_actual,destino);
    }
    camino.push_back(destino);
    return camino;
}

std::vector<size_t>
Floyd::calcular_camino_minimo(Matriz adyacencia, size_t vertices, size_t origen, size_t destino, bool hay_cambios) {
    if (hay_cambios) {
        matriz_adyacencia = adyacencia;
        cantidad_vertices = vertices;
        inicializar_matrices();
        int suma_costo;
        for(size_t nodos=0;nodos<cantidad_vertices;nodos++){
            for (size_t filas=0;filas<cantidad_vertices;filas++){
                for(size_t columnas=0;columnas<cantidad_vertices;columnas++){
                    suma_costo=matriz_costos.elemento(filas,nodos)+ matriz_costos.elemento(nodos,columnas);
                    if(matriz_costos.elemento(filas,columnas)> suma_costo){
                        matriz_costos.elemento(filas,columnas)=suma_costo;
                        matriz_caminos.elemento(filas,columnas)=matriz_caminos.elemento(filas,nodos);
                    }
                }
            }
        
        }
    }
    return obtener_camino(origen, destino);
}

Floyd::~Floyd() {}