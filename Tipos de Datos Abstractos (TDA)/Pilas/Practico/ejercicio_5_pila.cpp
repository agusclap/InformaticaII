/*
5. Desarrolle un programa que cargue una pila de numeros enteros aleatorios.  Luego realice un menu de opciones:

Agregar un nodo a la pila. (cuando agrega un valor, el mismo no tiene que estar repetido en la pila)
Borrar el último nodo de la pila.
Imprimir pila.
*/

#include <iostream>
#include <ctime>
using namespace std;

struct node {
    int numero;
    struct node *siguiente;
};

int main(){
    srand(time(NULL));
    struct node *stackptr=NULL;
    struct node *temp=NULL;
    char opcion,seguir = ' ';
    int cont = 0;
    int numero = 0;
    for(int i=0;i<5;i++){
        struct node *new_node = NULL;
        new_node = (struct node *) malloc(sizeof(struct node));
        new_node = (struct node *) new_node;
        if(new_node==NULL){
            cout<<"No memory available"<<endl;
            exit(0);
        }
        numero = 1 + rand()%15;
        new_node->numero=numero;
        new_node->siguiente=stackptr;
        stackptr = new_node;
    }

    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Agregar un nodo a la pila"<<endl;
        cout<<"b) Borrar el ultimo nodo de la pila"<<endl;
        cout<<"c) Imprimir pila"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            {
                numero = 0;
                cout<<"Ingrese un numero a la pila"<<endl;
                cin>>numero;
                temp = stackptr;
                while(temp!=NULL){
                    if(numero==temp->numero){
                        cont++;
                    }
                    temp = temp->siguiente;
                }
                cont = 0;
                if(cont==0){
                    struct node *new_node =NULL;
                    new_node = (struct node *) malloc(sizeof(struct node));
                    new_node = (struct node *) new_node;
                    if(new_node==NULL){
                    cout<<"No memory available"<<endl;
                    exit(0);
                    }
                    new_node->numero = numero;
                    new_node->siguiente = stackptr;
                    stackptr = new_node;
                } else{
                    cout<<"Numero repetido, ingrese otro."<<endl;
                }
                break;
            }
            case 'b':
            {
                if(stackptr!=NULL){
                    temp = stackptr;
                    stackptr = stackptr->siguiente;
                    free(temp);
                } else{
                    cout<<"Pila vacia"<<endl;
                }
                break;
            }
            case 'c':
            {
                cout<<"Imprimiendo pila..."<<endl;
                temp = stackptr;
                while(temp!=NULL){
                    cout<<""<<temp->numero<<endl;
                    temp = temp->siguiente;
                }
                break;
            }
            default:
            {
                cout<<"Ingrese una opcion correcta"<<endl;
            }

        }
        cout<<"Desea seguir con el programa ? y/n"<<endl;
        cin>>seguir;

    }while(seguir=='y' || seguir=='Y');


    return 0;
}