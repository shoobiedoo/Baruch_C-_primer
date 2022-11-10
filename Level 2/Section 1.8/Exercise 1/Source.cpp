#include <stdio.h>
#include <stdlib.h>
typedef struct Article {
	int articleNumber;// article number
	int quantity;//	quantity
	char description[21];//initialised to 21 to acommodate for 20 characters and null character
}Article;

void Print(Article * article) {
	printf("Article number = %d\n", (*article).articleNumber);//display the article number
	printf("Article quantity = %d\n", (*article).quantity); // display the quantity of that article
	printf("Article description = %s", (*article).description); // display the description
}

int main() {
	Article  article = { 123,10,"12345678901234567890" };// Initial input for testing 
	Print(&article);//The print method to print all the article details with passing article address as a parameter
	return 0;
}