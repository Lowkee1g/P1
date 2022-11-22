#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "searchMeals.h"

int main(void){
  printf("Pleeeease skriv 7: %d \n", mealssize);
  initializeStructs();
  printf("main: meal id %d \n", meals[0].id);
  printf("Tager noget fra første ret: %s", meals[0].name);

  free(meals);
  free(ingredients);
  free(foundmeals);

  return 0;
}
