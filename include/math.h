#ifndef MATH_H
#define MATH_H


#include <math.h>

// Define MAX and MIN macros
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))


class Vector2 
{
    public:
        int x, y;
};

class Vector3 
{
    public:
        int x, y, z;
};



#endif