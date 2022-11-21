#ifndef DATA_H
#define DATA_H

typedef struct Meals {
  int id;       
  char name[50];
  double price;
  int ings[50];
} Meals;

typedef struct Ingredients {
  int id;
  char name[50];
  double price;
} Ingredients;

extern int mealssize;
extern int ingredientssize;

void initializeStructs();

extern Meals *meals;
// extern Ingredients ingredients[];

#endif