/*6. Elaborar un sistema de stock, en la cual posee una pila de productos con los siguientes atributos: codigo, nombre, cantidad, precio lista. Desarrollar las siguientes funciones:

Agregar un nuevo producto.
Borrar el último nodo de la pila.
Mostrar el stock. 
Descontar stock.
Reponer stock.
*/

#include <iostream>
using namespace std;

struct producto {
    int codigo;
    string nombre;
    int cantidad;
    float precio;
};

struct node {
    struct producto p;
    struct node *siguiente;
};

void push(struct node **stackptr,struct producto p);
void eliminate(struct node **stackptr);
void print(struct node *stackptr);
void discount(struct node **stackptr);
void replenish(struct node **stackptr);
int main(){
    struct node *stackptr=NULL;
    struct producto p;
    char opcion,seguir = ' ';
    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Agregar un nuevo producto"<<endl;
        cout<<"b) Borrar el ultimo nodo de la pila"<<endl;
        cout<<"c) Mostrar el stock"<<endl;
        cout<<"d) Descontar el stock"<<endl;
        cout<<"e) Reponer stock"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            {
                push(&stackptr,p);
                break;
            }
            case 'b':
            {
                eliminate(&stackptr);
                break;
            }
            case 'c':
            {
                print(stackptr);
                break;
            }
            case 'd':
            {
                discount(&stackptr);
                break;
            }
            case 'e':
            {
                replenish(&stackptr);
                break;
            }
            default:
            {
                cout<<"Ingrese una opcion correcta"<<endl;
            }
        }
        cout<<"Desea continuar con el programa ? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir=='Y');
    return 0;

}

void push(struct node **stackptr, struct producto p){
    cout<<"Ingrese el codigo del producto"<<endl;
    cin>>p.codigo;
    cout<<"Ingrese el nombre del producto"<<endl;
    cin>>p.nombre;
    cout<<"Ingrese la cantidad que hay del producto"<<endl;
    cin>>p.cantidad;
    cout<<"Ingrese el precio del producto"<<endl;
    cin>>p.precio;
    struct node *new_node = NULL;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node = (struct node *) new_node;
    if(new_node==NULL){
        cout<<"No memory available"<<endl;
        exit(0);
    }
    new_node->p = p;
    new_node->siguiente=*stackptr;
    *stackptr = new_node;
    cout<<"Nodo cargado"<<endl;
}

void eliminate(struct node **stackptr){
    struct node *temp =NULL;
    if(*stackptr!=NULL){
        temp = *stackptr;
        *stackptr = (*stackptr)->siguiente;
        free(temp);
    } else{
        cout<<"Pila vacia"<<endl;
    }
    cout<<"Nodo borrado"<<endl;
}

void print(struct node *stackptr){
    struct node *temp =NULL;
    cout<<"Cod\t Nom\t Cant\t Pre\t"<<endl;
    while(temp!=NULL){
        cout<<""<<temp->p.codigo<<"\t"<<temp->p.nombre<<"\t"<<temp->p.cantidad<<"\t"<<temp->p.precio<<endl;
        temp = temp->siguiente;
    }

}

void discount(struct node **stackptr){
    int descontar,cod = 0;
    struct node *temp=NULL;
    cout<<"Ingrese la cantidad a descontar"<<endl;
    cin>>descontar;
    cout<<"Ingrese el codigo del producto"<<endl;
    cin>>cod;
    temp = *stackptr;
    while(temp!=NULL){
        if(temp->p.codigo==cod){
            (*stackptr)->p.cantidad = (*stackptr)->p.cantidad - descontar;
        }
        temp = temp->siguiente;
    }
    
}

void replenish(struct node **stackptr){
    int reponer,cod=0;
    struct node *temp=NULL;
    cout<<"Ingrese la cantidad a reponer"<<endl;
    cin>>reponer;
    cout<<"Ingrese el codigo del producto"<<endl;
    cin>>cod;
    temp = *stackptr;
    while(temp!=NULL){
        if(temp->p.codigo==cod){
            (*stackptr)->p.cantidad = (*stackptr)->p.cantidad + reponer;
        }
        temp = temp->siguiente;
    }
}