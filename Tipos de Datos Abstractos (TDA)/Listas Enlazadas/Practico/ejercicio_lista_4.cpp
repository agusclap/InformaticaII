#include <iostream>
using namespace std;

struct node{
	char data;
	struct node *next;
};

int main(int argc, char *argv[]) {
	struct node *head=NULL;
	struct node *temp=NULL;
	struct node *new_node=NULL;
	int i=0;
	char dato = ' ';
	do{
		cout<<"Ingrese una letra"<<endl;
		cin>>dato;
		new_node=(struct node *) malloc(sizeof(struct node));
		new_node = (struct node *) new_node;
		if(new_node==NULL)
		{
			cout<<"No hay memoria disponible"<<endl;
			exit(0);
		}
		new_node->data=dato;
		new_node->next=NULL;
		if(head==NULL)
		{
			head=new_node;
		} else{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=new_node;
		}
		i++;
	} while(i!=10);
	if(head==NULL)
	{
		cout<<"Lista vacia"<<endl;
		exit(0);
	} else{
		node *temp = head;
		cout<<"Las vocales son:"<<endl;
		while(temp!=NULL)
		{
			if(temp!=NULL)
			{
				if(temp->data=='a' || temp->data=='e' || temp->data=='i' || temp->data=='o' || temp->data=='u')
				{
					cout<<""<<temp->data<<endl;
				}
			}
			temp = temp->next;
		}
	}
	return 0;
}

