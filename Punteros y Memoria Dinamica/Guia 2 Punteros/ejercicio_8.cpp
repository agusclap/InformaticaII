#include <iostream>
using namespace std;

void minuscula(char *ptr[27]);
void mayuscula(char *ptr[27]);

int main(int argc, char *argv[]) {
	char cadena[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
		'ñ','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	char *ptr[27];
	
	for (int i=0;i<27;i++)
	{
		ptr[i] = &cadena[i];
		
	}
	minuscula(ptr);
	cout<<""<<endl;
	mayuscula(ptr);
	return 0;
}

void minuscula(char *ptr[27])
{
	cout<<"Abecedario en minuscula: "<<endl;
	for (int ii=0;ii<27;ii++)
	{
		cout<<*ptr[ii]<<"\t";
		
		
	}
	
}

void mayuscula(char *ptr[27])
{
	
	cout<<"Abecedario en mayuscula: "<<endl;
	for(int j=0;j<27;j++)
	{
		*ptr[j] = toupper(*ptr[j]);
		cout<<*ptr[j]<<"\t";
	}
	
}
