#include <iostream>
#define TAMANIO_MUESTRA 10
using namespace std;

struct Medidas {
	float longitud;
	float diametro;
};

int main(int argc, char *argv[]) {
	struct Medidas m[TAMANIO_MUESTRA];
	float acum_longitud =0;
	float acum_diametro = 0;
	for(int i=0;i<TAMANIO_MUESTRA;i++)
	{
		cout<<"Ingrese la longitud del tornillo"<<endl;
		cin>>m[i].longitud;
		cout<<"Ingrese el diametro del tornillo"<<endl;
		cin>>m[i].diametro;
		
	}
	cout<<"La media de la longitud y el diametro es:"<<endl;
	for(int ii=0;ii<TAMANIO_MUESTRA;ii++)
	{
		acum_longitud = acum_longitud + m[ii].longitud;
		acum_diametro = acum_diametro + m[ii].diametro;
		
		
	}
	float media_longitud =(acum_longitud/TAMANIO_MUESTRA);
	float media_diametro = (acum_diametro/TAMANIO_MUESTRA);
	cout<<"Longitud: "<<media_longitud<<endl;
	cout<<"Diametro: "<<media_diametro<<endl;
	return 0;
}

