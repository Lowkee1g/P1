#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
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
    char *expected = "Spaghetti Bolognese";
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
void prepSerachMealsTests(void){
    array = malloc(1 * sizeof(char *)); //Allocerer plads til 1 string
    if (array == NULL) //Hvis der ikke er plads til stringen, så stop
    {
        exit(EXIT_FAILURE);
    }
    strcpy(array[0],"water");
    inputSize = 1;
    foundmealsSize = 0;
    searchMeals();
}

// Tests if the first output is Halloween Pierogies when 'vand' is only input
void testFoundmeals(void){
    char expected[23];
    strcpy(expected, "Halloween Pierogies\0");
    assert(strcmp(foundmeals[0].name, expected) == 0);
}

// Tests if there has been found 14 meals (+ 1 to indicate that there are no more meals) if the only input is 'vand'
void testFoundmealsSize(void){
    int expected = 15;
    assert(foundmealsSize == expected);
}

/////////////////////// Tests for sortMeals


/////////////////////// End tests
void endTests(void){
    free(array);
}