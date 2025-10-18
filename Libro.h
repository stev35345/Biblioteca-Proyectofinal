#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class Libro {
private:
    std::string isbn;
    std::string titulo;
    std::string autor;
    bool disponible;

public:
    Libro();
    Libro(const std::string& isbn, const std::string& titulo, const std::string& autor, bool disponible = true);

    std::string getISBN() const;
    std::string getTitulo() const;
    std::string getAutor() const;
    bool estaDisponible() const;

    void setTitulo(const std::string& nuevoTitulo);
    void setAutor(const std::string& nuevoAutor);
    void setDisponible(bool estado);

    static bool validarISBN(const std::string& isbn);

    std::string toCSV() const;
    static Libro fromCSV(const std::string& lineaCSV);
};

#endif