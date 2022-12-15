#include <stdio.h>
#include <string.h>
#include "data.h"
#include "printOutput.h"


void printMeals(char **tmp, int LENGTH_OF_ARRAY) {
    int j = 0;
    int multi = 0;
    int remaining = LENGTH_OF_ARRAY;
    
    while (1) {
        if (remaining > 3) {
            j = 3;
        } else {
            j = remaining;
        }

        for (int i = 0; i < j; i++) {
            printf("%s", tmp[i + multi]);
            printf("\n");
            remaining--;
        }

        
        char input[50];
        gets(input);


        

        int i = 0;
        // Loop through all meals.
        while (i < mealSize) {
            // Check if the input is equal to the name of the meal.
            if (strcmp(input, meals[i].name) == 0) {
                printf("|---------------------|\n");
                printf("| %-20.20s|\n", meals[i].name);
                printf("|---------------------|\n");
                for (int j = 0; j < meals[i].sizeOfIngs; j++) {
                    printf("|%c %-19.20s|\n",175, ingredients[meals[i].ings[j]].name);
                }
                printf("|---------------------|\n");
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


