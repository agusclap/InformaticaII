#include <iostream>
#include <math.h>
using namespace std;

/* Escribir un programa que solicite tres numeros y luego crear una/s funcion/es
teniendo en cuenta que si el numero es par que lo eleve a el numero que ingrese
el cliente y si es impar directamente elevar el numero a la quinta */

int calcular(int *, int *, int *);

int main(int argc, char *argv[]) {
	int n1,n2,n3, resultado = 0;
	char seguir = ' ';
	do{
	cout<<"Ingrese tres numeros"<<endl;
	cin>>n1;
	cin>>n2;
	cin>>n3;
	resultado = calcular(&n1,&n2,&n3);
	cout<<"El numero elevado es "<<resultado<<endl;
	cout<<"Desea continuar ? y/n"<<endl;
	cin>>seguir;
	}while(seguir=='y' || seguir=='Y');
	return 0;
}

int calcular( int *n1, int *n2, int *n3)
{
	int numero,pot = 0;
	cout<<"Cual numero quiere elevar? 1, 2 o 3"<<endl;
	cin>>numero;
	if(numero==1)
	{
		if(((*n1)%2)!= 0)
		{
			pot = pow((*n1), 5);
			
			
		} else{
			cout<<"Ingrese la potencia a la cual quiere elevar el numero"<<endl;
			cin>>pot;
			pow((*n1), pot);
		}
		
	}
	if(numero==2)
	{
		if(((*n2)%2)!= 0)
		{
			pot = pow((*n2),5);
			
		} else{
			cout<<"Ingrese la potencia a la cual quiere elevar el numero"<<endl;
			cin>>pot;
			pow((*n2), pot);
		}
		
	}
	if(numero==3)
	{
		if(((*n3)%2)!= 0)
		{
			pot = pow((*n3),5);
			
		} else{
			cout<<"Ingrese la potencia a la cual quiere elevar el numero"<<endl;
			cin>>pot;
			pow((*n3), pot);
		}
		
	}
	return pot;
}
