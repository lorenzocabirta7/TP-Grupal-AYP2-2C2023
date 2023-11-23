#include "Interfaz.hpp"

using namespace std;

size_t Interfaz::generar_coordenada_aleatoria() {
    return rand() % 10;
}

bool Interfaz::posicion_valida(size_t fila, size_t columna) {
    return (tablero[fila][columna] != PARED && tablero[fila][columna] != PYRAMID_HEAD && tablero[fila][columna] != JAMES && tablero[fila][columna] != ORIGEN && tablero[fila][columna] != DESTINO);
}

void Interfaz::inicializar_paredes(size_t tipo_layout) {
    if (tipo_layout == 1){
        vector<size_t> posiciones_filas = {0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4 , 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 8};
        vector<size_t> posiciones_columnas = {1, 3, 5, 7, 1, 5, 7, 1, 3, 5, 3, 5, 7, 1, 3, 7, 1, 5, 7, 1, 3, 5, 7, 3, 5, 7, 3};
        for(size_t i = 0; i < posiciones_filas.size(); i++){
            for(size_t j = 0; j < posiciones_columnas.size(); j++){
                tablero[posiciones_filas[i]][posiciones_columnas[j]] = PARED;
            }
        }
    }
}


void Interfaz::inicializar_personajes() {
    size_t fila = 0;
    size_t columna = 0;
    size_t cantidad_pyramid_head = 0;
    
    tablero[FILA_ORIGEN][COLUMNA_ORIGEN] = JAMES;
    
    while (cantidad_pyramid_head != 2)
    {
        fila = generar_coordenada_aleatoria();
        columna = generar_coordenada_aleatoria();
        
        while (!posicion_valida(fila, columna)) {
            fila = generar_coordenada_aleatoria();
            columna = generar_coordenada_aleatoria();
        }
        tablero[fila][columna] = PYRAMID_HEAD;
        cantidad_pyramid_head++;
    }
}