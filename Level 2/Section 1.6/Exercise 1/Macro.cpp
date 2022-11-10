#include <stdio.h>
#include "Defs.h"//include the defs header file
int main() {
	int a, b;// declaring both the variables
	printf("Enter a and b :\n");
	scanf_s("%d%d",&a,&b); // Asking the user for inputting both a and b
	PRINT1(a)	//printing A using first macro
	PRINT2(a,b)	//printing A and B using second macro
	return 0;
}