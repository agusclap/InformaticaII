#include <iostream>
using namespace std;

struct node{

    int data;
    struct node *link;
};

void push(struct node **,struct node **, int);
void pop(struct node **, struct node **);
/// @brief 
/// @param  
void coutt(struct node *);
void search(struct node *);

int main(){
    char opcion,seguir = ' ';
    int dato, value,tamanio = 0;
    struct node *front=NULL;
    struct node *back=NULL;
    struct node *temp=NULL;
    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Agregar un nodo a la cola"<<endl;
        cout<<"b) Borrar el primer nodo de la cola"<<endl;
        cout<<"c) Imprimir cola"<<endl;
        cout<<"d) Tamaño de la cola"<<endl;
        cout<<"e) Valor del frente de la cola"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            cout<<"Ingrese el dato a ingresar"<<endl;
            cin>>dato;
            push(&front,&back,dato);
            break;
            case 'b':
            pop(&front,&back);
            break;
            case 'c':
            coutt(front);
            break;
            case 'd':
            tamanio = sizeof(struct node);
            cout<<"Tamaño de la cola: "<<tamanio<<endl;
            break;
            case 'e':
            //search(front);
            cout<<"El valor del frente de la fila es "<<front->data<<endl;

            break;
            default:
            cout<<"Ingrese una opcion correcta"<<endl;

        }
        cout<<"Desea continuar con el programa? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir=='Y');

    return 0;
}


void push(struct node **front,struct node **back, int d){
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    if(temp==NULL){
        cout<<"No memory available"<<endl;
        exit(0);
    }
    temp->data = d;
    temp->link = NULL;
    if(*back==NULL){
        *back=temp;
        *front=*back;

    }else{
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
        *back = (*back)->link;
    }
    free(temp);
}

void coutt(struct node *front){
    struct node *temp;
    temp = front;
    while(temp!=NULL){

        cout<<""<<temp->data<<endl;
        temp = temp->link;
    }


}

/*void search(struct node *front){
    struct node *temp;
    temp = front;
    while(temp!=NULL){
        if(temp->link==NULL){
            cout<<"El valor de al frente es: "<<temp->data<<endl;
        }
        temp = temp->link;
    }

} */