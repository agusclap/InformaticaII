#include <iostream>
using namespace std;

struct Empleado
{
	int legajo;
	string trabajo;
	int sueldo;
	int antiguedad;
};

void actualizar_sueldo(struct Empleado[3]);
void buscar_legajo(struct Empleado[3]);
void ordenar_sueldo(struct Empleado[3]);
void ordenar_antiguedad(struct Empleado[3]);

int main(int argc, char *argv[]) {
	struct Empleado e[3];
	char opcion, seguir = ' ';
	do{
	cout<<"MENU DE OPCIONES:"<<endl;
	cout<<"a) Agregar un empleado [maximo 3]"<<endl;
	cout<<"b) Mostrar todos los empleados"<<endl;
	cout<<"c) Buscar un empleado por legajo"<<endl;
	cout<<"d) Actualizar Sueldo"<<endl;
	cout<<"e) Ordenar por sueldo"<<endl;
	cout<<"f) Ordenar por antiguedad"<<endl;
	cin>>opcion;
	switch(opcion)
	{
	case 'a':
		for(int i=0;i<3;i++){
		cout<<"Ingrese el legajo"<<endl;
		cin>>e[i].legajo;
		cout<<"Ingrese el puesto de trabajo"<<endl;
		cin>>e[i].trabajo;
		cout<<"Ingrese el sueldo"<<endl;
		cin>>e[i].sueldo;
		cout<<"Ingrese la antiguedad"<<endl;
		cin>>e[i].antiguedad;
		}
		
		break;
	case 'b':
		for(int i=0;i<3;i++)
		{
			cout<<" Empleado "<<i<<":"<<endl;
			cout<<"Legajo: "<<e[i].legajo<<endl;
			cout<<"Puesto de trabajo: "<<e[i].trabajo<<endl;
			cout<<"Sueldo: "<<e[i].sueldo<<endl;
			cout<<"Antiguedad: "<<e[i].antiguedad<<" años"<<endl;
		}
		break;
	case 'c':
		buscar_legajo(e);
		break;
	case 'd':
		actualizar_sueldo(e);
		break;
	case 'e':
		ordenar_sueldo(e);
		break;
	case 'f':
		ordenar_antiguedad(e);
		break;
	default:
		
		cout<<"Ingrese una opcion correcta"<<endl;
		
		
	}
	cout<<"Quiere continuar con el programa"<<endl;
	cin>>seguir;
	}while(seguir=='y' || seguir=='Y');
	return 0;
	}

void buscar_legajo(struct Empleado e[3])
	{
		int legajo = 0;
		cout<<"Ingrese el legajo del empleado"<<endl;
		cin>>legajo;
		for(int i=0;i<3;i++)
		{
			if(legajo==e[i].legajo)
			{
				cout<<" Empleado "<<i<<":"<<endl;
				cout<<"Legajo: "<<e[i].legajo<<endl;
				cout<<"Puesto de trabajo: "<<e[i].trabajo<<endl;
				cout<<"Sueldo: "<<e[i].sueldo<<endl;
				cout<<"Antiguedad: "<<e[i].antiguedad<<" años"<<endl;
				
			}
			
			
		}
		
	}
void actualizar_sueldo(struct Empleado e[3])
{
	int legajo=0;
	cout<<"Ingrese el legajo"<<endl;
	cin>>legajo;
	for(int i=0;i<3;i++)
	{
		if(e[i].legajo==legajo)
		{
			int sueldo;
			cout<<"Ingrese el sueldo nuevo"<<endl;
			cin>>sueldo;
			e[i].sueldo = sueldo;
		}
		
	}
	
	
}
void ordenar_sueldo(struct Empleado e[3])
{
	int sueldo = 0;
	sueldo = e[0].sueldo;
	if(e[0].sueldo<e[1].sueldo)
	{sueldo=e[0].sueldo;
	e[0].sueldo=e[1].sueldo;
	e[1].sueldo =sueldo;
	}
	if(e[0].sueldo<e[2].sueldo)
	{sueldo=e[0].sueldo;
	e[0].sueldo=e[2].sueldo;
	e[2].sueldo=sueldo;
	}
	if(e[1].sueldo<e[2].sueldo)
	{sueldo=e[1].sueldo;
	e[1].sueldo=e[2].sueldo;
	e[2].sueldo=sueldo;
	}
	for(int i=0;i<3;i++)
	{
		cout<<" Empleado "<<i<<":"<<endl;
		cout<<"Legajo: "<<e[i].legajo<<endl;
		cout<<"Puesto de trabajo: "<<e[i].trabajo<<endl;
		cout<<"Sueldo: "<<e[i].sueldo<<endl;
		cout<<"Antiguedad: "<<e[i].antiguedad<<" años"<<endl;
	}
}
void ordenar_antiguedad(struct Empleado e[3])
{
	int ant = 0;
	ant = e[0].antiguedad;
	if(e[0].antiguedad<e[1].antiguedad)
	{ant=e[0].antiguedad;
	e[0].antiguedad=e[1].antiguedad;
	e[1].antiguedad =ant;
	}
	if(e[0].antiguedad<e[2].antiguedad)
	{ant=e[0].antiguedad;
	e[0].antiguedad=e[2].antiguedad;
	e[2].antiguedad=ant;
	}
	if(e[1].antiguedad<e[2].antiguedad)
	{ant=e[1].antiguedad;
	e[1].antiguedad=e[2].antiguedad;
	e[2].antiguedad=ant;
	}
	for(int i=0;i<3;i++)
	{
		cout<<" Empleado "<<i<<":"<<endl;
		cout<<"Legajo: "<<e[i].legajo<<endl;
		cout<<"Puesto de trabajo: "<<e[i].trabajo<<endl;
		cout<<"Sueldo: "<<e[i].sueldo<<endl;
		cout<<"Antiguedad: "<<e[i].antiguedad<<" años"<<endl;
	}
}
