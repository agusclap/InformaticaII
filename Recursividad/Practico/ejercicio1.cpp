/*1. Realizar un programa que solicite el ingresar de un número y 
mostrar su equivalente en binario usando una función recursiva. 
Por ejemplo:

SISTEMA DECIMAL SISTEMA BINARIO

2 10

3 11

4 100

5 101
*/


#include  <iostream>
using namespace std;

int calculo(int);

int main(void){
    int num = 0;
    char seguir = ' ';
    do{
        cout<<"Ingrese un numero"<<endl;
        cin>>num;
        cout<<"El binario de "<<num<<" es: "<<endl;
        calculo(num);
        cout<<endl;
        cout<<"Desea continuar ? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir == 'Y');


    return 0;
}

int calculo(int num){
    if(num>1){
        calculo(num/2);}
    cout<<num%2;
    return 0;
    
}