#include <stdio.h>
#include "data.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

Meals *meals; 
Ingredients *ingredients;

int mealSize;
int ingredientsSize;

void changeMeal(int id, char* name, double price, int*  ingredientids);
void changeIngredient(int id, char* name, double price);
void initializeStructs();
void initializeMeals(FILE *mealsFile);
void initializeIngredients(FILE *ingredientsFile);
int getNumberOfLines(FILE *file);

int main(int argc, char const *argv[])
{
    initializeStructs();
    for (int i = 0; i < mealSize; i++)
    {
      free(meals[i].ings);
    }
    
    free(meals);
    free(ingredients);
    return 0;
}

void initializeStructs() {

    // Open File Meals.txt as read
    FILE *mealsFile = fopen("meals.txt", "r");
    FILE *ingredientsFile = fopen("ingredients.txt", "r");

    // Check for failure
    if(mealsFile == NULL || ingredientsFile == NULL) {
        exit(EXIT_FAILURE);
    }
    initializeMeals(mealsFile);
    initializeIngredients(ingredientsFile);
}


void initializeMeals(FILE *mealsFile) {
    
    // initialize mealszie by calling GetNumberOfLines on meals.txt file
    mealSize = getNumberOfLines(mealsFile);
    fclose(mealsFile);  //Closing file

    // Initialize Meals
    meals = (Meals *) malloc(mealSize * sizeof(Meals));

    // Open meals.txt agian and check for failure 
    FILE *openMealsFileAgain = fopen("meals.txt", "r");

    if (meals == NULL || openMealsFileAgain == NULL){
        exit(EXIT_FAILURE); printf("58: Exits here");
    }

    // Intialize success and struct meal
    int success;
    //Meals meal;

    // Loop through all meals.
    for (int i = 0; i < mealSize; i++) {
        printf("MealsSize er: %d \n", mealSize);
        // Set a counter used to control ingredients mallock size and tempString to make ingredients array
        char tempString[100];
        int counter = 0;
        printf("last meals id = %d \n", meals[i - 1].id);

        // Intialize ingredients mallock and set size to 1 and set the sizeOfIngs to 0
        printf("meals[%d].ings bliver oprettet ", i);
        meals[i].ings = (int *) calloc(0, 1 * sizeof(int)); printf("Running - calloc \n");
        if (meals[i].ings == NULL){
            printf("EXIT - meal.ings == null\n"); exit(EXIT_FAILURE); 
        }

        meals[i].sizeOfIngs = 0;
        
        // Read each line in meals.txt
        success = fscanf(openMealsFileAgain, "%d, %[^,], %lf, %s", &meals[i].id, &*meals[i].name, &meals[i].price, &*tempString);
        printf("Success: %d - %d|%s|%lf|%s \n", success, meals[i].id, meals[i].name, meals[i].price, tempString);

        
        // If it fails break the loop
        if(success != 4) {
            printf("Break: success is not 4 \n");
            break; 
        }

        // Break the tempString into tokens. Splitting the string at , { }.
        char * token = strtok(tempString, ", { }");
        

        // loop through the string to extract all other tokens
        while( token != NULL ) {
            // Increase size of ingredients in the struct and realloc the size of ingredients
            meals[i].sizeOfIngs++;
            meals[i].ings = (int *) realloc(meals[i].ings, 1 * sizeof(int));
            if (meals[i].ings == NULL)
            {
                printf("3. exit ting");
                exit(EXIT_FAILURE);
            }
            printf("-Loaded Ingredience: %d \n", counter);
            
            // Convert the char into an integer and push it to ingredients array
            meals[i].ings[counter] = atoi(token);
            counter++;

            // Break at end of file
            if (!strcmp("\n", token)){
                break;
            }
            
            // When there is no tokents left to retrieve make token return null to stop the while loop
            token = strtok(NULL, ", { }");
        }
        printf("Stored: [%d|%s|%lf|%d] \n", meals[i].id, meals[i].name, meals[i].price, meals[i].ings[0]);
        printf("end of loop \n");
    }

    fclose(openMealsFileAgain);
    printf("Efter fclose linje 123 \n");
}

void initializeIngredients(FILE *ingredientsFile) {
    // initialize ingredientsSize by calling GetNumberOfLines on meals.txt file
    ingredientsSize = getNumberOfLines(ingredientsFile);
    
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
            printf("Linje 150 success er ikke 3\n");
            break;
        }
        ingredients[i] = ingredient;
    }
    fclose(openIngredientsFileAgain);
}

int getNumberOfLines(FILE *file) {
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
    return numberOfLines;
}