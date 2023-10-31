#ifndef NODOABB_H
#define NODOABB_H

#include <vector>
#include <queue>

template <typename T, bool menor(T, T), bool igual(T, T)>
class NodoABB
{

private:
    T dato{};
    NodoABB<T, menor, igual> *padre;
    NodoABB<T, menor, igual> *hijo_izquierdo;
    NodoABB<T, menor, igual> *hijo_derecho;

    // PRE: -
    // POST: Reordena los punteros
    void reemplazar_nodos(NodoABB *nodo, T dato_bajar);



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
    NodoABB<T, menor, igual> *baja(T dato_bajar);

    // Pre: -
    // Post: Devuelve true si el dato está en el subárbol.
    bool consulta(T dato_consultar);

    // Pre: -
    // Post: Carga los datos, respetando el recorrido inorder.
    void inorder(std::vector<T> &datos);

    // Pre: -
    // Post: Carga los datos, respetando el recorrido preorder.
    void preorder(std::vector<T> &datos);

    // Pre: -
    // Post: Carga los datos, respetando el recorrido postorder.
    void postorder(std::vector<T> &datos);

    // Pre: -
    // Post: Carga los datos, respetando el recorrido en ancho.
    void ancho(std::queue<NodoABB<T, menor, igual> *> &nodos, std::vector<T> &datos);

    // Pre: -
    // Post: Ejecuta el método/función en el subárbol.
    void ejecutar(void metodo(T));

    // Destructor.
    ~NodoABB();
};

template <typename T, bool menor(T, T), bool igual(T, T)>
NodoABB<T, menor, igual>::NodoABB(T dato)
{
    this->dato = dato;
    padre = nullptr;
    hijo_izquierdo = nullptr;
    hijo_derecho = nullptr;
}

template <typename T, bool menor(T, T), bool igual(T, T)>
void NodoABB<T, menor, igual>::alta(T dato_insertar)
{
    if (menor(dato_insertar, dato))
    {
        if (hijo_izquierdo == nullptr)
        {
            hijo_izquierdo = new NodoABB(dato_insertar);
            hijo_izquierdo->padre = this;
        }
        else
        {
            hijo_izquierdo->alta(dato_insertar);
        }
    }
    else if (menor(dato, dato_insertar))
    {
        if (hijo_derecho == nullptr)
        {
            hijo_derecho = new NodoABB(dato_insertar);
            hijo_derecho->padre = this;
        }
        else
        {
            hijo_derecho->alta(dato_insertar);
        }
    }
}

template <typename T, bool menor(T, T), bool igual(T, T)>
void NodoABB<T, menor, igual>::reemplazar_nodos(NodoABB *nodo, T dato_bajar)
{
    if (padre->hijo_derecho->dato == dato_bajar) // somos el hijo derecho de nuestro padre
    {
        padre->hijo_derecho = nodo; // nuestro padre tiene un nuevoi hijo
    }
    else // somos el hijo izquierdo
    {
        padre->hijo_izquierdo = nodo; // nuestro padre tiene un nuevo hijo
    }
    if (nodo != nullptr)
    {
        nodo->padre = padre; // el nuevo hijo tiene un nuevo padre
    }
}

template <typename T, bool menor(T, T), bool igual(T, T)>
NodoABB<T, menor, igual> *NodoABB<T, menor, igual>::baja(T dato_bajar)
{
    if (igual(dato_bajar, dato))
    {
        if (hijo_izquierdo != nullptr && hijo_derecho != nullptr) // tenemos 2 hijos
        {
            NodoABB<T, menor, igual> *nodo_mas_izquierdo = hijo_derecho;
            while (nodo_mas_izquierdo->hijo_izquierdo != nullptr)
            {
                nodo_mas_izquierdo = nodo_mas_izquierdo->hijo_izquierdo;
            }
            dato = nodo_mas_izquierdo->dato;
            nodo_mas_izquierdo->baja(nodo_mas_izquierdo->dato);
        }
        else if (hijo_izquierdo == nullptr && hijo_derecho != nullptr) // tenemos solo hijo derecho
        {
            reemplazar_nodos(hijo_derecho, dato_bajar);
            return hijo_derecho;
        }
        else if (hijo_derecho == nullptr && hijo_izquierdo != nullptr) // tenemos solo hijo izquierdo
        {
            reemplazar_nodos(hijo_izquierdo, dato_bajar);
            return hijo_izquierdo;
        }
        else // hoja
        {
            reemplazar_nodos(nullptr, dato_bajar);
            return nullptr;
        }
    }
    else if (menor(dato_bajar, dato) && hijo_izquierdo != nullptr)
    {
        hijo_izquierdo = hijo_izquierdo->baja(dato_bajar);
    }
    else if (hijo_derecho != nullptr)
    {
        hijo_derecho = hijo_derecho->baja(dato_bajar);
    }
    return this;
}


