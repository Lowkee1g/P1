#include <stdio.h>

struct Meals {
  int id;       
  char name[50];
  double price;
  int ings[50];
};

struct Ingredients {
  int id;
  char name[50];
  double price;
};

typedef struct Meals meals;
typedef struct Ingredients ingredients;

int initializeStructs(void){

    struct Meals meal[7] = {
      {1, "Spaghetti bolognese", 50.95, {1,4,7}},
      {2, "Lasagne", 50.95, {1,4,7}},
      {3, "Pasta pesto", 50.95, {2,7}},
      {4, "Hot dogs", 50.95, {}},
      {5, "Pizza", 50.95, {4,6}},
      {6, "Chili con carne", 50.95, {3}},
      {7, "Indian dahl", 50.95, {5}}
    };

    struct Ingredients ingredients[7] = {
      {1, "Minced meat", 39.95},
      {2, "Pesto", 15.95},
      {3, "Beans", 22.95},
      {4, "Dolmio", 10.95},
      {5, "Green Lentils", 5.95},
      {6, "Ham", 11.55},
      {7, "Pasta", 9.55},
    };

  return 0;
}
