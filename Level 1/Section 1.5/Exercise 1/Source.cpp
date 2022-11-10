#include <stdio.h>
//function defintion 
float minus(float a, float b){
	return a - b;//returning the difference
}
int main() {
	float a, b;
	printf("Enter the first argument:\n");
	scanf_s("%f", &a);
	printf("Enter the second argument:\n");
	scanf_s("%f", &b);
	printf("The difference is %f", minus(a, b));//function call
	return 0;
}