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
    // array[0] = "vand";
    // char *expected = "Halloween pirogger";
    // assert(strcmp(foundmeals[0].name, expected) == 0);
}

void testFoundmealsSize(void){
    // if (strcmp(array[0], "vand") == 0){
    //     int expected = 15;
    //     assert(foundmealsSize == expected);
    // }
    printf("Inden kaldet \n");
    array[0] = "vand";
    inputSize = 1;
    foundmealsSize = 0;
    // Vil gerne kalde seachMeals her, men den crasher.
    // searchMeals();
    int expected = 15;
    printf("\nfoundmealsSize %d, expected %d \n", foundmealsSize, expected);
    assert(foundmealsSize == expected);
}

/////////////////////// Tests for sortMeals
