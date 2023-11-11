#include "gmock/gmock.h"
#include "Grafo.hpp"

class Grafo_tests : public ::testing::Test {
protected:
    Grafo grafo;
    std::pair<std::vector<size_t>, int> resultado;

    void generar_grafo() {
        grafo = Grafo(7);
        grafo.cambiar_arista(0, 1, 9);
        grafo.cambiar_arista(0, 3, 7);
        grafo.cambiar_arista(0, 2, 10);
        grafo.cambiar_arista(1, 2, 8);
        grafo.cambiar_arista(1, 5, 15);
        grafo.cambiar_arista(2, 3, 9);
        grafo.cambiar_arista(2, 5, 7);
        grafo.cambiar_arista(3, 6, 25);
        grafo.cambiar_arista(3, 5, 20);
        grafo.cambiar_arista(5, 6, 12);
        grafo.cambiar_arista(5, 4, 2);
        grafo.cambiar_arista(2, 4, 12);
        grafo.cambiar_arista(4, 6, 13);
    }
};

TEST_F(Grafo_tests, camino_minimo) {
    generar_grafo();
    grafo.usar_floyd();
    resultado = grafo.obtener_camino_minimo(0, 6);
    ASSERT_THAT(resultado.first, testing::ElementsAre(0, 2, 5, 6));
    ASSERT_EQ(resultado.second, 29);

    grafo.usar_dijkstra();
    resultado = grafo.obtener_camino_minimo(0, 6);
    ASSERT_THAT(resultado.first, testing::ElementsAre(0, 2, 5, 6));
    ASSERT_EQ(resultado.second, 29);
}