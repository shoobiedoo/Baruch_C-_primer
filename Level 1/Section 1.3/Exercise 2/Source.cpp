#include <stdio.h>
int main() {
	double base, height;
	printf("Please enter the base and height of the triangle");
	scanf_s("%lf%lf", &base, &height);
	double area = (base * height) / 2;
	printf("The area of the triangle is %lf", area);
	return 0;
}