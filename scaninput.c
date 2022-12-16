#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GlobalFunctions.h"
//#include "scaninput.h"
//https://stackoverflow.com/questions/14768230/malloc-for-struct-and-pointer-in-c

char **array;
int inputSize = 0;

void scanData() {
    //Opretter 2D array af strings
    array = malloc(1 * sizeof(char *)); //Allocerer plads til 1 string
    if (array == NULL) //Hvis der ikke er plads til stringen, så stop
    {
        exit(EXIT_FAILURE);
    }
    

    //Går gennem inputs fra brugen indtil at der bliver skrevet "next"
    printf("\n|-----------------------------------|");
    printf("\n|Insert ingredients                 |");
    printf("\n|type next when you want to continue|");
    printf("\n|-----------------------------------|\n");

    while (1) {
        array[inputSize] = malloc(50 * sizeof(char)); //Allocerer plads til 50 chars i pointeren

        //Hvis der ikke er plads til 50 chars, så stop
        if (array[inputSize] == NULL){ 
            printf("Exit here - %d", inputSize);
            exit(EXIT_FAILURE);
        }

        printf("%c", 175);
        //strcpy(array[inputSize], getStringInput());
        fgets(array[inputSize], 50, stdin); // fgets tager en bestemt størrelse 
        //Fjern newline
        array[inputSize][strlen(array[inputSize]) - 1] = '\0';

        //Hvis der bliver indtastet "next", så stopper den
        if (strcmp(array[inputSize],"next") == 0) {
            //printf("Break \n");
            array[inputSize] = (char *) ' '; 
            break;
        }

        //Hvis der ikke bliver indtastet next, udvidre den arrayet med 1
        inputSize++;
        array = realloc(array, (1 + inputSize) * sizeof(char *)); //Reallocerer plads til 1 string
    }
}