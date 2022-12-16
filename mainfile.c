#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "searchMeals.h"
#include "scaninput.h"
#include "sortMeals.h" 
#include "printOutput.h"
#include "test.h" 

void runAllTests(void) {
  testSpaghettiBolognese();
  testScrambledEggs();
  testWrongMuffins();
  testRibbenstegIngredients();
}

int main(void){
    //char *tmp[] = {"Pasta pesto", "Brunsviger", "3. ", "4. "};

    //Load meals and ingrediences here
    initializeStructs();
    runAllTests();

    //Scan for data here
    scanData();

    //Search for meals based of the scan
    searchMeals();

    //Sort meals 
    sortMeals();

    //Output the data here
    printMeals(mealResults, SIZE);
    printf("\nending program\n");
    
    free(meals);
    free(ingredients);
    free(mealResults);
    free(foundmeals);
    free(array);
    //løkke med alle meals, hvor ings bliver freeet
    for (int i = 0; i < mealSize; i++)
    {
      free(meals[i].ings);
    }

    //Denne her skal ind i searchMeals når den er done 
    //free(array);

    return 0;
}