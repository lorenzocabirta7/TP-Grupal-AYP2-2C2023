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

//OTRA FORMA DE HACERLO
/* asginar_pared_layout_1(i,j)
{
    if ((i != 1 && j != 3)  (i != 2 && j != 7)    (i != 3 && j != 1)  (i != 4 && j != 5)  (i != 5 && j != 3)  (i == 8 && j == 3))
    {
        tablero[i][j] = PARED;
    }
}


for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {


        if(tipo_layout == 1)
        {
            if (j % 2 != 0)
            {
                asignar_pared_layout_1(i,j);
            }
        }
        else
        {
            if (i % 2 != 0  i == 8)
            {
                asignar_pared_layout_2(i,j);
            }
        }*/

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