#include <stdio.h>
int main() {
	int zero = 0, one = 0, two = 0, three = 0, four = 0, flag = 1;//number counters and flag to exit the loop
	printf("Please enter your string:\n");
	while (flag) {
		char current = getchar();
		switch (current) {
		case '0':
			zero++;
			break;
		case '1':
			one++;
			break;
		case '2':
			two++;
			break;
		case '3':
			three++;
			break;
		case '4':
			four++;
			break;
		case EOF:
			flag = 0;
			break;
		}
	}
	printf("zeroes : %d \n", zero);
	printf("ones : %d \n", one);
	printf("twos : %d \n", two);
	printf("threes : The number three appears %s times \n", three<3?(three==0?"zero":(three==1?"one":"two")):"more than two");//nested ternary 
	printf("fours : %d \n", four);
	return 0;
}