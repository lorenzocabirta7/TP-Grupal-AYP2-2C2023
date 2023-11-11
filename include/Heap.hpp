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

    //Pre: -
    //Post: Devuelve el padre.
    size_t devolver_padre(size_t index);

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

template<typename T, bool comp(T, T)>
Heap<T, comp>::Heap(){
    this -> datos = datos;
}

template<typename T, bool comp(T, T)>
size_t Heap<T, comp>::devolver_padre(size_t index){
    return (index - 1) / 2;
}

template<typename T, bool comp(T, T)>
void Heap<T, comp>::swap(size_t index_1, size_t index_2){
    T aux = datos[index_1];
    datos[index_1] = datos[index_2];
    datos[index_2] = aux;
}

template<typename T, bool comp(T, T)>
void Heap<T, comp>::upheap(size_t& index_insertado, size_t index_padre){
    if(index_insertado > 0 && comp(datos[index_insertado], datos[index_padre])){
        swap(index_insertado, index_padre);
        size_t nuevo_padre = devolver_padre(index_padre);
        upheap(index_padre, nuevo_padre);
    }
}

template<typename T, bool comp(T, T)>
void Heap<T, comp>::downheap(size_t& index_movido){
    size_t hijo_izquierdo = index_movido * 2 + 1;
    size_t hijo_derecho = index_movido * 2 + 2;
    if(hijo_izquierdo < tamanio() && comp(datos[hijo_izquierdo], datos[index_movido])){
        swap(hijo_izquierdo, index_movido);
        downheap(index_movido);
    }

    if(hijo_derecho < tamanio() && comp(datos[hijo_derecho], datos[index_movido])){
        swap(hijo_derecho, index_movido);
        downheap(index_movido);
    }
}

template<typename T, bool comp(T, T)>
void Heap<T, comp>::alta(T dato){
    datos.push_back(dato);
    size_t index_insertado = tamanio() - 1;
    size_t padre = 0;
    if(index_insertado != 0){
        padre = devolver_padre(index_insertado);
    }
    upheap(index_insertado, padre);
}

template<typename T, bool comp(T, T)>
T Heap<T, comp>::baja(){
    if(vacio()){
        throw Heap_exception();
    }
    T raiz = datos[0];
    size_t index_a_borrar = 0;
    datos[0] =  datos[tamanio() - 1];
    datos.pop_back();
    downheap(index_a_borrar);
    return raiz;
}

template<typename T, bool comp(T, T)>
T Heap<T, comp>::primero(){
    if(vacio()){
        throw Heap_exception();
    }
    return datos[0];
}

template<typename T, bool comp(T, T)>
bool Heap<T, comp>::vacio(){
    return datos.empty();
}

template<typename T, bool comp(T, T)>
size_t Heap<T, comp>::tamanio(){
    return datos.size();
}

template<typename T, bool comp(T, T)>
Heap<T, comp>::~Heap(){
}

#endif