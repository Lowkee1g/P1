#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "scaninput.h" 

Meals **foundmeals;

void searchMeals();
int contains(int a, int *list, int size);

void searchMeals(){
    // int size = sizeof(array)/sizeof(array);
    Meals **foundmeals = (Meals **) malloc(50 * sizeof(Meals)); 
    if (foundmeals == NULL){
        printf("searchMeals exit failture linje 15 \n");
        exit(EXIT_FAILURE);
    }
    printf("foundmeals oprettet \n");

    int *ingids = (int *) malloc(50 * sizeof(int));
    if (ingids == NULL){
        printf("searchMeals exit failture linje 21 \n");
        exit(EXIT_FAILURE);
    }
    printf("ingsid oprettet \n");
    
    for (int i = 0; i < 50; i++){ // For each input ingredient
        for (int j = 0; j < ingredientsSize; j++){ // For each existing ingredient struct
            if(!strcmp(array[i], ingredients[j].name)){ // Find the given ingredients id.
                ingids[i] = ingredients[j].id;
            }             
        }
    }

    for (int i = 0; i < 50; i++){ // Make a list of meals for each ingredient
        foundmeals[i] = (Meals *) malloc(mealSize * sizeof(Meals));
        if (foundmeals == NULL){
            printf("searchMeals exit failture linje 36 \n");
            exit(EXIT_FAILURE);
        }
    }

    int counter; 
    for (int i = 0; i < 50 ; i++){ // Iterate through list of ingredients
    counter = 0;
        for (int j = 0; j < mealSize; j++) { // Iterate through all meals to find the meals with matching ingredients
            if (contains(ingids[i], meals[j].ings, meals[j].sizeOfIngs)){
                foundmeals[i][counter] = meals[j];
                counter++;
            }
        }
    }
    free(ingids);
}

int contains(int a, int *list, int size){
    printf("I contains \n");
    int isElementPresent = 0;

    for (int i = 0; i < size; i++) {
        if (list[i] == a) {
            isElementPresent = 1;
            return 1;
        }
    }
    return 0;
}