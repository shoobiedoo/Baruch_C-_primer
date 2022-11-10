/* Predict what will be printed on the screen */
#include <stdio.h>
#define PRD(a) printf("%d", (a) ) // Print decimal
#define NL printf("\n"); // Print new line
// Create and initialse array
int a[] = { 0, 1, 2, 3, 4 };
int main()
{
	int i;
	int* p;
	for (i = 0; i <= 4; i++) PRD(a[i]); // 1 prints 01234  because prints initial array elements from index 0 to 4
	NL;
	for (p = &a[0]; p <= &a[4]; p++) PRD(*p); // 2 prints 01234 because &a[0] refers to the first array element 
	NL;										//and &a[4] refers to the address of the last array element and we are printing the dereferenced value of those addresses
	NL;
	for (p = &a[0], i = 0; i <= 4; i++) PRD(p[i]); // 3 prints 01234 because we are using the base address of the array and then accessing the values using the index 
	NL;
	for (p = a, i = 0; p + i <= a + 4; p++, i++) PRD(*(p + i)); // 4 prints 024 because we are incrementing both p and i and we are comparing their sum hence everything is incremented by 2
	NL;
	NL;
	for (p = a + 4; p >= a; p--) PRD(*p); // 5 prints 43210 same as the second one but we are going in a descending order and are using the array name as the address 
	NL;
	for (p = a + 4, i = 0; i <= 4; i++) PRD(p[-i]); // 6 prints 43210 as we are accessing from the end of the array hence indices can go backwards
	NL;
	for (p = a + 4; p >= a; p--) PRD(a[p - a]); // 7 prints 43210 because p-a tell the relative difference between the starting address a and p which is going backwards
	NL;
	return 0;
}
