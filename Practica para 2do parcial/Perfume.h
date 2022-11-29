#include <iostream>
#include <string>
using namespace std;

class Perfume{
    private:
    string nombre;
    int tamanio;
    string marca;
    public:
    Perfume(string,int,string);
    ~Perfume();
    Perfume();
    void setNombre(string);
    string getNombre();
    void setTamanio(int);
    int getTamanio();
    void setMarca(string);
    string getMarca();
    string toString();

};

Perfume::Perfume(string a,int b,string c){
    nombre = a;
    tamanio = b;
    marca = c;
}
Perfume::~Perfume(){
}
Perfume::Perfume(){
}

void Perfume::setNombre(string n){
    nombre = n;
}
string Perfume::getNombre(){
    return nombre;
}
void Perfume::setTamanio(int t){
    tamanio = t;
}
int Perfume::getTamanio(){
    return tamanio;
}
void Perfume::setMarca(string m){
    marca = m;
}
string Perfume::getMarca(){
    return marca;
}

string Perfume::toString(){
    string cadena;
    cadena = nombre+"\t"+"%d",tamanio+"\t"+marca;
    return cadena;
}