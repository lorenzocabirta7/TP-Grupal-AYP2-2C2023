#include "Personaje.hpp"

using namespace std;

Personaje::Personaje()
{
}

bool Personaje::movimiento_es_valido(char movimiento)
{
    if (movimiento != ABAJO && movimiento != ARRIBA && movimiento != DERECHA && movimiento != IZQUIERDA)
    {
        cout << "El movimento ingresado no es valido." << endl;
        return false;
    }
    return true;
}

char Personaje::pedir_movimiento()
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

void Personaje::usar_arma()
{
    desequipar_arma();
    Arma arma_borrar = inventario.baja();
}

void Personaje::equipar_arma()
{
    if (!inventario.vacio())
    {
        arma_equipada = true;
        cout << "Se ha equipado el arma: ";
        inventario.consulta();
    }
    else
    {
        cout << "No hay armas en el inventario." << endl;
        tiene_arma = false;
    }
}

void Personaje::desequipar_arma()
{
    arma_equipada = false;
    cout << "Se ha desequipado el arma." << endl;
}

bool Personaje::tipo_valido(string tipo)
{
    return (tipo == ID || tipo == POTENCIA);
}

int Personaje::generar_numero_aleatorio(string tipo)
{
    if (!tipo_valido(tipo))
    {
        cout << "El tipo ingresado no es valido." << endl;
        return -1;
    }

    int numero_aleatorio = 0;
    if (tipo == ID)
    {
        numero_aleatorio = (rand()) % (1 + ID_PLACA_MAXIMO - ID_PLACA_MINIMO) + ID_PLACA_MINIMO;
    }
    else
    {
        numero_aleatorio = (rand()) % (1 + POTENCIA_ARMA_MAXIMO - POTENCIA_ARMA_MINIMO) + POTENCIA_ARMA_MINIMO;
    }

    return numero_aleatorio;
}

void Personaje::generar_arma(Interfaz &interfaz)
{
    int potencia;
    do
    {
        potencia = generar_numero_aleatorio(POTENCIA);
    } while (potencia == -1);

    int dado = interfaz.calcular_numero_aleatorio(5);
    if (dado == 1)
    {
        size_t potencia_valida = size_t(potencia);
        Arma nueva_arma = Arma("nueva_arma", potencia_valida);
        inventario.alta(nueva_arma);
        tiene_arma = true;
    }
}

vector<size_t> Personaje::obtener_posicion_james(Interfaz &interfaz)
{
    bool james_encontrado = false;
    size_t fila = 0;
    size_t columna = 0;

    while (!james_encontrado && fila < CANTIDAD_FILAS)
    {
        while (!james_encontrado && columna < CANTIDAD_COLUMNAS)
        {
            if (interfaz.esta_ocupado(fila, columna, JAMES))
            {
                james_encontrado = true;
            }
            else
            {
                columna++;
            }
        }
        if (!james_encontrado)
        {
            columna = 0;
            fila++;
        }
    }

    vector<size_t> posicion = {fila, columna};

    return posicion;
}

bool Personaje::nivel_terminado(Interfaz &interfaz)
{
    vector<size_t> coordenadas = obtener_posicion_james(interfaz);

    if (coordenadas[0] == FILA_DESTINO && coordenadas[1] == COLUMNA_DESTINO)
    {
        interfaz.aumentar_niveles_completados();
        generar_arma(interfaz);
        generar_placa();
        return true;
    }
    return false;
}

bool Personaje::casilla_valida(size_t fila, size_t columna, Interfaz &interfaz)
{
    if (fila < 0 || columna > 8 || fila > 8 || columna < 0)
    {
        cout << "No se puede realizar el movimiento porque se sale del tablero." << endl;
        return false;
    }

    if (interfaz.esta_ocupado(fila, columna, PARED))
    {
        cout << "No se puede realizar el movimiento porque hay una pared." << endl;
        return false;
    }

    if (interfaz.esta_ocupado(fila, columna, PYRAMID_HEAD))
    {
        cout << "No se puede realizar el movimiento porque hay un Pyramid Head." << endl;
        return false;
    }
    return true;
}

void Personaje::realizar_movimiento(char movimiento, Interfaz &interfaz)
{
    vector<size_t> posicion_james = obtener_posicion_james(interfaz);

    size_t fila_james = posicion_james[0];
    size_t columna_james = posicion_james[1];

    if (movimiento == ABAJO)
    {
        if (casilla_valida(fila_james + 1, columna_james, interfaz))
        {
            interfaz.actualizar_tablero(fila_james, columna_james, ESPACIO_LIBRE);
            fila_james++;
            interfaz.actualizar_tablero(fila_james, columna_james, JAMES);
            actualizar_puntaje(interfaz);
        }
    }
    else if (movimiento == ARRIBA)
    {
        if (casilla_valida(fila_james - 1, columna_james, interfaz))
        {
            interfaz.actualizar_tablero(fila_james, columna_james, ESPACIO_LIBRE);
            fila_james--;
            interfaz.actualizar_tablero(fila_james, columna_james, JAMES);
            actualizar_puntaje(interfaz);
        }
    }
    else if (movimiento == DERECHA)
    {
        if (casilla_valida(fila_james, columna_james + 1, interfaz))
        {
            interfaz.actualizar_tablero(fila_james, columna_james, ESPACIO_LIBRE);
            columna_james++;
            interfaz.actualizar_tablero(fila_james, columna_james, JAMES);
            actualizar_puntaje(interfaz);
        }
    }
    else if (movimiento == IZQUIERDA)
    {
        if (casilla_valida(fila_james, columna_james - 1, interfaz))
        {
            interfaz.actualizar_tablero(fila_james, columna_james, ESPACIO_LIBRE);
            columna_james--;
            interfaz.actualizar_tablero(fila_james, columna_james, JAMES);
            actualizar_puntaje(interfaz);
        }
    }
    else
    {
        cout << "El movimiento ingresado no es valido." << endl;
        cout << "Los movimientos validos son: " << DERECHA << ", " << IZQUIERDA << ", " << ARRIBA << ", " << ABAJO << endl;
    }
}

