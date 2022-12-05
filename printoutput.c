#include <stdio.h>
#include <string.h>

void PrintMeals(char **tmp, int LENGTH_OF_ARRAY);

int main(void){
    
    char *tmp[] = {"Bearnaisesauce","Lakselasagne","Mini pizzaer","Vearnaisesauce","Vakselasagne"};
    int LENGTH_OF_ARRAY = sizeof(tmp)/sizeof(tmp[0]);
    
    PrintMeals(tmp, LENGTH_OF_ARRAY);

    return 0;
}


void PrintMeals(char **tmp, int LENGTH_OF_ARRAY) {
    int j = 0;
    int multi = 0;
    int remaining = LENGTH_OF_ARRAY;
    
    while (1) {
        if (remaining > 3) {
            j = 3;
        } else {
            j = remaining;
        }

        for (int i = 0; i < j; i++) {
            printf("%s", tmp[i + multi]);
            printf("\n");
            remaining--;
        }

        if (remaining == 0) {
            break;
        }
        char input[50];
        gets(input);

        if (strcmp("more", input) == 0) {
            multi += 3;
        } else {
            break;
        }
        
    }
}

