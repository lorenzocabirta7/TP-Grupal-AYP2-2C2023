#include "gmock/gmock.h"
#include "Heap.hpp"

bool mayor(int a, int b) {
    return a > b;
}

class Heap_tests : public ::testing::Test {
protected:
    Heap<int, mayor> heap{};

    static void cargar(Heap<int, mayor>& heap) {
        heap.alta(10);
        heap.alta(7);
        heap.alta(3);
        heap.alta(13);
        heap.alta(16);
        heap.alta(11);
    }
};

TEST_F(Heap_tests, alta) {
    cargar(heap);
    heap.alta(8);
    ASSERT_EQ(heap.primero(), 16);
    ASSERT_EQ(heap.tamanio(), 7);
    heap.alta(20);
    ASSERT_EQ(heap.primero(), 20);
    ASSERT_EQ(heap.tamanio(), 8);
}

TEST_F(Heap_tests, baja) {
    cargar(heap);
    ASSERT_EQ(heap.baja(), 16);
    ASSERT_EQ(heap.tamanio(), 5);
}

TEST_F(Heap_tests, baja_maneja_heap_vacio) {
    EXPECT_THROW(heap.baja(), Heap_exception);
}

TEST_F(Heap_tests, primero) {
    cargar(heap);
    ASSERT_EQ(heap.primero(), 16);
}

TEST_F(Heap_tests, primero_maneja_heap_vacio) {
    EXPECT_THROW(heap.primero(), Heap_exception);
}

TEST_F(Heap_tests, vacio) {
    ASSERT_TRUE(heap.vacio());
    cargar(heap);
    ASSERT_FALSE(heap.vacio());
}

TEST_F(Heap_tests, tamanio) {
    cargar(heap);
    ASSERT_EQ(heap.tamanio(), 6);
}