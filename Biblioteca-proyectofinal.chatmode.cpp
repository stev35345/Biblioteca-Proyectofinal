#include "Libro.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <locale>
#include <string>
#include <sstream>
#include <windows.h>
#include <fcntl.h>
#include <io.h>
using namespace std;
//Aca pego el codigo llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll
#include "Libro.h"
#include <vector>
#include <fstream>

vector<Libro> libros;

void cargarLibros() {
    ifstream archivo("libros.txt");
    string linea;
    while (getline(archivo, linea)) {
        libros.push_back(Libro::fromCSV(linea));
    }
    archivo.close();
}

void guardarLibros() {
    ofstream archivo("libros.txt");
    for (const auto& libro : libros) {
        archivo << libro.toCSV() << "\n";
    }
    archivo.close();
}

Libro* buscarLibroPorISBN(const string& isbn) {
    for (auto& libro : libros) {
        if (libro.getISBN() == isbn) {
            return &libro;
        }
    }
    return nullptr;
}

void registrarLibro() {
    string isbn, titulo, autor;
    cout << "ISBN: ";
    cin >> isbn;

    if (!Libro::validarISBN(isbn)) {
        cout << "ISBN inválido.\n";
        return;
    }

    if (buscarLibroPorISBN(isbn)) {
        cout << "Ya existe un libro con ese ISBN.\n";
        return;
    }

    cin.ignore();
    cout << "Título: ";
    getline(cin, titulo);
    cout << "Autor: ";
    getline(cin, autor);

    libros.emplace_back(isbn, titulo, autor);
    cout << "Libro registrado exitosamente.\n";
}

void listarLibros() {
    for (const auto& libro : libros) {
        cout << "ISBN: " << libro.getISBN()
             << " | Título: " << libro.getTitulo()
             << " | Autor: " << libro.getAutor()
             << " | Disponible: " << (libro.estaDisponible() ? "Sí" : "No") << "\n";
    }
}

void actualizarLibro() {
    string isbn;
    cout << "ISBN del libro a actualizar: ";
    cin >> isbn;

    Libro* libro = buscarLibroPorISBN(isbn);
    if (!libro) {
        cout << "Libro no encontrado.\n";
        return;
    }

    string nuevoTitulo, nuevoAutor;
    cin.ignore();
    cout << "Nuevo título: ";
    getline(cin, nuevoTitulo);
    cout << "Nuevo autor: ";
    getline(cin, nuevoAutor);

    libro->setTitulo(nuevoTitulo);
    libro->setAutor(nuevoAutor);
    cout << "Libro actualizado.\n";
}

void eliminarLibro() {
    string isbn;
    cout << "ISBN del libro a eliminar: ";
    cin >> isbn;

    auto it = remove_if(libros.begin(), libros.end(), [&](const Libro& l) {
        return l.getISBN() == isbn;
    });

    if (it != libros.end()) {
        libros.erase(it, libros.end());
        cout << "Libro eliminado.\n";
    } else {
        cout << "Libro no encontrado.\n";
    }
}
//Aca termina lllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll
void gestionarLibros() {
    int opcion;
    string entrada;

    do {
        cout << "\n--- Gestión de Libros ---\n";
        cout << "1. Registrar nuevo libro\n";
        cout << "2. Listar todos los libros\n";
        cout << "3. Actualizar libro\n";
        cout << "4. Eliminar libro\n";
        cout << "5. Volver al menú principal\n";
        cout << "Selecciona una opción: ";
        cin >> entrada;

        stringstream ss(entrada);
        if (!(ss >> opcion)) {
            opcion = -1;
            cin.clear();
        }

        switch (opcion) {
            case 1:
                registrarLibro();
                break;
            case 2:
                listarLibros();
                break;
            case 3:
                actualizarLibro();
                break;
            case 4:
                eliminarLibro();
                break;
            case 5:
                break;
            default:
                cout << "Opción no válida.\n";
        }

        cout << endl;

    } while (opcion != 5);
}
int main()
{
    // Configurar consola para UTF-8 antes de imprimir nada
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
cargarLibros();
    int opcion;
    string entrada;

    do {
        // Usamos prefijo u8 para asegurar UTF-8
        cout << u8"╔════════════════════════════════════════╗\n";
        cout << u8"║   SISTEMA DE GESTIÓN DE BIBLIOTECA     ║\n";
        cout << u8"╠════════════════════════════════════════╣\n";
        cout << u8"║1. Gestión de Libros                    ║\n";
        cout << u8"║2. Gestión de Usuarios                  ║\n";
        cout << u8"║3. Gestión de Préstamos                 ║\n";
        cout << u8"║4. Reportes y Estadísticas              ║\n";
        cout << u8"║5. Guardar y Salir                      ║\n";
        cout << u8"╚════════════════════════════════════════╝\n";
        cout << u8"Selecciona una opción: ";
        cin >> entrada;

        stringstream LETRAS(entrada);
        if (!(LETRAS >> opcion)) {
            opcion = -1; // Entrada inválida
            cin.clear(); // Limpia el error
        }

        switch (opcion) {
        case 1:
            cout << u8"Gestion de libros.\n";
            gestionarLibros();
            break;
        case 2:
            cout << u8"Función de gestión de usuarios aún no implementada.\n";
            break;
        case 3:
            cout << u8"Función de gestión de préstamos aún no implementada.\n";
            break;
        case 4:
            cout << u8"Función de reportes aún no implementada.\n";
            break;
        case 5:
        guardarLibros();
            cout << u8"Saliendo del programa...\n";
            break;
        default:
            cout << u8"Opción no válida.\n";
        }

        cout << endl;

    } while (opcion != 5);

    return 0;
}
