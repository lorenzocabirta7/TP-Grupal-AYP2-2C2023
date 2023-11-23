#include "Interfaz.hpp"

using namespace std;

Interfaz::Interfaz() {
    tablero = std::vector<std::vector<char>>(9, std::vector<char>(9, '*'));
}

size_t Interfaz::generar_coordenada_aleatoria() {
    return size_t (rand() % 9);
}

bool Interfaz::posicion_valida(size_t fila, size_t columna) {
    return (tablero[fila][columna] != PARED && tablero[fila][columna] != PYRAMID_HEAD && tablero[fila][columna] != JAMES && tablero[fila][columna] != ORIGEN && tablero[fila][columna] != DESTINO);
}

void Interfaz::inicializar_paredes(size_t tipo_layout) {
    vector<vector<size_t>> coordenadas;
    if (tipo_layout == 1){
        coordenadas={{0,1},{0,3},{0,5},{0,7},{1,1},{1,5},{1,7},{2,1},{2,3},{2,5},{3,3},{3,5},{3,7},{4,1},{4,3},{4,7},{5,1},{5,5},{5,7},{6,1},{6,3},{6,5},{6,7},{7,3},{7,5},{7,7},{8,3}};
        }
    else{
        coordenadas={{1,1},{1,2},{1,3},{1,4},{1,5},{1,7},{2,7},{3,0},{3,1},{3,3},{3,4},{3,5},{4,7},{5,1},{5,2},{5,3},{5,5},{5,7},{6,5},{7,1},{7,3},{7,5},{7,7},{7,8},{8,3}};
    }
    for(vector<size_t> &coordenada : coordenadas){
        size_t x =coordenada[0];
        size_t y =coordenada[1];
        tablero[x][y]=PARED;
    }
}

void Interfaz::inicializar_tablero(){
    for(size_t fila=0; fila<9; fila++){

        for(size_t columna=0;  columna<9; columna++){
            tablero[fila][columna]='-';
        }
    }

    inicializar_paredes(2);
    tablero[FILA_ORIGEN][COLUMNA_ORIGEN]=ORIGEN;
    tablero[FILA_DESTINO][COLUMNA_DESTINO]=DESTINO;
    inicializar_personajes();

}

void Interfaz::inicializar_personajes() {
    size_t fila = 0;
    size_t columna = 0;
    tablero[FILA_ORIGEN][COLUMNA_ORIGEN] = JAMES;
    
    for (size_t i = 0; i < 2; i++)
    {
        while (!posicion_valida(fila, columna)) {
            fila = generar_coordenada_aleatoria();
            columna = generar_coordenada_aleatoria();
        }
        tablero[fila][columna] = PYRAMID_HEAD;
    }
}

void Interfaz::imprimir_tablero(){

    for(size_t fila=0; fila<9; fila++){

        for(size_t columna=0;  columna<9; columna++){
            cout<<tablero[fila][columna];
        }
        cout<<endl;
    }
}