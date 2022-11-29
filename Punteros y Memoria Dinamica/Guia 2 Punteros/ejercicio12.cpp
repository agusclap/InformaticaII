#include <iostream>
using namespace std;

void cantidad_saldos(int *p[10], int cantidad);
float promedio_sueldos(int *p[10], int );
void saldos_menores(int *p[10], int, int);
void saldos_mayores(int *p[10], int , int);
int recaudacion(int *p[10], int);

int main(int argc, char *argv[]) {
	
	int saldos[10] = {0};
	int *p[10] = {NULL};
	int cantidad = 0;
	int saldo,recaudado = 0;
	float promedio = 0;
	char opcion,seguir = ' ';
	for(int i=0;i<10;i++){
		cout<<"Ingrese el saldo del proveedor "<<i<<endl;
		cin>>saldo;
		if(saldo <= 0){
			
			break;
		} else{
		saldos[i] = saldo;
		p[i] = &saldos[i];
		cantidad++;}
	}
	cantidad--;
	do{
		cout<<"MENU DE OPCIONES: "<<endl;
		cout<<"a) Cantidad de saldos cargados"<<endl;
		cout<<"b) Promedio de los saldos"<<endl;
		cout<<"c) Cantidad de saldos menores al promedio"<<endl;
		cout<<"d) Cantidad de saldos mayores al promedio"<<endl;
		cout<<"e) Calcular cuanto fue lo recaudado en el mes"<<endl;
		cin>>opcion;
		switch(opcion)
		{
		case 'a':
			cantidad_saldos(p,cantidad);
			break;
		case 'b':
			promedio = promedio_sueldos(p,cantidad);
			cout<<"El promedio es "<<promedio<<endl;
			break;
		case 'c':
			saldos_menores(p, cantidad, promedio);
			break;
		case 'd':
			saldos_mayores(p, cantidad, promedio);
			break;
		case 'e':
			recaudado=recaudacion(p, cantidad);
			cout<<"La cantidad recaudada es "<<recaudado<<endl;
			break;
		default:
			cout<<"Ingrese una opcion correcta :)"<<endl;
		}
		cout<<"Desea continuar con el programa y/n"<<endl;
		cin>>seguir;
	} while(seguir=='y' || seguir=='Y');
	
	
	cout<<*p[1];
	return 0;
}

void cantidad_saldos(int *p[10], int cantidad)
{
	cout<<"La cantidad de saldos es "<<cantidad<<endl;
}

float promedio_sueldos (int *p[10], int cantidad)
{
	int promedio,suma=0;
	for(int i=0;i<cantidad;i++)
	{
		suma = suma + *p[i];
		
		
	}
	promedio = suma/cantidad;
	return promedio;
}

void saldos_menores(int *p[10], int cantidad, int promedio)
{
	int cont=0;

	for(int i=0;i<cantidad;i++)
	{
		if(*p[i] < promedio)
		{
			cont++;
		}
		
	}
	cout<<"La cantidad de saldos menores al promedio es "<<cont<<endl;
}

void saldos_mayores(int *p[10], int cantidad, int promedio)
{
	
	int cont = 0;
	for(int i=0;i<cantidad;i++)
	{
		if(*p[i]>promedio)
		{
			cont++;
			
		}
		
		
	}
	cout<<"La cantidad de saldos mayores al promedio es "<<cont<<endl;
}

int recaudacion (int *p[10],int cantidad)
{
	int sumatoria=0;
	for(int i=0;i<cantidad;i++)
	{
		sumatoria = sumatoria + *p[i];
		
	}
	return sumatoria;
}
