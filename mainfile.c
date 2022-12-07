#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "searchMeals.h"
#include "scaninput.h"

int main(void){

    //Load meals and ingrediences here
    printf("Ind i data \n");
    initializeStructs();

    //Scan for data here
    printf("Efter data. Ind i scan \n");
    scanData();

    //Search for meals based of the scan
    printf("Efter scan \n");
    searchMeals();
    printf("Meal found: %s \n", foundmeals[0][0].name);
    //Sort the output here

    //Output the data here

    //løkke med alle meals, hvor ings bliver freeet
    for (int i = 0; i < mealSize; i++)
    {
      free(meals[i].ings);
    }
    
    free(meals);
    free(ingredients);
    free(foundmeals);

    //Denne her skal ind i searchMeals når den er done 
    free(array);

    return 0;
}