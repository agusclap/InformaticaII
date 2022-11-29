/*
Desarrolle un programa que cree una estructura llamada Equipo en la cual tiene los siguientes atributos:
 nombre del equipo, cantidad de juegos ganados, cantidad de juegos perdidos, cantidad de juegos empatados y puntaje. 
 El puntaje es calculado según la cantidad de partidos ganados, perdidos o empatados. Si ganó el partido se le suman 3 puntos, 
 si empatan no suman ni restan y si pierden se le restan -2.

Luego crear una lista de equipos, y cargar los datos de cada equipo. 
El puntaje debe ser calculado por una función. Una vez cargada la lista, mostrar un menu de opciones con los siguientes datos:

1. Mostrar el listado de equipos que participaron en el torneo.

2. Mostrar el equipo ganador con su puntaje. 
(En caso de que haya mas de uno, mostrarlos a todos) Ej. Si hay 3 equipos con 15 puntos y es el numero mayor de puntaje, mostrar los 3 equipos. 

3. Mostrar todos los equipos que nunca perdieron un partido.

4. Grabar un archivo llamado puntaje.txt en donde se listen los datos, por ejemplo:
*/
#include <iostream>
using namespace std;

struct team {
    char name[50];
    int wins;
    int loss;
    int draw;
    int scoreboard;
    struct team *next;
};

int load(struct team **head);
void show_team(struct team *head);
void show_winners(struct team *head);
void show_dontlosses(struct team *head, int);
void put(struct team *head);

int main(void){
    struct team *head = NULL;
    int cont = 0;
    char wish,seguir,opcion = ' ';
    do{
        cont = cont + load(&head);
        cout<<"Desea continuar agregando equipos ? y/n"<<endl;
        cin>>wish;
    }while(wish=='y' || wish=='Y');

    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Mostrar el listado de equipos que participaron en el torneo"<<endl;
        cout<<"b) Mostrar el/los equipo/s ganador/es con su puntaje"<<endl;
        cout<<"c) Mostrar todos los equipos que no perdieron ningun partido"<<endl;
        cout<<"d) Grabar datos en un archivo"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            {
                show_team(head);
                break;
            }
            case 'b':
            {
                show_winners(head);
                break;
            }
            case 'c':
            {
                show_dontlosses(head,cont);
                break;
            }
            case 'd':
            {
                put(head);
                break;
            }
            default:
            {
                cout<<"Ingrese una opcion existente"<<endl;
            }
        }
        cout<<"Desea continuar con el programa ? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir=='Y');

}

int load(struct team **head){
    struct team *new_node = NULL;
    struct team *temp = NULL;
    int cont = 0;
    int wins,draw,loss,scoreboard = 0;
    char name[50];
    new_node = (struct team *) malloc(sizeof(team));
    new_node = (struct team *) new_node;
    if(new_node==NULL){
        cout<<"No memory available"<<endl;
        exit(0);
    }
    cout<<"Ingrese el nombre del equipo"<<endl;
    cin>>name;
    cout<<"Ingrese la cantidad de partidos ganados"<<endl;
    cin>>wins;
    cout<<"Ingrese la cantidad de partidos empatados"<<endl;
    cin>>draw;
    cout<<"Ingrese la cantidad de partidos perdidos"<<endl;
    cin>>loss;
    scoreboard = (wins*3) - (2*loss);
    for(int i=0;i<50;i++){
        new_node->name[i] = name[i];
    }
    new_node->wins = wins;
    new_node->draw = draw;
    new_node->loss = loss;
    new_node->scoreboard = scoreboard;
    new_node->next = NULL;
    if(*head==NULL){
        *head = new_node;
    } else{
        temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    cont++;
    return cont;
}

void show_team(struct team *head){
    struct team *temp = NULL;
    temp = head;
    cout<<"Equipos: "<<endl;
    while(temp!=NULL){
        cout<<temp->name<<endl;
        temp = temp->next;
    }
}

void show_winners(struct team *head){
    int maxscore = 0;
    char name[50];
    struct team *temp = NULL;
    temp = head;
    maxscore = temp->scoreboard;
    while(temp!=NULL){
        if(maxscore<temp->scoreboard){
            maxscore = temp->scoreboard;
        }
        temp = temp->next;
    }
    temp = head;
    cout<<"Equipos ganadores.."<<endl;
    while(temp!=NULL){
        if(temp->scoreboard == maxscore){
            cout<<"Equipo: "<<temp->name<<"\tPuntaje: "<<temp->scoreboard<<endl;
        }
        temp = temp->next;
    }


}

void show_dontlosses(struct team *head,int cont){
    struct team *temp = NULL;
    temp = head;
    bool flag = false;
    int i = 0;
    while(temp!=NULL){
        i++;
        if(temp->loss==0){
            cout<<"Equipo: "<<temp->name<<endl;
            flag = true;
        } else if(flag==false && i==cont){
            cout<<"No hay ningun equipo que no haya nunca perdido"<<endl;
        }
        temp = temp->next;
    }

}

void put(struct team *head){
    FILE *fp;
    struct team *temp = NULL;
    fp=fopen("puntaje.txt","w");
    temp = head;
    fprintf(fp,"Team:\tScore:\n");
    while(temp!=NULL){
        fprintf(fp,"%s\t%d\n",temp->name,temp->scoreboard);
        temp = temp->next;
    }
    fclose(fp);
    cout<<"Datos guardados con exito"<<endl;
}