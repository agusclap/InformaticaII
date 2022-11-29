#include <iostream>
#include <ctime>
using namespace std;

struct node{
	int data;
	struct node *next;
};

int main(int argc, char *argv[]) {
	struct node *head = NULL;
	struct node *temp = NULL;
	struct node *new_node = NULL;
	int dato, i = 0;
	srand(time(NULL));
	do{
		dato = rand ()%50+1;
		new_node = (struct node *) malloc(sizeof(struct node));
		new_node = (struct node *) new_node;
		if(new_node==NULL){
			cout<<"No hay memoria disponible"<<endl;
			exit(0);
		}
		new_node->data=dato;
		new_node->next=NULL;
		if(head==NULL){
			head=new_node;
		}else{
			temp=head;
			while(temp->next=NULL){
				temp=temp->next;
			}
			temp->next=new_node;
		}
		i++;
	} while(i!=5);
	if(head==NULL){
		cout<<"Lista vacia"<<endl;
		exit(0);
	}else{
		node *temp= head;
		cout<<"Multiplos de 5"<<endl;
		while(temp!=NULL)
		{
			if(temp->data%5==0)
			{
				cout<<""<<temp->data<<endl;
			}
			temp = temp->next;
		}
	}
	return 0;
}

