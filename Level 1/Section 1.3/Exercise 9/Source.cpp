/* Conditional expressions */
#include <stdio.h>
int main()
{
	int x = 1;
	int y = 1;
	int z = 1;
	x += y += x;//y is 2 ; x is 3
	printf("%d\n\n", (x < y) ? y : x); // output is 3
	printf("%d\n", (x < y) ? x++ : y++); // output is 2 as x>y and y is incremented to 3
	printf("%d\n", x); // output is 3
	printf("%d\n", y); // output is 3
	return 0;
}
