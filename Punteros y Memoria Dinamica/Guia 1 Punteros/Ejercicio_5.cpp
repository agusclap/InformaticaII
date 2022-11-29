#include <iostream>
#include <math.h>
using namespace std;

int sumar(float *,float *);
int restar(float *,float *);
int multiplicar(float *,float *);
float dividir(float *,float *);
int elevar(float *,float *);
float raizz(float *,float *);

int main(int argc, char *argv[]) {
	
	int suma,resta,mult,elev = 0;
	float divid,raiz,n1,n2 = 0;
	char opcion,seguir = ' ';
	cout<<"Ingrese dos numeros"<<endl;
	cin>>n1;
	cin>>n2;
	do{
	cout<<"MENU DE OPCIONES: "<<endl;
	cout<<"a)Sumar"<<endl;
	cout<<"b)Restar"<<endl;
	cout<<"c)Dividir"<<endl;
	cout<<"d)Multiplicar"<<endl;
	cout<<"e)Elevar al cuadrado"<<endl;
	cout<<"f)Raiz cuadrada"<<endl;
	cin>>opcion;
	switch(opcion){
	case 'a':
		suma= sumar(&n1,&n2);
		cout<<"La suma es: "<<suma<<endl;
		break;
	case 'b':
		resta = restar(&n1,&n2);
		cout<<"La resta es: "<<resta<<endl;
		break;
	case'c':
		cout<<(n1/n2)<<endl;
		divid = dividir(&n1,&n2);
		cout<<"La division es: "<<divid<<endl;
		break;
	case 'd':
		mult = multiplicar(&n1,&n2);
		cout<<"La multiplicacion es: "<<mult<<endl;
		break;
	case 'e':
		elev = elevar(&n1,&n2);
		cout<<"El numero elevado da "<<elev<<endl;
		break;
	case 'f':
		raiz = raizz(&n1,&n2);
		cout<<"La raiz es: "<<raiz<<endl;
		break;
	default:
		cout<<"Ingrese una opcion correcta"<<endl;
	}
	cout<<"Desea continuar ? y/n"<<endl;
	cin>>seguir;
	}while(seguir=='y' || seguir=='Y');
	return 0;
}

int sumar(float *n1, float *n2)
{
	return ((*n1)+(*n2));	
}
int restar(float *n1, float *n2)
{
	return ((*n1)-(*n2));	
}

float dividir(float *n1, float *n2)
{
	return (*n1)/(*n2);
}

int multiplicar(float *n1, float *n2)
{
	return ((*n1)*(*n2));	
}

int elevar(float *n1, float *n2)
{
	int resp,elevar=0;
	
	cout<<"Cual numero quiere elevar "<<*n1<<" o "<<*n2<<endl;
	cin>>resp;
	if(resp==*n1)
	{
		elevar = pow((*n1), 2);
		
	}
	if(resp==*n2)
	{
		elevar = pow((*n2), 2);
		
	}
	return elevar;
}

float raizz(float *n1, float *n2)
{
	float raiz=0;
	float resp = 0;
	cout<<"Cual numero quiere hacer raiz cuadrada "<<*n1<<" o "<<*n2<<endl;
	cin>>resp;
	if(resp==*n1)
	{
		raiz = sqrt((*n1));
		
	}
	if(resp==*n2)
	{
		raiz = sqrt((*n2));
		
	}
	return raiz;
	
}
