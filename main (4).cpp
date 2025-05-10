#include <iostream>
using namespace std;

struct Juego {
    string nombre;
    string categoria; // rompecabezas, acción, deporte
    float tamanoKB;
    float precio;
    int licenciasDisponibles;
    int licenciasVendidas;

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << "\n";
        cout << "Categoría: " << categoria << "\n";
        cout << "Tamaño: " << tamanoKB << " KB\n";
        cout << "Precio: $" << precio << "\n";
        cout << "Licencias disponibles: " << licenciasDisponibles << "\n";
        cout << "Licencias vendidas: " << licenciasVendidas << "\n\n";
    }

    void comprarLicencia(int cantidad) {
        if (cantidad <= licenciasDisponibles) {
            licenciasDisponibles -= cantidad;
            licenciasVendidas += cantidad;
        } else {
            cout << "No hay suficientes licencias disponibles para " << nombre << ".\n";
        }
    }

    void venderLicencia(int cantidad) {
        licenciasDisponibles += cantidad;
        cout << cantidad << " licencias agregadas para " << nombre << ".\n";
    }
};

float calcularDescuento(Juego juegos[], int n, int cantidades[], float& total) {
    int totalRompecabezas = 0, totalDeportes = 0, totalAccion = 0;
    total = 0;

    for (int i = 0; i < n; ++i) {
        string cat = juegos[i].categoria;
        total += juegos[i].precio * cantidades[i];

        if (cat == "Rompecabezas") totalRompecabezas += cantidades[i];
        else if (cat == "Deporte") totalDeportes += cantidades[i];
        else if (cat == "Accion") totalAccion += cantidades[i];
    }

    // Aplicar descuentos según reglas
    if (totalRompecabezas >= 25) return 0.20; // 20%
    if (totalDeportes >= 20 && totalAccion >= 15) return 0.15; // 15%
    return 0.0;
}

Juego determinarMasVendido(Juego juegos[], int n) {
    Juego masVendido = juegos[0];
    for (int i = 1; i < n; ++i) {
        if (juegos[i].licenciasVendidas > masVendido.licenciasVendidas) {
            masVendido = juegos[i];
        }
    }
    return masVendido;
}

int main() {
    const int N = 4;
    Juego juegos[N] = {
        {"Futbol", "Deporte", 51200, 60.0, 100, 0},
        {"zombies", "Accion", 204800, 80.0, 150, 0},
        {"Tetris", "Rompecabezas", 1024, 15.0, 200, 0},
        {"Sudoku", "Rompecabezas", 2048, 10.0, 180, 0}
    };

    int cantidades[N] = {0};

    // Mostrar info
    for (int i = 0; i < N; ++i) {
        juegos[i].mostrarInformacion();
    }

    // Comprar licencias
    cout << "\nIngrese la cantidad de licencias que desea comprar por juego:\n";
    for (int i = 0; i < N; ++i) {
        cout << juegos[i].nombre << ": ";
        cin >> cantidades[i];
    }

    float totalSinDescuento, descuentoAplicado;
    float porcentaje = calcularDescuento(juegos, N, cantidades, totalSinDescuento);
    descuentoAplicado = totalSinDescuento * porcentaje;
    float totalFinal = totalSinDescuento - descuentoAplicado;

    for (int i = 0; i < N; ++i) {
        if (cantidades[i] > 0) {
            juegos[i].comprarLicencia(cantidades[i]);
        }
    }

    cout << "\nResumen de la compra:\n";
    cout << "Total sin descuento: $" << totalSinDescuento << "\n";
    cout << "Descuento aplicado: " << (porcentaje * 100) << "% -> $" << descuentoAplicado << "\n";
    cout << "Total final: $" << totalFinal << "\n";

    // Juego más vendido
    Juego masVendido = determinarMasVendido(juegos, N);
    cout << "\nJuego más vendido: " << masVendido.nombre << " con " << masVendido.licenciasVendidas << " licencias vendidas.\n";

    // Simular venta (opcional)
    cout << "\n¿Desea vender más licencias a algún juego? (1 = Sí / 0 = No): ";
    int op;
    cin >> op;
    if (op == 1) {
        for (int i = 0; i < N; ++i) {
            cout << "Licencias a agregar para " << juegos[i].nombre << ": ";
            int agregar;
            cin >> agregar;
            if (agregar > 0) juegos[i].venderLicencia(agregar);
        }
    }
}