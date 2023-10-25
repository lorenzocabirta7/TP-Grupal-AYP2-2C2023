#include "gmock/gmock.h"
#include "ABB.hpp"

bool menor(int a, int b) {
    return a < b;
}

bool igual(int a, int b) {
    return a == b;
}

class ABB_tests : public ::testing::Test {
protected:
    ABB<int, menor, igual> arbol{};
    std::vector<int> datos;

    static void cargar(ABB<int, menor, igual>& a) {
        a.alta(10);
        a.alta(7);
        a.alta(3);
        a.alta(13);
        a.alta(16);
        a.alta(11);
    }
};

// Se usa inorder de forma arbitraria para rescatar todos los elementos.
TEST_F(ABB_tests, alta) {
    cargar(arbol);
    arbol.alta(8);

    datos = arbol.inorder();
    ASSERT_THAT(datos, testing::ElementsAre(3, 7, 8, 10, 11, 13, 16));
    ASSERT_EQ(datos.size(), 7);
}

TEST_F(ABB_tests, alta_maneja_dato_repetido) {
    cargar(arbol);
    EXPECT_THROW(arbol.alta(10), ABB_exception);
}

TEST_F(ABB_tests, consulta) {
    cargar(arbol);
    EXPECT_TRUE(arbol.consulta(10));
    EXPECT_FALSE(arbol.consulta(8));
}

TEST_F(ABB_tests, inorder) {
    cargar(arbol);
    datos = arbol.inorder();
    ASSERT_THAT(datos, testing::ElementsAre(3, 7, 10, 11, 13, 16));
}

TEST_F(ABB_tests, preorder) {
    cargar(arbol);
    datos = arbol.preorder();
    ASSERT_THAT(datos, testing::ElementsAre(10, 7, 3, 13, 11, 16));
}

TEST_F(ABB_tests, postorder) {
    cargar(arbol);
    datos = arbol.postorder();
    ASSERT_THAT(datos, testing::ElementsAre(3, 7, 11, 16, 13, 10));
}

TEST_F(ABB_tests, ancho) {
    cargar(arbol);
    datos = arbol.ancho();
    ASSERT_THAT(datos, testing::ElementsAre(10, 7, 13, 3, 11, 16));
}

TEST_F(ABB_tests, tamanio) {
    cargar(arbol);
    ASSERT_EQ(arbol.tamanio(), 6);
}

TEST_F(ABB_tests, vacio) {
    ASSERT_TRUE(arbol.vacio());
    cargar(arbol);
    ASSERT_FALSE(arbol.vacio());
}

// Descomentar este test si el equipo implementa baja fisica. Usar sucesor.
/*
TEST_F(ABB_tests, baja) {
    cargar(arbol);
    arbol.baja(10);
    ASSERT_THAT(arbol.inorder(), testing::ElementsAre(3, 7, 11, 13, 16));
    ASSERT_THAT(arbol.preorder(), testing::ElementsAre(11, 7, 3, 13, 16));
    ASSERT_THAT(arbol.postorder(), testing::ElementsAre(3, 7, 16, 13, 11));
    ASSERT_THAT(arbol.ancho(), testing::ElementsAre(11, 7, 13, 3, 16));
    ASSERT_EQ(arbol.tamanio(), 5);

    arbol.baja(13);
    ASSERT_THAT(arbol.inorder(), testing::ElementsAre(3, 7, 11, 16));
    ASSERT_THAT(arbol.preorder(), testing::ElementsAre(11, 7, 3, 16));
    ASSERT_THAT(arbol.postorder(), testing::ElementsAre(3, 7, 16, 11));
    ASSERT_THAT(arbol.ancho(), testing::ElementsAre(11, 7, 16, 3));
    ASSERT_EQ(arbol.tamanio(), 4);

    arbol.baja(16);
    ASSERT_THAT(arbol.inorder(), testing::ElementsAre(3, 7, 11));
    ASSERT_THAT(arbol.preorder(), testing::ElementsAre(11, 7, 3));
    ASSERT_THAT(arbol.postorder(), testing::ElementsAre(3, 7, 11));
    ASSERT_THAT(arbol.ancho(), testing::ElementsAre(11, 7, 3));
    ASSERT_EQ(arbol.tamanio(), 3);

    arbol.baja(1);
    ASSERT_THAT(arbol.inorder(), testing::ElementsAre(3, 7, 11));
    ASSERT_THAT(arbol.preorder(), testing::ElementsAre(11, 7, 3));
    ASSERT_THAT(arbol.postorder(), testing::ElementsAre(3, 7, 11));
    ASSERT_THAT(arbol.ancho(), testing::ElementsAre(11, 7, 3));
    ASSERT_EQ(arbol.tamanio(), 3);
}
*/