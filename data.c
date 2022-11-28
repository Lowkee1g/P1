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
        meal.sizeOfIngs = 0;
        meal.ings = (int *) malloc(30 * sizeof(int));
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
            // printf( " %d \n", counter); //printing each token
            printf( " %d \n", atoi(token)); //printing each token
            // HVORFOR VIRKER DET HER IKKE - på onsdag ANDERS HJÆLP
            // meal.ings = (int *) realloc(meal.ings, counter + 1);
            meal.ings[counter] = atoi(token);
            counter++;
            if (!strcmp("\n", token)){
                break;
            }
            
            token = strtok(NULL, ", { }");
        }
        meals[i] = meal;
    }

            // printf("\n Meal Ings: %d \n", meals[0].ings[4]);
            // printf("\n %d \n", meals[0].sizeOfIngs );
        for (int n = 0; n < meals[1].sizeOfIngs; n++)
        {
            printf("\n Meal Ings: %d \n", meals[1].ings[n]);
        } 

    // printf("\n %d \n", meals[0].sizeOfIngs );

    //     printf("\nMeal Name: %lu\n", sizeof(&meals[0].ings));
    //     printf("\nMeal Name: %d\n", meals[0].ings[6]);
    //     // printf("\nMeal Name: %lu\n", sizeof(&meals[0].ings)/ sizeof(meals[0].ings[0]));
      
    //     int arr_lenth = sizeof &meals[0].ings /sizeof meals[0].ings[0];
    //     printf("\n  1-%d", *meals[0].ings);
    //     printf("\n  2-%d", meals[0].ings[0]);
    //     printf("\n array lenth: %d\n", arr_lenth);

    // for (int i = 0; i < mealsize; i++) {
    //     // printf("\n Meal ID: %d \n", meals[i].id);
    //     // printf("\n Meal Name: %s \n", meals[i].name);
    //     // printf("\n Meal Price: %lf \n", meals[i].price);
    //     for (int n = 0; n < meals[i].sizeOfIngs; n++)
    //     {
    //         printf("\n Meal Ings: %d \n", meals[i].ings[n]);
    //     } 
    // }
}