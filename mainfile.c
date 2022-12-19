#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "searchMeals.h"
#include "scaninput.h"
#include "sortMeals.h" 
#include "printOutput.h"
#include "test.h" 

void runStructTests(void) {
  testSpaghettiBolognese();
  testScrambledEggs();
  testWrongMuffins();
  testRibbenstegIngredients();
}

int main(void){    
    //Load meals and ingrediences here
    initializeStructs();
    runStructTests();

    //Scan for data here
    scanData();

    //Search for meals based of the scan
    searchMeals();

    //Sort meals 
    sortMeals();

    //Output the data here
    printMeals(mealResults, SIZE);
    printf("\nending program\n");    
    
    free(ingredients);
    free(mealResults);
    free(foundmeals);
    free(meals);
    free(array);

    return 0;
}