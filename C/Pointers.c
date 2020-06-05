#include <stdio.h>


int lista[100] = {9,8,7,6,5,4,3,2,1,0};

void main() {
	int i;
	int *pointer;

	pointer = &lista;

	*pointer += 1;
   printf("Value of *ip variable: %d\n", *pointer );
}
