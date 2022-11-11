
#include <stdio.h>

struct Ingredienser
{
  int id;
  char name[30];
  double price;
};



int main()
{
  struct Ingredienser tomat;
  struct Ingredienser salat;
  struct Ingredienser kebab;
  struct Ingredienser kød = {5, 30, strcpy("kød")};
  

  tomat.id = 1;
  tomat.price = 5;
  strcpy(tomat.name, "tomat");

  salat.id = 2;
  salat.price = 10;
  strcpy(salat.name, "salat");

  kebab.id = 3;
  kebab.price = 34;
  strcpy(kebab.name, "kebab");



  printf("%s %d %lf \n", tomat.name,tomat.id, tomat.price);
  printf("%s %d %lf", salat.name,salat.id, salat.price);

  return 0;
}
