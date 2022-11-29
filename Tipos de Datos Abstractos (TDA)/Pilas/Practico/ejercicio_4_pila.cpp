/*4. Crear un programa con el siguiente menu de opciones: 

Agregar un nodo a la pila.
Borrar el último nodo de la pila.
Imprimir pila.
Cantidad de nodos en la pila.
Cantidades de letras mayusculas y minusculas en la pila.
*/

#include <iostream>
using namespace std;

struct node {
    char dato;
    struct node *siguiente;
};

int main(){
    struct node *stackptr=NULL;
    struct node *temp=NULL;
    int cont,letras_may = 0;
    int letras_min = 0;
    char dato, opcion, seguir = ' ';
    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Agregar un nodo a la pila"<<endl;
        cout<<"b) Borrar el ultimo nodo de la pila"<<endl;
        cout<<"c) Imprimir pila"<<endl;
        cout<<"d) Cantidad de nodos en la pila"<<endl;
        cout<<"e) Cantidad de letras mayusculas y minusculas en la pila"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            {
                cout<<"Ingrese una letra"<<endl;
                cin>>dato;
                struct node *new_node=NULL;
                new_node=(struct node * ) malloc(sizeof(struct node));
                new_node = (struct node *) new_node;
                if(new_node==NULL){
                    cout<<"No memory available"<<endl;
                    exit(0);
                }
                new_node->dato=dato;
                new_node->siguiente = stackptr;
                stackptr = new_node;
                cout<<"Nodo cargado"<<endl;
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
                    cout<<""<<temp->dato<<endl;
                    temp = temp->siguiente;
                }
                break;
            }
            case 'd':
            {
                cont = 0;
                temp = stackptr;
                while(temp!=NULL){
                    cont++;
                    cout<<""<<temp->dato<<endl;
                    temp = temp->siguiente;
                }
                cout<<"La cantidad de nodos en la pila es "<<cont<<endl;
                break;
            }
            case 'e':
            {
                letras_may = 0;
                letras_min = 0;
                temp = stackptr;
                while(temp!=NULL){
                    if((temp->dato>='A') && (temp->dato<='Z') ){
                        letras_may++;
                    }
                    if((temp->dato >= 'a') && (temp->dato <= 'z')){
                        letras_min++;
                    }
                    temp = temp->siguiente;
                }
                cout<<"La cantidad de letras minusculas es: "<<letras_min<<endl;
                cout<<"La cantidad de letras mayusculas es: "<<letras_may<<endl;
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