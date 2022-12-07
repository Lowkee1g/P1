#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "scaninput.h"
//https://stackoverflow.com/questions/14768230/malloc-for-struct-and-pointer-in-c

char **array;
int size = 0;

int main(void)
{
    scanData();


    for (int i = 0; i < size; i++)
    {
        free(array[i]); // free memory for each string in the array
    }
    free(array);

    return 0;

    
}


void scanData() {
    //Peudokode
    /*Scanne efter et input
    Tager inputtet og ændre længende af arrayet ved at sætte det ind efter
    Loop vi op til start */

    //int c;

    //Opretter 2D array af strings
    array = malloc(1 * sizeof(char *)); 
    if (array == NULL)
    {
        exit(EXIT_FAILURE);
    }
    

    //Går gennem inputs fra brugen indtil at der bliver skrevet next
    printf("\nInsert ingredients (Type next to end): ");

    while (1) {
        printf("size - %d\n", size);
        array[size] = malloc(50 * sizeof(char));
        printf(" after");
        if (array[size] == NULL){
            printf("Exit here - %d", size);
            exit(EXIT_FAILURE);
        }
        // scanf("%[^\n]", array[size]);
        fgets(array[size], 50, stdin); // fgets tager en bestemt størrelse 
        
        if (strcmp(array[size],"next\n") == 0) {
            printf("Break \n");
            array[size] = (char *) ' '; 
            break;
        }

        printf("\nnext ingredient: ");

        //Hvis der ikke bliver indtastet next, udvidre den arrayet med 1
        size++;
        array = realloc(array, (1 + size) * sizeof(char *));
    }


    //Debug
    printf("size of Malloc: %d\n", size);

    for (int i = 0; i < size; i++) {
        printf("%d - %s",i,array[i]);
    }
}