#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"


// TODO - Safety Algorithm goes here
void isSafe(int **avail, int **alloc, int **need, int processes, int resources){
    int **availClone = clone(avail, resources);
    int *safe = (int *)malloc(processes * sizeof(int));
    
    bool contLoop = true;
    int num = 0;
    while(contLoop){
        // check if num is equal that means the schedule is safe 
    if (num == processes){ 
        printf("SAFE: ");
        for (int i = 0; i < processes; i++){
            printf("T%d ", safe[i]);
        }
        contLoop = false;
        free(avail);
        free(alloc);
        free(need);
        free(availClone);
        free(safe);
        return NULL;
    }
        int *finish = (int *)malloc(processes * sizeof(int)); 
        //instantiate to 0 to determined finihs vs unfinished state. 
        for(int i=0; i<processes;i++){
            finish[i]=0;
        }

        bool threadDone = false; 
        for (int i = 0; i < processes; i++){
            bool completable = true;
            if (finish[i] == 0){ 
                for (int j = 0; j < resources; j++){
                    if (need[i][j] > availClone[j]){
                        completable = false;
                    }   
                }
                if (completable == true){ 
                    finish[i] = 1;
                    threadDone = true; 
                    printf("here");
                }
            }
        }
        //if a thread cant run then break  
        if (threadDone==false){ 
            printf("UNSAFE: ");
            for (int i = 0; i < processes; i++){
                if (finish[i] == 0){
                    printf("T%d ", i);
                }
            }
            contLoop==false;
            printf("can not finish\n");
            //FREE EVERYTHING  
            free(avail);
            free(alloc);
            free(need);
            free(availClone);
            free(safe);
            return NULL; //to break out of the loop
        }

        for (int i = 0; i < processes; i++){
            if (finish[i] == 1){ 
                availClone = add(availClone, alloc[i], resources);
                finish[i] = 1;
                contLoop == true;
                safe[num] = i; 
                num++;
                
                /**
                //this might have to come out after the while loop
                finish[i] = 0;
                availClone = subtract(availClone, alloc[i],availClone, processes, resources);
                num--;
                */
            }
        }
        free(finish);
    
    
   }
}