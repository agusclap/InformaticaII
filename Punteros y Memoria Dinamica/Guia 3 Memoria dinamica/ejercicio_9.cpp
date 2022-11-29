#include <iostream>
#include <ctime>
#define F 2
#define C 3
using namespace std;
/*Cree un programa que permita reservar memoria para arreglo de enteros 2x3. Luego cargar
los valores de manera aleatoria. Realizar un menu de opciones que muestre la sumatoria, 
muestre todos los valores y al finalizar el programa libere la memoria. */

void cargar(int **p);
void mostrar(int **p);
void mostrar_valores(int **p);
int main(int argc, char *argv[]) {
	
	int **p = {NULL};
	p = (int **) malloc(C*sizeof(int *));
	if (p==NULL)
	{
		cout<<"No hay memoria disponible"<<endl;
		exit(0);
	}
	char opcion,seguir = ' ';
	cargar(p);
	do{
		cout<<"MENU DE OPCIONES:"<<endl;
		cout<<"a) Mostrar sumatoria"<<endl;
		cout<<"b) Mostrar todos los valores"<<endl;
		cin>>opcion;
		switch(opcion)
		{
		case 'a':
			mostrar(p);
			break;
		case 'b':
			mostrar_valores(p);
			break;
		default:
			cout<<"Ingrese una opcion correcta"<<endl;
		}
		cout<<"Desea continuar con el programa ? y/n"<<endl;
		cin>>seguir;
	} while(seguir=='y' || seguir=='Y');
	for (int i=0;i<C;i++)
	{
		free(*(p+i));
	}
	free(p);
	return 0;
}

void cargar(int **p)
{
	srand(time(NULL));
	for(int i=0;i<C;i++)
	{
		*(p+i) = (int *) malloc(F*sizeof(int));
		if(*(p+i) == NULL)
		{
			
			cout<<"No hay memoria disponible"<<endl;
			exit(0);
			
		}
	}
	
	for(int ii=0;ii<C;ii++)
	{
		for(int k=0;k<F;k++)
		{
			
			*(*(p+ii)+k) = rand()%100;
			
		}
		
	}
	
}

void mostrar(int **p)
{
	int sumatoria=0;
	for(int i=0;i<C;i++)
	{
		for(int ii=0;ii<F;ii++)
		{
			sumatoria = sumatoria +  (*(*(p+i)+ii));
			
		}
		
	}
	cout<<"La sumatoria es "<<sumatoria<<endl;
	
}

void mostrar_valores(int **p)
{
	for(int i=0;i<C;i++)
	{
		for(int ii=0;ii<F;ii++)
		{
			
			cout<<*(*(p+i)+ii)<<"\t";
			
		}
		cout<<endl;
		
	}
	
	
}
