#include <iostream>
using namespace std;
int main()
{
    int producto_juego,venta_de_licencias,descuentos;
	cout<<"Bienvenidos a mi app \n";
	cout<<"Selecciona una opcion: "<<endl;
	int opcion;

	do
	{
		cout<<"\n1.informacion 2.compra de  licencias 3.vender licencias 4.consulta de juegos 5.descuentos 6.salir\n";
		cin>>opcion;
		switch(opcion)
		{
		case 1:
		{
			cout<<"1 informacion";
		}
		break;
		case 2:
		{
			cout<<"2 compra de licencias";
		}
		break;
		case 3:
		{
			cout<<"vender licencias";
		}
		break;
			case 4:
		{
			cout<<"consulta de juego";
		}
		break;	
		    case 5:
		{
			cout<<"descuentos";
		}
		break;
			    case 6:
		{
			cout<<"salir";
		}
		break;
		default:
		{
			cout<<"Selecciona una opcion valida";
		}
		break;
		}
	} while (opcion!=6);
}