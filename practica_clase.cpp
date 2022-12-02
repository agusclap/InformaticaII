#include <iostream>
#include "Cantantes.h"
using namespace std;

int main (void){
    int opcion = 0;
    cout<<"Ingresar por defecto (1) o por set y get (0)"<<endl;
    cin>>opcion;
    if(opcion == 1){
    int conciertos=0,audiencia=0;
    cout<<"Ingrese la cantidad de conciertos y la audiencia"<<endl;
    cin>>conciertos;
    cin>>audiencia;
    Cantantes c("Leonel",12,2,"gay",conciertos,audiencia);
    c.printf();
    c.recaudacion(conciertos,audiencia);
    } else if(opcion==0){
        Cantantes c1;
        string nombre = " ";
        string genero = " ";
        int edad=0,cant_discos=0,cant_conciertos=0,audiencia=0;
        cout<<"Ingrese toda info del cantante"<<endl;
        cin>>nombre;
        cin>>edad;
        cin>>cant_discos;
        cin>>genero;
        cin>>cant_conciertos;
        cin>>audiencia;
        c1.setNombre(nombre);
        c1.setEdad(edad);
        c1.setCant_discos(cant_discos);
        c1.setGenero(genero);
        c1.setCant_conc(cant_conciertos);
        c1.setAudiencia(audiencia);
        cout<<"Datos: "<<endl;
        c1.printf();
        cout<<"Calculamos recaudacion...."<<endl;
        c1.recaudacion(cant_conciertos,audiencia);
    } else{
        cout<<"Anda a dormir calistenico con el rey del futbol y los pases.."<<endl;
        cout<<"Y el gil que casi le tira el proyector al profe, que salamaso"<<endl;
        exit(001000);
    }

    

    return 0;
}