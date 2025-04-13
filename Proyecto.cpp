#include <iostream>
using namespace std;

struct juegos
{
	//atributos
	int idJuego;
	string nombre;
	string categoria;
	//mC)todos
	void mostrarNombre();
	void asignaridJuego();
}

void juegos::mostrarNombre() {
	cout<<"la categoria del juego es: \n";
	cout<<nombre;
}

void juegos::asignaridJuego() {
	cout<<"categoria: \n";
	cin>>idJuego;
}

main()
{
	juegos accion, deporte, rompecabezas;
	accion.asignaridJuego();
	cout<<accion.idJuego;
	cout<<"ingrese el juego de accion";
	cin>>accion.categoria;
}
main()
{
	juegos accion, deporte, rompecabezas;
	accion.asignaridJuego();
	cout<<deporte.idJuego;
	cout<<"ingrese el juego de deporte";
	cin>>deporte.categoria;
}
main()
{
	juegos accion, deporte, rompecabezas;
	accion.asignaridJuego();
	cout<<rompecabezas.idJuego;
	cout<<"ingrese el juego de rompecabezas";
	cin>>rompecabezas.categoria;
}

struct marketing
{
	//atributos
	int numero_de_clientes;
	string nombrecliente;
	//mC)todos
	void mostrar numero_de_clientes();
	void nombrecliente();
	void juegos::mostrarNombre()
}

void marketing::asignar numero_de_clientes() {
	cout<<"numero_de_clientes";
	cin>>numero_de_clientes;
}
void marketing::asignar nombrecliente() {
	cout<<"nombrecliente";
	cin>>nombrecliente;

}

struct comercial
{
	//atributos
	float desncuento_del_juego;

	//mC)todos
	void mostra desncuento_del_juego()
}
main()
{
	comercial desncuento_del_juego;
	cout<<"ingrese el desncuento_del_juego";
	cin>> desncuento_del_juego;
}
