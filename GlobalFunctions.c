#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GlobalFunctions.h"


char getStringInput() {
    char *input;
    fgets(input, 100, stdin);

    if (strcmp(input, "quit") == 0) {
        printf("quiting program");
        exit(EXIT_SUCCESS);
    }
    return input;

}