#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "closest_points.c"

// Test driving
int main(){
    struct Point plain[5] = {{34,31},{1,8},{13,14},{25,133},{23,15}};
    int n = sizeof(plain)/sizeof(plain[0]);

    struct Point *closest = bFClosestPoints(plain,n) ;
    printf( "Closest Pairs: \n"
            "X1: %i Y1: %i\n"
            "X2: %i Y2: %i\n", closest[0].x, closest[0].y, closest[1].x, closest[1].y);

    return 0;

}
