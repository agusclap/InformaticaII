/*7. Desarrollo un programa que cree una pila de vehiculos que pasan por un peaje, en la cual se deben registrar patente, marca, color, cantidad de ejes, precio, direccion.
 El precio es segun la cantidad de ejes. (1 eje = $100, 2 ejes = $150, 3 ejes = $200 y 4 ejes o mas $300). La direccion es a la que se dirige el vehiculo, en este caso
  puede ser de Norte a Sur o Sur a Norte. Luego, arme un menu de opciones que muestre lo siguiente: 

Agregar un vehiculo a la pila
Borrar el último nodo de la pila.
Mostrar todos los vehiculos. 
Mostrar los vehiculos por dirección
Mostrar los vehiculos por ejes. 
*/

#include <iostream>
using namespace std;

struct registro {
    string patente;
    string marca;
    string color;
    int cantidad;
    float precio;
    string direccion;
};

struct node {
    struct registro r;
    struct node *siguiente;
};

void push(struct node **stackptr);
void eliminate(struct node **stackptr);
void print(struct node *stackptr);
void direcc(struct node *stackptr);
void ejes(struct node *stackptr);

int main(){
    struct node *stackptr=NULL;
    struct registro r;
    char seguir, opcion = ' ';

    do{
        cout<<"a) Agregar un vehiculo a la pila"<<endl;
        cout<<"b) Borrar el ultimo nodo de la pila"<<endl;
        cout<<"c) Mostrar todos los vehiculos"<<endl;
        cout<<"d) Mostrar los vehiculos por direccion (SN o NS)"<<endl;
        cout<<"e) Mostrar los vehiculos por ejes"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            {
                push(&stackptr);
                cout<<"Vehiculo agregado"<<endl;
                break;
            }
            case 'b':
            {
                eliminate(&stackptr);
                cout<<"Vehiculo borrado"<<endl;
                break;
            }
            case 'c':
            {
                cout<<"Imprimiendo pila..."<<endl;
                print(stackptr);
                break;
                
            }
            case 'd':
            {
            cout<<"Imprimiendo pila por direccion.."<<endl;
            direcc(stackptr);
            break;}
            case 'e':
            {
                cout<<"Imprimiendo pila por ejes"<<endl;
                ejes(stackptr);
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

void push(struct node **stackptr){
    struct node *new_node=NULL;
    struct registro r;
    string patente,marca,color,direccion = " ";
    int precio, cantidad = 0;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node = (struct node *) new_node;
    if(new_node==NULL){
        cout<<"No memory available"<<endl;
        exit(0);
    }

    cout<<"Ingrese la patente del vehiculo"<<endl;
    cin>>patente;
    new_node->r.patente = patente;
    cout<<"Ingrese la marca del vehiculo"<<endl;
    cin>>marca;
    new_node->r.marca = marca;
    cout<<"Ingrese el color del vehiculo"<<endl;
    cin>>color;
    new_node->r.color = color;
    cout<<"Ingrese la cantidad de ejes del vehiculo"<<endl;
    cin>>cantidad;
    new_node->r.cantidad = cantidad;
    cout<<"Ingrese la direccion hacia donde se dirige"<<endl;
    cin>>direccion;
    new_node->r.direccion = direccion;
    if(cantidad == 1){
        new_node->r.precio = 100;
    }
    if(cantidad == 2){
        new_node->r.precio = 150;
    }
    if(cantidad == 3){
        new_node->r.precio = 200;
    }
    if(cantidad >= 4){
        new_node->r.precio = 300;
    }
    new_node->siguiente = *stackptr;
    *stackptr = new_node;
}

void eliminate(struct node **stackptr){
    struct node *temp = NULL;
    if(*stackptr!=NULL){
        temp = *stackptr;
        *stackptr = (*stackptr)->siguiente;
        free(temp);
    } else{
        cout<<"Pila vacia"<<endl;
    }
}

void print(struct node *stackptr){
    struct node *temp = NULL;
    temp = stackptr;
    cout<<"Pat\tMar\tCol\tCan\tPre\tDir"<<endl;
    while(temp!=NULL){
        cout<<""<<temp->r.patente<<"\t"<<temp->r.marca<<"\t"<<temp->r.color<<"\t"<<temp->r.cantidad<<"\t"<<temp->r.precio<<"\t"<<temp->r.direccion<<endl;
        temp = temp->siguiente;
    }
}

void direcc(struct node *stackptr){
    struct node *temp = NULL;
    int cont = 0;
    temp = stackptr;
    cout<<"Vehiculo con direccion al Norte:"<<endl;
    while(temp!=NULL){
        cont++;
        if(temp->r.direccion=="SN"){
            cout<<"Vehiculo: "<<cont<<endl;
            cout<<"Pat: "<<temp->r.patente<<"\tMarca: "<<temp->r.marca<<"\tColor: "<<temp->r.color<<"\tEjes: "<<temp->r.cantidad<<"\tPrecio: "<<temp->r.precio<<"\tDirec: "<<temp->r.direccion<<endl;
        }
    }
    temp = stackptr;
    cont = 0;
    cout<<"Vehiculo con direccion al Sur:"<<endl;
    while(temp!=NULL){
        cont++;
        if(temp->r.direccion=="NS"){
            cout<<"Vehiculo: "<<cont<<endl;
            cout<<"Pat: "<<temp->r.patente<<"\tMarca: "<<temp->r.marca<<"\tColor: "<<temp->r.color<<"\tEjes: "<<temp->r.cantidad<<"\tPrecio: "<<temp->r.precio<<"\tDirec: "<<temp->r.direccion<<endl;
        }
    }
}

void ejes(struct node *stackptr){
    struct node *temp;
	temp=stackptr;
	cout<<"Impresion de la cola con 1 eje\n";
	cout<<"Pat.\tPrec.\tDirec.\n";
	while(temp!=NULL){
		if(temp->r.cantidad==1){
			cout<<temp->r.patente<<"\t"<<temp->r.precio<<"\t"<<temp->r.direccion<<"\n";
		}
		temp=temp->siguiente;
	}
	temp=stackptr;
	cout<<"\nImpresion de la cola con 2 eje\n";
	cout<<"Pat.\tPrec.\tDirec.\n";
	while(temp!=NULL){
		if(temp->r.cantidad==2){
			cout<<temp->r.patente<<"\t"<<temp->r.precio<<"\t"<<temp->r.direccion<<"\n";
		}
		temp=temp->siguiente;
	}
	temp=stackptr;
	cout<<"\nImpresion de la cola con 3 eje\n";
	cout<<"Pat.\tPrec.\tDirec.\n";
	while(temp!=NULL){
		if(temp->r.cantidad==3){
			cout<<temp->r.patente<<"\t"<<temp->r.precio<<"\t"<<temp->r.direccion<<"\n";
		}
		temp=temp->siguiente;
	}
	temp=stackptr;
	cout<<"\nImpresion de la cola con 4 eje o mas\n";
	cout<<"Pat.\tCant.\tPrec.\tDirec.\n";
	while(temp!=NULL){
		if(temp->r.precio>=4){
			cout<<temp->r.patente<<"\t"<<temp->r.cantidad<<"\t"<<temp->r.precio<<"\t"<<temp->r.direccion<<"\n";
		}
		temp=temp->siguiente;
	}
}