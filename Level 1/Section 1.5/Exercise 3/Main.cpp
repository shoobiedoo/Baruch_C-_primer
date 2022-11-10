#include <stdio.h>
#include "Print.cpp"
int main() {
	float i;//initial number
	printf("Please enter i : \n");
	scanf_s("%f", &i);
	print(i);//calling the method inside print.cpp
	return 0;
}