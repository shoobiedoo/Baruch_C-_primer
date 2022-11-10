#include <stdio.h>
int main() {
	int input,shiftedInput;
	printf("Please enter the input");
	scanf_s("%d", &input);
	shiftedInput = input >> 2;//shifting the number to 2 places to the right
	printf("%s Shift of the number %d is %d",(input<0&&shiftedInput>0)?"Logical":"Arithmetic", input, shiftedInput);
	return 0;
}