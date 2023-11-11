#include "Matriz.hpp"

using namespace std;

Matriz::Matriz() {
    fila = 0;
    columna = 0;
}

Matriz::Matriz(size_t fila, size_t columna, int valor) {
    this->fila = fila;
    this->columna = columna;
    if (fila * columna != 0) {
        matriz = new int[fila * columna];
        for (size_t i = 0; i < fila * columna; i++) {
            matriz[i] = valor;
        }
    }
}

Matriz::Matriz(size_t fila, size_t columna) : Matriz(fila, columna, 0) {}

Matriz::Matriz(size_t tamanio, int valor) : Matriz(tamanio, tamanio, valor) {}

Matriz::Matriz(size_t tamanio) : Matriz(tamanio, tamanio, 0) {}

Matriz::Matriz(const Matriz& matriz1) {
    this->fila = matriz1.fila;
    this->columna = matriz1.columna;
    if (fila * columna != 0) {
        matriz = new int[fila * columna];
        for (size_t i = 0; i < fila * columna; i++) {
            matriz[i] = matriz1.matriz[i];
        }
    }
}

Matriz& Matriz::operator=(const Matriz& matriz1) {
    if (this != &matriz1) {
        delete[] matriz;
        matriz = nullptr;
        this->fila = matriz1.fila;
        this->columna = matriz1.columna;
        if (fila * columna != 0) {
            matriz = new int[fila * columna];
            for (size_t i = 0; i < fila * columna; i++) {
                matriz[i] = matriz1.matriz[i];
            }
        }
    }
    return *this;
}

size_t Matriz::calcular_indice(size_t i, size_t j) {
    return i * columna + j;
}

bool Matriz::indice_valido(size_t i, size_t j) {
    return i < fila && j < columna;
}

int& Matriz::elemento(size_t i, size_t j) {
    if (!indice_valido(i, j) || !matriz) {
        throw Indice_no_valido_exception();
    } else {
        return matriz[calcular_indice(i, j)];
    }
}

void Matriz::expandir() {
    int* matriz_aux = new int[(fila + 1) * (columna + 1)];
    for (size_t i = 0; i < fila + 1; i++) {
        for (size_t j = 0; j < columna + 1; j++) {
            try {
                matriz_aux[i * (columna + 1) + j] = elemento(i, j);
            } catch (Indice_no_valido_exception& e) {
                matriz_aux[i * (columna + 1) + j] = 0;
            }
        }
    }
    fila++;
    columna++;
    delete[] matriz;
    matriz = matriz_aux;
}

size_t Matriz::filas() {
    return fila;
}

size_t Matriz::columnas() {
    return columna;
}

Matriz::~Matriz() {
    delete[] matriz;
}