#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "closest_points.c"

// Test driving
int main(){
    struct Point opPlain[5] = {{34,31},{1,8},{13,14},{25,133},{23,15}};
    int oN = sizeof(opPlain)/sizeof(opPlain[0]);

    struct Point *opClosest = closestPoints(opPlain,oN) ;
    printf( "Closest Pairs: \n"
            "X1: %i Y1: %i\n"
            "X2: %i Y2: %i\n", opClosest[0].x, opClosest[0].y, opClosest[1].x, opClosest[1].y);

    return 0;

}
