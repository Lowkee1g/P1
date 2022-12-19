#include <stdio.h>
#include <string.h>
#include "data.h"
#include "printOutput.h"


void printMeals(int *mealid, int LENGTH_OF_ARRAY) {
    int j = 0;
    int multi = 0;
    int remaining = LENGTH_OF_ARRAY;

    printf("|-----------------------------------|\n");

    while (1) {
        if (remaining > 3) {
            j = 3;
        } else {
            j = remaining;
        }
        printf("|    Found %d meals - Showing %d/%d    |\n", remaining, multi+j, remaining);
        printf("|%-35.35s|\n", "   type meal name to see details");
        printf("|-----------------------------------|\n");
        for (int i = 0; i < j; i++) {
            //find meal name from id
            for (int k = 0; k < mealSize; k++) {
                if (mealid[i + multi] == meals[k].id) {
                    printf("|%-35.35s|", meals[k].name);
                    printf("\n");
                    break;
                }
            }
            remaining--;
        }

        printf("|-----------------------------------|\n%c", 175);
        char input[50];
        gets(input);


        

        int i = 0;
        // Loop through all meals.
        while (i < mealSize) {
            // Check if the input is equal to the name of the meal.
            if (strcmp(input, meals[i].name) == 0) {
                printf("|-----------------------------------|\n");
                printf("|Showing ingrediences needed to make|\n|%-35.35s|\n", meals[i].name);
                printf("|-----------------------------------|\n");
                for (int j = 0; j < meals[i].sizeOfIngs; j++) {
                    printf("|%c %-33.33s|\n",175, ingredients[meals[i].ings[j]-1].name);
                }
                printf("|-----------------------------------|\n");
                break;
            }
            i++;
        }

        if (remaining == 0) {
            break;
        }

        if (strcmp("more", input) == 0) {
            multi += 3;
        } else {
            break;
        }
        
    }
}


