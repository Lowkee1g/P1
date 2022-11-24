#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//https://stackoverflow.com/questions/14768230/malloc-for-struct-and-pointer-in-c

char inputString[50];
char *inputArray;

void BlueOuputColor() {
    printf("\033[0;36m");
}
void ResetOutputColor() {
    printf("\033[0m");
}
void Debug(char s[100]) {
    printf("\033[0;35m");
    printf("     %c <%s>",175,s);
    ResetOutputColor();
}

int main(void)
{
    scanData();

    //Debug("This is an Debug");

    
    return 0;
}




void scanData() {
    //Peudokode
    /*Scanne efter et input
    Tager inputtet og ændre længende af arrayet ved at sætte det ind efter
    Loop vi op til start */
    int c;
    char **array;

    array = malloc(10 * sizeof *array);
    for (int i = 0; i <10; i++) {
        array[i] = malloc(sizeof *array[i]);
    }

    

    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 1; j++)
        {
            array[i][j] = ' ';
        }
    }

    int size = 0;  
    while (1) {
        printf("\nInsert a string here: ");
        gets(array[size]);
        Debug(array[size]);
        if (strcmp(array[size],"next\0") == 0) { break; }
        size++;
    }

    // numbers = malloc((rounds+1) * sizeof *numbers);
    // for(int i = 0; i < rounds+1; i++) {
    //     numbers[i] = malloc(n * sizeof *numbers[i]);
    // }


    
    for (int i = 0; i < size; i++) {
        printf("\n");
        for (int j = 0; j <= sizeof(*array)/sizeof(*array[0]); j++)
        {
            printf("%c", array[i][j]);
        }
        
    }

}