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

    Debug("This is an Debug");

    
    return 0;
}




void scanData() {
    //Peudokode
    /*Scanne efter et input
    Tager inputtet og ændre længende af arrayet ved at sætte det ind efter
    Loop vi op til start */

    int **array;

    array = malloc(10 * sizeof *array);

    for (int i = 0; i < )



}