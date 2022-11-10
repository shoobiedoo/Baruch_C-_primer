#include <stdio.h>
void swap(double* a, double* b) {//method for swapping 
	double temp;//using temp variable for swapping
	temp = *a;
	*a = *b;
	*b = temp;
}
int main() {
	double a,b;//Declaring both the numbers
	printf("Enter both the number a and b:\n");
	scanf_s("%lf%lf", &a, &b);//taking the input for both the numbers
	printf("Numbers before swapping a=%lf and b=%lf\n",a,b);//displaying the numbers before swapping
	swap(&a,&b);//function call for swapping a and b(passing the address using & for both the variables)
	printf("Numbers after swapping a=%lf and b=%lf", a, b);//displaying the numbers after swapping
	return 0;
}