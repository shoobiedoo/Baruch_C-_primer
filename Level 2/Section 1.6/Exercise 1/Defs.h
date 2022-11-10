#ifndef DEFS_H//Avoiding multiple inclusion
#define DEFS_H

#ifndef PRINT(a)//Precautionary multiple inclusion avoidance
#define PRINT1(a) printf("Printing a: %d\n",a);//Defining macro 1 for printing A
#endif

#ifndef PRINT2(a,b)//Precautionary multiple inclusion avoidance
#define PRINT2(a,b) printf("Printing a: %d and b: %d",a,b);// Defining macro 2 for printing both the numbers A and B
#endif

#endif