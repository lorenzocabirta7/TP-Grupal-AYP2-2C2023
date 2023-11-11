#include "Arma.hpp"
#include <iostream>

Arma::Arma(std::string nombre, size_t potencia) {
    this->nombre = nombre;
    this->potencia = potencia;
}

std::ostream& operator<<(std::ostream& os, const Arma& arma) {
    os << arma.nombre << '\n';
    return os;
}

std::ostream& operator<<(std::ostream& os, const Arma* arma) {
    os << *arma;
    return os;
}

bool Arma::menor(Arma* arma1, Arma* arma2) {
    return *arma1 < *arma2;
}

bool Arma::igual(Arma* arma1, Arma* arma2) {
    return *arma1 == *arma2;
}

bool Arma::mayor(Arma* arma1, Arma* arma2) {
    return *arma1 > *arma2;
}

bool Arma::menor(Arma arma1, Arma arma2) {
    return arma1 < arma2;
}

bool Arma::igual(Arma arma1, Arma arma2) {
    return arma1 == arma2;
}

bool Arma::mayor(Arma arma1, Arma arma2) {
    return arma1 > arma2;
}

bool Arma::operator<(Arma arma) {
    return this->potencia < arma.potencia;
}

bool Arma::operator==(Arma arma) {
    return this->potencia == arma.potencia;
}

bool Arma::operator>(Arma arma) {
    return this->potencia > arma.potencia;
}

void Arma::liberar(Arma* arma) {
    delete arma;
}