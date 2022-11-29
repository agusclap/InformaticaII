#include <iostream>
using namespace std;

void cargar(char *, int,char);
void mostrar(char *, int);
void mostrar_inverso(char *, int);

int main(int argc, char *argv[]) {
	char *p = NULL;
	int cantidad=0;
	char valor = ' ';
	cout<<"Ingrese la cantidad de valores a ingresar"<<endl;
	cin>>cantidad;
	p = (char *) malloc(cantidad*sizeof(char));
	cargar(p,cantidad,valor);
	mostrar(p,cantidad);
	mostrar_inverso(p,cantidad);
	free(p);
	return 0;
}

void cargar(char *p, int cantidad, char valor)
{
	
	for(int i=0;i<cantidad;i++)
	{
		cout<<"Ingrese el elemento: "<<i<<endl;
		cin>>valor;
		*(p+i) = valor;
		
		
	}
	
}

void mostrar(char *p, int cantidad)
{
	cout<<"Valores en orden"<<endl;
	for(int i=0;i<cantidad;i++)
	{
		
		cout<<"Valores ingresados: "<<*(p+i)<<endl;
		
	}
	
}

void mostrar_inverso(char *p, int cantidad)
{
	int cont=0;
	cout<<"Valores en orden inverso"<<endl;
	for (int ii=cantidad;ii>0;ii--)
	{
		cont++;
		cout<<"Valores ingresados: "<<*(p+cantidad-cont)<<endl;
		
	}
	
}
