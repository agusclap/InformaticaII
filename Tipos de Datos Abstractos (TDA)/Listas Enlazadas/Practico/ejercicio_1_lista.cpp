#include <iostream>
using namespace std;

struct node {
	int data;
	struct node *next;
};
int main(int argc, char *argv[]) {
	int dato = 0;
	char seguir = ' ';
	struct node* head=NULL;
	struct node* temp= NULL;
	struct node *new_node=NULL;
	do{
		cout<<"Ingrese un dato"<<endl;
		cin>>dato;
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node = (struct node *) new_node;
		if(new_node==NULL)
		{
			cout<<"No hay memoria dispobible"<<endl;
			exit(0);
		}
		new_node->data = dato;
		new_node->next = NULL;
		if(head==NULL)
		{
			head = new_node;
			
		} else{
			temp=head;
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next=new_node;
		}
		cout<<"Desea continuar? y/n"<<endl;
		cin>>seguir;
	} while(seguir=='y' || seguir=='Y');
	temp = head;
	while(temp!= NULL)
	{
		cout<<temp->data<<endl;
		temp = temp -> next;
		
	}
	return 0;
}

