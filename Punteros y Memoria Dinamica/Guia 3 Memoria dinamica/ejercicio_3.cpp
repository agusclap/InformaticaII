#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	char n = ' ';
	char *p=NULL;
	int cantidad = 0;
	cout<<"Ingrese la cantidad de elementos char para ingresar"<<endl;
	cin>>cantidad;
	p = (char *) malloc(cantidad*sizeof(char));
	if(p==NULL)
	{
		cout<<"No hay memoria disponible"<<endl;
	} else
	{
		for(int i=0;i<cantidad;i++)
		{
			cout<<"Ingrese el caracter numero "<<endl;
			cin>>n;
			*(p+i)= n;
			
		} 
		for(int ii=0;ii<cantidad;ii++)
		{
			cout<<"Elemento cargados: "<<*(p+ii)<<endl;
			
		}
	}
	free(p);
	return 0;
}

