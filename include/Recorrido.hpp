#ifndef RECORRIDO_H
#define RECORRIDO_H
#include <vector>
#include "Grafo.hpp"

const std::vector<std::vector<size_t>> VERTICES_LAYOUT1 = {{0,1,8},{1,0,2,9},{2,1,10},{3,4,11},{4,3,5},{5,4,6,12},{6,5,7},{7,6,13},{8,9,14,0},{9,8,10,1},{10,9,2,15},{11,3,16},{12,5,17},{13,7,18},{14,8,19},{15,10,20},{16,11,22},{17,12,23},{18,13,24},{19,14,25},{20,15,26,21},{21,20,22},{22,21,16,27},{23,17,29},{24,18,30},{25,19,31},{26,20,33},{27,22,34,28},{28,27,29},{29,28,23,35},{30,24,36},{31,32,25,37},{32,31,33},{33,26,32,38},{34,27,39},{35,29,40},{36,30,42},{37,31,43},{38,33,44},{39,34,46},{40,35,47,41},{41,40,42},{42,41,36,48},{43,37,49},{44,50,38,45},{45,44,46},{46,45,39,51},{47,40,52},{48,42,53},{49,43},{50,44},{51,46},{52,47},{53,48}};
const std::vector<std::vector<size_t>> VERTICES_LAYOUT2 = {{0,1,8},{1,2,0},{2,1,9},{3,10,4},{4,3,5},{5,4,6},{6,5,7},{7,6},{8,0,12},{9,2,14},{10,3,16},{11,5,17},{12,8,20},{13,12,14},{14,13,15},{15,14,16},{16,15,10,21},{17,11,22,18},{18,17,19},{19,18,23},{20,12,24},{21,16,28},{22,17,30},{23,19,31},{24,20,25},{25,24,26},{26,25,27},{27,26,28},{28,27,29},{29,28,30},{30,29,22,33},{31,23,35},{32,26,38},{33,30,42},{34,33,35},{35,34,31,43},{36,37,44},{37,36,38},{38,37,39},{39,38,40},{40,39,41},{41,40,42},{42,41,33,45},{43,35,46},{44,36,47},{45,42,53},{46,43,55},{47,44,48},{48,47,49},{49,48,50},{50,49,51},{51,50,52},{52,51,53},{53,52,54,45},{54,53,55},{55,54,46}};

const std::vector<std::vector<size_t>> COORDENADAS_LAYOUT1 = {{8,0},{8,1},{8,2},{8,4},{8,5},{8,6},{8,7},{8,8},{7,0},{7,1},{7,2},{7,4},{7,6},{7,7},{6,0},{6,2},{6,4},{6,6},{6,8},{5,0},{5,2},{5,3},{5,4},{5,6},{5,8},{4,0},{4,2},{4,4},{4,5},{4,6},{4,8},{3,0},{3,1},{3,2},{3,4},{3,6},{3,8},{2,0},{2,2},{2,4},{2,6},{2,7},{2,8},{1,0},{1,2},{1,3},{1,4},{1,6},{1,8},{0,0},{0,2},{0,4},{0,6},{0,8}};
const std::vector<std::vector<size_t>> COORDENADAS_LAYOUT2 = {{8,0},{8,1},{8,2},{8,4},{8,5},{8,6},{8,7},{8,8},{7,0},{7,2},{7,4},{7,5},{6,0},{6,1},{6,2},{6,3},{6,4},{6,6},{6,7},{6,8},{5,0},{5,4},{5,6},{5,8},{4,0},{4,1},{4,2},{4,3},{4,4},{4,5},{4,6},{4,8},{3,2},{3,6},{3,7},{3,8},{2,0},{2,1},{2,2},{2,3},{2,4},{2,5},{2,6},{2,8},{1,0},{1,6},{1,8},{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8}};

const int PESO_ARISTA = 10;
const int PESO_ARISTA_PYRAMID = 50;

class Recorrido {
private:
    Grafo grafo_layout1;
    Grafo grafo_layout2;
    std::vector<size_t> posicion_james2;
    std::vector<size_t> posicion_pyramid1;
    std::vector<size_t> posicion_pyramid2;
    bool aristas_cargadas;
    std::vector<std::vector<size_t>> layout_actual;
    int numero_layout;


    //pre: -
    //post: agrega las aristas al grafo del layout 1
    void agregar_artistas_layout1();

    //pre: -
    //post: agrega las aristas al grafo del layout 2
    void agregar_artistas_layout2();

    //pre: -
    //post: retorna el numero de vertice donde se encuentra james basado en su posicion
    size_t encontrar_vertice_james();

    //pre: -
    //post: carga las aristas de los grafos
    void cargar_aristas();

    //pre: -
    //post: descifra si el layout actual es el 1 o el 2
    void descifrar_tipo_layout(size_t altura_arbol);

    //pre: -
    //post: asigna el grafo correspondiente dependiendo el tipo de layout
    Grafo asignar_grafo_correspondiente();

    //pre: -
    //post: modifica las coordenadas de James y los pyramidhead
    void modificar_posicion_personajes(std::vector<size_t> &posicion_actual_james, std::vector<std::vector<size_t>> posiciones_pyramidheads);

    //pre: -
    //post: Encuentra el numero de vertice donde esta situado un pyramidhead
    size_t encontrar_vertice_pyramid(int numero_pyramid);

    //pre: -
    //post: actualiza las aristas de los pyramidhead
    void modificar_aristas_pyramidheads(Grafo &grafo_a_utilizar);

    //pre: -
    //post: Modifica el peso de las aristas de los vertices adyacentes a los que se encuentra un pyramdidhead
    void actualizar_valor_arista_pyramidhead(Grafo &grafo_a_utilizar, size_t vertice_pyramid);

public:
    //Constructor
    Recorrido();

    //pre: -
    //post: Actualiza la posicion de james
    void acutalizar_posicion_james(std::vector<size_t> posicion);

    //pre: -
    //post: Encuentra el camino minimo del grafo
    std::vector<std::vector<size_t>> encontrar_camino_minimo(std::vector<size_t> posicion_actual_james, std::vector<std::vector<size_t>> posiciones_pyramidheads, size_t altura_arbol);

};


#endif
