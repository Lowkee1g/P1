#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "searchMeals.h"
#include "scaninput.h"
#include "sortMeals.h" 

int main(void){

    //Load meals and ingrediences here
    initializeStructs();

    //Scan for data here
    scanData();

    //Search for meals based of the scan
    searchMeals();
    printf("Printer foundmeals[0][0].id = %d \n", foundmeals[0][0].id);

    //Output the data here

    //løkke med alle meals, hvor ings bliver freeet
    for (int i = 0; i < mealSize; i++)
    {
      free(meals[i].ings);
    }
    
    free(meals);
    free(ingredients);
    free(mealResults);

    //Denne her skal ind i searchMeals når den er done 
    free(array);

    return 0;
}