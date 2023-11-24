#include "Personaje.hpp"


Personaje::Persoanje(Inventario inventario){
    this->inventario =inventario;
}

bool Persoanje::movimiento_es_valido(char movimiento)
{
    if (movimiento != ABAJO || movimiento != ARRIBA || movimiento != DERECHA || movimiento != IZQUIERDA)
    {
        cout << "El movimento ingresado no es valido." << endl;
        return false;
    }
    return true;
}

char Persoanje::pedir_movimiento()
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

std::vector<size_t> Interfaz::obtener_posicion_james(Interfaz interfaz)
{
    int fila = -1;
    int columna = -1;
    bool encontrado = false;
    do
    {
        fila++;
        columna++;
        if (interfaz.esta_personaje(fila,columna,JAMES))
        {
            encontrado = true;
        }

    } while (fila < CANTIDAD_FILAS && columna < CANTIDAD_COLUMNAS && !encontrado);

    size_t fila_james = size_t(fila);
    size_t columna_james = size_t(columna);
    vector<size_t> posicion = {fila_james, columna_james};

    return posicion;
}

void Interfaz::realizar_movimiento(char movimiento,Interfaz interfaz)
{
    vector<size_t> posicion_james = obtener_posicion_james();
    size_t fila_james = posicion_james[0];
    size_t columna_james = posicion_james[1];

    if (movimiento == ABAJO)
    {
        fila_james++;
        interfaz.actualizar_tablero(fila_james,columna_james,JAMES);
    }
    else if (movimiento == ARRIBA)
    {
        fila_james--;
        interfaz.actualizar_tablero(fila_james,columna_james,JAMES);
    }
    else if (movimiento == DERECHA)
    {
        columna_james++;
        interfaz.actualizar_tablero(fila_james,columna_james,JAMES);
    }
    else if (movimiento == IZQUIERDA)
    {
        columna_james--;
        interfaz.actualizar_tablero(fila_james,columna_james,JAMES);
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
