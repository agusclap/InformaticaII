#include <iostream>
#include <ctime>
using namespace std;

int maximo(int *ptr[5]);
int minimo(int *ptr[5]);
int sumatoria(int *ptr[5]);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int vector[5];
	int *ptr[5];
	int valor_maximo,valor_minimo,suma = 0;
	for (int i=0;i<5;i++)
	{
		vector[i] = rand()%100;
		ptr[i]=&vector[i];
	}
	valor_maximo = maximo(ptr);
	cout<<"El valor mas grande del vector es "<<valor_maximo<<endl;
	valor_minimo=minimo(ptr);
	cout<<"El valor mas pequeño del vector es "<<valor_minimo<<endl;
	suma=sumatoria(ptr);
	cout<<"La suma de los numeros es "<<suma<<endl;
	return 0;
}

int maximo(int *ptr[5])
{
	int max=0;
	max= *ptr[0];
	for(int i=0;i<5;i++)
	{
		if(*ptr[i] > max)
		{
			
			max = *ptr[i];
			
		}
		
	}
	return max;
	
}
int minimo(int *ptr[5])
{
	int min=0;
	min= *ptr[0];
	for(int i=0;i<5;i++)
	{
		if(*ptr[i] < min)
		{
			
			min = *ptr[i];
			
		}
		
	}
	return min;
	
}

int sumatoria(int *ptr[5])
{
	int suma=0;
	for(int i=0;i<5;i++)
	{
		
		suma = suma + *ptr[i];
		
	}
	
	return suma;
	
}
