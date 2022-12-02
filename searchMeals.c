#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

Meals **foundmeals;

void searchMeals(char **ings);
int contains(int a, int *list);

void searchMeals(char **ings){
    int size = sizeof(ings)/sizeof(ings[0]);
    Meals **foundmeals = (Meals **) malloc(size * sizeof(Meals)); 
    if (foundmeals == NULL){
        exit(EXIT_FAILURE);
    }

    int *ingids = (int *) malloc(size * sizeof(int));
    if (ingids == NULL){
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < size; i++){ // For each input ingredient
        for (int j = 0; j < ingredientsSize; j++){ // For each existing ingredient struct
            if(!strcmp(ings[i], ingredients[j].name)){ // Find the given ingredients id.
                ingids[i] = ingredients[j].id;
            }
        }
    }

    for (int i = 0; i < size; i++){ // Make a list of meals for each ingredient
        foundmeals[i] = (Meals *) malloc(mealSize * sizeof(Meals));
        if (foundmeals == NULL){
            exit(EXIT_FAILURE);
        }
    }

    int counter; 
    for (int i = 0; i < size ; i++){ // Iterate through list of ingredients
    counter = 0;
        for (int j = 0; j < mealSize; j++) { // Iterate through all meals to find the meals with matching ingredients
            if (contains(ingids[i], meals[j].ings)){
                foundmeals[i][counter] = meals[j];
                counter++;
            }
        }
    }

    free(ingids);

    // Hvis det er en mulighed at lave første liste i foundmeals til at være de retter, som har flest til fælles, så kan search og sort meals
    // være den samme funktion. https://stackoverflow.com/questions/58306236/can-i-use-contains-for-integer-list .... Det kan man sikkert ikke,
    // men nu er linket her

    // This tho https://www.tutorialkart.com/c-programming/c-check-if-array-contains-specified-element/
}

int contains(int a, int *list){
    int size = sizeof list / sizeof list[0];
    int isElementPresent = 0;

    for (int i = 0; i < size; i++) {
        if (list[i] == a) {
            isElementPresent = 1;
            return 1;
        }
    }
    return 0;
}