#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Heap.hpp"
#include "Arma.hpp"

class Inventario
{
private:
    Heap<Arma , Arma::mayor> armas;

public:
    Inventario();

    // Pre: -
    // Post: Agrega el arma al inventario.
    void alta(Arma arma);

    // Pre: El inventario no puede estar vacio
    // Post: Elimina el arma del inventario.
    Arma baja();

    // Pre: -
    // Post: Muestra el arma mas poderosa
    void consulta();

    bool vacio();


};

#endif // INVENTARIO_H