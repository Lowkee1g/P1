#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GlobalFunctions.h"

char **inputIngredienceArray;
int inputSize = 0;

void scanData() {
    //Make a 2D array of strings
    inputIngredienceArray = malloc(1 * sizeof(char *)); //allocate space for 1 string
    if (inputIngredienceArray == NULL) //Check if malloc failed
    {
        exit(EXIT_FAILURE);
    }
    

    //go through the array and ask for input
    printf("\n|-----------------------------------|");
    printf("\n|Insert ingredients                 |");
    printf("\n|type next when you want to continue|");
    printf("\n|-----------------------------------|\n");

    while (1) {
        inputIngredienceArray[inputSize] = malloc(50 * sizeof(char)); //allocate space for 50 chars

        //if there is no space left, exit
        if (inputIngredienceArray[inputSize] == NULL){ 
            printf("Exit here - %d", inputSize);
            exit(EXIT_FAILURE);
        }

        printf("%c", 175);

        fgets(inputIngredienceArray[inputSize], 50, stdin); // fgets takes a given size, so it will not overflow the buffer
        //remove newline
        inputIngredienceArray[inputSize][strlen(inputIngredienceArray[inputSize]) - 1] = '\0';

        //if the input is next, break the loop
        if (strcmp(inputIngredienceArray[inputSize],"next") == 0) {

            inputIngredienceArray[inputSize] = (char *) ' '; 
            break;
        }

        //if the input is not next, add 1 to the size of the array and realloc the array
        inputSize++;
        inputIngredienceArray = realloc(inputIngredienceArray, (1 + inputSize) * sizeof(char *)); //Reallocerer plads til 1 string
    }
}