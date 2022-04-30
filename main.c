#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"
#include <string.h>


int main(int argc, char *argv[])
{
  // TODO: attempt to open scenario file and scan data into allocated structures
  FILE* inputFile;
  char path[] = "./cs475-hwk7-bankers/";
  char *arg = argv[1];
  strcat(path, arg);
  printf("%s\n", path);
  inputFile = fopen(arg, "r");
  if(argc < 2 || argc >2){ 
    printf("ERROR: Please input a file via ./bankers <file name>\n ");
    return 0;
  }else{
    if(inputFile == NULL){
      printf("ERROR: File does not exist. Try again!");
      fclose(inputFile);
      return 0;
    }else{ // if file does not exist
      int NRES; 	// number of resource types
      int NPROC;	// number of processes
      fscanf(inputFile, "%d", &NRES);
      fscanf(inputFile, "%d", &NPROC);
      //space  for allocated matrix and then max and avalible
      int **allocated = (int**)malloc((NPROC)*sizeof(int*));
      int **max = (int**)malloc((NPROC)*sizeof(int*));
      for (int i = 0; i < NPROC; i++){
          allocated[i] = (int*)malloc(NRES*sizeof(int));
          max[i] = (int*)malloc(NRES*sizeof(int));

      }
      int *avail = malloc((NRES)*sizeof(int));
      for(int i=0;i<NRES;i++){
          fscanf(inputFile, "%d", &avail[i]);
      }

      //fill out matricies
      for(int i=0;i<NPROC;i++){
          for(int j=0;j<NRES;j++){
            fscanf(inputFile, "%d", &allocated[i][j]);
          }
      }

      for(int i=0;i<NPROC;i++){
          for(int j=0;j<NRES;j++){
            fscanf(inputFile, "%d", &max[i][j]);
          }
      }


      //SANITY CHECK
      if(compare(max, allocated) == false){
        printf("Integrity test failed: allocated resources exceed demand\n");
        return 0;
      }



    }
  }
  fclose(inputFile);
  //Run banker's safety algorithm

  // free memory here 

  return 0;
}