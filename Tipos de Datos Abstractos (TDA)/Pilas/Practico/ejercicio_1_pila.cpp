/*. Crear un programa con el siguiente menu de opciones: 

Agregar un nodo a la pila. (se deben agregar 5 valores)
Borrar el último nodo de la pila.
Imprimir pila.
Suma de los valores de la pila.*/
#include <iostream>
using namespace std;

struct node {
    int numero;
    struct node *siguiente;
};

int main(){
    char opcion,seguir = ' ';
    int numero = 0;
    int sumatoria=0;
    struct node *stackptr=NULL;
    struct node *temp=NULL;
    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Agregar un nodo a la pila"<<endl;
        cout<<"b) Borrar el ultimo nodo de la pila"<<endl;
        cout<<"c) Imprimir pila"<<endl;
        cout<<"d) Suma de los valores de la pila"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
                {
                cout<<"Ingresa un numero a agregar a la pila"<<endl;
                cin>>numero;
                struct node *new_node = NULL;
                new_node = (struct node *) malloc(sizeof(struct node));
                new_node = (struct node *) new_node;
                if(new_node==NULL){
                    cout<<"No memory available"<<endl;
                    exit(0);
                }
                new_node->numero=numero;
                new_node->siguiente= stackptr;
                stackptr = new_node;
                break;}
            case 'b':
                {
                if(stackptr!=NULL){
                temp = stackptr;
                stackptr = stackptr->siguiente;
                free(temp);
                }else{
                cout<<"Pila vacia"<<endl;}
                break;}
            case 'c':
                {
                cout<<"Impresion de la pila:"<<endl;
                temp = stackptr;
                while(temp!=NULL){
                cout<<""<<temp->numero<<endl;
                temp = temp->siguiente;
                }
                break;}
            case 'd':
                {
                if(stackptr==NULL){
                cout<<"Pila vacia"<<endl;
                exit(0);
                }
                temp = stackptr;
                while(temp!=NULL){
                sumatoria = sumatoria + temp->numero;
                temp = temp->siguiente;
                }
                cout<<"La suma de los valores de la pila es: "<<sumatoria<<endl;
                break;}
            default:
                cout<<"Ingrese una opcion existente"<<endl;
           }
        cout<<"Desea continuar con el programa ? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir=='Y');

    return 0;
}
/* if(stackptr!=NULL){
                temp = stackptr;
                stackptr = stackptr->siguiente;
                free(temp);
            }
            cout<<"Pila vacia"<<endl;
            break;
                case 'c':
            cout<<"Impresion de la pila:"<<endl;
            temp = stackptr;
            while(temp!=NULL){
                cout<<""<<temp->numero<<endl;
                temp = temp->siguiente;
            }
            break;
                case 'd':
            if(stackptr==NULL){
                cout<<"Pila vacia"<<endl;
                exit(0);
            }
            temp = stackptr;
            while(temp!=NULL){
                sumatoria = sumatoria + temp->numero;
                temp = temp->siguiente;
            }
            break;
                default:
            cout<<"Ingrese una opcion existente"<<endl;*/