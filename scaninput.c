#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//https://stackoverflow.com/questions/14768230/malloc-for-struct-and-pointer-in-c

char inputString[50];
char *inputArray;


void scanData() {
    //Peudokode
    /*Scanne efter et input
    Tager inputtet og ændre længende af arrayet ved at sætte det ind efter
    Loop vi op til start */

    int c;
    char **array;

    //Opretter 2D array af strings
    array = malloc(1 * sizeof *array);
    for (int i = 0; i < 50; i++) {
        array[i] = malloc(sizeof *array[i]);
    }

    //Går gennem inputs fra brugen indtil at der bliver skrevet next
    int size = 0;  
    while (1) {
        printf("\nInsert a string here : ");
        gets(array[size]);
        if (strcmp(array[size],"next\0") == 0) {array[size] = ' '; break;  }

        //Hvis der ikke bliver indtastet next, udvidre den arrayet med 1
        array = (char *) realloc(array, 1);
        size++;
    }    


    //Debug
    for (int i = 0; i < size; i++) {
        puts(array[i]);
    }

}