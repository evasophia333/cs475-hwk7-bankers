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

      int mat = malloc((NPROC*NRES)*sizeof(int));
    }
  }
  // TODO: Run banker's safety algorithm

  return 0;
}