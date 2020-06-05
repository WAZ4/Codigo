#include <stdio.h>
#include <string.h>

char str[50];

void separarString() {

	int i, ctd;

	for (int i = 0; i < strlen(str); ++i)
	{
		if (str[i] == ' ');{
			
		}
		ctd += 1;
	}
}


int main () {
	strcpy( str, "WAZA WAZA#");
	printf("%s", str);

}