#include <iostream>
#include <ctime>
using namespace std;
/* Crear un programa donde el usuario ingrese la dimension(columnas y filas) del
puntero, automaticamente ingresar los valores de dicho arreglo con numeros aleatorios
y crear un menu de opciones con: calcular el promedio total del arreglo de enteros, sumatoria, y identificar cuales son
los numeros pares y impares y mostrarlos por pantalla junto al arreglo. Al final liberar la memoria	.
(usar funciones,punteros) */

void cargar(int **p, int *, int *);
float calcular_prom(int **p, int *, int *);
int calcular_sum(int **p, int *, int *);
void numeros(int **p, int *, int *);

int main(int argc, char *argv[]) {
	int filas,columnas,suma = 0;
	float promedio = 0;
	int **p = {NULL};
	char opcion,seguir = ' ';
	cargar(p,&columnas,&filas);
	do{
		cout<<"MENU DE OPCIONES:"<<endl;
		cout<<"a) Calcular el promedio total del arreglo"<<endl;
		cout<<"b) Calcular la sumatoria"<<endl;
		cout<<"c) Imprimir Matriz, Numeros pares y impares"<<endl;
		cin>>opcion;
		switch(opcion)
		{
		case 'a':
			promedio=calcular_prom(p,&columnas,&filas);
			cout<<"El promedio del arreglo es "<<promedio<<endl;
			break;
		case 'b':
			suma = calcular_sum(p,&columnas,&filas);
			cout<<"La suma es "<<suma<<endl;
			break;
		case 'c':
			numeros(p,&columnas,&filas);
			break;
		default:
			cout<<"Ingrese una opcion correcta"<<endl;
		}
		cout<<"Desea continuar con el programa"<<endl;
		cin>>seguir;
	} while(seguir=='y' || seguir=='Y');
	
	for (int i=0;i<columnas;i++)
	{
		free(*(p+i));
		
	}
	free(p);
	return 0;
}

void cargar(int **p, int *columnas, int *filas)
{
	srand(time(NULL));
	cout<<"Ingrese la cantidad de columnas"<<endl;
	cin>>*columnas;
	p= (int **) malloc((*columnas)*sizeof(int *));
	if(p==NULL)
	{
		cout<<"No hay memoria disponible"<<endl;
		exit(0);
		
	}
	cout<<"Ingrese la cantidad de filas"<<endl;
	cin>>*filas;
	for(int i=0;i<*columnas;i++)
	{
		*(p+i) = (int *) malloc((*filas)*sizeof(int));
		if(*(p+i)== NULL)
		{
			cout<<"No hay memoria suficiente"<<endl;
			exit(0);
			
		}
		
	}
	
	for( int k=0;k<*columnas;k++)
	{
		for(int ii=0;ii<*filas;ii++)
		{
			
			*(*(p+k)+ii) = rand()%100;
			
		}
		
		
	}
	cout<<"Arreglo:"<<endl;
	for (int i=0;i<*columnas;i++)
	{
		for(int ii=0;ii<*filas;ii++)
		{
			
			cout<<*(*(p+i)+ii)<<"\t";
			
		}
		cout<<"\n";
		
	}
}
float calcular_prom(int **p, int *columnas, int *filas)
{
	int sumatoria=0;
	float prom = 0;
	
	for(int u=0;u<*columnas;u++)
	{
		for(int v=0;v<*filas;v++)
		{
			sumatoria = sumatoria + (*(*(p+u)+v));
		}
		
	}
	cout<<"lol"<<endl;
	prom = sumatoria/(*columnas)*(*filas);;
	
	return prom;
}

int calcular_sum(int **p, int *columnas, int *filas)
{
	int sumatoria = 0;
	for(int i=0;i<*columnas;i++)
	{
		for(int ii=0;ii<*filas;ii++)
		{
			
			sumatoria = sumatoria + (*(*(p+i)+ii));
			
		}
		
	}
	return sumatoria;
	
	
}

void numeros(int **p, int *columnas, int *filas)
{
	
	cout<<"Arreglo:"<<endl;
	for (int i=0;i<*columnas;i++)
	{
		for(int ii=0;ii<*filas;ii++)
		{
			
			cout<<*(*(p+i)+ii);
			
		}
		cout<<endl;
		
	}
	cout<<endl;
	cout<<"Numeros pares: "<<endl;
	for(int k=0;k<*columnas;k++)
	{
		for(int kk=0;kk<*filas;kk++)
		{
			if((*(*(p+k)+kk))%2==0)
			{
				
				cout<<(*(*(p+k)+kk));
				
			}
			cout<<endl;
		}
		
		
	}
	cout<<endl;
	cout<<"Numeros impares: "<<endl;
	for(int x=0;x<*columnas;x++)
	{
		for(int y=0;y<*filas;y++)
		{
			if(((*(*(p+x)+y))%2)!=0)
			{
				
				cout<<(*(*(p+x)+y));
				
			}
			cout<<endl;
			
		}
		
		
	}
	
}
