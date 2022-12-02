#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "searchMeals.h"
#include "scaninput.h"

int main(void){
  initializeStructs();
  scanData();
  char **ings = (char **) malloc(2 * sizeof(char));
  ings[0] = "Spaghetti";
  ings[1] = "Noget andet end spaghetti";
  searchMeals(ings);
  printf("Found meals %s \n", foundmeals[0][0].name);

  free(meals);
  free(ingredients);
  free(foundmeals);

    //Load meals and ingrediences here

    //Scan for data here
    scanData();

    //Search for meals based of the scan

    //Sort the output here

    //Output the data here

    return 0;
}