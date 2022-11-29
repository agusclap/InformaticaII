/*
3. Crear un programa con el siguiente menu de opciones: 

Agregar un nodo a la pila. (se deben agregar 5 valores)
Borrar el último nodo de la pila.
Imprimir pila.
Tamaño de la pila
Mostrar el último valor de la pila
*/
#include <iostream>
using namespace std;

struct node {
    int numero;
    struct node *siguiente;
};

int main(){
    struct node *stackptr;
    struct node *temp=NULL;
    int numero, cont = 0;
    char opcion, seguir = ' ';
    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Agregar un nodo a la pila"<<endl;
        cout<<"b) Borrar el ultimo nodo de la pila"<<endl;
        cout<<"c) Imprimir pila"<<endl;
        cout<<"d) Tamaño de la pila"<<endl;
        cout<<"e) Mostrar el ultimo valor de la pila"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            {
                cout<<"Ingrese el numero"<<endl;
                cin>>numero;
                struct node *new_node = NULL;
                new_node = (struct node *) malloc(sizeof(struct node));
                new_node = (struct node *) new_node;
                if(new_node==NULL){
                    cout<<"No memory available"<<endl;
                    exit(0);
                }
                new_node->numero = numero;
                new_node->siguiente = stackptr;
                stackptr = new_node;
                cout<<"Nodo cargado"<<endl;
                break;
            }
            case 'b':
            {
                if(stackptr!=NULL){
                    temp = stackptr;
                    stackptr = stackptr->siguiente;
                    free(temp);
                    cout<<"Nodo borrado"<<endl;
                } else{
                    cout<<"Pila vacia"<<endl;
                }
            }
            case 'c':
            {
                cout<<"Imprimiendo pila.."<<endl;
                temp = stackptr;
                while(temp!=NULL){
                    cout<<""<<temp->numero<<endl;
                    temp = temp->siguiente;
                }
            }
            case 'd':
            {
                temp = stackptr;
                while(temp!=NULL){
                    cont++;
                    temp = temp->siguiente;
                }
                cout<<"La cantidad de elementos de la pila es de "<<cont<<endl;
            }
            case 'e':
            {
                temp = stackptr;
                while(temp!=NULL){
                    if(temp->siguiente == NULL){
                        cout<<"El ultimo valor de la pila es: "<<temp->numero<<endl;
                    }
                    temp = temp->siguiente;
                }
            }
            default:{
            cout<<"Ingrese una opcion correcta"<<endl;}
        }
        cout<<"Desea seguir con el programa ? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir=='Y');

    return 0;
}