/* Assignment operators */
#include <stdio.h>
int main()
{
	int x = 2;
	int y;
	int z;
	x *= 3 + 2;//first adds the numbers and then mulitplies the sum by existing value of x which is 2 
	printf("x=%d\n", x);//output is x=10
	x *= y = z = 4;//assigns y and z to 4 and updates x as 40
	printf("x=%d\n", x);//output is x=40
	x = y == z;// assigns x to the boolean value of the given equality which is True or 1 in this case
	printf("x=%d\n", x);//output is x=1
	return 0;
}
