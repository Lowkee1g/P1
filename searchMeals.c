// Modtag søge input (Ingredienser)
// Få alle meals og ingredients
// Søg gennem meals efter ingredients id

#include <stdio.h>
#include "data.c"

int searchMeals(char* ings[]){
    int size = sizeof(ings)/sizeof(ings[0]);

    int ingredientsid[size];
    for (int i = 0; i < size ; i++){ // Itererer gennem listen af ingredienser
        for (int j = 0;j < (sizeof(ingredients)/sizeof(ingredients[0])); j++) // Der er problemer med at få ingredients fra data.c
        {
            /* code */
        }
        
        ingredientsid[i] = ings[i];

    }

    return 0;
}
