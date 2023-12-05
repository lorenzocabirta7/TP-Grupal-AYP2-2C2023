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
//    Interfaz interfaz;
//    Personaje Personaje(&inventario);

    Menu menu;
    menu.flujo_juego();

    // ** ver probabilidad del 20% del arma
    // ** ver probabilidad del 50% de Pyramid Head cada uno
    // ** ver grafo

//    Grafo grafo1(54);
//    Grafo grafo2(56);
//
//    vector<vector<size_t>> vertices1 = {{0,1,8},{1,0,2,9},{2,1,10},{3,4,11},{4,3,5},{5,4,6,12},{6,5,7},{7,6,13},{8,9,14,0},{9,8,10,1},{10,9,2,15},{11,3,16},{12,5,17},{13,7,18},{14,8,19},{15,10,20},{16,11,22},{17,12,23},{18,13,24},{19,14,25},{20,15,26,21},{21,20,22},{22,21,16,27},{23,17,29},{24,18,30},{25,19,31},{26,20,33},{27,22,34,28},{28,27,29},{29,28,23,35},{30,24,36},{31,32,25,37},{32,31,33},{33,26,32,38},{34,27,39},{35,29,40},{36,30,42},{37,31,43},{38,33,44},{39,34,46},{40,35,47,41},{41,40,42},{42,41,36,48},{43,37,49},{44,50,38,45},{45,44,46},{46,45,39,51},{47,40,52},{48,42,53},{49,43},{50,44},{51,46},{52,47},{53,48}};
//    vector<vector<size_t>> vertices2 = {{0,1,8},{1,2,0},{2,1,9},{3,10,4},{4,3,5},{5,4,6},{6,5,7},{7,6},{8,0,12},{9,2,14},{10,3,16},{11,5,17},{12,8,20},{13,12,14},{14,13,15},{15,14,16},{16,15,10,21},{17,11,22,18},{18,17,19},{19,18,23},{20,12,24},{21,16,28},{22,17,30},{23,19,31},{24,20,25},{25,24,26},{26,25,27},{27,26,28},{28,27,29},{29,28,30},{30,29,22,33},{31,23,35},{32,26,38},{33,30,42},{34,33,35},{35,34,31,43},{36,37,44},{37,36,38},{38,37,39},{39,38,40},{40,39,41},{41,40,42},{42,41,33,45},{43,35,46},{44,36,47},{45,42,53},{46,43,55},{47,44,48},{48,47,49},{49,48,50},{50,49,51},{51,50,52},{52,51,53},{53,52,54,45},{54,53,55},{55,54,46}};
//
//    for (vector<size_t> vertice1: vertices1) {
//        for (size_t i = 1; i < vertice1.size(); ++i) {
//            grafo1.cambiar_arista(vertice1[0], vertice1[i], 10);
//        }
//    }
//
//    for (vector<size_t> vertice2: vertices2) {
//        for (size_t i = 1; i < vertice2.size(); ++i) {
//            grafo2.cambiar_arista(vertice2[0], vertice2[i], 10);
//        }
//    }


    return 0;
}
