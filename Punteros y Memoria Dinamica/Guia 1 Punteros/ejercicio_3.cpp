#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int a = 777;
	int *p=&a;
	
	cout<<"Direccion de la variable: "<<&a<<endl;
	cout<<"Valor de la variable: "<<a<<endl;
	cout<<"Valor del puntero : "<<p<<endl;
	cout<<"Valor al que apunta el puntero: "<<*p<<endl;
	return 0;
}

