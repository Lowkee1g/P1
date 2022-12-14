#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "data.h"
#include "scaninput.h" 
#include "sortMeals.h"

Meals **foundmeals;

void searchMeals();
int contains(int a, int *list, int size);

void searchMeals(){
    foundmeals = (Meals **) malloc(inputSize * sizeof(Meals **)); 
    if (foundmeals == NULL){
        printf("searchMeals exit failure linje 15 \n");
        exit(EXIT_FAILURE);
    }

    int *ingids = (int *) malloc(inputSize * sizeof(int));
    if (ingids == NULL){
        printf("searchMeals exit failure linje 21 \n");
        exit(EXIT_FAILURE);
    }
    
    // Convert ingredients from char to int
    for (int i = 0; i < inputSize; i++){ // For each input ingredient
        // Allocate space for meals in foundmeals
        foundmeals[i] = (Meals *) malloc(mealSize * sizeof(Meals *));   
        if (foundmeals == NULL){
            exit(EXIT_FAILURE);
        }
        ingids[i] = - 1;
        for (int j = 0; j < ingredientsSize; j++){ // For each existing ingredient struct
            array[i][0] = tolower(array[i][0]);
            ingredients[j].name[0] = tolower(ingredients[j].name[0]);
            if(!strcmp(array[i], ingredients[j].name)){ // Find the given ingredients id.
                ingids[i] = ingredients[j].id; 
                break;
            }             
        }
        printf("\n");
    }

    int counter; 
    for (int i = 0; i < inputSize ; i++){ // Iterate through list of input ingredients
    counter = 0;
        for (int j = 0; j < mealSize; j++) { // Iterate through all meals to find the meals with matching ingredients
            if (contains(ingids[i], meals[j].ings, meals[j].sizeOfIngs)){
                foundmeals[i][counter] = meals[j];
                printf("%s, %d \n", foundmeals[i][counter].name, foundmeals[i][counter].id);
                counter++;
            }
        }
        foundmeals[i][counter].id = -1; // -1 tells that there are no more meals in foundmeals[i]
    }
    // sortMeals(foundmeals);
    
    free(ingids);
    free(foundmeals);
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