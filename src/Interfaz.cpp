#include "Interfaz.hpp"

using namespace std;

Interfaz::Interfaz()
{
    tablero = std::vector<std::vector<char>>(CANTIDAD_FILAS, std::vector<char>(CANTIDAD_COLUMNAS, ESPACIO_LIBRE));
}

// ** INICIALIZACION **

size_t Interfaz::generar_coordenada_aleatoria()
{
    return size_t(rand() % CANTIDAD_FILAS);
}

bool Interfaz::posicion_valida(size_t fila, size_t columna)
{
    return (tablero[fila][columna] != PARED && tablero[fila][columna] != PYRAMID_HEAD && tablero[fila][columna] != JAMES && tablero[fila][columna] != ORIGEN && tablero[fila][columna] != DESTINO);
}

void Interfaz::inicializar_paredes(size_t tipo_layout)
{
    vector<vector<size_t>> coordenadas;
    if (tipo_layout == 1)
    {
        coordenadas = {{0, 1}, {0, 3}, {0, 5}, {0, 7}, {1, 1}, {1, 5}, {1, 7}, {2, 1}, {2, 3}, {2, 5}, {3, 3}, {3, 5}, {3, 7}, {4, 1}, {4, 3}, {4, 7}, {5, 1}, {5, 5}, {5, 7}, {6, 1}, {6, 3}, {6, 5}, {6, 7}, {7, 3}, {7, 5}, {7, 7}, {8, 3}};
    }
    else
    {
        coordenadas = {{1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 7}, {2, 7}, {3, 0}, {3, 1}, {3, 3}, {3, 4}, {3, 5}, {4, 7}, {5, 1}, {5, 2}, {5, 3}, {5, 5}, {5, 7}, {6, 5}, {7, 1}, {7, 3}, {7, 5}, {7, 7}, {7, 8}, {8, 3}};
    }
    for (vector<size_t> &coordenada : coordenadas)
    {
        size_t x = coordenada[0];
        size_t y = coordenada[1];
        modificar_tablero(x,y,PARED);
    }
}

void Interfaz::inicializar_tablero(size_t tipo_layout)
{
    for (size_t fila = 0; fila < CANTIDAD_FILAS; fila++)
    {

        for (size_t columna = 0; columna < CANTIDAD_COLUMNAS; columna++)
        {
            modificar_tablero(fila,columna,ESPACIO_LIBRE);
        }
    }

    inicializar_paredes(tipo_layout);
    modificar_tablero(FILA_ORIGEN,COLUMNA_ORIGEN,ORIGEN);
    modificar_tablero(FILA_DESTINO,COLUMNA_DESTINO,DESTINO);
    inicializar_personajes();
}

void Interfaz::inicializar_personajes()
{
    size_t fila = 0;
    size_t columna = 0;
    modificar_tablero(FILA_ORIGEN,COLUMNA_ORIGEN,JAMES);
   
    for (size_t i = 0; i < 2; i++)
    {
        while (!posicion_valida(fila, columna))
        {
            fila = generar_coordenada_aleatoria();
            columna = generar_coordenada_aleatoria();
        }
        modificar_tablero(fila,columna,PYRAMID_HEAD);
    }
}

// ** IMPRIMIR **
void Interfaz::imprimir_tablero()
{
    for (size_t fila = 0; fila < CANTIDAD_FILAS; fila++)
    {

        for (size_t columna = 0; columna < CANTIDAD_COLUMNAS; columna++)
        {
            cout << tablero[fila][columna];
        }
        cout << endl;
    }
}

void Interfaz::mostrar_puntaje()
{
    cout << "Puntaje total utilizado: " << puntaje << endl;
}

void Interfaz::mostrar_mejor_recorrido()
{
    // grafo -> mejor_recorrido();
}

void Interfaz::recorrer_mejor_camino()
{
    // grafo -> recorrer_mejor_camino();
}

size_t Interfaz::elegir_layout(size_t altura_arbol)
{
    size_t tipo_layout;
    if (altura_arbol % 2 == 0)
    {
        tipo_layout = 1;
    }
    else
    {
        tipo_layout = 2;
    }
    return tipo_layout;
}

// ** MOVIMIENTOS **


Placa *Interfaz::generar_placa()
{
    int id;
    do
    {
        id = generar_numero_aleatorio(POTENCIA);
    } while (id == -1);

    size_t id_valido = size_t(id);
    Placa nueva_placa = Placa("nombre", "leyenda", id_valido);

    if (arbol_placas.consulta(&nueva_placa))
    {
        generar_placa();
    }

    arbol_placas.alta(&nueva_placa);
    return &nueva_placa;
}

size_t Interfaz::estado_juego()
{
    if (niveles_completados == 5)
    {
        return 1;
    }
    /*
    else if(no hay camino posible)
    {
        return 2;
    }
    */
    return 0;
}


void Interfaz::interaccion_grafo(size_t opcion)
{
    if (opcion == MOSTRAR_MEJOR_RECORRIDO)
    {
        mostrar_mejor_recorrido();
    }
    else
    {
        recorrer_mejor_camino();
    }
}

void Interfaz::modificar_tablero(size_t fila, size_t columna,char personaje){

    tablero[fila][columna]=personaje;
}


bool Interfaz::esta_personaje(size_t filas, size_t columnas, char personaje){
    return tablero[fila][columna] == personaje;
}

int distancia_manhattan(int fila1, int fila2, int columna1, int columna2){
    bool 
    int coordenada_en_x, coordenada_en_y,resultado;
    coordenada_en_x = (fila1- fila2);
    coordenada_en_y = (columna1 - columna2);

    if(coordenada_en_x < 0){
        coordenada_en_x = MODULO;
    }
    if(coordenada_en_y < 0){
        coordenada_en_y= MODULO;
    }
    resultado = coordenada_en_x + coordenada_en_y;
}