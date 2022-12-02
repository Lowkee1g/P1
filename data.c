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

    FILE *file = fopen("meals.txt", "r");

    if(file == NULL) {
        exit(EXIT_FAILURE);
    }

    InitializeMeals(file);
    fclose(file);

}

void InitializeMeals(FILE *file) {
    // Get number of meals in meals.txt
    int sample_chr = getc(file);
    int mealsize = 1;
    while(sample_chr != EOF) {
        if(sample_chr == '\n') {
            mealsize++;
        }

        sample_chr = getc(file);
    }
    fclose(file);
    printf("SIZE: %d\n", mealsize);
    meals = (Meals *) malloc(mealsize * sizeof(Meals));

    
    FILE *openFileAgain = fopen("meals.txt", "r");

    if (meals == NULL){
        exit(EXIT_FAILURE);
    }

    int success;

    Meals meal;
    for (int i = 0; i < mealsize; i++) {
        int counter = 0;
        char tempString[50];
        meal.ings = (int *) malloc(1 * sizeof(int));
        meal.sizeOfIngs = 0;

        if (meal.ings == NULL)
        {
            exit(EXIT_FAILURE);
        }
        
        success = fscanf(openFileAgain, "%d, %[^,], %lf, %s", &meal.id, &*meal.name, &meal.price, &*tempString);
        printf("success: %d", success);
        if(success != 4) {
            break;
        }

        char * token = strtok(tempString, ", { }");
        
         // loop through the string to extract all other tokens
        while( token != NULL ) {
            meal.sizeOfIngs++;
            meal.ings = (int *) realloc(meal.ings, counter * sizeof(int));
            meal.ings[counter] = atoi(token);
            counter++;
            if (!strcmp("\n", token)){
                break;
            }
            
            token = strtok(NULL, ", { }");
        }
        meals[i] = meal;
    }

    for (int i = 0; i < mealsize; i++) {
        printf("\n Meal ID: %d \n", meals[i].id);
        printf("\n Meal Name: %s \n", meals[i].name);
        printf("\n Meal Price: %lf \n", meals[i].price);
        for (int n = 0; n < meals[i].sizeOfIngs; n++)
        {
            printf("\n Meal Ings: %d \n", meals[i].ings[n]);
        } 
    }
}