template <typename T, bool menor(T, T), bool igual(T, T)>
bool NodoABB<T, menor, igual>::consulta(T dato_consultar)
{
    if (igual(dato_consultar, dato))
    {
        return true; // Dato encontrado en este nodo.
    }
    else if (menor(dato_consultar, dato) && hijo_izquierdo != nullptr)
    {
        return hijo_izquierdo->consulta(dato_consultar);
    }
    else if (hijo_derecho != nullptr)
    {
        return hijo_derecho->consulta(dato_consultar);
    }
    return false; // Dato no encontrado en el subárbol.
}

template <typename T, bool menor(T, T), bool igual(T, T)>
void NodoABB<T, menor, igual>::inorder(std::vector<T> &datos)
{
    if (hijo_izquierdo != nullptr)
    {
        hijo_izquierdo->inorder(datos);
    }
    datos.push_back(dato);
    if (hijo_derecho != nullptr)
    {
        hijo_derecho->inorder(datos);
    }
}

template <typename T, bool menor(T, T), bool igual(T, T)>
void NodoABB<T, menor, igual>::preorder(std::vector<T> &datos)
{
    datos.push_back(dato);
    if (hijo_izquierdo != nullptr)
    {
        hijo_izquierdo->preorder(datos);
    }
    if (hijo_derecho != nullptr)
    {
        hijo_derecho->preorder(datos);
    }
}

template <typename T, bool menor(T, T), bool igual(T, T)>
void NodoABB<T, menor, igual>::postorder(std::vector<T> &datos)
{
    if (hijo_izquierdo != nullptr)
    {
        hijo_izquierdo->postorder(datos);
    }
    if (hijo_derecho != nullptr)
    {
        hijo_derecho->postorder(datos);
    }
    datos.push_back(dato);
}

template <typename T, bool menor(T, T), bool igual(T, T)>
void NodoABB<T, menor, igual>::ancho(std::queue<NodoABB<T, menor, igual> *> &nodos, std::vector<T> &datos)
{
    if (nodos.empty())
    {
        return;
    }
    NodoABB<T, menor, igual> *nodo_actual = nodos.front();
    nodos.pop();
    datos.push_back(nodo_actual->dato);
    if (nodo_actual->hijo_izquierdo != nullptr)
    {
        nodos.push(nodo_actual->hijo_izquierdo);
    }
    if (nodo_actual->hijo_derecho != nullptr)
    {
        nodos.push(nodo_actual->hijo_derecho);
    }
    ancho(nodos, datos);
}

template <typename T, bool menor(T, T), bool igual(T, T)>
void NodoABB<T, menor, igual>::ejecutar(void metodo(T))
{
    metodo(dato);
    if (hijo_izquierdo != nullptr)
    {
        hijo_izquierdo->ejecutar(metodo);
    }
    if (hijo_derecho != nullptr)
    {
        hijo_derecho->ejecutar(metodo);
    }
}

template <typename T, bool menor(T, T), bool igual(T, T)>
NodoABB<T, menor, igual>::~NodoABB()
{
    delete hijo_izquierdo;
    delete hijo_derecho;
    // No es necesario eliminar el padre, ya que no es el propietario del padre.
}

#endif