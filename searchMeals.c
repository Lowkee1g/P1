// Modtag søge input (Ingredienser)
// Få alle meals og ingredients
// Søg gennem meals efter ingredients id

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void searchMeals(char* ings);
int contains(int a, int *list);

void searchMeals(char* ings){
    int size = sizeof(ings)/sizeof(ings[0]);
    Meals **foundmeals = (Meals *) malloc(size * sizeof(Meals)); 
    if (foundmeals == NULL){
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++){ // Lav en liste af meals for hver ingrediens
        foundmeals[i] = (Meals *) malloc(mealssize * sizeof(Meals));
        if (foundmeals == NULL){
            exit(EXIT_FAILURE);
        }
    }

    int counter; 
    for (int i = 0; i < size ; i++){ // Itererer gennem listen af input ingredienser
    counter = 0;
        for (int j = 0; j < mealssize; j++) { // Itererer gennem alle meals for at finde nogle med ingredienser, som matcher
            if (contains(ings[i], meals[j].ings)){ //Der er noget der ikke helt fungerer her...
                foundmeals[i][counter] = meals[j];
                counter++;
            }
            
        }
    }


    //  Hvis det er en mulighed at lave første liste i foundmeals til at være de retter, som har flest til fælles, så kan search og sort meals
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