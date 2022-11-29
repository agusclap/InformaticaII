#include <iostream>
using namespace std;

void mostrar(char *,int,int);

int main(int argc, char *argv[]) {
	
	char n=' ';
	char *p=NULL;
	int cantidad,cantidad1 = 0;
	cout<<"Ingrese la cantidad de valores a ingresar"<<endl;
	cin>>cantidad;
	p = (char *) malloc(cantidad*sizeof(char));
	if(p==NULL)
	{
		cout<<"No hay memoria disponible"<<endl;
		
	} else{
		
		for(int i=0;i<cantidad;i++)
		{
			cout<<"Ingrese el elemento: "<<i<<endl;
			cin>>n;
			*(p+i)=n;
			
		}
		mostrar(p,cantidad,cantidad1);
		
	}
	cout<<"Cuantos elementos quiere agregar "<<endl;
	cin>>cantidad1;
	p= (char *) realloc(p,cantidad1*sizeof(char));
	if(p==NULL)
	{
		cout<<"No hay suficiente memoria"<<endl;
	} else{
		char valor1=' ';
		for (int i=0;i<cantidad1;i++)
		{
			cout<<"Ingrese los elementos nuevos a agregar"<<endl;
			cin>>valor1;
			*(p+i+cantidad) = valor1;
			
		}
		mostrar(p,cantidad,cantidad1);
	}
	free(p);
	return 0;
}
 
  

void mostrar(char *p, int cantidad, int cantidad1)
{
	int cant = cantidad+cantidad1;
	for(int i=0;i<cant;i++)
	{
		
		cout<<"Valores ingresados: "<<*(p+i)<<endl;
		
	}
	
	
}
