#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "searchMeals.h"
#include "scaninput.h"
#include "sortMeals.h" 

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
    printf("Efter searchMeals \n");
    // printf("Meal found: %d \n", foundmeals[1][0].id);
    //Sort the output here
    sortMeals();
    printf("Ud af sortMeals \n");
    //Output the data here

    //løkke med alle meals, hvor ings bliver freeet
    for (int i = 0; i < mealSize; i++)
    {
      free(meals[i].ings);
    }
    
    free(meals);
    free(ingredients);
    free(foundmeals);
    free(mealResults);

    //Denne her skal ind i searchMeals når den er done 
    free(array);

    return 0;
}