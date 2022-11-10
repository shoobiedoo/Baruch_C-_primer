#include <stdio.h>
int main() {
	float startingFRange = 20;// starting range of fahrenheit table
	float endingFRange = 300;//ending range of fahrenheit table
	float steps = 20.0f;//table increment for fahrenheit
	printf("Fahrenheit		Celsius\n");
	while (startingFRange <= endingFRange) {
		float celsius = ((startingFRange - 32) * 5 )/ 9;//can use double for larger values
		printf("%10.1f	%10.1f\n", startingFRange, celsius);
		startingFRange += steps;//table increment
	}
	return 0;
}