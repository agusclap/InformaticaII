#include <iostream>
#include <string>
using namespace std;

struct node{
    char data;
    struct node *link;
};

void push(struct node **front, struct node **back, char);
void pop(struct node **front, struct node **back);
void print(struct node *front);
int cant(struct node *front);
void cant_letras(struct node *front);


int main(){
    struct node *front=NULL;
    struct node *back=NULL;
    struct node *temp=NULL;
    int tamanio = 0;
    char opcion, seguir, dato = ' ';
    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Agregar un nodo a la cola"<<endl;
        cout<<"b) Borrar el primer nodo de la cola"<<endl;
        cout<<"c) Imprimir cola"<<endl;
        cout<<"d) Cantidad de nodos en la cola"<<endl;
        cout<<"e) Cantidad de letras minusculas y mayusculas en la cola"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            cout<<"Ingrese la letra a ingresar"<<endl;
            cin>>dato;
            push(&front,&back,dato);
            break;
            case 'b':
            pop(&front,&back);
            break;
            case 'c':
            print(front);
            break;
            case 'd':
            tamanio = cant(front);
            cout<<"La cantidad de nodos en la cola es "<<tamanio<<endl;
            break;
            case 'e':
            cant_letras(front);
            break;
            default:
            cout<<"Ingrese una opcion correcta"<<endl;
        }
        cout<<"Desea continuar con el programa ? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir=='Y');

    return 0;
}


void push(struct node **front, struct node **back, char d){

    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    if(temp==NULL){
        cout<<"No memory available"<<endl;
        exit(0);
    }
    temp->data = d;
    temp->link = NULL;
    if(*back==NULL){
        *back = temp;
        *front = *back;
    } else{
        (*back)->link = temp;
        *back = temp;

    }
}

void pop(struct node **front, struct node **back){
    struct node *temp;
    if((*front==*back) && (*back==NULL)){
        cout<<"Lista vacia"<<endl;
        exit(0);
    }
    temp = *front;
    *front = (*front)->link;
    if(*back==temp){
        (*back)->link = *back;
    }
    free (temp);
}

void print(struct node *front){
    struct node *temp;
    temp = front;
    if(temp==NULL){
        cout<<"Lista vacia"<<endl;
        exit(0);
    }
    while(temp!=NULL){
        cout<<""<<temp->data<<endl;
        temp = temp->link;
    }
    


}

int cant(struct node *front){
    int cont=0;
    struct node *temp;
    temp = front;
    if(temp==NULL){
        cout<<"Lista vacia"<<endl;
        exit(0);
    }
    while(temp!=NULL){
        cont++;
        temp = temp->link;
    }
    return cont;
}

void cant_letras(struct node *front){
    struct node *temp;
    temp = front;
    int mayus = 0;
    int minus = 0;
    if(temp==NULL){
        cout<<"Lista vacia"<<endl;
        exit(0);
    }
    while(temp!=NULL){
        if(((temp->data >= 'a') && (temp->data <= 'z'))){
            mayus++;
        } else if((temp->data >= 'A') && (temp->data <= 'Z')){
            minus++;
        }
        temp = temp->link;
    }
    cout<<"La cantidad de letras mayusculas es: "<<mayus<<endl;
    cout<<"La cantidad de letras minusculas es: "<<minus<<endl;

}