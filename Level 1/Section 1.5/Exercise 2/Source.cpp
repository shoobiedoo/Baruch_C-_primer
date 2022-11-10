#include <stdio.h>
int factorial(int n) {
	if (n == 1 || n == 0)//base case to exit the recursion
		return 1;
	return n * factorial(n - 1);//recursive callback
}
int main() {
	int n;//input number
	printf("Please enter the number \n");
	scanf_s("%d",&n);
	if (n < 0)
		printf("Invalid input");
	else 
		printf("The factorial of %d is %d", n, factorial(n));
	return 0;
}