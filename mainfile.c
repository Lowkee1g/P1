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

    //Scan for data here
    scanData();

    //Search for meals based of the scan
    searchMeals();

    //Sort meals 
    sortMeals();

    //Output the data here
    printMeals(mealResults, SIZE);
    printf("\nending program\n");    

    array[0] = NULL;
    free(array);
    array = NULL;
    
    printf("Run searchMeals tests \n");
    runSearchMealsTests(); // Test searchMeals
    printf("searchMeals tests passed\n");

    endTests();
    
    free(ingredients);
    free(mealResults);
    free(foundmeals);
    free(meals);

    return 0;
}