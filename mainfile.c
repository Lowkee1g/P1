#include <stdio.h>
#include "data.h"

int main(void){
  printf("Pleeeease skriv 7: %d \n", mealssize);
  initializeStructs();
  printf("main: meal id %d \n", meals[0].id);
  printf("Tager noget fra første ret: %s", meals[0].name);
  return 0;
}
