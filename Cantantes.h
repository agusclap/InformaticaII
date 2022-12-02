#include <iostream>
using namespace std;
// Dinero recaudado = cantidad de conciertos * audiencia;
class Cantantes{

private:
string nombre;
int edad;
int cantidad_discos;
string genero;
int cantidad_conciertos;
int audiencia;
int dinero;
public:
void setNombre(string n);
string getNombre();
void setEdad(int e);
int getEdad();
void setCant_discos(int c);
int getCant_discos();
void setGenero(string g);
string getGenero();
void setCant_conc(int cc);
int getCant_conc();
void setAudiencia(int au);
int getAudiencia();
Cantantes();
Cantantes(string n,int e,int cd,string g,int cc,int au);
~Cantantes();
void printf();
int recaudacion(int cc, int au); 

};

Cantantes::Cantantes(){
    cout<<"Se creo un objeto"<<endl;
}
Cantantes::Cantantes(string n,int e,int cd,string g,int cc,int au){
    nombre = n;
    edad = e;
    cantidad_discos = cd;
    genero = g;
    cantidad_conciertos = cc;
    audiencia = au;
}
Cantantes::~Cantantes(){
    cout<<"Se destruyo el objeto"<<endl;
}

void Cantantes::setNombre(string n){
    nombre = n;
}
string Cantantes::getNombre(){
    return nombre;
}
void Cantantes::setEdad(int e){
    edad = e;
}
int Cantantes::getEdad(){
    return edad;
}
void Cantantes::setCant_discos(int cc){
    cantidad_discos = cc;
}
int Cantantes::getCant_discos(){
    return cantidad_discos;
}
void Cantantes::setGenero(string g){
    genero = g;
}
string Cantantes::getGenero(){
    return genero;
}
void Cantantes::setCant_conc(int cc){
    cantidad_conciertos = cc;
}
int Cantantes::getCant_conc(){
    return cantidad_conciertos;
}
void Cantantes::setAudiencia(int au){
    audiencia=au;
}
int Cantantes::getAudiencia(){
    return audiencia;
}
void Cantantes::printf(){
    cout<<"El nombre es: "<<nombre<<endl;
    cout<<"La edad es: "<<edad<<endl;
    cout<<"Cantidad de discos: "<<cantidad_discos<<endl;
    cout<<"Genero: "<<genero<<endl;
    cout<<"Cantidad de conciertos: "<<cantidad_conciertos<<endl;
    cout<<"La audiencia es: "<<audiencia<<endl;
}

int Cantantes::recaudacion(int cc, int au){
    dinero = cantidad_conciertos * audiencia;
    cout<<"El dinero recaudado: "<<dinero<<endl;
}
