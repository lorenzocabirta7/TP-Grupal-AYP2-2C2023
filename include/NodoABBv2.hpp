#ifndef NODOABB_H
#define NODOABB_H

#include <vector>
#include <queue>

template<typename T, bool menor(T, T), bool igual(T, T)>
class ABB;

template<typename T, bool menor(T, T), bool igual(T, T)>
class NodoABB {
private:
    T dato{};
    NodoABB<T, menor, igual>* padre;
    NodoABB<T, menor, igual>* hijo_izquierdo;
    NodoABB<T, menor, igual>* hijo_derecho;

    /* friend class, en resumen, permite el libre acceso de los atributos
     * del nodo desde el árbol. Simplifica getters y setters. */
    friend class ABB<T, menor, igual>;
};

#endif