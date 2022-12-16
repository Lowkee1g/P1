#include <stdio.h>
#include <stdlib.h>
#include "searchMeals.h"
#include "data.h"
#include "scaninput.h"
#include "sortMeals.h"

void sortMeals();
int comp(const void * a, const void * b);

int *mealResults;
int counter = 0;

void sortMeals(){
    int mealIds[foundmealsSize];
    mealResults = (int *) malloc(SIZE * sizeof(int *));
    if (mealResults == NULL){
        exit(EXIT_FAILURE);
    }
    for (int k = 0; k < SIZE; k++){
        mealResults[k] = 0;
    }

    // Convert the found meals to ids
    for (int j = 0; j < foundmealsSize; j++){
        mealIds[j] = foundmeals[j].id;
    }
    
    qsort(mealIds, foundmealsSize, sizeof(int), comp);

    int mostInCommonId = -1;
    int mostDuplicates = 0;
    int tempCounter = 1;
    for (int i = 0; i < SIZE; i++){ 
        for (int j = 1; j < foundmealsSize; j++){
            if (mealIds[j] == mealIds[j - 1]){ // Check for duplicates
                if (!contains(mealIds[j], mealResults, SIZE)){ // If this id is not already counted
                    tempCounter++;
                    if (tempCounter >= mostDuplicates){ // Find the most duplicates and save that id
                        mostDuplicates = tempCounter;
                        mostInCommonId = mealIds[j];
                    }
                }
            } else {
                tempCounter = 1;
            }
        }
        if (inputSize == 1){
            mealResults[i] = mealIds[i];
        } else {
            mealResults[i] = mostInCommonId;
        }
    }
    free(mealIds);
}

// Sort function for qsort
int comp(const void * a, const void * b){
    return (*(int *)b - *(int *)a);
}