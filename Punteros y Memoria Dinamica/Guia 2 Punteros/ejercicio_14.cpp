#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
	int vector[2][3] = {0};
	int *p[2][3] = {NULL};
	srand(time(NULL));
	
	for(int i=0;i<2;i++)
	{
		for (int ii=0;ii<3;ii++)
		{
			vector[i][ii] = rand () % 100;
			p[i][ii] = &vector[i][ii];
			
		}
	}
	cout<<"Resultado: "<<endl;
	for(int j=0;j<2;j++){
		for(int jj=0;jj<3;jj++)
		{
			cout<<""<<(*p[j][jj])<<"\t";
			
		}
		cout<<endl;
	}
	return 0;
}

