#include <iostream>
using namespace std;

void intercambiar(int *a, int *b) {
	int temporal = *a;
	*a = *b;
	*b = temporal;
}

int main(void) {
	int edad1 = 10, edad2 = 20;
	printf("Antes de intercambiar. edad1: %d, edad2: %d\n", edad1, edad2);
	intercambiar(&edad1, &edad2);
	printf("Después de intercambiar. edad1: %d, edad2: %d", edad1, edad2);
	return 0;

}

