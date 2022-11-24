#include <stdio.h>
#include "data.h"
#include <string.h>
#include <stdlib.h>

int mealssize = 7;
int ingredientssize = 7;
Meals *meals; 
Ingredients *ingredients;

void changeMeal(int id, char* name, double price, int*  ingredientids);
void changeIngredient(int id, char* name, double price);
void initializeStructs();

void initializeStructs(){
    meals = (Meals *) malloc(mealssize * sizeof(Meals));
    if (meals == NULL){
        exit(EXIT_FAILURE);
    }
    
    int *ingredientids = (int *) malloc(3 * sizeof(int));
    if (ingredientids == NULL){
        exit(EXIT_FAILURE);
    }
    
    ingredientids[0] = 1;
    ingredientids[1] = 4;
    ingredientids[2] = 7;
    changeMeal(1, "Spaghetti bolognese", 50.95, ingredientids);
    // {2, "Lasagne", 50.95, {1,4,7}},
    // {3, "Pasta pesto", 50.95, {2,7}},
    // {4, "Hot dogs", 50.95, {}},
    // {5, "Pizza", 50.95, {4,6}},
    // {6, "Chili con carne", 50.95, {3}},
    // {7, "Indian dahl", 50.95, {5}}
    
    free(ingredientids);

    ingredients = (Ingredients *) malloc(ingredientssize * sizeof(Ingredients));
    if (ingredients == NULL){
        exit(EXIT_FAILURE);
    }

    changeIngredient(1, "Spaghetti", 10);

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

void changeMeal(int id, char* name, double price, int* ingredientids){
    meals[id - 1].id = id;
    strcpy(meals[id - 1].name, name);
    meals[id - 1].price = price;
    // meals[id - 1].ings = ingredientids;
}

void changeIngredient(int id, char* name, double price){
    ingredients[id - 1].id = id;
    strcpy(ingredients[id - 1].name, name);
    ingredients[id - 1].price = price;
}
