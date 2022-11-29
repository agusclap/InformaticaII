/*2. Crear un programa en la cual cargue una pila de 5 numeros aleatoriamente (entre 1 y 10), luego los muestre y muestre los valores pares.*/
#include <iostream>
#include <ctime>
using namespace std;

struct node {
    int numero;
    struct node *siguiente;
};

int main(){
    srand(time(NULL));
    int numero = 0;
    struct node *stackptr=NULL;
    struct node *temp=NULL;
    for(int i=0;i<5;i++){
        numero = 1 + rand()%10;
        struct node *new_node=NULL;
        new_node = (struct node *) malloc(sizeof(struct node));
        new_node = (struct node * ) new_node;
        if(new_node==NULL){
        cout<<"No memory available"<<endl;
        exit(0);
         }
        new_node->numero = numero;
        new_node->siguiente=stackptr;
        stackptr=new_node;
    }
    temp = stackptr;
    cout<<"Impresion de la pila:"<<endl;
    while(temp!=NULL){
        cout<<""<<temp->numero<<endl;
        temp = temp->siguiente;
    }
    temp = stackptr;
    cout<<"Numeros pares:"<<endl;
    while(temp!=NULL){
        if((temp->numero)%2==0){
            cout<<""<<temp->numero<<endl;
        }
        temp = temp->siguiente;
    }


    return 0;
}