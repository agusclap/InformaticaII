#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
	int cantidad,valor = 0;
	int *p=NULL;
	cout<<"Ingrese la cantidad de elementos"<<endl;
	cin>>cantidad;
	p= (int *) malloc(cantidad*4);
	if(p==NULL)
	{
		cout<<"No hay memoria disponible"<<endl;
	} else{
		for (int i=0;i<cantidad;i++)
		{
			cout<<"Ingrese el elemento "<<i<<endl;
			cin>>valor;
			*(p+i)  = valor;
		}
		for(int ii=0;ii<cantidad;ii++)
		{
			cout<<"Valores ingresados: "<<*(p+ii)<<endl;
			
		}
	}
	free(p);
	return 0;
}

