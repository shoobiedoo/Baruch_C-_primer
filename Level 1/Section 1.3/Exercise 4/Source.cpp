#include <stdio.h>
int main() {
	int married;//the integer which refers to the non zero / zero number
	printf("Please enter a number");
	scanf_s("%d", &married);
	printf("%s", married ? "Person is married" : "Person is not married");
	return 0;
}