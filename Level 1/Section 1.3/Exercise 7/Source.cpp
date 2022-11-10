#include <stdio.h>
int main() {
	int input,n;
	printf("Please enter the input and the power n to which 2 will be raised\n");
	scanf_s("%d%d", &input,&n);
	printf("The final answer is %d", input << n);//bitshift to the left by n places
	return 0;
}