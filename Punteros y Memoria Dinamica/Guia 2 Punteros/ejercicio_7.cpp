#include <iostream>
using namespace std;
// 7. Desarrolle un programa que declare e inicialice un vector de 5 valores (4.5,8,2.3,1.1,3). 
//Luego, se pide que calcule y muestre la sumatoria y el promedio. Utilice punteros para realizar el ejercicio.


int main(int argc, char *argv[]) {
	float vector[5] = {4.5,8,2.3,1.1,3};
	float *ptr[5];
	float sumatoria,promedio = 0;
	for (int i = 0;i<5;i++)
	{
		ptr[i] = &vector[i];
	}
	cout<<"Calcular sumatoria y el promedio.."<<endl;
	
	for (int ii=0;ii<5;ii++)
	{
		sumatoria = sumatoria + (*ptr[ii]) ;
		
	}
	promedio = sumatoria/5.0;
	cout<<"La sumatoria total del vector es "<<sumatoria<<endl;
	cout<<"El promedio de la sumatoria total del vector es "<<promedio<<endl;
	return 0;
}

