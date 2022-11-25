#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "searchMeals.h"

int main(void){
  initializeStructs();
  char **ings = (char **) malloc(2 * sizeof(char));
  ings[0] = "Spaghetti";
  ings[1] = "Noget andet end spaghetti";
  searchMeals(ings);
  printf("Found meals %s \n", foundmeals[0][0].name);

  free(meals);
  free(ingredients);
  free(foundmeals);

  return 0;
}