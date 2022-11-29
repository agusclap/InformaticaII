/* 1. Escribir un programa donde se solicite el tamaño del vector (entre 5 y 10) y reservar memoria. Luego al finalizar la ejecucion del programa liberarla. Luego crear las siguientes funciones:

- cargarNumero(), que rellene aleatoriamente el vector con números entre el 1 y 10 utilizando punteros.

- mostrarNumero(), que muestre el vector anterior por medio de punteros los valores del vector y las direcciones en las cuales los valores sean mayores a 5 inclusive.

- sumarNumero() que sume todos los números del vector de manera recursiva.
*/
#include <iostream>
#include <ctime>
using namespace std;


void cargarNumero(int *p, int cantidad);
void mostrarNumero(int *p, int cantidad);
void sumarNumero(int *p, int cantidad);

int main(int argc, char *argv[]) {
	int *p = NULL;
	bool flag = false;
	int cantidad = 0;
	do{
	cout<<"Ingrese el tamaño del vector entre 5 y 10"<<endl;
	cin>>cantidad;

	if(cantidad<5 || cantidad>10){
		cout<<"Ingrese una cantidad valida"<<endl;
	}
	if(cantidad<=10 && cantidad>=5)
	{
		flag = true;
		p = ( int *) malloc(cantidad*sizeof(int));
		if(p==NULL)
		{
			cout<<"No hay memoria suficiente"<<endl;
			exit(404);
		}
	}
	}while(flag==false);
	cargarNumero(p,cantidad);
	mostrarNumero(p,cantidad);
	sumarNumero(p,cantidad);
	return 0;
}
void cargarNumero(int *p, int cantidad)
{
	
	for(int i=0;i<cantidad;i++)
	{
		
		*(p+i) = 1 + rand () % 10;
		
	}
	
}
void mostrarNumero(int *p, int cantidad)
{
	
	for(int i=0;i<cantidad;i++)
	{
		
		cout<<"Los valores son: "<<*(p+i)<<endl;
		
	}
	cout<<"Direcciones de los valores mayores a 5"<<endl;
	for(int ii=0;ii<cantidad;ii++)
	{
		if(*(p+ii) >= 5)
		{
			cout<<"Direccion del numero "<<ii<<" es "<<*(p+ii)<<endl;
			
		}
		
		
	}
}

void sumarNumero(int *p, int cantidad)
{
	int suma=0;
	for(int i=0;i<cantidad;i++)
	{
		
		suma = suma + *(p+i);
		
	}
	
	cout<<"La suma es "<<suma;
}
