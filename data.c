#include <stdio.h>
#include "data.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

Meals *meals; 
Ingredients *ingredients;

void changeMeal(int id, char* name, double price, int*  ingredientids);
void changeIngredient(int id, char* name, double price);
void initializeStructs();
void InitializeMeals(FILE *mealsFile);
void InitializeIngredients(FILE *ingredientsFile);
int GetNumberOfLines(FILE *file);

void initializeStructs() {

    // Open File Meals.txt as read
    FILE *mealsFile = fopen("meals.txt", "r");
    FILE *ingredientsFile = fopen("ingredients.txt", "r");

    // Check for failure
    if(mealsFile == NULL || ingredientsFile == NULL) {
        exit(EXIT_FAILURE);
    }

    InitializeMeals(mealsFile);
    InitializeIngredients(ingredientsFile);
}

void InitializeMeals(FILE *mealsFile) {
    
    // initialize mealszie by calling GetNumberOfLines on meals.txt file
    int mealSize = GetNumberOfLines(mealsFile);

    // Initialize Meals
    meals = (Meals *) malloc(mealSize * sizeof(Meals));

    // Open meals.txt agian and check for failure 
    FILE *openMealsFileAgain = fopen("meals.txt", "r");

    if (meals == NULL || openMealsFileAgain == NULL){
        exit(EXIT_FAILURE);
    }

    // Intialize success and struct meal
    int success;
    Meals meal;
    // Loop through all meals.
    for (int i = 0; i < mealSize; i++) {
        // Set a counter used to control ingredients mallock size and tempString to make ingredients array
        char tempString[100];
        int counter = 0;

        // Intialize ingredients mallock and set size to 1 and set the sizeOfIngs to 0
        meal.ings = (int *) malloc(1 * sizeof(int));
        meal.sizeOfIngs = 0;

        if (meal.ings == NULL)
        {
            exit(EXIT_FAILURE);
        }
        
        // Read each line in meals.txt
        success = fscanf(openMealsFileAgain, "%d, %[^,], %lf, %s", &meal.id, &*meal.name, &meal.price, &*tempString);
        
        // If it fails break the loop
        if(success != 4) {
            break;
        }

        // Break the tempString into tokens. Splitting the string at , { }.
        char * token = strtok(tempString, ", { }");
        
        // loop through the string to extract all other tokens
        while( token != NULL ) {
            // Increase size of ingredients in the struct and realloc the size of ingredients
            meal.sizeOfIngs++;
            meal.ings = (int *) realloc(meal.ings, counter * sizeof(int));
            // Convert the char into an integer and push it to ingredients array
            meal.ings[counter] = atoi(token);
            counter++;

            // Break at end of file
            if (!strcmp("\n", token)){
                break;
            }
            
            // When there is no tokents left to retrieve make token return null to stop the while loop
            token = strtok(NULL, ", { }");
        }
        // Put each meal into the array of meals
        meals[i] = meal;
    }

    fclose(openMealsFileAgain);
}

void InitializeIngredients(FILE *ingredientsFile) {
    // initialize ingredientsSize by calling GetNumberOfLines on meals.txt file
    int ingredientsSize = GetNumberOfLines(ingredientsFile);
    
    // Initialize ingredients
    ingredients = (Ingredients *) malloc(ingredientsSize * sizeof(Ingredients));

    // Open ingredients.txt agian and check for failure 
    FILE *openIngredientsFileAgain = fopen("ingredients.txt", "r");

    if (ingredients == NULL || openIngredientsFileAgain == NULL){
        exit(EXIT_FAILURE);
    }

    // Intialize success and struct meal
    int success;
    Ingredients ingredient;
    // Loop through all ingredients
    for (int i = 0; i < ingredientsSize; i++) {
        // Read each line in ingredients.txt
        success = fscanf(openIngredientsFileAgain, "%d, %[^,], %lf", &ingredient.id, &*ingredient.name, &ingredient.price);
        // If it fails break the loop
        if(success != 3) {
            break;
        }
        ingredients[i] = ingredient;
    }
    fclose(openIngredientsFileAgain);
}

int GetNumberOfLines(FILE *file) {
      // Get number of meals in meals.txt to make a malloc
    int sampleChr = getc(file);
    int numberOfLines = 1;

    // If sampleChr is not equal to end of file do mealSize++ for each break line
    while(sampleChr != EOF) {
        if(sampleChr == '\n') {
            numberOfLines++;
        }
        sampleChr = getc(file);
    }
    // Close file to get back to the top of the document
    fclose(file);
    return numberOfLines;
}