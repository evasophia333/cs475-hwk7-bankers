#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


/**
 * clones the elements of the first vector into another vector 
 *
 *@returns the cloned vector
 *@param vector to copy from and a vector to copy to 
 */
int** clone(int **cloning, int resources){
    // clone here
    int **clonedInto = malloc(sizeof(int)*resources);
    for (int i = 0; i < resources; i++)
    {
        clonedInto[i] = cloning[i];
    }
    return clonedInto;
}

/**
 *compares the size of each matrix element and returns true if one is larger than two
 *
 *@return true or false
 */
bool compare(int **matrix1, int **matrix2, int processes, int resources){
  for (int i = 0; i < processes; i++){ 
    for (int j = 0; j < resources; j++){
      if (matrix1[i][j] > matrix2[i][j]){
        return false;
      }
    }
  }
  return true;
}
/**
 *compares the total sums for two matricies
 *
 *@param NPROC
 *@param NRES
  *@param allocated matrix
 *@param availble vector 
 *@return true if the comparison is true otherwise fasle
 */
bool compTotal(int processes, int resources, int **alloc, int **availVec){
    for (int i = 0; i < resources; i++){
        int sumToDeter = 0;
        for (int j = 0; j < processes; j++){
        sumToDeter += alloc[i][j];
        }
        int *num = availVec[i];
        if (sumToDeter > num){
            return false;
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
int** add(int *matrix1, int *matrix2, int size){
    // add thevectors/matrices
    int **result = (int **)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        result = matrix1[i]+matrix2[i];
    }
    return result;
}
/**
 * subtracts two matricies to determine a needed amount
 *
 * @return needed matrix  
 * @param two matricies 
 */
int** subtract(int **matrix1, int **matrix2, int **matrix3, int processes, int resources){
    // subtract the vectors/matrices
    for (int i = 0; i < processes; i++){
        matrix3[i] = (int *)malloc(processes * sizeof(int));
        //create the need matrix by subtracting the max matrix by the alloc matrix
        for (int j = 0; j < resources; j++){
            matrix3[i][j]= matrix1[i][j] - matrix2[i][j];
        }
    }
    return matrix3;
}
/**
 *prints a vector/matrix
 *
 */
void print(int **matrix, int processes, int resources){
    // print the vectors/matrices
    for (int i = 0; i < processes; i++){
        printf("\n");
        for (int j = 0; j < resources; j++){
            printf("%d ", matrix[i][j]);
        }
    }
}