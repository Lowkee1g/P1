#include <stdio.h>
#include <stdlib.h>
#include "searchMeals.h"
#include "data.h"
#include "scaninput.h"

void sortMeals();
int comp(const void * a, const void * b);

int *mealResults;
int counter = 0;
int size = 3;

void sortMeals(){
    int meal_Ids[foundmealsSize];
    mealResults = (int *) malloc(3 * sizeof(int *));
    if (mealResults == NULL){
        exit(EXIT_FAILURE);
    }
    for (int k = 0; k < size; k++){
        mealResults[k] = 0;
    }
    // Meals to Ids
    for (int j = 0; j < foundmealsSize; j++)
    {
        printf(" l'økkefoundmeals[j].name %d \n", foundmeals[j].id);
        meal_Ids[j] = foundmeals[j].id;
    }
    
    qsort(meal_Ids, foundmealsSize, sizeof(int), comp);
    for (int i = 0; i < foundmealsSize; i++)
    {
        printf("%d, ", meal_Ids[i]);
    }
    printf("\n");
    printf("meals_Ids[0] %d \n", meal_Ids[0]);

    int mostInCommonId = -1;
    int mostDuplicates = 0;
    int tempCounter = 1;
    for (int i = 0; i < size; i++){
        for (int j = 1; j < foundmealsSize; j++){
            if (meal_Ids[j] == meal_Ids[j - 1]){
                if (!contains(meal_Ids[j], mealResults, size)){
                    tempCounter++;
                    if (tempCounter >= mostDuplicates){
                        mostDuplicates = tempCounter;
                        mostInCommonId = meal_Ids[j];
                    }
                }
            } else {
                tempCounter = 1;
            }
        }
        if (inputSize == 1){
            mealResults[i] = meal_Ids[i];
        } else {
            mealResults[i] = mostInCommonId;
        }
        
        printf("mealResults[i] = %d \n", mealResults[i]);
    }
    free(meal_Ids);
}

int comp(const void * a, const void * b){
    return (*(int *)b - *(int *)a);
}