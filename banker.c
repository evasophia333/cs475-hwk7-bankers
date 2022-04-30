#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"
int NRES;
int NPROC;
// TODO - Safety Algorithm goes here
void safteyAlgo(int *avail, int **max, int **alloc){
    //clone avalible because you loose it in subtract
    int *cloned = malloc(NRES*sizeof(int));
    cloned = clone(avail);

    //subtract alloc resources using vector.c method
    subtract(cloned ,alloc);

    //allocate space for finish array
    int *finish = malloc(NRES*sizeof(int));
    for (int i = 0; i < NPROC; i++){
        finish[i] = 0;
    }

}