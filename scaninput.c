#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scaninput.h"
//https://stackoverflow.com/questions/14768230/malloc-for-struct-and-pointer-in-c

char **array;

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
    int size = 0;
    while (1) {
        array[size] = malloc(50 * sizeof(char));
        if (array[size] == NULL)
        {
            exit(EXIT_FAILURE);
        }
        gets(array[size]);
        if (strcmp(array[size],"next\0") == 0) {
            printf("Break \n");
            array[size] = (char *) ' '; 
            break;
        }   
        printf("\nnext ingredient: ");

        //Hvis der ikke bliver indtastet next, udvidre den arrayet med 1
        array = realloc(array, 1);
        size++;
    }    


    //Debug
    for (int i = 0; i < size; i++) {
        puts(array[i]);
    }

}