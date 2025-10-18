#include "Libro.h"
#include <sstream>
#include <regex>
#include <vector>

Libro::Libro() : isbn(""), titulo(""), autor(""), disponible(true) {}

Libro::Libro(const std::string& isbn, const std::string& titulo, const std::string& autor, bool disponible)
    : isbn(isbn), titulo(titulo), autor(autor), disponible(disponible) {}

std::string Libro::getISBN() const { return isbn; }
std::string Libro::getTitulo() const { return titulo; }
std::string Libro::getAutor() const { return autor; }
bool Libro::estaDisponible() const { return disponible; }

void Libro::setTitulo(const std::string& nuevoTitulo) { titulo = nuevoTitulo; }
void Libro::setAutor(const std::string& nuevoAutor) { autor = nuevoAutor; }
void Libro::setDisponible(bool estado) { disponible = estado; }

bool Libro::validarISBN(const std::string& isbn) {
    std::regex formato("(\\d{3}-)?\\d{1,5}-\\d{1,7}-\\d{1,7}-[\\dX]");
    return std::regex_match(isbn, formato);
}

std::string Libro::toCSV() const {
    return isbn + "," + titulo + "," + autor + "," + (disponible ? "1" : "0");
}

Libro Libro::fromCSV(const std::string& lineaCSV) {
    std::stringstream ss(lineaCSV);
    std::string campo;
    std::vector<std::string> campos;

    while (std::getline(ss, campo, ',')) {
        campos.push_back(campo);
    }

    if (campos.size() != 4) return Libro();

    return Libro(campos[0], campos[1], campos[2], campos[3] == "1");
}