#include <iostream>
#include "Perfume.h"
using namespace std;

void cargar();
void cargar1();
int main(void){
    char opcion,seguir = ' ';
    do{
        cout<<"MENU DE OPCINES:"<<endl;
        cout<<"a) Cargar por defecto"<<endl;
        cout<<"b) Cargar por sets"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            {
                cargar();
                break;
            }
            case 'b':
            {
                cargar1();
                break;
            }
            default:
            {
                cout<<"Ingrese una opcion correcta"<<endl;
            }
        }
        cout<<"Desea continuar con el programa ? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir == 'Y');

    return 0;
}

void cargar(){
    Perfume p("Givenchy",10,"Gucci");
    cout<<"Datos ingresados: "<<endl;
    cout<<"Nombre: "<<p.getNombre()<<endl;
    cout<<"Tamaño: "<<p.getTamanio()<<endl;
    cout<<"Marca: "<<p.getMarca()<<endl;
}

void cargar1(){
    Perfume p;
    string nombre,marca = " ";
    int tamanio = 0;
    cout<<"Ingrese el nombre del perfume"<<endl;
    cin>>nombre;
    p.setNombre(nombre);
    cout<<"Ingrese el tamanio del perfume"<<endl;
    cin>>tamanio;
    p.setTamanio(tamanio);
    cout<<"Ingrese la marca del perfume"<<endl;
    cin>>marca;
    p.setMarca(marca);
    cout<<"Datos ingresados: "<<endl;
    cout<<"Nombre: "<<p.getNombre()<<endl;
    cout<<"Tamaño: "<<p.getTamanio()<<endl;
    cout<<"Marca: "<<p.getMarca()<<endl;
}