#include <iostream>
using namespace std;

struct Jugadores{
	
	string nombre;
	int altura;
	int edad;
};
void cargar(struct Jugadores j[10]);
void listar_nombres(struct Jugadores j[10]);
void listar_alturas(struct Jugadores j[10]);
void listar_edades(struct Jugadores j[10]);


int main(int argc, char *argv[]) {
	struct Jugadores j[10];
	cargar(j);
	char opcion,seguir = ' ';
	do{
		cout<<"MENU DE OPCIONES:"<<endl;
		cout<<"a) Listar los nombres de los jugadores"<<endl;
		cout<<"b) Listar las alturas de los jugadores"<<endl;
		cout<<"c) Listar las edades de los jugadores"<<endl;
		cin>>opcion;
		switch(opcion)
		{
		case 'a':
			listar_nombres(j);
			break;
		case 'b':
			listar_alturas(j);
			break;
		case 'c':
			listar_edades(j);
			break;
		default:
			cout<<"Ingrese una opcion correcta"<<endl;
			
		}
		cout<<"Desea continuar con el programa"<<endl;
		cin>>seguir;
	} while(seguir=='y' || seguir=='Y');
	return 0;
}
void cargar(struct Jugadores j[10])
{
	for(int i=0;i<10;i++)
	{
		cout<<"Ingrese el nombre del jugador"<<endl;
		cin>>j[i].nombre;
		cout<<"Ingrese la altura del jugador"<<endl;
		cin>>j[i].altura;
		cout<<"Ingrese la edad del jugador"<<endl;
		cin>>j[i].edad;
		
	}
	
	
}
void listar_nombres(struct Jugadores j[10]){
	cout<<"Lista de nombres:"<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<j[i].nombre<<endl;
		
		
	}	
}
void listar_alturas(struct Jugadores j[10]){
	cout<<"Lista de nombres:"<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<j[i].altura<<endl;
	}	
}
void listar_edades(struct Jugadores j[10]){
	cout<<"Lista de nombres:"<<endl;
	for(int i=0;i<10;i++)		{
	cout<<j[i].edad<<endl;

	}	
}
