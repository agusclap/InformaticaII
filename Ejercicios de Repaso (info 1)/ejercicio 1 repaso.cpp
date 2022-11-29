#include <iostream>
#include <ctime>
using namespace std;

void mostrar_factura(int matriz[10][6]);
int mostrar_recaudacion(int matriz[10][6]);
void mostrar_consumio(int matriz[10][6]);
void mostrar_matriz(int matriz[10][6]);
void cargar_matriz(int matriz[10][6]);
int calcular_recargo(int gb, int dia);

int main(int argc, char *argv[]) {
	int matriz[10][6];
	srand(time(NULL));
	char respuesta,seguir = ' ';
	cargar_matriz(matriz);
	do{
		cout<<"MENU DE OPCIONES:"<<endl;
		cout<<"a) Mostrar la factura del cliente"<<endl;
		cout<<"b) Mostrar la recaudacion de la empresa"<<endl;
		cout<<"c) Mostrar el cliente que mas ha consumido"<<endl;
		cout<<"d) Mostrar el consumo y las facturas de los clientes"<<endl;
		cin>>respuesta;
		switch(respuesta)
		{
		case 'a':
			mostrar_factura(matriz);
			
			break;
		case 'b':
			cout<<"La recaudacion total es "<<mostrar_recaudacion(matriz)<<endl;
			break;
		case 'c':
			mostrar_consumio(matriz);
			break;
		case 'd':
			mostrar_matriz(matriz);
			break;
		default:
			cout<<"La opcion que ingreso no es valida"<<endl;
		}
		cout<<"Desea continuar ? y/n"<<endl;
		cin>>seguir;
	}while(seguir=='y' || seguir=='Y');
	
	return 0;
}

void cargar_matriz(int matriz[10][6])
{
	int costo,gb,dia=0;
	
	
	for(int i=0;i<10;i++)
	{
		gb= rand()%100;
		dia= 1+rand()%31;
		matriz[i][0]= i+1;
		matriz[i][1]= gb;
		matriz[i][3]= dia;
		matriz[i][4]= calcular_recargo(gb, dia);
		costo = gb * 1000;
		matriz[i][2]= costo;
		matriz[i][5] = matriz[i][4] + matriz[i][2];
	}
	
}

int calcular_recargo(int gb, int dia)
{
	int recargo=0;
	if (dia >= 10)
	{
		recargo=(dia-10)*100;
	}else{
		recargo=0;
	}
	return recargo;
	
}

void mostrar_factura(int matriz[10][6]){
	int n=0;
	cout<<"Ingrese el codigo del cliente"<<endl;
	cin>>n;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(matriz[i][0]==n){
			cout<<matriz[i][j]<<"\t";
			}
		}
		
	}
}


int mostrar_recaudacion(int matriz[10][6])
{
	int recaudacion=0;
	for(int i=0;i<10;i++)
	{
		recaudacion = recaudacion + matriz[i][5];
	}
	
	return recaudacion;
}

void mostrar_consumio(int matriz[10][6])
{
	int mayor = 0;
	mayor= matriz[0][1];
	for(int i=1;i<10;i++)
	{
		if(matriz[i][1] > matriz[0][1])
		{
			mayor= matriz[i][1];
			
		} 
		
		
	}
	for(int j=0;j<10;j++)
	{
		
			if(matriz[j][1] == mayor)
			{
				for(int i=0;i<10;i++)
				{
					for(int ii=0;ii<6;ii++)
					{
						cout<<""<<matriz[i][ii]<<"\t";
					}
					cout<<endl;
				}
				
			}
		
	}
}

void mostrar_matriz(int matriz[10][6])
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<6;j++)
		{
			cout<<matriz[i][j]<<"\t";
			
		}
		cout<<endl;
	}
}
