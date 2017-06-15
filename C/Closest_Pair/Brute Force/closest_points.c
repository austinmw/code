/*
Coded by Omri Meshulam
A Brute Force method that takes a list of points on a plane,
and returns the two closest points. Parameters array of points P[] of size n
The code should include these headers
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "point.h"
//and the Point structure should adhere to contain the following 2 values
struct Point
{
    int x, y;
};
*/

// Must contain >= 2 points
struct Point * bFClosestPoints(struct Point P[], int n)
{
    if ((n < 2) || (P == NULL)){
        fprintf(stderr, "Error: not enough points to find closest pair");
        exit(EXIT_FAILURE);
    }

    struct Point * closestPair = (struct Point *)malloc(2 * (sizeof(struct Point)));
    if (closestPair == NULL){
        fprintf(stderr, "Error: memory allocation failed");
        exit(EXIT_FAILURE);
    }

    float currClo = FLT_MAX;
    float dist = 0.0;
    int i, j;
    for (i = 0; i < n; ++i){
        for (j = i+1; j < n; ++j){
            dist = sqrt( (P[i].x - P[j].x)*(P[i].x - P[j].x) +
                        (P[i].y - P[j].y)*(P[i].y - P[j].y)
                        );
            if (dist < currClo){
                currClo = dist;
                closestPair[0] = P[i];
                closestPair[1] = P[j];
            }
        }
    }
    return closestPair;
}

/*
//Test driver to test conditions
int main(){
    struct Point myPlain[3] = {{0,1},{5,10},{13,14}};
    int n = sizeof(myPlain)/sizeof(myPlain[0]);

    struct Point *closest = bFClosestPoints(myPlain,n) ;

    printf( "Closest Pairs: \n"
            "X1: %i Y1: %i\n"
            "X2: %i Y2: %i\n", closest[0].x, closest[0].y, closest[1].x, closest[1].y);

    return 0;
}
*/



