#include <stdio.h>
#include "data.h"
#include <string.h>

int mealssize = 7;
int ingredientssize = 7;
Meals meals[1]; // TODO: Det her virker til at skulle være malloc. Det skal på heap, så det kan tilgås globalt

void initializeStructs(){
    meals[0].id = 1;
    strcpy(meals[0].name, "Spaghetti bolognese");
    meals[0].price = 50.95;
    // meal[0].ings = {1,4,7};
    printf("Meals virker?: %d \n", meals[0].id);

    // Meals meals[mealssize] = {
    //   {1, "Spaghetti bolognese", 50.95, {1,4,7}},
    //   {2, "Lasagne", 50.95, {1,4,7}},
    //   {3, "Pasta pesto", 50.95, {2,7}},
    //   {4, "Hot dogs", 50.95, {}},
    //   {5, "Pizza", 50.95, {4,6}},
    //   {6, "Chili con carne", 50.95, {3}},
    //   {7, "Indian dahl", 50.95, {5}}
    // };

    // Ingredients ingredients[ingredientssize] = {
    //   {1, "Minced meat", 39.95},
    //   {2, "Pesto", 15.95},
    //   {3, "Beans", 22.95},
    //   {4, "Dolmio", 10.95},
    //   {5, "Green Lentils", 5.95},
    //   {6, "Ham", 11.55},
    //   {7, "Pasta", 9.55},
    // };
}
