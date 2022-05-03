#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"
#include <string.h>


int main(int argc, char *argv[])
{
  // TODO: attempt to open scenario file and scan data into allocated structures
  FILE* inputFile;
  char *arg = argv[1];



  inputFile = fopen(arg, "r");
  
  if(argc < 2 || argc >2){ 
    printf("ERROR: Please input a file via ./bankers <file name>\n ");
    return 0;
  }else{
    if(inputFile == NULL){
      printf("ERROR: File does not exist. Try again!");
      fclose(inputFile);
      return 0;
    }else { 
      int NRES; 	// number of resource types
      int NPROC;	// number of processes
      fscanf(inputFile, "%d", &NRES); //Get NRES
      fscanf(inputFile, "%d", &NPROC); //GET NPROC
      //space  for allocated matrix and then max and avalible
      int **allocated = (int**)malloc(sizeof(int*)*NPROC);
      int **max = (int**)malloc(sizeof(int*)*NPROC);
      for (int i = 0; i < NPROC; i++){
          allocated[i] = (int*)malloc(sizeof(int)*NRES);
          max[i] = (int*)malloc(sizeof(int)*NRES);
      }
      //avalible vector
      int **vector = (int **) malloc(sizeof(int)*NRES);
      for(int i=0;i<NRES;i++){
          fscanf(inputFile, "%d", &vector[i]);
      }
       
      //need matrix
      int **need = (int **) malloc(sizeof(int *) *NPROC);
      for(int i = 0; i < NPROC; i++){
          need[i] = (int *) malloc(sizeof (int) *NRES);
      }


      //fill out matricies
      for(int i=0;i<NPROC;i++){
          for(int j=0;j<NRES;j++){
            fscanf(inputFile, "%d", &allocated[i][j]);
            fscanf(inputFile, "%d", &max[i][j]);
          }
      }


      //SANITY CHECK
      if(compTotal(NPROC, NRES, allocated, vector)){
        printf("Integrity test FAILED: allocated resources exceed total resources\n");
        free(max);
        free(allocated);
        free(need);
        free(vector);
        return 0;
      }else if(compare(allocated, max, NPROC, NRES)){
        printf("Integrity test FAILED: allocated resources exceed demand for threads\n");
        free(max);
        free(allocated);
        free(need);
        free(vector);
        return 0;
      }else{
        //clone structures to avoid changing state of system
        int **tot = subtract(max, allocated, need, NPROC, NRES);

        int **newAvail = clone(vector, NRES);
        for(int i = 0; i < NPROC; i++){
          for(int j = 0; j < NRES; j++){
              newAvail[j] -= allocated[i][j];
          }
        }
        
        isSafe(newAvail,allocated, tot, NPROC, NRES);
        //Run Bankers saftey algorithm using newAvail 
        free(max);
        free(vector);
      }



    }
    
  }
  fclose(inputFile);

  return 0;
  
}