#include <stdio.h>
void printnumber(int n) {
	int digit = n % 10;//taking out the last digit and printing it in the end after performing the rest of the recursion
	if((n/10)!=0)//condition to exit recursion; This solution will not print the succeeding zeros for example for 0123 will only print 123
		printnumber(n / 10);
	putchar(digit + '0');//printing the character
}
int main(){
	int n;
	printf("Please enter the number:\n");
	scanf_s("%d", &n);
	printf("The number is :");
	printnumber(n);//function call
	return 0;

}