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

void runSearchMealsTests(void) {
  prepSerachMealsTests();
  testFoundmeals();
  testFoundmealsSize();
}

int main(void){    
    //Load meals and ingrediences here
    initializeStructs();
    runStructTests();
    printf("Run searchMeals tests \n");
    runSearchMealsTests(); // Test searchMeals
    printf("searchMeals tests passed\n");

    endTests();

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
    free(array);
    //løkke med alle meals, hvor ings bliver freeet
    for (int i = 0; i < mealSize; i++)
    {
      free(meals[i].ings);
    }
    free(meals);

    return 0;
}