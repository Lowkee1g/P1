#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x,y;
} player;

int main(int argc, char const *argv[])
{
    char **plade;
    int size = 10;
    player player;

    player.x = size/2;
    player.y = size/2;

    plade = malloc(size * sizeof *plade);
    for (int i = 0; i < size; i++) {
        plade[i] = malloc(size * sizeof *plade[i]);
    }


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            plade[i][j] = 'X';
        }
    }
    


    while(1) {
        char input = ' ';
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (player.y == i && player.x == j) {
                    printf("\033[0;36m");
                    printf(" @");
                } else {
                    printf("\033[0;32m");
                    printf(" %c", plade[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");

        scanf("%c", &input);
        if (input == 'a') {
            player.x --;
        } else if (input == 's') {
            player.y++;
        } else if (input == 'd') {
            player.x++;
        } else if (input == 'w') {
            player.y--;
        }
    }

    printf("\033[0;0m");
    return 0;
}
