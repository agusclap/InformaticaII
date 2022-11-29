/*7. Desarrollo un programa que cree una cola de vehiculos que pasan por un peaje, en la cual se deben registrar patente, marca, color, cantidad de ejes, precio, direccion.
 El precio es segun la cantidad de ejes. (1 eje = $100, 2 ejes = $150, 3 ejes = $200 y 4 ejes o mas $300). La direccion es a la que se dirige el vehiculo,
  en este caso puede ser de Norte a Sur o Sur a Norte. Luego, arme un menu de opciones que muestre lo siguiente: 

Agregar un vehiculo a la cola
Borrar el primer nodo de la cola.
Mostrar todos los vehiculos. 
Mostrar los vehiculos por dirección
Mostrar los vehiculos por ejes. */

#include <iostream>
using namespace std;


struct vehiculo{
    string patente;
    string marca;
    string color;
    int cantidad;
    int precio;
    string direccion;
};

struct node {
    struct vehiculo v;
    struct node *link;
};

void push(struct node **front,struct node **back,struct vehiculo);
void pop(struct node **front,struct node **back);
void print(struct node *front);
void direcc(struct node *front);
void ejes(struct node *front);

int main(void){
    struct node *front=NULL;
    struct node *back=NULL;
    struct vehiculo v;
    char opcion,seguir = ' ';


    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Agregar un vehiculo a la cola"<<endl;
        cout<<"b) Borrar el primer nodo de la cola"<<endl;
        cout<<"c) Mostrar todos los vehiculos"<<endl;
        cout<<"d) Mostrar los vehiculos por direccion"<<endl;
        cout<<"e) Mostrar los vehiculos por ejes"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            cout<<"Ingrese la patente del vehiculo"<<endl;
            cin>>v.patente;
            cout<<"Ingrese la marca del vehiculo"<<endl;
            cin>>v.marca;
            cout<<"Ingrese el color del vehiculo"<<endl;
            cin>>v.color;
            cout<<"Ingrese la cantidad de ejes del vehiculo"<<endl;
            cin>>v.cantidad;
            if(v.cantidad==1){
                v.precio = 100;
            }
            if(v.cantidad==2){
                v.precio = 150;
            }
            if(v.cantidad==3){
                v.precio = 200;
            }
            if(v.cantidad>3){
                v.precio = 300;
            }
            cout<<"Ingrese la direccion hacia donde se dirige el vehiculo (Norte o Sur)"<<endl;
            cin>>v.direccion;
            push(&front,&back,v);
            break;
            case 'b':
            pop(&front,&back);
            break;
            case 'c':
            print(front);
            break;
            case 'd':
            direcc(front);
            break;
            case 'e':
            ejes(front);
            break;
            default:
            cout<<"Ingrese una opcion correcta"<<endl;
        }
        cout<<"Desea seguir con el programa ? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir=='Y');




    return 0;
}

void push(struct node **front,struct node **back,struct vehiculo v){
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    if(temp==NULL){
        cout<<"No memory available"<<endl;
        exit(404);
    }
    temp->v = v;
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
    if((*front==*back) && (*back=NULL)){
        cout<<"Lista vacia"<<endl;
        exit(0);
    }
    temp = *front;
    *front = (*front)->link;
    if(*back==NULL){
        (*back)->link = *back;

    }
    free(temp);
    cout<<"Nodo Borrado"<<endl;

}
void print(struct node *front){
    struct node *temp;
    temp = front;
    if(temp==NULL){
        cout<<"Lista vacia"<<endl;
        exit(0);
    }
    int cont = 0;
    while(temp!=NULL){
        cont++;
     cout<<"Vehiculo: "<<cont<<endl;
     cout<<"Pat: "<<temp->v.patente<<"\tMarca: "<<temp->v.marca<<"\tColor: "<<temp->v.color<<"\tEjes: "<<temp->v.cantidad<<"\tPrecio: "<<temp->v.precio<<"\tDirec: "<<temp->v.direccion<<endl;
     temp = temp->link;   
    }
}

void direcc(struct node *front){
    struct node *temp;
    temp = front;
    if(temp==NULL){
        cout<<"Lista vacia"<<endl;
        exit(0);
    }
    int cont = 0;
    while(temp!=NULL){
        cont++;
        if(temp->v.direccion=="Sur"){
            cout<<"Vehiculo con direccion al Sur:"<<endl;
            cout<<"Vehiculo: "<<cont<<endl;
            cout<<"Pat: "<<temp->v.patente<<"\tMarca: "<<temp->v.marca<<"\tColor: "<<temp->v.color<<"\tEjes: "<<temp->v.cantidad<<"\tPrecio: "<<temp->v.precio<<"\tDirec: "<<temp->v.direccion<<endl;
        } else if(temp->v.direccion=="Norte"){
                cout<<"Vehiculo con direccion al Norte:"<<endl;
                cout<<"Vehiculo: "<<cont<<endl;
                cout<<"Pat: "<<temp->v.patente<<"\tMarca: "<<temp->v.marca<<"\tColor: "<<temp->v.color<<"\tEjes: "<<temp->v.cantidad<<"\tPrecio: "<<temp->v.precio<<"\tDirec: "<<temp->v.direccion<<endl;
            }
        temp = temp->link;
    }

}

void ejes(struct node *front){
    struct node *temp;
    struct node *aux;
    cout<<"Valor ordenados por ejes:"<<endl;
        aux = front;
        temp =front;
        while(temp!=NULL){
        if(temp->v.cantidad<temp->link->v.cantidad){
            aux->v = temp->v;
            temp->v = temp->link->v;
            temp->link->v = aux->v;
        }
        temp = temp->link;
    }
    temp=front;
    while(temp!=NULL){
        cout<<"Pat: "<<temp->v.patente<<"\tMarca: "<<temp->v.marca<<"\tColor: "<<temp->v.color<<"\tEjes: "<<temp->v.cantidad<<"\tPrecio: "<<temp->v.precio<<"\tDirec: "<<temp->v.direccion<<endl;
        temp = temp->link;
    }
}