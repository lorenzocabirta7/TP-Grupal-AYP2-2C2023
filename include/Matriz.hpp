#ifndef MATRIZ_H
#define MATRIZ_H

#include <exception>
#include <cstddef>

class Indice_no_valido_exception : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Error: el indice ingresado no es valido.";
    }
};

class Matriz {
private:
    int* matriz = nullptr;
    size_t fila;
    size_t columna;

    // Pre: -
    // Post: Devuelve true si el indice es valido (0 <= i < filas, 0 <= j < columnas).
    bool indice_valido(size_t i, size_t j);

    // Pre: El indice bidimensional debe ser valido.
    // Post: Devuelve el indice unidimensional equivalente al ingresado.
    size_t calcular_indice(size_t i, size_t j);

    // Pre: Ninguna de las dimesiones puede ser menor que 1.
    // Post: Genera una matriz con las dimensiones indicadas, inicializada con el valor ingresado.
    Matriz(size_t fila, size_t columna, int valor);

    // Pre: Ninguna de las dimesiones puede ser menor que 1.
    // Post: Genera una matriz con las dimensiones indicadas, inicializada con 0.
    Matriz(size_t fila, size_t columna);

public:
    // Constructor default
    Matriz();

    // Pre: Ninguna de las dimesiones puede ser menor que 1.
    // Post: Genera una matriz cuadrada con el tamaño indicado, inicializada con el valor ingresado.
    Matriz(size_t tamanio, int valor);

    // Pre: Ninguna de las dimesiones puede ser menor que 1.
    // Post: Genera una matriz cuadrada con el tamaño indicado, inicializada con 0.
    Matriz(size_t tamanio);

    // Constructor por copia.
    Matriz(const Matriz& matriz1);

    // Operador de asignación.
    Matriz& operator=(const Matriz& matriz1);

    // Pre: El indice debe ser valido, es decir, 0 <= i < filas, 0 <= j < columnas.
    // Post: Devuelve la referecia al elemento accedido.
    int& elemento(size_t i, size_t j);

    // Pre: -
    // Post: Aumenta el tamaño de la matriz en una fila y una columna.
    void expandir();

    // Pre: -
    // Post: Devuelve la cantidad de filas de la matriz.
    // NOTA: En un contexto de matriz cuadrada, equivale también a las columnas.
    size_t filas();

    // Pre: -
    // Post: Devuelve la cantidad de columnas de la matriz.
    // NOTA: En un contexto de matriz cuadrada, equivale también a las filas.
    size_t columnas();

    // Pre: -
    // Post: Libera la memoria reservada por la matriz.
    ~Matriz();
};

#endif