// Tjek id inputtede ingredients og match med meals ingredients

#include <stdio.h>
#include <stdlib.h>
#include "searchMeals.h"
#include "data.h"
#include "scaninput.h"


void sortMeals();
void mealsToIds();
int comp(const void * a, const void * b);

int *mealIds; // Vi skal returnere 10 meals
int *mealResults;
int counter;
int size = 3;

void sortMeals(){
    printf("Kommer ind i sort \n");
    mealIds = (int *) malloc(1 * sizeof(int)); 
    mealResults = (int *) malloc(3 * sizeof(int));
    if (mealResults == NULL || mealResults == NULL){
        exit(EXIT_FAILURE);
    }
    for (int k = 0; k < size; k++){
        mealResults[k] = 0;
    }
    printf("Mallocs i sort er done \n");

    mealsToIds();
    
    qsort(mealIds, counter, sizeof(int), comp);
    int mostInCommonId = -1;
    int mostDuplicates = 0;
    int tempCounter = 1;
    for (int i = 0; i < size; i++){
        printf("Inde i første løkke i sort \n");
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

void mealsToIds(){
    // Gather all ids of meals in a list of ints. 
    printf("mealsToIds her \n");
    printf("Her er et id fra foundmeals: %d \n", foundmeals[0][-1].id);
    counter = 0;
    int j = 0;
    for (int i = 0; i < inputSize; i++){
        j = 0;
        printf("Lige inden foundmeals tjek \n");
        while (foundmeals[i][j].id != -1){
            printf("Lige inden foundmeals tjek \n");
            mealIds[counter] = foundmeals[i][j].id;
            counter++;
            printf("Før realloc i sort\n");
            realloc(mealIds, counter * sizeof(int));
            printf("Efter realloc i sort\n");
            j++;
        }
        counter--;
        realloc(mealIds, counter * sizeof(int));
        printf("Efter anden realloc i sort\n");
    }
}

int comp(const void * a, const void * b){
    return (*(int *)a - *(int *)b);
}