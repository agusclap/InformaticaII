/*6. Elaborar un sistema de stock, en la cual posee una cola de productos con los siguientes atributos: codigo, nombre, cantidad, precio lista. Desarrollar las siguientes funciones:

Agregar un nuevo producto.
Borrar el primer nodo de la cola.
Mostrar el stock. 
Descontar stock.
Reponer stock.*/

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
    struct node *link;
};

void push(struct node **front, struct node **back,struct producto *p);
void pop(struct node **front, struct node **back);
void print(struct node *front);
void discount(struct node *front);
void replenish(struct node *front);

int main(void){
    struct node *front=NULL;
    struct node *back=NULL;
    struct producto p;
    char opcion,seguir = ' ';
    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Agregar un nuevo producto"<<endl;
        cout<<"b) Borrar el primer nodo de la cola"<<endl;
        cout<<"c) Mostrar el stock"<<endl;
        cout<<"d) Descontar el stock"<<endl;
        cout<<"e) Reponer el stock"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            cout<<"Ingrese el codigo del producto"<<endl;
            cin>>p.codigo;
            cout<<"Ingrese el nombre del producto"<<endl;
            cin>>p.nombre;
            cout<<"Ingrese la cantidad del producto"<<endl;
            cin>>p.cantidad;
            cout<<"Ingrese el precio lista del producto"<<endl;
            cin>>p.precio;
            push(&front,&back,&p);
            break;
            case 'b':
            pop(&front,&back);
            break;
            case 'c':
            print(front);
            break;
            case 'd':
            discount(front);
            break;
            case 'e':
            replenish(front);
            break;
            default:
            cout<<"Ingrese una opcion existente"<<endl;
        }    
        cout<<"Desea continuar con el programa ? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir=='Y');
    

}

void push(struct node **front, struct node **back, struct producto *p){
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    if(temp==NULL){
        cout<<"No memory available"<<endl;
        exit(0);
    }
    temp->p = *p;
    temp->link = NULL;
    if(*back==NULL){
        *back = temp;
        *front = *back;
    }else{
        (*back)->link = temp;
        *back = temp;
    }

}

void pop(struct node **front,struct node **back){
    struct node *temp;
    if((*front==*back) && (*back==NULL)){
        cout<<"Lista vacia"<<endl;
        exit(0);
    }
    temp = *front;
    *front = (*front)->link;
    if(*back==temp){
        (*back)->link=*back;
    }
    free(temp);
    cout<<"Nodo borrado."<<endl;
}

void print(struct node *front){
    struct node *temp;
    temp = front;
    cout<<"Lista de productos:"<<endl;
    cout<<"Cod\tNombre\tCant\tPrecio\t"<<endl;
    while(temp!=NULL){
        cout<<temp->p.codigo<<"\t"<<temp->p.nombre<<"\t"<<temp->p.cantidad<<"\t"<<temp->p.precio<<"\t"<<endl;
        temp = temp->link;
    }

}

void discount(struct node *front){
    struct node *temp;
    int cod,cant=0;
    temp = front;
    cout<<"Ingrese el codigo del producto"<<endl;
    cin>>cod;
    cout<<"Ingrese la cantidad a descontar"<<endl;
    cin>>cant;
    while(temp!=NULL){
        if(temp->p.codigo==cod){
            temp->p.cantidad = temp->p.cantidad - cant; 
        }
        temp = temp->link;
    }
    cout<<"Nuevo stock listo"<<endl;
    
}

void replenish(struct node *front){
    int cod = 0;
    int cant = 0;
    struct node *temp;
    temp = front;
    if(temp==NULL){
        cout<<"Lista sin productos"<<endl;
        exit(0);
    }
    cout<<"Ingrese el codigo del producto"<<endl;
    cin>>cod;
    cout<<"Ingrese la cantidad a reponer"<<endl;
    cin>>cant;
    while(temp!=NULL){
        if(temp->p.codigo == cod){
            temp->p.cantidad = temp->p.cantidad + cant;
        }
        temp = temp->link;
    }
    cout<<"Stock listo con nueva cantidad"<<endl;
}