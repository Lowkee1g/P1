// Modtag søge input (Ingredienser)
// Få alle meals og ingredients
// Søg gennem meals efter ingredients id

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

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

    for (int i = 0; i < size ; i++){ // Itererer gennem listen af input ingredienser
        for (int j = 0; j < mealssize; j++) { // Itererer gennem alle meals for at finde nogle med ingredienser, som matcher
            // if (meals[j].ings.Contains(ings[i])){ //Der er noget der ikke helt fungerer her...
                
            // }
            
        }
    }
}
