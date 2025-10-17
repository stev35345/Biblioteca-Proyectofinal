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

int main()
{
    // Configurar consola para UTF-8 antes de imprimir nada
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

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
            cout << u8"Función de gestión de libros aún no implementada.\n";
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
            cout << u8"Saliendo del programa...\n";
            break;
        default:
            cout << u8"Opción no válida.\n";
        }

        cout << endl;

    } while (opcion != 5);

    return 0;
}
