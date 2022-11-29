/* 11. Un negocio de paqueter�a con entregas a domicilio nos ha solicitado un programa 
para almacenar datos sobre las calles y las viviendas de su Ciudad. 
Cada calle se identificar� por dos elementos: Nombre y viviendas que tiene.
 Adem�s, cada vivienda estar� identificada por el n�mero que ocupa en la calle y la planta. 
Admitiendo que la ciudad tiene 5 calles y cada calle tiene cinco viviendas, 
desarrollar un programa que permita al usuario: 

a.  Almacenar los datos sobre las calles y las viviendas de la ciudad.

b. Ver toda la informaci�n sobre una calle: n�mero y viviendas que tiene */


#include <iostream>
#include <string>
using namespace std;

struct Vivienda{
	int num;
	int planta;
};
struct Calle {
	string nombre;
	int cant;
};
struct Ciudad{
	
	struct Calle c;
	struct Vivienda v[5];
};

int main(int argc, char *argv[]) {
	struct Ciudad cd[5];
	
	for( int i=0;i<5;i++)
	{
		cout<<"Ingrese el nombre de la calle"<<endl;
		cin>>cd[i].c.nombre;
		cout<<"Ingrese la cantidad de viviendas en esa calle"<<endl;
		cin>>cd[i].c.cant;
		for(int j=0;j<5;j++){
			cout<<"Ingrese el numero con el que se identifica la vivienda"<<endl;
			cin>>cd[i].v[j].num;
			cout<<"Ingrese la planta de la vivienda"<<endl;
			cin>>cd[i].v[j].planta;
		}
		
		
	}
	string cal;
	cout<<"Ingrese el nombre de la calle"<<endl;
	cin>>cal;
	for(int ii=0;ii<5;ii++)
	{
		if(cal.compare(cd[ii].c.nombre)==0){
		cout<<"Calle: "<<cd[ii].c.nombre<<"\tCantidad: "<<cd[ii].c.cant;
		for(int jj=0;jj<5;jj++)
		{
			cout<<"\tNum: "<<cd[ii].v[jj].num<<"\tPlanta: "<<cd[ii].v[jj].planta<<endl;
		}
		}
		
		
	}
	return 0;
}

