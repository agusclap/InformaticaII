#include <iostream>
using namespace std;

struct Cumpleanos {
	
	string nombre;
	int dia;
	int mes;
	int year;
};

int main(int argc, char *argv[]) {
	struct Cumpleanos c[20];
	for(int i=0;i<20;i++)
	{
		cout<<"Ingrese el nombre"<<endl;
		cin>>c[i].nombre;
		cout<<"Ingrese el dia del cumpleaños"<<endl;
		cin>>c[i].dia;
		cout<<"Ingrese el mes del cumpleaños"<<endl;
		cin>>c[i].mes;
		cout<<"Ingrese el año del cumpleaños"<<endl;
		cin>>c[i].year;
		
	}
	int dia, mes, cont = 0;
	cout<<"Ingrese el dia para buscar"<<endl;
	cin>>dia;
	cout<<"Ingrese el mes para buscar"<<endl;
	cin>>mes;
	for(int i=0;i<20;i++)
	{
		if(dia==c[i].dia && mes==c[i].mes)
		{
			
			cont++;
			
		}
		
	}
	cout<<"Los amigos que cumplen en ese dia y mes son: "<<cont<<endl;
	return 0;
}

