#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "scaninput.h" 

Meals **foundmeals;

void searchMeals();
int contains(int a, int *list, int size);

void searchMeals(){
    Meals **foundmeals = (Meals **) malloc(inputSize * sizeof(Meals *)); 
    if (foundmeals == NULL){
        printf("searchMeals exit failure linje 15 \n");
        exit(EXIT_FAILURE);
    }

    int *ingids = (int *) malloc(inputSize * sizeof(int));
    if (ingids == NULL){
        printf("searchMeals exit failure linje 21 \n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < inputSize; i++){ // For each input ingredient
        for (int j = 0; j < ingredientsSize; j++){ // For each existing ingredient struct
        printf("String compare. String 1 \n.%s.\n, string 2 %s, %d \n", array[i], ingredients[j].name, strcmp(array[i], ingredients[j].name));
            if(!strcmp(array[i], ingredients[j].name)){ // Find the given ingredients id.
            printf("\n \nJeg printer noget her \n \n");
            printf("Der blev fundet %s og %s som matcher", array[i], ingredients[j].name);
                ingids[i] = ingredients[j].id;
            }             
        }
        printf("\n");
    }

    for (int i = 0; i < inputSize; i++){ // Make a list of meals for each ingredient
        foundmeals[i] = (Meals *) malloc(mealSize * sizeof(Meals));
        if (foundmeals == NULL){
            printf("searchMeals exit failture linje 36 \n");
            exit(EXIT_FAILURE);
        }
    }

    int counter; 
    for (int i = 0; i < inputSize ; i++){ // Iterate through list of input ingredients
    counter = 0;
        for (int j = 0; j < mealSize; j++) { // Iterate through all meals to find the meals with matching ingredients
        // printf("- %d -", contains(ingids[i], meals[j].ings, meals[j].sizeOfIngs));
            if (contains(ingids[i], meals[j].ings, meals[j].sizeOfIngs)){
                // printf("Contains tingen \n");
                foundmeals[i][counter] = meals[j];
                printf("%s, %d \n", foundmeals[i][counter].name, foundmeals[i][counter].id);
                counter++;
            }
        }
    }
    free(ingids);
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