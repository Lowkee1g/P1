#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* inputString;

typedef struct {
    char name[30];
    int numberOf;
} InputIngredience;

int main(void)
{
    scanData();

    
    return 0;
}




void scanData() {
    
    InputIngredience *Input = malloc(sizeof(InputIngredience));
    //Input *input = malloc(sizeof(Input));

    //inputs = (int *) malloc(1);
    //Input->name = "Hello";
    //Input->numberOf = 2;

    //printf("%d",Input->numberOf);
    gets(inputString);
    do
    {
        
        
    } while (inputString != "end");
    
    

    

    
    free(Input);
}