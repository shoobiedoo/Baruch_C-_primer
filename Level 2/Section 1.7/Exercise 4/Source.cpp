#include <stdio.h>
int main() {
	int dayNumber;// Day number to be inputted
	char daysOfWeek[7][10] = {"Sunday","Monday", "Tuesday","Wednesday","Thursday", "Friday","Saturday"};//harcoding the array of strings with days of the week

	printf("Enter the day number\n");
	scanf_s("%d",&dayNumber);//Taking day input 

	if (dayNumber >= 1 && dayNumber <= 7) {
		printf("The %d day of week is %s", dayNumber, daysOfWeek[dayNumber-1]);//Decreasing the day number by 1 for adjusting for zero based indexing
	}
	else {
		printf("Invalid input, please input a number between 1 and 7");//If the number is not range; ask for valid input
	}
	return 0;
}