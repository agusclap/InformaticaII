#include <iostream>
#include <ctime>
using namespace std;

struct Producto{
	
	int codigo;
	string nombre;
	int stock;
	int cantidad_vend;
};

void mostrar(struct Producto p[10], int);
void cargar(struct Producto p[10], int);
void reponer(struct Producto p[10], int);
void ordenar_vent(struct Producto p[10], int);
void ordenar_stock(struct Producto p[10], int);

int main(int argc, char *argv[]) {
	Producto p[10];
	srand(time(NULL));
	int cantidad = 0;
	cout<<"Ingrese un tamaño para el producto"<<endl;
	cin>>cantidad;
	for(int i=0;i<cantidad;i++)
	{
		p[i].codigo = i+1;
		cout<<"Ingrese el nombre del producto ("<<i+1<<")"<<endl;
		cin>>p[i].nombre;
		cout<<"Ingrese el stock del producto ("<<i+1<<")"<<endl;
		cin>>p[i].stock;
		cout<<"Ingrese cantidad vendida (si es que hay, sino ingrese 0) ("<<i+1<<")"<<endl;
		cin>>p[i].cantidad_vend;
		
	}
	char opcion,seguir = ' ';
	do{
		cout<<"MENU DE OPCIONES:"<<endl;
		cout<<"a) Mostrar todos los productos"<<endl;
		cout<<"b) Cargar una venta"<<endl;
		cout<<"c) Reponer mercaderia"<<endl;
		cout<<"d) Ordenar por productos mas vendidos"<<endl;
		cout<<"e) Ordenar por productos con menor stock"<<endl;
		cin>>opcion;
		switch(opcion)
		{
		case 'a':
			mostrar(p,cantidad);
			break;
		case 'b':
			cargar(p,cantidad);
			break;
		case 'c':
			reponer(p,cantidad);
			break;
		case 'd':
			ordenar_vent(p,cantidad);
			break;
		case 'e':
			ordenar_stock(p,cantidad);
			break;
		default:
			cout<<"Ingrese una opcion correcta"<<endl;
			
		}
		cout<<"Desea continuar con el programa? y/n"<<endl;
		cin>>seguir;
	} while(seguir=='y' || seguir=='Y');
	return 0;
}

void mostrar(struct Producto p[10],int cantidad)
{
	for(int i=0;i<cantidad;i++)
	{
		cout<<"Codigo: "<<p[i].codigo<<endl;
		cout<<"Nombre: "<<p[i].nombre<<endl;
		cout<<"Stock: "<<p[i].stock<<endl;
		cout<<"Cantidad Vendida:"<<p[i].cantidad_vend<<endl;
	}
}

void cargar(struct Producto p[10], int cantidad)
{
	int cant=0;
	int cod=0;
	cout<<"Ingrese la cantidad vendida"<<endl;
	cin>>cant;
	cout<<"Ingrese el codigo del producto"<<endl;
	cin>>cod;
	for(int i=0;i<cantidad;i++)
	{
		if(cod==p[i].codigo)
		{
			p[i].cantidad_vend = p[i].cantidad_vend + cant;
			
		} 
		
	}
}

void reponer(struct Producto p[10], int cantidad)
{
	int rep,cod=0;
	
	cout<<"Ingrese el codigo del producto"<<endl;
	cin>>cod;
	cout<<"Ingrese la cantidad a reponer"<<endl;
	cin>>rep;
	for(int i=0;i<cantidad;i++){
		if(p[i].codigo == cod)
		{
			p[i].stock = p[i].stock + rep;
		} 
		
	}
	
	
}

void ordenar_vent(struct Producto p[10], int cantidad)
{
	for(int i=0;i<(2*cantidad);i++)
	{
		if(p[i+1].cantidad_vend>p[i].cantidad_vend)
		{
			p[i].cantidad_vend = p[i+1].cantidad_vend;
			p[i].codigo = p[i+1].codigo;
			p[i].stock = p[i+1].stock;
			p[i].nombre = p[i+1].nombre;
			
		}
		
		
	}
	for( int ii=0;ii<cantidad;ii++)
	{
		cout<<"Codigo: "<<p[ii].codigo<<endl;
		cout<<"Nombre: "<<p[ii].nombre<<endl;
		cout<<"Stock: "<<p[ii].stock<<endl;
		cout<<"Cantidad Vendida:"<<p[ii].cantidad_vend<<endl;
		
		
	}
	
}
void ordenar_stock(struct Producto p[10], int cantidad)
{
	for(int i=0;i<(2*cantidad);i++)
	{
		if(p[i+1].stock>p[i].stock)
		{
			p[i].cantidad_vend = p[i+1].cantidad_vend;
			p[i].codigo = p[i+1].codigo;
			p[i].stock = p[i+1].stock;
			p[i].nombre = p[i+1].nombre;
			
		}
		
		
	}
	
	for( int ii=0;ii<cantidad;ii++)
	{
		cout<<"Codigo: "<<p[ii].codigo<<endl;
		cout<<"Nombre: "<<p[ii].nombre<<endl;
		cout<<"Stock: "<<p[ii].stock<<endl;
		cout<<"Cantidad Vendida:"<<p[ii].cantidad_vend<<endl;
		
		
	}
	
}
