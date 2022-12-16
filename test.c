#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "data.h"
#include "scaninput.h"
#include "searchMeals.h"

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
    int *ings = getIngs(19);
    int expected[3] = {78,11,19};
    for (int i = 0; i < sizeof(expected)/sizeof(expected[0]); i++) {
        assert(ings[i] == expected[i]);
    }
}


/////////////////////// Tests for searchMeals
void testFoundmeals(void){
    array[0] = "vand";
    char *expected = "Halloween pirogger";
    printf("s% er det samme som %s \n", foundmeals[0].name, expected);
    assert(strcmp(foundmeals[0].name, expected) == 0);
}

void testFoundmealsSize(void){
    array[0] = "vand\0";
    int expected = 15;
    assert(foundmealsSize == expected);
}

/////////////////////// Tests for sortMeals
