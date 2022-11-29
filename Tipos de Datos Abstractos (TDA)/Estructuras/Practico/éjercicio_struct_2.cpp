#include <iostream>
using namespace std;

void agregar(struct estructura[3], int *);
void mostrar(struct estructura[3], int);
void buscar(struct estructura[3], int);

struct estructura{
	string artista;
	string Titulo;
	int duracion;
	int tamanio;
	
	
};


int main(int argc, char *argv[]) {
	struct estructura p[3];
	int cant=0;
	char opcion,seguir = ' ';
	do{
	cout<<"MENU DE OPCIONES:"<<endl;
	cout<<"a) Agregar una nueva cancion"<<endl;
	cout<<"b) Mostrar todas las canciones"<<endl;
	cout<<"c) Buscar una cancion por titulo"<<endl;
	cin>>opcion;
	switch(opcion){
	case 'a':
		agregar(p,&cant);
		break;
	case 'b':
		mostrar(p,cant);
		break;
	case 'c':
		buscar(p,cant);
		break;
	default:
		cout<<"Ingrese una opcion correcta"<<endl;
	}
	cout<<"Desea continuar con el programa y/n"<<endl;
	cin>>seguir;
	}while(seguir=='y' || seguir=='Y');
	
	
	return 0;
}

void agregar(struct estructura p[3], int *cant)
{
	int cantidad = 0;
	cout<<"Cuantas canciones quiere agregar ( 3 como maximo)"<<endl;
	cin>>cantidad;
	*cant = cantidad;
	for(int i=0;i<cantidad;i++)
	{
		cout<<"Ingrese el artista"<<endl;
		cin>>p[i].artista;
		cout<<"Ingrese el titulo de la cancion"<<endl;
		cin>>p[i].Titulo;
		cout<<"Ingrese la duracion en segundos de la cancion"<<endl;
		cin>>p[i].duracion;
		cout<<"Ingrese el tamaño de la cancion en Kb"<<endl;
		cin>>p[i].tamanio;	
	}
}

void mostrar(struct estructura p[3],int cant)
{
	
	for(int x=0;x<cant;x++)
	{
		cout<<"El artista es "<<p[x].artista<<endl;
		cout<<"El titulo de la cancion es "<<p[x].Titulo<<endl;
		cout<<"La duracion es de "<<p[x].duracion<<" segundos"<<endl;
		cout<<"El tamaño de la cancion es de "<<p[x].tamanio<<" kilobytes"<<endl;	
		
		
	}
	
}
void buscar(struct estructura p[3], int cant)
{
	string cancion=" ";
	cout<<"Ingrese el titulo de la cancion "<<endl;
	cin>>cancion;
	
	for(int i=0;i<cant;i++)
	{
		if(p[i].Titulo==cancion)
		{
			cout<<"El artista es "<<p[i].artista<<endl;
			cout<<"El titulo de la cancion es "<<p[i].Titulo<<endl;
			cout<<"La duracion es de "<<p[i].duracion<<" segundos"<<endl;
			cout<<"El tamaño de la cancion es de "<<p[i].tamanio<<" kilobytes"<<endl;
			
		}
		
	}
}

	
	
