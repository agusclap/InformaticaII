#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

int main()
{
    int x = 0;
    char seguir,opcion = ' ';
    float cont,sumatoria,promedio,dato = 0.0;
    struct node* head=NULL;
    struct node* temp=NULL;
    struct node *new_node=NULL;
    do{
        
        cout<<"Ingrese un dato"<<endl;
        cin>>dato;
        cont++;
        new_node= (struct node*) malloc(sizeof(struct node));
        new_node = (struct node * ) new_node;
        if(new_node==NULL){
            cout<<"No hay memoria disponible"<<endl;
            exit(0);
        }
        new_node->data=dato;
        new_node->next = NULL;
        if(head==NULL)
        {
            head = new_node;
        }else{
            temp=head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next=new_node;
        }
        
        cout<<"Desea seguir agregando numeros? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir=='Y');
    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Mostrar la lista y mostrar el promedio"<<endl;
        cin>>opcion;
        switch(opcion)
        {
            case 'a':
            temp = head;
            while(temp!=NULL)
            {
                cout<<temp->data<<endl;
                sumatoria = sumatoria + temp->data;
                temp = temp -> next;
            }
            promedio = sumatoria/cont;
            cout<<"El promedio de los valores es: "<<promedio<<endl;
            break;
            default:
            cout<<"Ingrese una opcion correcta"<<endl;
        }
        cout<<"Desea continuar ? (ingrese 1 para terminar)"<<endl;
        cin>>x;
    }while(x!=1);

    return 0;
}