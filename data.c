#include <stdio.h>
#include "data.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

int ingredientssize = 7;
Meals *meals; 
Ingredients *ingredients;

void changeMeal(int id, char* name, double price, int*  ingredientids);
void changeIngredient(int id, char* name, double price);
void initializeStructs();
void InitializeMeals(FILE *file);
void initializeStructs(){
    
    // int *ingredientids = (int *) malloc(3 * sizeof(int));
    // if (ingredientids == NULL){
    //     exit(EXIT_FAILURE);
    // }
    
    // ingredientids[0] = 1;
    // ingredientids[1] = 4;
    // ingredientids[2] = 7;
    // changeMeal(1, "Spaghetti bolognese", 50.95, ingredientids);

    
    // free(ingredientids);

    // ingredients = (Ingredients *) malloc(ingredientssize * sizeof(Ingredients));
    // if (ingredients == NULL){
    //     exit(EXIT_FAILURE);
    // }

    FILE *file = fopen("meals.txt", "r");

    if(file == NULL) {
        exit(EXIT_FAILURE);
    }

    InitializeMeals(file);
    fclose(file);

}

void InitializeMeals(FILE *file) {
    // Get number of meals in meals.txt
    int mealsize = 1;
    int ch = 0;
    // Tests the end-of-file indiacator
    while(!feof(file)) {
        ch = fgetc(file);
        // If the last char is breakline do mealsize++
        if(ch == '\n') {
            mealsize++;
        }
    }
    printf("%d", mealsize);

    meals = (Meals *) malloc(mealsize * sizeof(Meals));
    if (meals == NULL){
        exit(EXIT_FAILURE);
    }

    int success;
    Meals meal;
    for (int i = 0; i < mealsize; i++) {
        success = fscanf(file, "%d", &meal.id);
        printf("success: %d", success);
        //  if(success != 1) {

        //  }
        // meal.id = i + 1;
        meals[i] = meal;
    }

    for (int i = 0; i < mealsize; i++) {
        printf("\nMeal ID: %d\n", meals[i].id);
        // printf("\nMeal Name: %s\n", meals[i].name);
        // printf("\nMeal Price: %lf\n", meals[i].price);
    }
}

// void changeMeal(int id, char* name, double price, int* ingredientids){
//     meals[id - 1].id = id;
//     strcpy(meals[id - 1].name, name);
//     meals[id - 1].price = price;
//     // meals[id - 1].ings = ingredientids;
// }

// void changeIngredient(int id, char* name, double price){
//     ingredients[id - 1].id = id;
//     strcpy(ingredients[id - 1].name, name);
//     ingredients[id - 1].price = price;
// }
