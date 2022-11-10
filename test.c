#include <stdlib.h>
#include <stdio.h>
#include "json-c/json.h"
#include <string.h>
#include "test.h"

struct Meals {   // Structure declaration
  int id;           // Member (int variable)
  char name[50];       // Member (char variable)
  double price;
  int ings[50];
}; // End the structure with a semicolon

void initializeStructs()
{
    // struct json variables
    struct json_object *id;
    struct json_object *name;
    struct json_object *price;
    struct json_object *ingredients;
    struct json_object *ingredient;

    // Counter to create an array of structures (meals)
    int counter = 0;

    json_object *root = json_object_from_file("data.json");
    json_object *meals = json_object_object_get(root, "meals");
    size_t n_ingredients;

    struct Meals testmeal[50];

    json_object_object_foreach(meals, key, val) { // Loop through root
    
        json_object *meal = json_object_object_get(meals, key); // get meals
        json_object_object_get_ex(meal,"id", &id);
        json_object_object_get_ex(meal,"name", &name);
        json_object_object_get_ex(meal,"price", &price);
        json_object_object_get_ex(meal,"ings", &ingredients);

        n_ingredients = json_object_array_length(ingredients);

        testmeal[counter].id = json_object_get_int(id);
        strcpy(testmeal[counter].name, json_object_get_string(name));
        testmeal[counter].price = json_object_get_double(price);

        for(int i = 0; i < n_ingredients; i++) {
            ingredient = json_object_array_get_idx(ingredients, i);
            testmeal[counter].ings[i] = json_object_get_int(ingredient);
            
        }
 
        // printf("Id of meal: %i\n", testmeal[counter].id);
        // printf("Name of meal: %s\n", testmeal[counter].name);
        // printf("Total price of meal: %f\n", testmeal[counter].price);
        // for(int n = 0; n < n_ingredients; n++) {
        //     printf("This meal contains the ingredients: %i\n", testmeal[counter].ings[n]);
        // }

        counter++;
    }

        // printf("Name of meal: %s & %s\n", testmeal[0].name,json_object_get_string(name));
        char teststring[50];

        //  Scan a meal in
        printf("Enter a meal\n");
        scanf("%49[^\n]%*1[\n]", teststring);


        // Need to set set array of ings with mallock to used in ingredients loop
        // int arr_length = *(&testmeal[0].ings + 1) - testmeal[0].ings;
        // printf(" The length of int array is : %i \n", arr_length);

    // Used for search based om name of meal
    for(int i = 0; i < 2; i++) {
        if(strcmp(testmeal[i].name, teststring) == 0)
        {
            printf("Found it!, Here are the informations:\n");
            printf("Location ID: %i\n", testmeal[i].id);
            printf("Name of meal: %s\n", testmeal[i].name);
            printf("Total price of meal: %f\n", testmeal[i].price);
            // for(int n = 0; n < (sizeof(testmeal[i].ings) / (testmeal[i].ings[0]) ); n++) {
            //     printf("This meal contains the ingredients: %i\n", testmeal[i].ings[n]);
            // }
            break;
        }
    }

    // Research what this means 
    json_object_put(root); 
}
