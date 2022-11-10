#include <stdio.h>
#include "Defs.h"
int main() {
	double x,y,z;// declaring all the three variables
	printf("Enter x and y and z :\n");
	scanf_s("%lf%lf%lf", &x, &y, &z); // Asking the user for input for all the three variables
	printf("The max between %lf and %lf is %lf\n", x, y, MAX2(x, y));	//printing max between x and y using first macro
	printf("The max between %lf, %lf and %lf is %lf", x, y, z, MAX3(x, y, z));//printing max between x,y and z using second macro
	return 0;
}