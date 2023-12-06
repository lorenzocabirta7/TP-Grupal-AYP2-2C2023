/*
#include "ABB.hpp"
#include "Placa.hpp"
#include "bGVjdG9y.hpp"
#include <fstream>
*/
#include "include/Inventario.hpp"
//#include <iostream>
//#include "Interfaz.hpp"
#include "Menu.hpp"
//#include "Personaje.hpp"

#include <vector>
#include "Grafo.hpp"

using namespace std;

int main()
{
    Inventario inventario;
    srand((unsigned)time(NULL));
    Menu menu;
    menu.flujo_juego();
    return 0;
}
