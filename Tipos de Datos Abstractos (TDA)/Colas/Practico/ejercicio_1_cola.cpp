/*Falta enunciado*/

#include <iostream>
using namespace std;



struct Node{
    int data;
    struct Node *link;

};

int main(){
    struct Node *front = NULL;
    struct Node *back = NULL;
    struct Node *temp = NULL;
    int n,value,op =1;
    int sumatoria = 0;
    char seguir,opcion = ' ';

    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Agregar un nodo a la cola (5)"<<endl;
        cout<<"b) Borrar el primer nodo de la cola"<<endl;
        cout<<"c) Imprimir cola"<<endl;
        cout<<"d) Suma de los valores de la cola"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
             for(int i=0;i<5;i++){
                cout<<"Ingrese un elemento"<<endl;
                cin>>value;
                temp=(struct Node*) malloc(sizeof(struct Node));
                if(temp==NULL){
                    cout<<"No memory available"<<endl;
                    exit(0);
                }
                temp->data = value;
                temp->link =NULL;
                if(back==NULL){
                    back = temp;
                    front = back;
                } else{
                    back->link= temp;
                    back = temp;
                }
             }
            break;
            case 'b':
                if((front== back) && (back==NULL)){
                    cout<<"Void"<<endl;
                    exit(0);
                }
                temp = front;
                front = (front)->link;
                if(back==temp){
                    back= back->link;
                }
                free(temp);
            break;
            case 'c':
                temp = front;
                while(temp!=NULL){
                cout<<""<<temp->data<<endl;
                temp=temp->link;
                }
            break;
            case 'd':
                if((front==back) && (back==NULL)){
                    cout<<"Void"<<endl;
                    exit(0);
                }
                temp = front;
                front = front ->link;
                while(temp!=NULL){
                    sumatoria = sumatoria + temp->data;
                    temp = temp->link;
                }
                cout<<"La sumatoria de los valores de la cola es "<<sumatoria<<endl;
            break;
            default:
            cout<<"Ingrese una opcion correcta"<<endl;
        }
        cout<<"Desea continuar con el programa? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir=='Y');

    return 0;
}


