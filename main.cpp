

#include <iostream>
#include <string>
using namespace std;

struct Juego {
    string nombre;
    string categoria; // rompecabezas, acción, deporte
    int tamanoKB;
    float precio;
    int licenciasDisponibles;
    int licenciasVendidas;
    string imagen;
};

class AppStore {
private:
    static const int MAX_JUEGOS = 10;
    Juego juegos[MAX_JUEGOS];
    int cantidadJuegos = 0;

public:
    void agregarJuego(const Juego& juego) {
        if (cantidadJuegos < MAX_JUEGOS) {
            juegos[cantidadJuegos++] = juego;
        } else {
            cout << "No se pueden agregar más juegos." << endl;
        }
    }

    void mostrarJuegos() {
        for (int i = 0; i < cantidadJuegos; i++) {
            cout << "Nombre: " << juegos[i].nombre << "\n"
                 << "Categoría: " << juegos[i].categoria << "\n"
                 << "Tamaño: " << juegos[i].tamanoKB << " KB\n"
                 << "Precio: $" << juegos[i].precio << "\n"
                 << "Licencias disponibles: " << juegos[i].licenciasDisponibles << "\n"
                 << "Licencias vendidas: " << juegos[i].licenciasVendidas << "\n"
                 << "Imagen: " << juegos[i].imagen << "\n\n";
        }
    }

    float calcularDescuento(string nombres[], int cantidades[], int numPedidos) {
        int totalRompe = 0, totalDeporte = 0, totalAccion = 0;
        float totalPrecio = 0;

        for (int i = 0; i < numPedidos; i++) {
            string nombre = nombres[i];
            int cantidad = cantidades[i];

            for (int j = 0; j < cantidadJuegos; j++) {
                if (juegos[j].nombre == nombre) {
                    totalPrecio += juegos[j].precio * cantidad;
                    if (juegos[j].categoria == "rompecabezas") totalRompe += cantidad;
                    if (juegos[j].categoria == "deporte") totalDeporte += cantidad;
                    if (juegos[j].categoria == "accion") totalAccion += cantidad;
                }
            }
        }

        if (totalRompe >= 25)
            return totalPrecio * 0.8f; // 20% de descuento
        else if (totalDeporte >= 20 && totalAccion >= 15)
            return totalPrecio * 0.85f; // 15% de descuento
        else
            return totalPrecio;
    }
};

int main() {
    AppStore app;
    Juego juego1 = {"PuzzleMania", "rompecabezas", 2048, 5.99, 100, 20, "puzzle.jpg"};
    Juego juego2 = {"FutbolPro", "deporte", 5120, 9.99, 50, 30, "futbol.jpg"};
    Juego juego3 = {"ActionHero", "accion", 4096, 7.99, 70, 40, "accion.jpg"};

    app.agregarJuego(juego1);
    app.agregarJuego(juego2);
    app.agregarJuego(juego3);

    app.mostrarJuegos();

    string nombresPedidos[] = {"PuzzleMania"};
    int cantidadesPedidos[] = {26};
    int numPedidos = 1;

    float totalConDescuento = app.calcularDescuento(nombresPedidos, cantidadesPedidos, numPedidos);
    cout << "Total con descuento: $" << totalConDescuento <<;

    }
    