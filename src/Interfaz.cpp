#include "Interfaz.hpp"

using namespace std;

Interfaz::Interfaz()
{
    tablero = std::vector<std::vector<char>>(9, std::vector<char>(9, '*'));
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
        tablero[x][y] = PARED;
    }
}

void Interfaz::inicializar_tablero(size_t tipo_layout)
{
    for (size_t fila = 0; fila < CANTIDAD_FILAS; fila++)
    {

        for (size_t columna = 0; columna < CANTIDAD_COLUMNAS; columna++)
        {
            tablero[fila][columna] = '-';
        }
    }

    inicializar_paredes(tipo_layout);
    tablero[FILA_ORIGEN][COLUMNA_ORIGEN] = ORIGEN;
    tablero[FILA_DESTINO][COLUMNA_DESTINO] = DESTINO;
    inicializar_personajes();
}

void Interfaz::inicializar_personajes()
{
    size_t fila = 0;
    size_t columna = 0;
    tablero[FILA_ORIGEN][COLUMNA_ORIGEN] = JAMES;

    for (size_t i = 0; i < 2; i++)
    {
        while (!posicion_valida(fila, columna))
        {
            fila = generar_coordenada_aleatoria();
            columna = generar_coordenada_aleatoria();
        }
        tablero[fila][columna] = PYRAMID_HEAD;
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

bool Interfaz::movimiento_es_valido(char movimiento)
{
    if (movimiento != ABAJO || movimiento != ARRIBA || movimiento != DERECHA || movimiento != IZQUIERDA)
    {
        cout << "El movimento ingresado no es valido." << endl;
        return false;
    }
    return true;
}

char Interfaz::pedir_movimiento()
{
    char movimiento;
    do
    {
        cout << "Ingrese un movimiento: ";
        cin >> movimiento;
        cout << endl;
    } while (!movimiento_es_valido(movimiento));

    return movimiento;
}

void Interfaz::romper_arma()
{
    desequipar_arma();
    Arma *arma_borrar = inventario->baja();
    delete arma_borrar;
}

void Interfaz::equipar_arma()
{
    if (!inventario->vacio())
    {
        arma_equipada = true;
        cout << "Se ha equipado el arma: ";
        inventario->consulta();
    }
    else
    {
        cout << "No hay armas en el inventario." << endl;
    }
}

void Interfaz::desequipar_arma()
{
    arma_equipada = false;
    cout << "Se ha desequipado el arma." << endl;
}

bool Interfaz::tipo_valido(string tipo)
{
    return (tipo == ID || tipo == POTENCIA);
}

int Interfaz::generar_numero_aleatorio(string tipo)
{
    if (!tipo_valido(tipo))
    {
        cout << "El tipo ingresado no es valido." << endl;
        return -1;
    }
    int numero_aleatorio = 0;
    if (tipo == "ID")
    {
        numero_aleatorio = rand() % (1 + ID_PLACA_MAXIMO - ID_PLACA_MINIMO) + ID_PLACA_MINIMO;
    }
    else
    {
        numero_aleatorio = rand() % (1 + POTENCIA_ARMA_MAXIMO - POTENCIA_ARMA_MINIMO) + POTENCIA_ARMA_MINIMO;
    }

    return numero_aleatorio;
}

Arma *Interfaz::generar_arma()
{
    int potencia;
    do
    {
        potencia = generar_numero_aleatorio(POTENCIA);
    } while (potencia == -1);

    size_t potencia_valida = size_t(potencia);
    Arma *nueva_arma = new Arma("nueva_arma", potencia_valida);
    inventario->alta(nueva_arma);
}

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

std::vector<size_t> Interfaz::obtener_posicion_james()
{
    int fila = -1;
    int columna = -1;
    bool encontrado = false;
    do
    {
        fila++;
        columna++;
        if (tablero[fila][columna] == JAMES)
        {
            encontrado = true;
        }

    } while (fila < CANTIDAD_FILAS && columna < CANTIDAD_COLUMNAS && !encontrado);

    size_t fila_james = size_t(fila);
    size_t columna_james = size_t(columna);
    vector<size_t> posicion = {fila_james, columna_james};

    return posicion;
}

void Interfaz::realizar_movimiento(char movimiento)
{
    vector<size_t> posicion_james = obtener_posicion_james();
    size_t fila_james = posicion_james[0];
    size_t columna_james = posicion_james[1];

    if (movimiento == ABAJO)
    {
        fila_james++;
        tablero[fila_james][columna_james] = JAMES;
    }
    else if (movimiento == ARRIBA)
    {
        fila_james--;
        tablero[fila_james][columna_james] = JAMES;
    }
    else if (movimiento == DERECHA)
    {
        columna_james++;
        tablero[fila_james][columna_james] = JAMES;
    }
    else if (movimiento == IZQUIERDA)
    {
        columna_james--;
        tablero[fila_james][columna_james] = JAMES;
    }
    else
    {
        cout << "El movimiento ingresado no es valido." << endl;
        cout << "Los movimientos validos son: " << DERECHA << ", " << IZQUIERDA << ", " << ARRIBA << ", " << ABAJO << endl;
    }
}

void Interfaz::interaccion_armas()
{
    if (arma_equipada)
    {
        desequipar_arma();
    }
    else
    {
        equipar_arma();
    }
}

void Interfaz::interaccion_personaje(size_t opcion)
{
    if (opcion == MOVER_PERSONAJE)
    {
        char movimiento = pedir_movimiento();
        realizar_movimiento(movimiento);
        imprimir_tablero();
    }
    else
    {
        interaccion_armas();
    }
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

void Interfaz::flujo_juego()
{
    size_t opcion;
    // mostrar opciones
    while (estado_juego() == 0)
    {
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case MOVER_PERSONAJE:
        case MANEJO_ARMAS:
            interaccion_personaje(opcion);
            break;
        case MOSTRAR_MEJOR_RECORRIDO:
        case RECORRER_MEJOR_CAMINO:
            interaccion_grafo(opcion);
            break;
        case MOSTRAR_PUNTAJE:
            mostrar_puntaje();
            break;
        default:
            cout << "La opcion ingresada no es valida." << endl;
            break;
        }
    }
    if (estado_juego() == 1)
    {
        cout << "Ganaste!" << endl;
        mostrar_puntaje();
    }
    else
    {
        cout << "Perdiste!" << endl;
    }
}
