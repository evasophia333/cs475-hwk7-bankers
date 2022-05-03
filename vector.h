#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// TODO: function prototypes of vector and matrix operations
int** clone(int **cloning, int resources);
bool compare(int **matrix1, int **matrix2, int processes, int resources);
int** add(int *matrix1, int *matrix2, int size);
int** subtract(int **matrix1, int **matrix2, int **matrix3, int processes, int resources);
void print(int **matrix);
bool compTotal(int processes, int resources, int **alloc, int **availVector);
