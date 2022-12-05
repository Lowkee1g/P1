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

    printf("Efter scan \n");
    //Search for meals based of the scan

    //Sort the output here

    //Output the data here

    //Fuck all her
    // char **ings = (char **) malloc(2 * sizeof(char));
    // ings[0] = "Spaghetti";
    // ings[1] = "Noget andet end spaghetti";
    // searchMeals(ings);
    // printf("Found meals %s \n", foundmeals[0][0].name);

    //løkke med alle meals, hvor ings bliver freeet
    for (int i = 0; i < mealSize; i++)
    {
      free(meals[i].ings);
    }
    
    free(meals);
    free(ingredients);
    // free(foundmeals);

    return 0;
}