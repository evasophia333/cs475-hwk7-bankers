#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
//globals 
int NPROC;
int NRES;

/**
 * clones the elements of the first vector into another vector 
 *
 *@returns the cloned vector
 *@param vector to copy from and a vector to copy to 
 */
int* clone(int *cloning){
    // clone here
    int *clonedInto = malloc((NRES)*sizeof(int));
    for (int i = 0; i < NRES; i++)
    {
        clonedInto[i] = cloning[i];
    }
    return clonedInto;
}
/**
 * compares two vectors/matricies
 *
 *@return true if the threads do not exceed the max and false if they do exceed
 *@param two different vectors
 */
bool compare(int **matrix1, int **matrix2){
    // compare vectors
    for (int i = 0; i < NPROC; i++){
        for (int j = 0; j < NRES; j++){
            if (matrix2[i][j] > matrix1[i][j]){
                return false;
            }
        }
    }
    return true;
}
/**
 * adds each of the elements of the matrix to return a total
 *
 *@return the total amount
 *@param a matrix 
 */
int* add(int *matrix1, int *matrix2){
    // add thevectors/matrices
    for(int i = 0; i < NPROC; i++) {
        matrix1[i]+=matrix2[i];
    }
    return matrix1;
}
/**
 * subtracts two matricies to determine a needed amount
 *
 * @return needed matrix  
 * @param two matricies 
 */
int** subtract(int **matrix1, int **matrix2){
    // subtract the vectors/matrices
    for (int i = 0; i < NPROC; i++)
    {
        //create the need matrix by subtracting the max matrix by the alloc matrix
        for (int j = 0; j < NRES; j++)
        {
            matrix1[j] -= matrix2[i][j];
        }
    }
    return matrix1;
}
/**
 *prints a vector/matrix
 *
 */
void print(int **matrix){
    // print the vectors/matrices
    for (int i = 0; i < NPROC; i++){
        printf("\n");
        for (int j = 0; j < NRES; j++){
            printf("%d ", matrix[i][j]);
        }
    }
}