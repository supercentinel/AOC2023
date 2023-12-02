#include <iso646.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int blues;
    int greens;
    int reds;
} Set;

int canBePlayed(Set game, Set total) {
    if(game.blues <= total.blues
        && game.greens <= total.greens
        && game.reds <= total.reds) {
        return 1;
    }

    return 0;
}

Set readGame(char *buffer) {
    Set game;
    game.blues = 0;
    game.reds = 0;
    game.greens = 0;

    int i = 0;
    int dummy = 0;
    char dd[2];

    while (buffer[i] != '\0') {

        if (buffer[i] == ' ') {
            if(buffer[i+2] == ' ') {
                dd[1] = buffer[i+1];

                dummy = atoi(dd);
            }

            if(buffer[i+3] == ' ' && buffer[i+2] != ':') {
                dd[0] = buffer[i+1];
                dd[1] = buffer[i+2];

                dummy = atoi(dd);
            }

            switch (buffer[i+1]) {
                case 'b':
                    game.blues += dummy;
                break;
                case 'r':
                    game.reds += dummy;
                break;
                case 'g':
                    game.greens += dummy;
                break;
            }
        }

        dd[0] = '0';
        dd[1] = '0';
        i++;
    }

    return game;
}

int main() {
    FILE *fp;
    Set total, game;
    int sum = 0;

    int gg = 1;
    total.reds = 12;
    total.greens = 13;
    total.blues = 14;

    char buffer[180];

    fp = fopen("../input.txt", "r");

    if (fp == NULL) return 1;

    while (fgets(buffer, 180, fp) != NULL) {

        game = readGame(buffer);
        if(canBePlayed(game, total) != 0) {
            printf("Game %d can be played\n", gg);
            sum += gg;
        }

        /* printf("%d\n", gg); */
        gg++;
    }

    printf("%d\n", sum);

    return 0;
}
