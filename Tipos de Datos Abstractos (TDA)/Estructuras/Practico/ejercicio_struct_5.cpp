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
	struct Persona p;
	string arreglo[3];
	int notas[3];
	cout<<"Ingrese el nombre "<<endl;
	cin>>p.nombre;
	cout<<"Ingrese el apellido "<<endl;
	cin>>p.apellido;
	cout<<"Ingrese el nro de telefono"<<endl;
	cin>>p.telefono;
	cout<<"Ingrese la fecha de nacimiento"<<endl;
	getline(cin,p.f.fecha,'.');
	cout<<"Ingrese la direecion"<<endl;
	getline(cin,p.d.direc,'.');
	cout<<"Ingrese la primera materia"<<endl;
	cin>>arreglo[0];
	cout<<"Ingrese la nota del final"<<endl;
	cin>>notas[0];
	cout<<"Ingrese la segunda materia"<<endl;
	cin>>arreglo[1];
	cout<<"Ingrese la nota del final"<<endl;
	cin>>notas[1];
	cout<<"Ingrese la tercera materia"<<endl;
	cin>>arreglo[2];
	cout<<"Ingrese la nota del final"<<endl;
	cin>>notas[2];
	
	cout<<"Nombre\tApellido\t    Tel\t   Fecha nac\t   Direcc\n";
	cout<<p.nombre<<"\t"<<p.apellido<<"\t"<<p.telefono<<"\t"<<p.f.fecha<<"\t"<<p.d.direc<<endl;
	for(int x=0;x<3;x++){
	cout<<"Materia:  "<<arreglo[x]<<"\tNota: "<<notas[x]<<endl;
	}
	return 0;
}

