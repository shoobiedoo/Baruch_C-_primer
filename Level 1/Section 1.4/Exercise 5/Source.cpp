#include <stdio.h>
int main() {
	float startingCRange = 0;//starting range of Celsius
	float endingCRange = 19;//ending range of Celsius
	float steps = 1.0f;//step increment
	printf("Celsius		Fahrenheit\n");
	while (startingCRange <= endingCRange) {
		float fahrenheit = (9*startingCRange)/5+32;//conversion from celsius to fahrenheit
		printf("%10.1f	%10.1f\n", startingCRange, fahrenheit);
		startingCRange += steps;//table incremented
	}
	return 0;
}