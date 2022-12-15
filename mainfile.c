#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "searchMeals.h"
#include "scaninput.h"
#include "sortMeals.h" 
#include "printOutput.h"

int main(void){
    char *tmp[] = {"Pasta pesto", "Brunsviger", "3. ", "4. "};

    //Load meals and ingrediences here
    initializeStructs();

    //Scan for data here
    scanData();

    //Search for meals based of the scan
    searchMeals();
    //Output the data here
    printMeals(tmp, 4);

    
    free(meals);
    free(ingredients);
    free(mealResults);
    free(foundmeals);
    //løkke med alle meals, hvor ings bliver freeet
    for (int i = 0; i < mealSize; i++)
    {
      free(meals[i].ings);
    }

    //Denne her skal ind i searchMeals når den er done 
    // free(array);

    return 0;
}