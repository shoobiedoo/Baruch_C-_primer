#include <stdio.h>
int main()
{
	int x;
	x = -3 + 4 * 5 - 6;
	// x is 11
	printf("x=%d\n", x);
	x = 3 + 4 % 5 - 6;
	//x is 1
	printf("x=%d\n", x);
	x = -3 * 4 % -6 / 5;
	//x is 0
	printf("x=%d\n", x);
	x = (7 + 6) % 5 / 2;
	//x is 1
	printf("x=%d\n", x);
	return 0;
}