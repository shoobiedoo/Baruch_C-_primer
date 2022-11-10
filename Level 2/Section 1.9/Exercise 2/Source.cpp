#include <stdio.h>
#include <stdlib.h>
int main() {

	char c = 0;//initial input so that the 1 in the while condition is not compared with a garbage value
	FILE* opFile;//declaring the file pointer
	fopen_s(&opFile,"test.txt", "w+");//opening the file pointer/file in write mode 

	while (c != 1) { //loop exit condition 
		c = getchar();//taking the input from console
		if (c == 1) {
			fprintf(opFile,"CTRL + A is a correct ending.");//printing the exit statement inside the file 
			break;//exiting the loop once ctr+A is clicked so that before reaching the while condition itself it breaks
		}
		if (opFile != NULL) {
			fputc(c, opFile);//printing the input to console
		}
		else {
			printf("File pointer is null please check your file handling and the file you are trying to access");
		}
	}
	fclose(opFile);//closing the file pointer
	return 0;
}