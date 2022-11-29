/*5. Desarrolle un programa que cargue una cola de numeros enteros aleatorios.  Luego realice un menu de opciones:

Agregar un nodo a la cola. (cuando agrega un valor, el mismo no tiene que estar repetido en la cola)
Borrar el primer nodo de la cola.
Imprimir cola.*/

#include <iostream>
#include <ctime>
using namespace std;

struct node{
    int data;
    struct node *link;
};

void push(struct node **front, struct node **back, int );
void pop(struct node **front, struct node **back);
void print(struct node *front);
bool repetido(struct node *front, int);

int main(void){
    srand(time(NULL));
    struct node *front=NULL;
    struct node *back=NULL;
    struct node *temp=NULL;
    char opcion, seguir = ' ';
    int dato = 0;
    for(int i=0;i<5;i++){
        dato = 1 + rand()%10;
        push(&front,&back,dato);
    }
    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Agregar un nodo a la cola"<<endl;
        cout<<"b) Borrar el primer nodo de la cola"<<endl;
        cout<<"c) Imprimir cola"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            do{
                cout<<"Ingrese un valor a ingresar"<<endl;
                cin>>dato;
                if(repetido(front,dato)==false){
                push(&front,&back,dato);
                break;
                }else{
                cout<<"Valor repetido, ingrese otro"<<endl;
                }
            }while(repetido(front,dato)==true);
            break;
            case 'b':
            pop(&front,&back);
            break;
            case 'c':
            print(front);
            break;
            default:
            cout<<"Ingrese una opcion existente"<<endl;

        }
        cout<<"Desea continuar con el programa ? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir=='Y');

}

void push(struct node **front,struct node **back, int d){
    struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("No hay suficiente memoria");
		exit(0);
	}
	temp->data=d;
	temp->link=NULL;
	if(*back==NULL){ //Insercion del primer nodo
		*back=temp;
		*front=*back;
	}else{ //Insercion del resto de los nodos
		(*back)->link =temp;
		*back=temp;
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
    free(temp);

}

void print(struct node *front){
    struct node *temp;
    temp = front;
    while(temp!=NULL){
        cout<<""<<temp->data<<endl;
        temp = temp->link;
    }

}
bool repetido(struct node *front, int dato){
	bool repe=false;
	struct node *temp = NULL;
	temp=front;
	while(temp!=NULL){
		if(temp->data==dato){
			repe=true;
		}
		temp=temp->link;
	}
	return repe;
}