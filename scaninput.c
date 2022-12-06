#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scaninput.h"
//https://stackoverflow.com/questions/14768230/malloc-for-struct-and-pointer-in-c

char **array;
int inputSize;

void scanData() {
    //Peudokode
    /*Scanne efter et input
    Tager inputtet og ændre længende af arrayet ved at sætte det ind efter
    Loop vi op til start */

    //int c;

    //Opretter 2D array af strings
    array = malloc(50 * sizeof(char)); 
    if (array == NULL)
    {
        exit(EXIT_FAILURE);
    }
    

    //Går gennem inputs fra brugen indtil at der bliver skrevet next
    printf("\nInsert ingredients (Type next to end): ");
    inputSize = 0;
    while (1) {
        array[inputSize] = malloc(50 * sizeof(char));
        if (array[inputSize] == NULL){
            exit(EXIT_FAILURE);
        }
        // scanf("%[^\n]", array[size]);
        fgets(array[inputSize], 50, stdin); // fgets tager en bestemt størrelse 
        if (strcmp(array[inputSize],"next\n") == 0) {
            printf("Break \n");
            array[inputSize] = (char *) ' '; 
            break;
        }
        printf("\nnext ingredient: ");

        //Hvis der ikke bliver indtastet next, udvidre den arrayet med 1
        inputSize++;
    }    


    //Debug
    for (int i = 0; i < inputSize; i++) {
        puts(array[i]);
    }
}