#include "Interfaz.hpp"

using namespace std;

int Interfaz::calcular_numero_aleatorio(int largo)
{
    return rand() % largo + 1;
}

Interfaz::Interfaz()
{
    tablero = std::vector<std::vector<char>>(CANTIDAD_FILAS, std::vector<char>(CANTIDAD_COLUMNAS, ESPACIO_LIBRE));
}

// ** INICIALIZACION **

size_t Interfaz::generar_coordenada_aleatoria()
{
    return size_t(static_cast<size_t>(rand()) % CANTIDAD_FILAS);
}

bool Interfaz::posicion_valida(size_t fila, size_t columna)
{
    return (tablero[fila][columna] != PARED && tablero[fila][columna] != PYRAMID_HEAD && tablero[fila][columna] != JAMES && tablero[fila][columna] != ORIGEN && tablero[fila][columna] != DESTINO);
}

void Interfaz::inicializar_paredes(size_t tipo_layout)
{
    vector<vector<size_t>> coordenadas;
    if (tipo_layout % 2 == 0)
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
        actualizar_tablero(x, y, PARED);
    }
}

void Interfaz::inicializar_tablero(size_t tipo_layout)
{
    for (size_t fila = 0; fila < CANTIDAD_FILAS; fila++)
    {
        for (size_t columna = 0; columna < CANTIDAD_COLUMNAS; columna++)
        {
            actualizar_tablero(fila, columna, ESPACIO_LIBRE);
        }
    }

    inicializar_paredes(tipo_layout);
    actualizar_tablero(FILA_ORIGEN, COLUMNA_ORIGEN, ORIGEN);
    actualizar_tablero(FILA_DESTINO, COLUMNA_DESTINO, DESTINO);
    inicializar_personajes();
}

void Interfaz::inicializar_personajes()
{
    actualizar_tablero(FILA_ORIGEN, COLUMNA_ORIGEN, JAMES);
    size_t cantidad_de_pyramid_head = 0;

    for (int i = 0; i < 2; i++)
    {
        int dado = calcular_numero_aleatorio(2);
        if (dado == 1)
        {
            cantidad_de_pyramid_head++;
        }
    }
    for (size_t i = 0; i < cantidad_de_pyramid_head; i++)
    {

        size_t fila = 0;
        size_t columna = 0;
        fila = generar_coordenada_aleatoria();
        columna = generar_coordenada_aleatoria();
        while (!posicion_valida(fila, columna))
        {
            fila = generar_coordenada_aleatoria();
            columna = generar_coordenada_aleatoria();
        }

        actualizar_tablero(fila, columna, PYRAMID_HEAD);
    }
}

// ** IMPRIMIR **
void Interfaz::imprimir_tablero(size_t tipo_tablero)
{
    for (size_t fila = 0; fila < CANTIDAD_FILAS; fila++)
    {

        for (size_t columna = 0; columna < CANTIDAD_COLUMNAS; columna++)
        {
            if(tipo_tablero == TABLERO_2){
                cout << tablero2[fila][columna];
            }else{
                cout << tablero[fila][columna];
            }
        }
        cout << endl;
    }
}

// ** MOVIMIENTOS **

size_t Interfaz::estado_juego(size_t altura_arbol, bool tiene_arma)
{

    if (niveles_completados == 5)
    {
        return 1;
    }
    else if (!tiene_arma)
    {
        if (altura_arbol % 2 == 0 && (esta_ocupado(1, 8, PYRAMID_HEAD) || esta_ocupado(2, 8, PYRAMID_HEAD)))
        {
            return 2;
        }
        else if (altura_arbol % 2 != 0 && ((esta_ocupado(1, 8, PYRAMID_HEAD) || esta_ocupado(2, 8, PYRAMID_HEAD) || esta_ocupado(3, 8, PYRAMID_HEAD)) && (esta_ocupado(0, 7, PYRAMID_HEAD) || esta_ocupado(0, 6, PYRAMID_HEAD))))
        {
            return 2;
        }
    }

    return 0;
}


void Interfaz::actualizar_tablero(size_t fila, size_t columna, char personaje)
{
    tablero[fila][columna] = personaje;
}

bool Interfaz::esta_ocupado(size_t fila, size_t columna, char objeto)
{
    return tablero[fila][columna] == objeto;
}

bool Interfaz::hay_pared(size_t filas, size_t columnas)
{
    return tablero[filas][columnas] == PARED;
}

void Interfaz::aumentar_niveles_completados()
{
    niveles_completados++;
}


void Interfaz::mostrar_coordenadas_camino_minimo(std::vector<std::vector<size_t>> coordenadas_camino_minimo)
{
    tablero2 = tablero;
    for(size_t i = 0; i < coordenadas_camino_minimo.size(); ++i)
    {
        for(size_t j = 0; j < coordenadas_camino_minimo[i].size(); ++j)
        {
            tablero2[coordenadas_camino_minimo[i][0]][coordenadas_camino_minimo[i][1]] = '^';
        }
    }
    imprimir_tablero(TABLERO_2);
}

void Interfaz::cambiar_posicion_james(vector<size_t> posicion_james){
    actualizar_tablero(posicion_james[0], posicion_james[1], ESPACIO_LIBRE);
    actualizar_tablero(1, 8, JAMES);
}

