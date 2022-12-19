#ifndef TEST_H
#define TEST_H
#include "data.h"

char* getStruct(int index);
int* getIngs(int index);
void testSpaghettiBolognese(void);
void testScrambledEggs(void);
void testWrongMuffins(void);
void testRibbenstegIngredients(void);

// serachMeals tests
void prepSerachMealsTests(void);
void testFoundmeals(void);
void testFoundmealsSize(void);

// sortMeals tests

// End tests
void endTests(void);

#endif // SORT_MEALS_H