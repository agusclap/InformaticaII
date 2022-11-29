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
    int draw;
    int loss;
    int scoreboard;
    struct team *next;
};

int load(struct team **front,struct team **back);
void show_teams(struct team *front);
void show_winner(struct team *front);
void show_dontlosses(struct team *front, int);
void put(struct team *front);

int main(void){
    char wish,opcion,seguir = ' ';
    int cont = 0;
    struct team *front = NULL;
    struct team *back = NULL;
    do{
        cont = cont + load(&front,&back);
        cout<<"Desea agregar mas equipos ? y/n"<<endl;
        cin>>wish;
    }while(wish=='y' || seguir == 'Y');

    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Mostrar el listado de los equipos que participaron"<<endl;
        cout<<"b) Mostrar el equipo ganador con su puntaje"<<endl;
        cout<<"c) Mostrar todos los equipos que nunca perdieron un partido"<<endl;
        cout<<"d) Grabar un archivo"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            {
                show_teams(front);
                break;
            }
            case 'b':
            {
                show_winner(front);
                break;
            }
            case 'c':
            {
                show_dontlosses(front,cont);
                break;
            }
            case 'd':
            {
                put(front);
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


int load(struct team **front, struct team **back){
    int wins,draw,loss,scoreboard = 0;
    char name[50];
    struct team *new_node=NULL;
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
    scoreboard = (wins*3) - (loss*2);
    for(int i=0;i<50;i++){
        new_node->name[i] = name[i];
    }
    new_node->wins = wins;
    new_node->draw = draw;
    new_node->loss = loss;
    new_node->scoreboard = scoreboard;
    new_node->next = NULL;
    if(*back==NULL){
        *back = new_node;
        *front = *back;
    }else{
        (*back)->next = new_node;
        *back = new_node;
    }
}

void show_teams(struct team *front){
    struct team *temp = NULL;
    temp = front;
    cout<<"Equipos: "<<endl;
    while(temp!=NULL){
        cout<<"- "<<temp->name<<endl;
        temp = temp->next;
    }
}

void show_winner(struct team *front){
    int maxscore = 0;
    struct team *temp = NULL;
    temp = front;
    maxscore = temp->scoreboard;
    while(temp!=NULL){
        if(maxscore<temp->scoreboard){
            maxscore = temp->scoreboard;
        }
        temp = temp->next;
    }
    temp = front;
    cout<<"Equipos ganador/es...."<<endl;
    cout<<"---------------"<<endl;
    cout<<"Equipo\tScore"<<endl;
    cout<<"---------------"<<endl;
    while(temp!=NULL){
        if(temp->scoreboard==maxscore){
            cout<<temp->name<<"\t"<<temp->scoreboard<<endl;
            cout<<"---------------"<<endl;
        }
        temp = temp->next;
    }
}

void show_dontlosses(struct team *front, int cont){
    struct team *temp=NULL;
    temp = front;
    int i=0;
    bool flag = false;
    cout<<"Equipos que nunca perdieron.."<<endl;
    while(temp!=NULL){
        i++;
        if(temp->loss==0){
            cout<<"- "<<temp->name<<endl;
            flag = true;
        }else if(flag==false && cont==i){
            cout<<"No hay ningun equipo que nunca haya perdido"<<endl;
        }
        temp = temp->next;
    }
}

void put(struct team *front){
    FILE *fp;
    struct team *temp = NULL;
    temp = front;
    fp = fopen("puntaje.txt","w");
    if(fp==NULL){
        cout<<"Unable to open the file"<<endl;
        exit(0);
    }
    fprintf(fp,"Equipo\tPuntaje\n");
    while(temp!=NULL){
        fprintf(fp,"%s\t%d\n",temp->name,temp->scoreboard);
        temp = temp->next;
    }
    fclose(fp);
    cout<<"Datos guardados con exito"<<endl;
}