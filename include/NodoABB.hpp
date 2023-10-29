#ifndef NODOABB_H
#define NODOABB_H

#include <vector>
#include <queue>

template<typename T, bool menor(T, T), bool igual(T, T)>
class NodoABB {

private:
    T dato{};
    NodoABB<T, menor, igual>* padre;
    NodoABB<T, menor, igual>* hijo_izquierdo;
    NodoABB<T, menor, igual>* hijo_derecho;
public:
    // Constructor.
    NodoABB(T dato);

    // Pre: -
    // Post: Agrega el dato al árbol.
    // NOTA: Ya se debería haber revisado si el dato está o no.
    void alta(T dato_insertar);

    // Pre: -
    // Post: Elimina el dato del árbol y devuelve la nueva raiz, de haberla.
    // NOTA: Ya se debería haber revisado si el dato está o no.
    NodoABB<T, menor, igual>* baja(T dato_bajar);

    // Pre: -
    // Post: Devuelve true si el dato está en el subárbol.
    bool consulta(T dato_consultar);

    // Pre: -
    // Post: Carga los datos, respetando el recorrido inorder.
    void inorder(std::vector<T>& datos);

    // Pre: -
    // Post: Carga los datos, respetando el recorrido preorder.
    void preorder(std::vector<T>& datos);

    // Pre: -
    // Post: Carga los datos, respetando el recorrido postorder.
    void postorder(std::vector<T>& datos);

    // Pre: -
    // Post: Carga los datos, respetando el recorrido en ancho.
    void ancho(std::queue<NodoABB<T, menor, igual>*>& nodos, std::vector<T>& datos);

    // Pre: -
    // Post: Ejecuta el método/función en el subárbol.
    void ejecutar(void metodo(T));

    // Destructor.
    ~NodoABB();
};

#endif

template<typename T, bool menor(T, T), bool igual(T, T)>
NodoABB<T, menor, igual>::NodoABB(T dato) {
    this -> dato = dato;
    padre = nullptr;
    hijo_izquierdo = nullptr;
    hijo_derecho = nullptr;
}


template<typename T, bool menor(T, T), bool igual(T, T)>
void NodoABB<T, menor, igual>::alta(T dato_insertar) {
    if (menor(dato_insertar, dato)) {
        if (hijo_izquierdo == nullptr) {
            hijo_izquierdo = new NodoABB(dato_insertar);
            hijo_izquierdo->padre = this;
        } else {
            hijo_izquierdo->alta(dato_insertar);
        }
    } else if (menor(dato, dato_insertar)) {
        if (hijo_derecho == nullptr) {
            hijo_derecho = new NodoABB(dato_insertar);
            hijo_derecho->padre = this;
        } else {
            hijo_derecho->alta(dato_insertar);
        }
    }
}

template<typename T, bool menor(T, T), bool igual(T, T)>
bool NodoABB<T, menor, igual>::consulta(T dato_consultar) {
    if (igual(dato_consultar, dato)) {
        return true; // Dato encontrado en este nodo.
    } else if (menor(dato_consultar, dato) && hijo_izquierdo != nullptr) {
        return hijo_izquierdo->consulta(dato_consultar);
    } else if (hijo_derecho != nullptr) {
        return hijo_derecho->consulta(dato_consultar);
    }
    return false; // Dato no encontrado en el subárbol.
}

template<typename T, bool menor(T, T), bool igual(T, T)>
void NodoABB<T, menor, igual>::inorder(std::vector<T>& datos) {
    if (hijo_izquierdo != nullptr) {
        hijo_izquierdo->inorder(datos);
    }
    datos.push_back(dato);
    if (hijo_derecho != nullptr) {
        hijo_derecho->inorder(datos);
    }
}

template<typename T, bool menor(T, T), bool igual(T, T)>
void NodoABB<T, menor, igual>::preorder(std::vector<T>& datos) {
    datos.push_back(dato);
    if (hijo_izquierdo != nullptr) {
        hijo_izquierdo->preorder(datos);
    }
    if (hijo_derecho != nullptr) {
        hijo_derecho->preorder(datos);
    }
}

template<typename T, bool menor(T, T), bool igual(T, T)>
void NodoABB<T, menor, igual>::postorder(std::vector<T>& datos) {
    if (hijo_izquierdo != nullptr) {
        hijo_izquierdo->postorder(datos);
    }
    if (hijo_derecho != nullptr) {
        hijo_derecho->postorder(datos);
    }
    datos.push_back(dato);
}

template<typename T, bool menor(T, T), bool igual(T, T)>
void NodoABB<T, menor, igual>::ancho(std::queue<NodoABB<T, menor, igual>*>& nodos, std::vector<T>& datos) {
    if (nodos.empty()) {
         //datos.insert(datos.begin(),nodos.front()->dato); esto esta re mal xq lo estoy haciendo cuando nodos 
        return;
    }
    NodoABB<T, menor, igual>* nodo_actual = nodos.front();
    nodos.pop();
    datos.push_back(nodo_actual->dato);// eso hace que se añada dos veces los hijos
    if (nodo_actual->hijo_izquierdo != nullptr) {
        nodos.push(nodo_actual->hijo_izquierdo);
        //nodos.pop();
        //datos.push_back(nodo_actual->hijo_izquierdo->dato);
    }
    if (nodo_actual->hijo_derecho != nullptr) {
        nodos.push(nodo_actual->hijo_derecho);
        //nodos.pop(); con esos nodos.pop() obtenemos esto Actual: { 10, 7, 13 }, which has 3 elements
        //datos.push_back(nodo_actual->hijo_derecho->dato);
    }
    //ahi guarde tres elementos, la 
    ancho(nodos,datos); // asi como esta ahora tengo Actual: { 7, 13, 3, 11, 16 }, which has 5 elements falta la raiz, pero s
}

template<typename T, bool menor(T, T), bool igual(T, T)>
void NodoABB<T, menor, igual>::ejecutar(void metodo(T)) {
    metodo(dato);
    if (hijo_izquierdo != nullptr) {
        hijo_izquierdo->ejecutar(metodo);
    }
    if (hijo_derecho != nullptr) {
        hijo_derecho->ejecutar(metodo);
    }
}

template<typename T, bool menor(T, T), bool igual(T, T)>
NodoABB<T, menor, igual>::~NodoABB() {
    delete hijo_izquierdo;
    delete hijo_derecho;
    // No es necesario eliminar el padre, ya que no es el propietario del padre.
}