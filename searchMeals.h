#ifndef SEACH_MEALS_H
#define SEACH_MEALS_H
#include "data.h"

extern Meals *foundmeals;
extern int foundmealsSize;

void searchMeals();
int contains(int a, int *list, int size);

#endif // SEACH_MEALS_H