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
    array = malloc(1 * sizeof *array);
    for (int i = 0; i < 50; i++) {
        array[i] = malloc(sizeof *array[i]);
    }

    //Går gennem inputs fra brugen indtil at der bliver skrevet next
    printf("\nInsert ingrediences (Type next to end): ");
    int size = 0;  
    while (1) {
        gets(array[size]);
        if (strcmp(array[size],"next\0") == 0) {array[size] = ' '; break;}   
        printf("\nnext ingredience: ");

        //Hvis der ikke bliver indtastet next, udvidre den arrayet med 1
        array = realloc(array, 1);
        size++;
    }    


    //Debug
    for (int i = 0; i < size; i++) {
        puts(array[i]);
    }

}