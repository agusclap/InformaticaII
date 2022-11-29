#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int n1,n2,n3 = 0;
	float promedio=0;
	cout<<"Ingrese las notas para promediar n1"<<endl;
	cin>>n1;
	cout<<"Ingrese las notas para promediar n2"<<endl;
	cin>>n2;
	cout<<"Ingrese las notas para promediar n3"<<endl;
	cin>>n3;
	promedio = (n1+n2+n3)/3.0;
	cout<<"El promedio es: "<<promedio;
	return 0;
}

