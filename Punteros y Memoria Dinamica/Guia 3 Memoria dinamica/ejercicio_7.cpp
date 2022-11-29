#include <iostream>
using namespace std;
/*7. Crear un programa que pregunte al usuario cuántos caracteres desea introducir, 
reserve espacio para dicho número de caracteres, le permita al usuario introducirlos 
desde teclado y luego mostrar por pantalla los valores. Luego, 
el programa pregunta cuántos caracteres desea agregar a la lista de elementos ya introducida,
agrega espacio de memoria y solicita el ingreso de los nuevos valores. Por último, mostrar la lista resultante. Utilizar funciones.
*/

void cargar(char *p, int , int *, char);
void mostrar(char *p, int , int *);
void agregar(char *p, int, int * , char);
int main(int argc, char *argv[]) {
	
	char *p=NULL;
	char valor =' ';
	int cantidad,cantidad1 = 0;
	cout<<"Ingrese la cantidad de valores a ingresar"<<endl;
	cin>>cantidad;
	p = (char *) malloc(cantidad*sizeof(char));
	if(p==NULL)
	{
		
		cout<<"No hay memoria disponible"<<endl;
		exit(0);
	}
	cargar(p,cantidad,&cantidad1,valor);
	mostrar(p,cantidad,&cantidad1);
	agregar(p,cantidad,&cantidad1,valor);
	mostrar(p,cantidad,&cantidad1);
	free(p);
	return 0;
}

void cargar(char *p, int cantidad, int *cantidad1, char valor)
{
	int cant = cantidad + *cantidad1;
	for(int i=0;i<cant;i++)
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

void mostrar(char *p, int cantidad, int *cantidad1)
{
	int cant = (cantidad + *cantidad1);
	for(int i=0;i<cant;i++)
	{
		cout<<"Valores ingresados: "<<*(p+i)<<endl;
		
	}
	
}
void agregar(char *p, int cantidad, int *cantidad1,char valor)
{
	cout<<"Ingrese la nueva cantidad de elementos a agregar"<<endl;
	cin>>*cantidad1;
	p = (char *) realloc(p,(*cantidad1)*sizeof(char));
	if(p==NULL)
	{
		
		cout<<"No hay memoria disponible"<<endl;
		exit(0);
	}
	for(int i=0;i<*cantidad1;i++)
	{
		cout<<"Ingrese el nuevo elemento a agregar"<<endl;
		cin>>valor;
		*(p+cantidad+i) = valor;
		
	}
	
	
}
