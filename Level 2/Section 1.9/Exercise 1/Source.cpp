#include<stdio.h>
int main() {
	char c = 0;//initial input so that the 1 in the while condition is not compared with a garbage value
	while (c != 1) { //loop exit condition 
		c = getchar();//taking the input from console
		if (c == 1) {
			printf("CTRL + A is a correct ending.");
			break;//exiting the loop once ctr+A is clicked so that before reaching the while condition itself it breaks
		}
		putchar(c);//printing the input to console
	}return 0;
}