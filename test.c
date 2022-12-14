#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "data.h"

char* getStruct(int index)
{
    return meals[index].name;
}

int* getIngs(int index)
{
    return meals[index].ings;
}

void testSpaghettiBolognese(void) {
    char *name = getStruct(0);
    char *expected = "Spaghetti bolognese";
    assert(strcmp(name, expected) == 0);
}

void testGraeskarsuppe(void) {
    char *name = getStruct(40);
    char *expected = "Græskarsuppe";
    assert(strcmp(name, expected) == 0);
}

void testWrongMuffins(void) {
    char *name = getStruct(17);
    char *expected = "Muffiiiins";
    assert(strcmp(name, expected) != 0);
}

void testScrambledEggs(void) {
    char *name = getStruct(56);
    char *expected = "Scrambled eggs";
    assert(strcmp(name, expected) == 0);
}

void testRibbenstegIngredients(void) {
    int *ings = getIngs(0);
    int expected[10] = {2,4,5,6,7,8,9,10,11,12};
    for (int i = 0; i < sizeof(expected)/sizeof(expected[0]); i++) {
        assert(ings[i] == expected[i]);
    }
}