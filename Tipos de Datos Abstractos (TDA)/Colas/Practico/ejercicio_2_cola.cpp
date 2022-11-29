#include <iostream>
#include <ctime>
using namespace std;

struct node{
    int data;
    struct node *link;
};

int main(){
    srand(time(NULL));
    struct node *front=NULL;
    struct node *back=NULL;
    struct node *temp=NULL;
    int dato = 0;
    for(int i=0;i<5;i++){
        dato = 1 + rand() % 10;
        temp = (struct node *) malloc(sizeof(struct node));
        if(temp==NULL){
            cout<<"No memory avaliable"<<endl;
            exit(0);
        }
        temp->data = dato;
        temp->link = NULL;
        if(back==NULL){
            back = temp;
            front = back;
        } else{
            back->link = temp;
            back = temp;
        }
        
    }
    int cont=0;
    do{
        if((front==back) && (back==NULL)){
           cout<<"Lista vacia"<<endl;
          exit(0);
      } else{
        temp = front;
          while(temp!=NULL){
            cont++;
             cout<<""<<temp->data<<endl;
             temp = temp->link;
          }
      }
    }while(cont!=5);
       
        cont=0;
     if((front==back) && (back=NULL)){
         cout<<"Lista vacia"<<endl;
         exit(0);
     } else{
        do{
            cout<<"Valores pares:"<<endl;
            temp = front;
            cont++;
          while(temp!=NULL){
              if(((temp->data)%2)==0){
                 cout<<"Valor: "<<temp->data<<" es par"<<endl;
                 temp = temp->link;

              }
          }
        }while(cont!=5);
      }
    



    return 0;
}
