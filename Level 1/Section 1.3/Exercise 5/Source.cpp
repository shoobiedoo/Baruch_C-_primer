#include <stdio.h>
int main() {
	int i = 0;
	printf("Initial Value of i = %d\n", i);
	printf("i-- keeps the value of i as %d for current step and updates it to %d for futher steps.\n", i--,i);//demonstrating how i-- updates the value in both the current step and the next step
	i = 0;	// reinitalizing i to 0 for comparison
	printf("While --i changes value of i to %d for current step and keeps it as %d for further steps.", --i, i);;//demonstrating how --i updates the value in both the current step and the next step
	return 0;
}