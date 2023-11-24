/*
#include "ABB.hpp"
#include "Placa.hpp"
#include "bGVjdG9y.hpp"
#include <fstream>
*/
#include "include/Inventario.hpp"
#include <iostream>
#include "Interfaz.hpp"
using namespace std;
#include "Menu.hpp"
int main()
{
    /*
    ABB<Placa *, Placa::menor, Placa::igual> arbol;
    bGVjdG9y::Y2FyZ2Fy(arbol);
    ofstream archivo("mensaje_oculto.txt");

    vector<Placa *> recorrido = arbol.preorder();

    for (size_t i = 0; i < arbol.tamanio(); i++)
    {
        archivo << recorrido[i] << endl;
    }

    archivo.close();
    */

    Inventario inventario;
    // inventario.alta(new Arma("Espada", 10));
    // inventario.alta(new Arma("Hacha", 20));
    // inventario.alta(new Arma("Arco", 30));
    // inventario.alta(new Arma("Ballesta", 40));
    // Arma* arma = inventario.baja();
    // cout << *arma << endl;
    // inventario.consulta();
    srand((unsigned)time(NULL));
    Interfaz interfaz;
    Personaje Personaje(&inventario);

    // ** ver probabilidad del 20% del arma
    // ** ver probabilidad del 50% de Pyramid Head cada uno
    // ** ver grafo

    return 0;
}
