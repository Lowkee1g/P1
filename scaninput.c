#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    scanData();
    return 0;
}


struct inputIngredience {
    char name[30];
    int lengthOfWord;
    int numberOf;
};

void scanData() {
    char inputWord[30];
    int totalInputs;
    
    do {
        printf("input: ");
        fgets(inputWord, sizeof(inputWord), stdin);
        totalInputs++;
    } while (inputWord != "next");
}