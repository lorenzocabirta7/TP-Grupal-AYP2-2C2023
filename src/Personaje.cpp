#include "Personaje.hpp"

using namespace std;

Personaje::Personaje(Inventario *inventario)
{
    this->inventario = inventario;
}

Personaje::Personaje()
{
}

bool Personaje::movimiento_es_valido(char movimiento)
{
    if (movimiento != ABAJO || movimiento != ARRIBA || movimiento != DERECHA || movimiento != IZQUIERDA)
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

void Personaje::romper_arma()
{
    desequipar_arma();
    Arma *arma_borrar = inventario->baja();
    delete arma_borrar;
}

void Personaje::equipar_arma()
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

Arma *Personaje::generar_arma()
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

vector<size_t> Personaje::obtener_posicion_james(Interfaz &interfaz)
{
    int fila = -1;
    int columna = -1;
    bool encontrado = false;
    do
    {
        fila++;
        columna++;
        if (interfaz.esta_ocupado(fila, columna, JAMES))
        {
            encontrado = true;
        }

    } while (fila < CANTIDAD_FILAS && columna < CANTIDAD_COLUMNAS && !encontrado);

    size_t fila_james = size_t(fila);
    size_t columna_james = size_t(columna);
    vector<size_t> posicion = {fila_james, columna_james};

    return posicion;
}

bool Personaje::casilla_valida(int fila, int columna, Interfaz &interfaz)
{
    if (interfaz.esta_ocupado(size_t(fila), size_t(columna), PARED))
    {
        cout << "No se puede realizar el movimiento porque hay una pared." << endl;
        return false;
    }
    if (fila < 0 || columna > 8 || fila > 8 || columna < 0)
    {
        cout << "No se puede realizar el movimiento porque se sale del tablero." << endl;
        return false;
    }
    return true;
}

void Personaje::realizar_movimiento(char movimiento, Interfaz &interfaz)
{
    vector<size_t> posicion_james = obtener_posicion_james(interfaz);

    int fila_james = static_cast<int>(posicion_james[0]);
    int columna_james = static_cast<int>(posicion_james[1]);

    if (movimiento == ABAJO)
    {
        if (casilla_valida(fila_james + 1, columna_james, interfaz))
        {
            fila_james++;
            interfaz.actualizar_tablero(fila_james, columna_james, JAMES);
        }
    }
    else if (movimiento == ARRIBA)
    {
        if (casilla_valida(fila_james - 1, columna_james, interfaz))
        {
            fila_james--;
            interfaz.actualizar_tablero(fila_james, columna_james, JAMES);
        }
    }
    else if (movimiento == DERECHA)
    {
        if (casilla_valida(fila_james, columna_james + 1, interfaz))
        {
            columna_james++;
            interfaz.actualizar_tablero(fila_james, columna_james, JAMES);
        }
    }
    else if (movimiento == IZQUIERDA)
    {
        if (casilla_valida(fila_james, columna_james - 1, interfaz))
        {
            columna_james--;
            interfaz.actualizar_tablero(fila_james, columna_james, JAMES);
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
        interfaz.imprimir_tablero();
    }
    else
    {
        interaccion_armas();
    }
}
