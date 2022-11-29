#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
	
	int arreglo[2][3];
	srand(time(NULL));
	int *ptr[2][3];
	
	for (int i=0;i<2;i++)
	{
		for(int ii=0;ii<3;ii++)
		{
			arreglo[i][ii] = rand()%100;
			ptr[i][ii] = &arreglo[i][ii];
		}
		
	}
	
	for (int k=0;k<2;k++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<*ptr[k][j]<<endl;
		}
		
		
	}
	return 0;
}

