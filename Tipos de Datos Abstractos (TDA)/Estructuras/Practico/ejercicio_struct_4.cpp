#include <iostream>
#include <string>
using namespace std;

struct direccion{
	string direc;
};
struct fecha_nac{
	string fecha;
};
struct Persona{
	string nombre;
	string apellido;
	int telefono;
	struct fecha_nac f;
	struct direccion d;
};



int main(int argc, char *argv[]) {
	struct Persona p[5];
	for(int i=0;i<5;i++){
	cout<<"Ingrese el nombre "<<endl;
	cin>>p[i].nombre;
	cout<<"Ingrese el apellido "<<endl;
	cin>>p[i].apellido;
	cout<<"Ingrese el nro de telefono"<<endl;
	cin>>p[i].telefono;
	cout<<"Ingrese la fecha de nacimiento"<<endl;
	getline(cin,p[i].f.fecha,'.');
	cout<<"Ingrese la direecion"<<endl;
	getline(cin,p[i].d.direc,'.');
	}
	for(int x=0;x<5;x++){
	cout<<"El nombre es "<<p[x].nombre<<endl;
	cout<<"El apellido es "<<p[x].apellido<<endl;
	cout<<"El numero de telefono es "<<p[x].telefono<<endl;
	cout<<"La fecha de nacimiento es "<<p[x].f.fecha<<endl;
	cout<<"La direccion es "<<p[x].d.direc<<endl;
	}
	return 0;
}

