#include "Inventario.hpp"
#include <iostream>

Inventario::Inventario()
{
}
void Inventario::alta(Arma arma)
{
    armas.alta(arma);
}

Arma Inventario::baja()
{
    return armas.baja();
}

void Inventario::consulta()
{
    std::cout << armas.primero() << std::endl;
}

bool Inventario::vacio()
{
    return armas.vacio();
}


