#include <iostream>
#include <ctime>
using namespace std;

void cargar_matriz(int matriz[10][6]);
void mostrar_factura(int matriz[10][6]);
int calcular_rec(int matriz[10][6]);
void calcular_exp(int matriz[10][6]);



int main(int argc, char *argv[]) {
	
	int matriz[10][6] = {0};
	cargar_matriz(matriz);
	int recaudacion = 0;
	char opcion, seguir = ' ';
	do{
		cout<<"MENU DE OPCIONES:"<<endl;
		cout<<"a) Mostrar factura de un residente"<<endl;
		cout<<"b) Mostrar recaudacion"<<endl;
		cout<<"c) Mostrar el residente que pago mas expensas"<<endl;
		cout<<"d) Mostrar todas las facturas emitidas"<<endl;
		cin>>opcion;
		switch(opcion)
		{
		case 'a':
			mostrar_factura(matriz);
			break;
		case 'b':
			recaudacion = calcular_rec(matriz);
			cout<<"La recaudacion total es "<<recaudacion<<endl;
			break;
		case 'c':
			calcular_exp(matriz);
			break;
		case 'd':
			
			for (int i=0;i<10;i++)
			{
				for(int j=0;j<6;j++)
				{
					
					cout<<""<<matriz[i][j]<<"\t";
					
				}
				cout<<"\n"<<endl;
			}
			break;
		default:
			cout<<"Ingrese una opcion valida"<<endl;
		}
		cout<<"Desea continuar ? y/n"<<endl;
		cin>>seguir;
	}while(seguir=='y' || seguir=='Y');
	
	return 0;
}

void cargar_matriz(int matriz[10][6])
{
	srand(time(NULL));
	
	for (int i=0;i<10;i++)
	{
		matriz[i][0] = i+1;
		matriz[i][1] = 30 + rand()%500;
		matriz[i][2] = matriz[i][1] * 50;
		matriz[i][3] = 1 + rand()%31;
		if (matriz[i][3] > 10)
		{
			matriz[i][4] = matriz[i][3] * 100;
			
		} else {
			
			matriz[i][4] = 0;
			
		}
		
		matriz[i][5] = matriz[i][2] + matriz[i][4];
	}
	
	
}
void mostrar_factura(int matriz[10][6])
{
	int codigo = 0;
	cout<<"Ingrese el codigo del cliente"<<endl;
	cin>>codigo;
	for(int i=0;i<10;i++)
	{
		if(matriz[i][0] == codigo){
			
			for (int j=0;j<6;j++)
			{
				
				cout<<""<<matriz[i][j]<<"\t";
				
			}
			cout<<"\n"<<endl;
		}
		
	}
	
	
}

int calcular_rec(int matriz[10][6])
{
	int rec=0;
	for (int i =0;i<10;i++)
	{
		rec = rec + matriz[i][5];
		
	}
	return rec;
	
}

void calcular_exp(int matriz[10][6])
{
	
	int mayor=0;
	
	mayor = matriz[0][2];
	
	for(int i=0;i<10;i++)
	{
		if(mayor<matriz[i][2])
		{
			
			mayor = matriz[i][2];
			
		}
	}
	
	cout<<"El residente que pago mas expensas es "<<endl;
	
	for (int j=0;j<10;j++)
	{
		if (mayor==matriz[j][2])
		{
			for (int k=0;k<6;k++)
			{
				
				cout<<""<<matriz[j][k]<<"\t";
				
			}
			
			cout<<"\n"<<endl;
		}
		
		
	}
}
