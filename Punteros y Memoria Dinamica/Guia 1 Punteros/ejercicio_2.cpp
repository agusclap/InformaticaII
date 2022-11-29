#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int a=777;
	int *p=&a;
	cout<<"La direccion de memoria de la variable es: "<<&a<<endl;
	cout<<"El valor que almacena la variable es: "<<a<<endl;
	cout<<"El valor del puntero es: "<<p<<endl;
	cout<<"El valor al que apunta el puntero: "<<*p<<endl;
	
	return 0;
}

