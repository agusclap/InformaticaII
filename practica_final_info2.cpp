/*Desarrolle un programa que cree una estructura llamada Calificaciones de la materia Ingles, en la cual tiene los siguientes atributos: 
nombre de alumno, nota1, nota2, nota3, recuperatorio, nota final, resultado. 
La nota final  es el promedio de las 3 notas y en el caso de que tuvo un ausente o reprobó una instancia, 
puede rendir el recuperatorio. La carga de las notas 1,2, 3 y recuperatorio deben ser aleatorias entre 0 y 10. 
En caso de que la nota o el recuperatorio sea 0 significa q es ausente. En caso de que el alumno haya aprobado las 3 instancias, 
no rinde recuperatorio entonces su valor es -1. En el caso de que el alumno se ausenta en una instancia y en el recuperatorio pieden 
la posibilidad de aprobar (no se le calcula el promedio)

Luego crear una lista de calificaciones, y cargar los datos del informe de calificaciones. 
El promedio debe ser calculado por una función. Una vez cargada la lista, mostrar un menu de opciones con los siguientes datos:

1. Mostrar el listado de calificaciones del curso.

2. Mostrar el mejor alumno. (En caso de que haya mas de uno, mostrarlos a todos)

3. Mostrar todos los alumnos que reprobaron (promedio menor a 4).

4. Mostrar todos los alumnos que aprobaron (promedio mayor o igual a 4).

5. Mostrar todos los alumnos que tuvieron al menos un ausente (nota 1,2 o 3 tiene un 0).

5. Contar cuantos alumnos en total hay en el curso.

6. Grabar un archivo llamado calificaciones.txt en donde se listen los datos
*/

#include <iostream>
#include <ctime>
#include<stdio.h>
#include<conio.h>
using namespace std;

struct Calificaciones {
    char nombre[50];
    float nota1;
    float nota2;
    float nota3;
    float recuperatorio;
    float nota_final;
    char resultado[15];
    struct Calificaciones *next;
};

void cargar(struct Calificaciones **stackptr);
void mostrar_curso(struct Calificaciones *);
void mostrar_mejor(struct Calificaciones *);
void mostrar_reprobados(struct Calificaciones *);
void mostrar_aprobados(struct Calificaciones *);
void contar_alumnos(struct Calificaciones *);
void mostrar_ausentes(struct Calificaciones *);
void archivo(struct Calificaciones *);

int main(void){
    int opcion = 0;
    char seguir = ' ';
    struct Calificaciones *stackptr=NULL;
    cargar(&stackptr);
    do{
        cout<<"1) Mostrar el listado de calificaciones del curso"<<endl;
        cout<<"2) Mostrar el mejor alumno"<<endl;
        cout<<"3) Mostrar todos los alumnos que reprobaron"<<endl;
        cout<<"4) Mostrar todos los alumnos que aprobaron"<<endl;
        cout<<"5) Contar cuantos alumnos en total hay en el curso"<<endl;
        cout<<"6) Mostrar todos los alumnos que al menos tuvieron un ausente"<<endl;
        cout<<"7) Grabar un archivo"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
            {
                mostrar_curso(stackptr);
                break;
            }
            case 2:
            {
                mostrar_mejor(stackptr);
                break;
            }
            case 3:
            {
                mostrar_reprobados(stackptr);
                break;
            }
            case 4:
            {
                mostrar_aprobados(stackptr);
                break;
            }
            case 5:
            {
                contar_alumnos(stackptr);
                break;
            }
            case 6:
            {
                mostrar_ausentes(stackptr);
                break;
            }
            case 7:
            {
                archivo(stackptr);
                break;
            }
            default:
            {
                cout<<"Ingrese una opcion existente.."<<endl;
            }
        }
        cout<<"Desea continuar con el programa ? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir=='Y');

}

