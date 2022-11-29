#include <iostream>
#include <ctime>
using namespace std;

void valor_max(int *p[]);
void valor_min(int *p[]);
void sumatoria(int *p[]);

int main(int argc, char *argv[]) {
	int vector[5] = {0};
	int *p[5] = {NULL};
	srand(time(NULL));
	for(int i=0;i<5;i++)
	{
		vector[i] = rand () % 100;
		p[i] = &vector[i];;
		
	}
	for(int i=0;i<5;i++)
	{
		cout<<(*p[i])<<endl;
		
	}
	valor_max(p);
	valor_min(p);
	sumatoria(p);
	return 0;
}

void valor_max(int *p[5])
{
	int valor_max = *p[0];
	for(int i=0;i<5;i++)
	{
		if(valor_max<(*p[i]))
		{
			valor_max = *p[i];
			
		} else{
			valor_max = valor_max;
		}
		
	}
	cout<<"El valor maximo del vector es "<<valor_max<<endl;
	
}

void valor_min(int *p[5])
{
	int valor_min = *p[0];
	
	for(int i=0;i<5;i++){
		
		if(valor_min> (*p[i]))
		{
			valor_min  = *p[i];
			
			
		} else{
			valor_min=valor_min;
		}
	}
	cout<<"El valor minimo del vector es "<<valor_min<<endl;
}

void sumatoria(int *p[5])
{
	int sumatoria = 0;
	for(int i=0;i<5;i++)
	{
		sumatoria =  sumatoria + *p[i];
		
	}
	cout<<"La sumatoria de los elementos del vector es "<<sumatoria<<endl;
}
