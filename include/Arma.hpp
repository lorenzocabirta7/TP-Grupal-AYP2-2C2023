#ifndef TDAS_TESTS_ARMA_HPP
#define TDAS_TESTS_ARMA_HPP

#include <string>
#include <cstddef>

class Arma {
private:
    std::string nombre;
    size_t potencia = 0;
public:
    // Constructores.
    Arma() {};

    Arma(std::string nombre, size_t potencia);

    // Pre: Ninguna de las armas puede ser nullptr.
    // Post: Devuelve true si el primer arma es mas debil que la segunda, por potencia.
    static bool menor(Arma* arma1, Arma* arma2);

    // Pre: Ninguna de las armas puede ser nullptr.
    // Post: Devuelve true si las armas son iguales, por potencia.
    static bool igual(Arma* arma1, Arma* arma2);

    // Pre: Ninguna de las armas puede ser nullptr.
    // Post: Devuelve true si el primer arma es mas fuerte que la segunda, por potencia.
    static bool mayor(Arma* arma1, Arma* arma2);

    // Pre: -
    // Post: Devuelve true si el primer arma es mas debil que la segunda, por potencia.
    static bool menor(Arma arma1, Arma arma2);

    // Pre: -
    // Post: Devuelve true si las armas son iguales, por potencia.
    static bool igual(Arma arma1, Arma arma2);

    // Pre: -
    // Post: Devuelve true si el primer arma es mas fuerte que la segunda, por potencia.
    static bool mayor(Arma arma1, Arma arma2);

    // Pre: -
    // Post: Devuelve true si el primer arma es mas debil que la segunda, por potencia.
    bool operator<(Arma arma);

    // Pre: -
    // Post: Devuelve true si las armas son iguales, por potencia.
    bool operator==(Arma arma);

    // Pre: -
    // Post: Devuelve true si el primer arma es mas fuerte que la segunda, por potencia.
    bool operator>(Arma arma);

    // Pre: -
    // Post: Carga la información al stream de salida, con el formato especificado.
    friend std::ostream& operator<<(std::ostream& os, const Arma& arma);

    // Pre: El arma no puede ser nullptr.
    // Post: Carga la información al stream de salida, con el formato especificado.
    friend std::ostream& operator<<(std::ostream& os, const Arma* arma);

    // Pre: El arma no puede ser nullptr.
    // Post: Libera la memoria reservada para la placa.
    static void liberar(Arma* arma);

    // Destructor.
    ~Arma() {};
};

#endif