#include <iostream>
using namespace std;

void cargar(int *p, int, int, int*  );
void agregar(int *p, int, int *, int);
void mostrar(int *p, int  , int *  );

int main(int argc, char *argv[]) {
	int *p=NULL;
	char opcion,seguir = ' ';
	int cantidad,valor=0;
	int cantidad1=0;
	do{
	cout<<"MENU DE OPCIONES"<<endl;
	cout<<"a) Reservar memoria e introducir datos enteros"<<endl;
	cout<<"b) Agregar reserva de memoria e introducir nuevos datos enteros"<<endl;
	cout<<"c) Mostrar los datos en orden y orden inverso"<<endl;
	cin>>opcion;
	switch(opcion)
	{
	case 'a':
		cout<<"Ingrese la cantidad de elementos a ingresar"<<endl;
		cin>>cantidad;
		p=(int *) malloc(cantidad*sizeof(int));
		if(p==NULL)
		{
			
			cout<<"No hay memoria disponible"<<endl;
			exit(0);
		}
		cargar(p,cantidad,valor,&cantidad1);
		break;
	case 'b':
		agregar(p,cantidad,&cantidad1,valor);
		break;
	case 'c':
		mostrar(p,cantidad,&cantidad1);
		break;
	default: 
		cout<<"Ingrese la opcion correcta"<<endl;
	}
	cout<<"Desea continuar con el programa? y/n"<<endl;
	cin>>seguir;
	}while(seguir=='y' || seguir=='Y');
	free(p);
	return 0;
}

void cargar(int *p, int cantidad, int valor, int *cantidad1)
{
	int cant = cantidad + *cantidad1;
	cout<<*cantidad1;
	for (int i=0;i<cant;i++)
	{
		cout<<"Ingrese el elemento: "<<i<<endl;
		cin>>valor;
		if(cant==cantidad){
			*(p+i) = valor;
		}else if(cant>cantidad){
			*(p+cantidad+i) = valor;
		}
	} 
	
}

void agregar(int *p, int cantidad, int *cantidad1, int valor)
{
	valor = 0;
	cout<<"Ingrese la cantidad nueva a agregar"<<endl;
	cin>>*cantidad1;
	p = (int *) realloc(p,(*cantidad1)*sizeof(int));
	if(p==NULL)
	{
		
		cout<<"No hay memoria disponible"<<endl;
		exit(0);
	}
	for(int i=0;i<*cantidad1;i++)
	{
		cout<<"Ingrese el valor nuevo a agregar"<<endl;
		cin>>valor;
		*(p+cantidad+i) = valor;
	}
}

void mostrar(int *p, int cantidad, int *cantidad1)
{
	int cant = (cantidad + *cantidad1);
	for(int i=0;i<cant;i++)
	{
		cout<<"Los valores ingresados son: "<<*(p+i)<<endl;
		
	}
	for(int ii=cant;ii>0;ii--)
	{
		cout<<"Los valores en orden reverso son: "<<*(p+ii-1)<<endl;
		
	}
	
	
}
