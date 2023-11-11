#ifndef ALGO2_TP3_PT2_HEAP_H
#define ALGO2_TP3_PT2_HEAP_H

#include <vector>
#include <cstdlib>
#include <exception>

class Heap_exception : public std::exception {
};

template<typename T, bool comp(T, T)>
class Heap {
private:
    std::vector<T> datos;

    // Pre: Ambos índices deben ser menor que la cantidad de datos.
    // Post: Intercambia de lugar los datos de los indices indicados.
    void swap(size_t index_1, size_t index_2);

    // Pre: Ambos índices deben ser menor que la cantidad de datos.
    // Post: Realiza un "upheap" sobre los índices indicados.
    // (El dato "sube" en el heap.)
    void upheap(size_t& index_insertado, size_t index_padre);

    // Post: El índice debe ser menor que la cantidad de datos.
    // Post: Realiza un "downheap" sobre el índice indicado.
    // (El dato "baja" en el heap, intercambiándose con el menor/mayor dato.)
    void downheap(size_t& index_movido);

    // NOTA: No es necesario que lancen excepciones en estos métodos porque son privados.
    // Deberian siempre asegurar que los indices pasados por parámetros son válidos.
    // Consideren cada caso con detenimiento.
    // Adicionalmente, tengan cuidado con el casteo de las variables, porque son size_t.
    // Hacer, por ejemplo, size_t i = 0; i - 1; produce un underflow.
public:
    // Constructor.
    Heap();

    // Pre: -
    // Post: Agrega el dato al Heap.
    void alta(T dato);

    // Pre: El heap no puede estar vacío.
    // Post: Elimina y devuelve el primer dato.
    T baja();

    // Pre: El heap no puede estar vacío.
    // Post: Devuelve el primer dato.
    T primero();

    // Pre: -
    // Post: Devuelve true si el heap está vacío.
    bool vacio();

    // Pre: -
    // Post: Devuelve la cantidad de datos en el heap.
    size_t tamanio();

    // El constructor de copia está deshabilitado.
    Heap(const Heap& heap) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Heap& heap) = delete;

    // Destructor.
    ~Heap();
};

#endif