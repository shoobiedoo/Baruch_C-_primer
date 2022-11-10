#ifndef DEFS_H//Avoiding multiple inclusion
#define DEFS_H

#ifndef MAX2(x,y)//Precautionary multiple inclusion avoidance
#define MAX2(x,y) ((x>y)?x:y)//Defining macro 1 for finding max between x and y
#endif

#ifndef MAX3(x,y,z)//Precautionary multiple inclusion avoidance
#define MAX3(x,y,z) ((x > y) ? (x > z ? x : z) : (y > z ? y : z))// Defining macro 2 for first finding x and y and then comparing it with z
#endif

#endif