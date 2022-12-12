// Tjek id inputtede ingredients og match med meals ingredients

#include <stdio.h>
#include <stdlib.h>
#include "searchMeals.h"
#include "data.h"
#include "scaninput.h"


void sortMeals(Meals **found);
void mealsToIds();
int comp(const void * a, const void * b);

int *mealIds; // Vi skal returnere 10 meals
int *mealResults;
int counter;
int size = 3;

void sortMeals(Meals **found){
    mealIds = (int *) malloc(1 * sizeof(int)); 
    mealResults = (int *) malloc(3 * sizeof(int));
    if (mealResults == NULL || mealResults == NULL){
        exit(EXIT_FAILURE);
    }
    for (int k = 0; k < size; k++){
        mealResults[k] = 0;
    }

    mealsToIds(found);
    
    qsort(mealIds, counter, sizeof(int), comp);
    int mostInCommonId = -1;
    int mostDuplicates = 0;
    int tempCounter = 1;
    for (int i = 0; i < size; i++){
        for (int j = 1; j < counter; j++){
            if (mealIds[j] == mealIds[j - 1]){
                if (!contains(mealIds[j], mealResults, size)){
                    tempCounter++;
                    if (tempCounter > mostDuplicates){
                        mostDuplicates = tempCounter;
                        mostInCommonId = mealIds[j];
                    }
                }
            } else {
                tempCounter = 1;
            }
        }
        mealResults[i] = mostInCommonId;
    }
    free(mealIds);
}

void mealsToIds(Meals **found){
    // Gather all ids of meals in a list of ints. 
    counter = 0;
    int j = 0;
    for (int i = 0; i < inputSize; i++){
        j = 0;
        while (found[i][j].id != -1){
            mealIds[counter] = found[i][j].id;
            printf("found[%d][%d].id = %d \n", i, j, found[i][j].id);
            counter++;
            realloc(mealIds, counter * sizeof(int));
            j++;
        }
    }
}

int comp(const void * a, const void * b){
    return (*(int *)b - *(int *)a);
}