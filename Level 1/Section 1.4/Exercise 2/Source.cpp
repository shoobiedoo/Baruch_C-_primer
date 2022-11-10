#include <stdio.h>
int main() {
	int loopControlVariable = 0;//the current character input
	int totalChar = 0, newLine = 0, words = 0;
	char prev = ' ';//the previous character ; initialised to space to account for the case where the input is starting with a space
	printf("Please enter your string:\n");
	do {
		loopControlVariable = getchar();
		totalChar++;
		if (loopControlVariable == '\n') {
			newLine++;//if a newline is seen
		}
		else if (loopControlVariable != ' ' && loopControlVariable != 4 && loopControlVariable != '\n') {
			/*For this code we are considering all characters other than space and control z and newline as the building blocks of words
			We can consider only alpha numeric characters as letters by just adding a condition where lowerCase(loopControlVariable)(>='a' and <='z' )||( >='0'&&<='9')
			*/
			if (prev == ' ' || prev == '\n')
				words++;
		}
		prev = loopControlVariable;
	} while (loopControlVariable != 4);//exit controlled loop doesnt waste an extra iteration 
	printf("The total number of characters excluding control D are %d \n", totalChar - 1);
	printf("The total number of characters including control D are %d \n", totalChar);
	printf("The total number of newlines are %d \n", newLine);
	printf("The total number of words are %d ", words);
	return 0;
}