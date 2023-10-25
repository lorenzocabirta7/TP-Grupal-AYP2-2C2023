#ifndef PLACA_H
#define PLACA_H

#include <string>

class Placa {
private:
    std::string nombre;
    std::string leyenda;
    int id = 0;
public:
    // Constructores.
    Placa() {};

    Placa(std::string nombre, std::string leyenda, int id);

    /* Métodos de comparacion para pasar al arbol, dependiendo de si son punteros o datos estaticos.
     * Para punteros, usar los siguientes. */

    // Pre: Ninguna de las placas puede ser nullptr.
    // Post: Devuelve true si la primera placa es mas chica que la segunda, por ID.
    static bool menor(Placa* placa1, Placa* placa2);

    // Pre: Ninguna de las placas puede ser nullptr.
    // Post: Devuelve true si las placas son iguales, por ID.
    static bool igual(Placa* placa1, Placa* placa2);

    /* Para estaticos, usar los siguientes. */

    // Pre: -
    // Post: Devuelve true si la primera placa es mas chica que la segunda, por ID.
    static bool menor(Placa placa1, Placa placa2);

    // Pre: -
    // Post: Devuelve true si las placas son iguales, por ID.
    static bool igual(Placa placa1, Placa placa2);

    // Pre: -
    // Post: Devuelve true si la placa es mas chica, por ID.
    bool operator<(Placa placa);

    // Pre: -
    // Post: Devuelve true si las placas son iguales, por ID.
    bool operator==(Placa placa);

    // Pre: -
    // Post: Carga la información al stream de salida, con el formato especificado.
    friend std::ostream& operator<<(std::ostream& os, const Placa& placa);

    // Pre: La placa no puede ser nullptr.
    // Post: Carga la información al stream de salida, con el formato especificado.
    friend std::ostream& operator<<(std::ostream& os, const Placa* placa);

    // Pre: La placa no puede ser nullptr.
    // Post: Libera la memoria reservada para la placa.
    static void liberar(Placa* placa);

    // Destructor.
    ~Placa() {};
};

#endif