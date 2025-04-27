#include <iostream>
#include <string>
using namespace std;

// Estructura juegos
struct Juego {
    int idJuego;
    string nombre;
    string categoria;

    void mostrarNombre() {
        cout << "El nombre del juego es: " << nombre << endl;
    }

    void asignarIdJuego() {
        cout << "Ingrese el ID del juego: ";
        cin >> idJuego;
    }
};

// Estructura marketing
struct Marketing {
    int numero_de_clientes;
    string nombre_cliente;

    void asignarNumeroDeClientes() {
        cout << "Ingrese el número de clientes: ";
        cin >> numero_de_clientes;
    }

    void asignarNombreCliente() {
        cout << "Ingrese el nombre del cliente: ";
        cin >> nombre_cliente;
    }
};

// Estructura cliente
struct Cliente {
    string juego;
    int cupo;
};

// Estructura comercial
struct Comercial {
    float descuento_del_juego;

    void mostrarDescuento() {
        cout << "Descuento aplicado al juego: " << descuento_del_juego << "%" << endl;
    }
};

int main() {
    // Juegos
    Juego accion, deporte, rompecabezas;

    cout << "--- Datos de juegos ---" << endl;
    accion.asignarIdJuego();
    cout << "Ingrese el nombre del juego de accion: ";
    cin >> accion.nombre;
    cout << "Ingrese la categoria: ";
    cin >> accion.categoria;

    deporte.asignarIdJuego();
    cout << "Ingrese el nombre del juego de deporte: ";
    cin >> deporte.nombre;
    cout << "Ingrese la categoria: ";
    cin >> deporte.categoria;

    rompecabezas.asignarIdJuego();
    cout << "Ingrese el nombre del juego de rompecabezas: ";
    cin >> rompecabezas.nombre;
    cout << "Ingrese la categoria: ";
    cin >> rompecabezas.categoria;

    // Marketing
    Marketing marketing;
    marketing.asignarNumeroDeClientes();
    marketing.asignarNombreCliente();

    // Licencias de juegos
    int z;
    cout << "Cantidad de licencias vendidas: ";
    cin >> z;
    Cliente* licenciaJuego = new Cliente[z];
    int acum_cupo = 0;

    for (int i = 0; i < z; i++) {
        cout << "Nombre del juego: ";
        cin >> licenciaJuego[i].juego;
        cout << "Cupo vendido: ";
        cin >> licenciaJuego[i].cupo;
        acum_cupo += licenciaJuego[i].cupo;
    }

    cout << "El cupo promedio de licencias es: " << (float)acum_cupo / z << endl;

    // Descuentos de juegos
    int d;
    cout << "Cantidad de descuentos aplicados: ";
    cin >> d;
    Comercial* descuentos = new Comercial[d];
    float acum_descuento = 0;

    for (int f = 0; f < d; f++) {
        cout << "Descuento aplicado (%): ";
        cin >> descuentos[f].descuento_del_juego;
        acum_descuento += descuentos[f].descuento_del_juego;
    }

    cout << "El descuento promedio aplicado es: " << acum_descuento / d << "%" << endl;

    // Ganancias
    int y;
    cout << "Cantidad de juegos vendidos para ganancias: ";
    cin >> y;
    Cliente* ganancias = new Cliente[y];
    int acum_ganancias = 0;

    for (int l = 0; l < y; l++) {
        cout << "Nombre del juego vendido: ";
        cin >> ganancias[l].juego;
        cout << "Cantidad ganada: ";
        cin >> ganancias[l].cupo;
        acum_ganancias += ganancias[l].cupo;
    }

    cout << "La ganancia promedio es: " << acum_ganancias / y;
}