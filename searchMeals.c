#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "data.h"
#include "scaninput.h" 
#include "sortMeals.h"

Meals *foundmeals;
int foundmealsSize = 0;

void searchMeals();
int contains(int a, int *list, int size);

void searchMeals(){
    foundmeals = (Meals *) malloc(inputSize * mealSize * sizeof(Meals *)); 
    if (foundmeals == NULL){
        exit(EXIT_FAILURE);
    }

    int *ingids = (int *) malloc(inputSize * sizeof(int));
    if (ingids == NULL){
        exit(EXIT_FAILURE);
    }
    
    // Convert ingredients from char to int
    for (int i = 0; i < inputSize; i++){ // For each input ingredient
        ingids[i] = - 1;
        for (int j = 0; j < ingredientsSize; j++){ // For each existing ingredient struct
            array[i][0] = tolower(array[i][0]);
            ingredients[j].name[0] = tolower(ingredients[j].name[0]);
            if(!strcmp(array[i], ingredients[j].name)){ // Find the given ingredients id.
                ingids[i] = ingredients[j].id; 
                break;
            }             
        }
        //printf("\n");
    }

    for (int i = 0; i < inputSize ; i++){ // Iterate through list of input ingredients
        for (int j = 0; j < mealSize; j++) { // Iterate through all meals to find the meals with matching ingredients
            if (contains(ingids[i], meals[j].ings, meals[j].sizeOfIngs)){
                foundmeals[foundmealsSize] = meals[j];
                foundmealsSize++;
            }
        }
    }
    foundmeals[foundmealsSize].id = -1; // Set last meals id to -1 to indicate that it is the last meal
    sortMeals();
    
    free(ingids);
    free(array);
}

// Funktion returnerer 1, hvis listen list indeholder a
int contains(int a, int *list, int size){
    for (int i = 0; i < size; i++) {
        if (list[i] == a) {
            return 1;
        }
    }
    return 0;
}