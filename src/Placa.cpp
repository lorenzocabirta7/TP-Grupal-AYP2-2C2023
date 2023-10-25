#include "Placa.hpp"
#include <iostream>

Placa::Placa(std::string nombre, std::string leyenda, int id) {
    this->nombre = nombre;
    this->leyenda = leyenda;
    this->id = id;
}

std::ostream& operator<<(std::ostream& os, const Placa& placa) {
    os << placa.leyenda << '\n';
    return os;
}

std::ostream& operator<<(std::ostream& os, const Placa* placa) {
    os << *placa;
    return os;
}

bool Placa::menor(Placa* placa1, Placa* placa2) {
    return *placa1 < *placa2;
}

bool Placa::igual(Placa* placa1, Placa* placa2) {
    return *placa1 == *placa2;
}

bool Placa::menor(Placa placa1, Placa placa2) {
    return placa1 < placa2;
}

bool Placa::igual(Placa placa1, Placa placa2) {
    return placa1 == placa2;
}


bool Placa::operator<(Placa placa) {
    return this->id < placa.id;
}

bool Placa::operator==(Placa placa) {
    return this->id == placa.id;
}

void Placa::liberar(Placa* placa) {
    delete placa;
}