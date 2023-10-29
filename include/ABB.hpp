#ifndef ABB_H
#define ABB_H

#include <exception>
#include "NodoABB.hpp"

class ABB_exception : public std::exception {
};

template<typename T, bool menor(T, T), bool igual(T, T)>
class ABB {
private:
    NodoABB<T, menor, igual>* raiz;
    std::size_t cantidad_datos;
public:
    // Constructor.
    ABB();

    // Pre: El dato a ingresar no puede estar en el árbol.
    // Post: Agrega el dato al árbol. Si no hay datos, crea una nueva raiz.
    void alta(T dato);

    // Pre: -
    // Post: Elimina el dato del árbol. Si no existe, no hace nada.
    // NOTA: Si la raiz cambia (sin importar el caso), se debe reasignar correctamente.
    void baja(T dato);

    // Pre: -
    // Post: Devuelve true si el dato está en el árbol. Si no hay datos, devuelve false.
    bool consulta(T dato);

    // Pre: -
    // Post: Devuelve el recorrido inorder.
    std::vector<T> inorder();

    // Pre: -
    // Post: Devuelve el recorrido preorder.
    std::vector<T> preorder();

    // Pre: -
    // Post: Devuelve el recorrido postorder.
    std::vector<T> postorder();

    // Pre: -
    // Post: Devuelve el recorrido en ancho.
    std::vector<T> ancho();

    // Pre: -
    // Post: Ejecuta el método/función en cada uno de los nodos.
    // NOTA: No abusar de este método, está solamente para simplificar
    // algunas cosas, como liberar la memoria de los nodos de usar punteros
    // o imprimir por pantalla el contenido. Pueden usar cualquier recorrido.
    void ejecutar(void metodo(T));

    // Pre: -
    // Post: Devuelve la cantidad de datos en el árbol.
    std::size_t tamanio();

    // Pre: -
    // Post: Devuelve true si el árbol está vacio.
    bool vacio();

    // El constructor de copia está deshabilitado.
    ABB(const ABB& abb) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const ABB& abb) = delete;

    // Destructor.
    ~ABB();
};

#endif


template<typename T, bool menor(T, T), bool igual(T, T)>
ABB<T, menor, igual>::ABB() {
    raiz = nullptr;
    cantidad_datos = 0;
}

//template<typename T, bool menor(T, T), bool igual(T, T)>
//void ABB<T, menor, igual>::alta(T dato) {
//    if (raiz == nullptr) {
//        raiz = new NodoABB<T, menor, igual>(dato);
//    } else {
//        raiz->alta(dato);
//    }
//    cantidad_datos++;
//}

template<typename T, bool menor(T, T), bool igual(T, T)>
void ABB<T, menor, igual>::alta(T dato) {
    if (!consulta(dato)) {
        if (raiz == nullptr) {
            raiz = new NodoABB<T, menor, igual>(dato);
        } else {
            raiz->alta(dato);
        }
        cantidad_datos++;
    } else{
        throw ABB_exception();
    }
}


template<typename T, bool menor(T, T), bool igual(T, T)>
bool ABB<T, menor, igual>::consulta(T dato) {
    if (raiz != nullptr) {
        return raiz->consulta(dato);
    }
    return false;
}

template<typename T, bool menor(T, T), bool igual(T, T)>
std::vector<T> ABB<T, menor, igual>::inorder() {
    std::vector<T> datos;
    if (raiz != nullptr) {
        raiz->inorder(datos);
    }
    return datos;
}

template<typename T, bool menor(T, T), bool igual(T, T)>
std::vector<T> ABB<T, menor, igual>::preorder() {
    std::vector<T> datos;
    if (raiz != nullptr) {
        raiz->preorder(datos);
    }
    return datos;
}

template<typename T, bool menor(T, T), bool igual(T, T)>
std::vector<T> ABB<T, menor, igual>::postorder() {
    std::vector<T> datos;
    if (raiz != nullptr) {
        raiz->postorder(datos);
    }
    return datos;
}

template<typename T, bool menor(T, T), bool igual(T, T)>
std::vector<T> ABB<T, menor, igual>::ancho() {
    std::vector<T> datos;
   if (raiz != nullptr) {
       std::queue<NodoABB<T, menor, igual>*> nodos;
       nodos.push(raiz);
       //datos.push_back(raiz); esto esta mal, porque termino guardando memoria, tengo que de alguna maner  guardar la raiz
        //datos.push_back(raiz->dato); lo ideal seria guardarlo asi y estaria todo bien peeero, dato es un atributo privado
        raiz->ancho(nodos, datos);
    }
    return datos;
}
/*
template<typename T, bool menor(T, T), bool igual(T, T)>
std::vector<T> ABB<T, menor, igual>::ancho() {
   std::vector<T> datos;
   if (raiz == nullptr) {
       return datos; // El árbol está vacío, retorna un vector vacío.
   }

    std::queue<NodoABB<T, menor, igual>*> nodos;
  nodos.push(raiz);
}*/
//
//    while (!nodos.empty()) {
//        NodoABB<T, menor, igual>* nodo_actual = nodos.front();
//        nodos.pop();
//        datos.push_back(nodo_actual->dato);
//
//        if (nodo_actual->hijo_izquierdo != nullptr) {
//            nodos.push(nodo_actual->hijo_izquierdo);
//        }
//        if (nodo_actual->hijo_derecho != nullptr) {
//            nodos.push(nodo_actual->hijo_derecho);
//        }
//    }
//
//    return datos;
//}
/*
template<typename T, bool menor(T, T), bool igual(T, T)>
std::vector<T> ABB<T, menor, igual>::ancho() {
    std::vector<T> datos;
    if (raiz == nullptr) {
        return datos; // El árbol está vacío, retorna un vector vacío.
    }

    std::queue<NodoABB<T, menor, igual>*> nodos;
    nodos.push(raiz);

    while (!nodos.empty()) {
        NodoABB<T, menor, igual>* nodo_actual = nodos.front();
        nodos.pop();
        nodo_actual->ancho(nodos, datos);  

        
    }

    return datos;
}
*/
template<typename T, bool menor(T, T), bool igual(T, T)>
void ABB<T, menor, igual>::ejecutar(void metodo(T)) {
    if (raiz != nullptr) {
        raiz->ejecutar(metodo);
    }
}

template<typename T, bool menor(T, T), bool igual(T, T)>
std::size_t ABB<T, menor, igual>::tamanio() {
    return cantidad_datos;
}

template<typename T, bool menor(T, T), bool igual(T, T)>
bool ABB<T, menor, igual>::vacio() {
    return cantidad_datos == 0;
}

template<typename T, bool menor(T, T), bool igual(T, T)>
ABB<T, menor, igual>::~ABB() {
    delete raiz;
}