void Personaje::interaccion_armas()
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

void Personaje::interaccion_personaje(size_t opcion, Interfaz &interfaz)
{
    if (opcion == MOVER_PERSONAJE)
    {
        char movimiento = pedir_movimiento();
        realizar_movimiento(movimiento, interfaz);
    }
    else
    {
        interaccion_armas();
    }
}

void Personaje::generar_placa()
{
    int id;
    Placa nueva_placa;
    do
    {
        id = generar_numero_aleatorio(ID);
        nueva_placa = Placa("nombre", "leyenda", id);
    } while (id == -1 && arbol_placas.consulta(nueva_placa));

    arbol_placas.alta(nueva_placa);
}

size_t Personaje::get_altura()
{
    return arbol_placas.calcular_altura();
}

bool Personaje::get_tiene_arma()
{
    return tiene_arma;
}

vector<vector<size_t>> Personaje::obtener_posicion_pyramidhead(Interfaz &interfaz)
{
    int cantidad_pyramidheads = 0;
    size_t fila = 0;
    size_t columna = 0;

    std::vector<size_t> posicion_pyramidhead1 = {POSICION_INVALIDA, POSICION_INVALIDA};
    std::vector<size_t> posicion_pyramidhead2 = {POSICION_INVALIDA, POSICION_INVALIDA};

    while (fila < CANTIDAD_FILAS && cantidad_pyramidheads < 2)
    {
        while (columna < CANTIDAD_COLUMNAS && cantidad_pyramidheads < 2)
        {
            if (interfaz.esta_ocupado(fila, columna, PYRAMID_HEAD))
            {
                cantidad_pyramidheads++;
                if (cantidad_pyramidheads == 1)
                {
                    posicion_pyramidhead1 = {fila, columna};
                    if (fila < (CANTIDAD_FILAS - 1))
                    {
                        fila++;
                    }
                }
                else
                {
                    posicion_pyramidhead2 = {fila, columna};
                }
            }
            else
            {
                columna++;
            }
        }
        if (cantidad_pyramidheads < 2)
        {
            columna = 0;
            fila++;
        }
    }

    vector<vector<size_t>> posiciones_pyramidheads = {posicion_pyramidhead1, posicion_pyramidhead2};

    return posiciones_pyramidheads;
}

bool Personaje::eliminar_pyramid_head(Interfaz &interfaz)
{
    vector<vector<size_t>> posiciones_pyramid_heads = obtener_posicion_pyramidhead(interfaz);
    if (posiciones_pyramid_heads[0][0] == POSICION_INVALIDA)
    {
        return false;
    }
    vector<size_t> posicion_pyramid_head1 = posiciones_pyramid_heads[0];
    vector<size_t> posicion_james = obtener_posicion_james(interfaz);
    vector<size_t> posicion_pyramid_head2 = posiciones_pyramid_heads[1];

    if (arma_equipada)
    {

        if (pyramid_head_cercano(posicion_pyramid_head1, posicion_james))
        {
            usar_arma();
            return true;
        }
        else if (posicion_pyramid_head2[0] != POSICION_INVALIDA)
        {
            if (pyramid_head_cercano(posicion_pyramid_head2, posicion_james))
            {
                usar_arma();
                return true;
            }
        }
    }
    return false;
}

size_t Personaje::obtener_puntaje_total()
{
    return puntaje_total;
}

bool Personaje::pyramid_head_cercano(std::vector<size_t> posicion_pyramid_head, std::vector<size_t> posicion_james)
{
    if (posicion_pyramid_head[0] == POSICION_INVALIDA)
    {
        return false;
    }
    if (distancia_manhattan(posicion_pyramid_head[0], posicion_james[0], posicion_pyramid_head[1], posicion_james[1]) == 1)
    {

        return true;
    }

    return false;
}

void Personaje::actualizar_puntaje(Interfaz &interfaz)
{
    vector<size_t> posicion_james = obtener_posicion_james(interfaz);
    vector<vector<size_t>> posicion_pyramid_heads = obtener_posicion_pyramidhead(interfaz);
    if (pyramid_head_cercano(posicion_pyramid_heads[0], posicion_james) && !arma_equipada)
    {
        puntaje_total += PESO_ARISTA_PYRAMID;
    }
    else if (posicion_pyramid_heads[1][0] != POSICION_INVALIDA && pyramid_head_cercano(posicion_pyramid_heads[1], posicion_james) && !arma_equipada)
    {
        puntaje_total += PESO_ARISTA_PYRAMID;
    }
    else
    {
        puntaje_total += PESO_ARISTA;
    }
}

size_t Personaje::distancia_manhattan(size_t fila1, size_t fila2, size_t columna1, size_t columna2)
{
    int fila11 = (int)fila1;
    int fila22 = (int)fila2;
    int columna11 = (int)columna1;
    int columna22 = (int)columna2;

    int coordenada_en_x, coordenada_en_y, resultado;
    coordenada_en_x = (fila11 - fila22);       
    coordenada_en_y = (columna11 - columna22);

    if (coordenada_en_x < 0)
    {
        coordenada_en_x *= -1;
    }
    if (coordenada_en_y < 0)
    {
        coordenada_en_y *= -1;
    }
    resultado = coordenada_en_x + coordenada_en_y;
    return (size_t)resultado;
}