void cargar (struct Calificaciones **stackptr){
    bool flag,recup = true;
    char seguir = ' ';
    srand(time(NULL));
    char nombre[50];
    char aprobado[15]="Aprobado";
    char desaprobado[15] ="Desaprobado";
    float nota1=0,nota2=0,nota3=0,nota_final=0;
    float recuperatorio=0;
    float promedio = 0;
    do{
        struct Calificaciones *new_node=NULL;
        new_node = (struct Calificaciones *) malloc(sizeof(struct Calificaciones));
        new_node = (struct Calificaciones *) new_node;
        if(new_node == NULL){
            cout<<"No memory available"<<endl;
            exit(0);
        }
        cout<<"Ingrese el nombre del alumno"<<endl;
        cin>>nombre;
        nota1 = rand () % 10;
        nota2 = rand () % 10;
        nota3 = rand() % 10;
        recuperatorio = rand() % 10;
        if(nota1<4 || nota2<4 || nota3<4){
            if(recuperatorio>=4){
                recup = false;
            }else{
                for(int i=0;i<15;i++){
                    new_node->resultado[i] = desaprobado[i];
                }
            }
        }else if(nota1>=4 && nota2>=4 && nota3>=4){
            recuperatorio = -1;
            flag = true;
            for(int i=0;i<15;i++){
                new_node->resultado[i] = aprobado[i];
            }
            
        }
        if(recuperatorio==0 && (nota1==0 || nota2==0 || nota3==0)){
            flag = false;
        }

        for(int i=0;i<50;i++){
            new_node->nombre[i] = nombre[i];
        }
        new_node->nota1 = nota1;
        new_node->nota2 = nota2;
        new_node->nota3 = nota3;
        new_node->recuperatorio = recuperatorio;
        if(flag==true){
            promedio = (nota1+nota2+nota3)/3;
            new_node->nota_final = promedio;
        }else if(recup==false){
            if(nota1==0){
                promedio = (nota2+nota3+recuperatorio)/4;
                new_node->nota_final = promedio;
                if(new_node->nota_final>=4){
                    for(int i=0;i<15;i++){
                        new_node->resultado[i] = aprobado[i];
                    }
                }else{
                    for(int i=0;i<15;i++){
                        new_node->resultado[i] = desaprobado[i];
                    }
                }        
            }else if(nota2==0){
                promedio = (nota1+nota3+recuperatorio)/4;
                new_node->nota_final = promedio;
                if(new_node->nota_final>=4){
                    for(int i=0;i<15;i++){
                        new_node->resultado[i] = aprobado[i];
                    }
                }else{
                    for(int i=0;i<15;i++){
                        new_node->resultado[i] = desaprobado[i];
                    }
                }        
            }else if(nota3==0){
                promedio = (nota1+nota2+recuperatorio)/4;
                new_node->nota_final = promedio;
                if(new_node->nota_final>=4){
                    for(int i=0;i<15;i++){
                        new_node->resultado[i] = aprobado[i];
                    }
                }else{
                    for(int i=0;i<15;i++){
                        new_node->resultado[i] = desaprobado[i];
                    }
                }    
            }
        }else{
            new_node->nota_final=0; //desaprobado
        }
        
        new_node->next=*stackptr;
        *stackptr = new_node;
        cout<<"Alumno Cargado.."<<endl;
        cout<<"Desea continuar cargando alumnos ? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir=='Y');
}

void mostrar_curso(struct Calificaciones *stackptr){
    struct Calificaciones *temp = NULL;
    temp = stackptr;
    cout<<"INFORME DE CALIFICACIONES DE INGLES"<<endl;
    cout<<"Alumno\tNota1\tNota2\tNota3\tRecup\tProm\tResultado"<<endl;
    while(temp!=NULL){
        cout<<temp->nombre<<"\t"<<temp->nota1<<"\t"<<temp->nota2<<"\t"<<temp->nota3<<"\t"<<temp->recuperatorio<<"\t"<<temp->nota_final<<"\t"<<temp->resultado<<endl;
        temp = temp->next;
    }
}

void mostrar_mejor(struct Calificaciones *stackptr){
    struct Calificaciones *new_node = NULL;
    new_node = stackptr;
    float nota_max = 0;
    int i=0;
    while(new_node!=NULL){
        if(nota_max<new_node->nota_final){
            nota_max =  new_node->nota_final;
        }
        new_node = new_node->next;
    }
    new_node = stackptr;
    cout<<"El/Los mejor/es del curso son:"<<endl;
    while(new_node!=NULL){
        if(nota_max==new_node->nota_final){
            cout<<new_node->nombre<<endl;
        }
        new_node = new_node->next;
    }
}

void mostrar_reprobados(struct Calificaciones *stackptr){
    struct Calificaciones *new_node=NULL;
    new_node = stackptr;
    cout<<"Los alumnos reprobados:"<<endl;
    while(new_node!=NULL){
        if(new_node->nota_final<4){
            cout<<new_node->nombre<<endl;
        }
        new_node = new_node->next;
    }
}

void mostrar_aprobados(struct Calificaciones *stackptr){
    struct Calificaciones *new_node = NULL;
    new_node = stackptr;
    cout<<"Alumnos que aprobaron: "<<endl;
    while(new_node!=NULL){
        if(new_node->nota_final>=4){
            cout<<new_node->nombre<<endl;
        }
        new_node = new_node->next;
    }
}

void contar_alumnos(struct Calificaciones *stackptr){
    struct Calificaciones *new_node=NULL;
    int cont=0;
    new_node = stackptr;
    while(new_node!=NULL){
        cont++;
        new_node = new_node->next;
    }
    cout<<"La cantidad de alumnos en el curso es "<<cont<<endl;
}

void mostrar_ausentes(struct Calificaciones *stackptr){
    struct Calificaciones *new_node=NULL;
    new_node = stackptr;
    cout<<"Alumnos con al menos un ausente"<<endl;
    while(new_node!=NULL){
        if(new_node->nota1==0 || new_node->nota2==0 || new_node->nota3==0 || new_node->recuperatorio==0 ){
            cout<<new_node->nombre<<endl;
        }
        new_node=new_node->next;
    }
}

void archivo(struct Calificaciones *stackptr){
    struct Calificaciones *new_node=NULL;
    new_node = stackptr;
    FILE *fp;
    fp=fopen("calificaciones.txt","w");
    fprintf(fp,"CALIFICACIONES DE INGLES\n");
    fprintf(fp,"Alumno\tNota1\tNota2\tNota3\tRecup\tProm\tResultado\n");
    while(new_node!=NULL){
        fprintf(fp,"%s\t%f\t%f\t%f\t%f\t%f\t%s\n",new_node->nombre,new_node->nota1,new_node->nota2,new_node->nota3,new_node->recuperatorio,new_node->nota_final,new_node->resultado);
        new_node = new_node->next;
    }
    fclose(fp);
}