#include <stdio.h>
#include <stdlib.h>

int isSymbol(char c) {

    switch (c) {
        case '*':
            return 1;
        break;
        case '&':
            return 1;
        break;
        case '=':
            return 1;
        break;
        case '+':
            return 1;
        break;
        case '#':
            return 1;
        break;
        case '@':
            return 1;
        break;
        case '%':
            return 1;
        break;
        case '/':
            return 1;
        break;
        case '-':
            return 1;
        break;
        case '$':
            return 1;
        break;
    }

    return 0;
}

int isAdjacent(char data[150][150], int i, int j) {

    //check up
    if (isSymbol(data[i-1][j])) {
        return 1;
    }
    //check up-right
    if (isSymbol(data[i-1][j+1])) {
        return 1;
    }
    //check up-left
    if (isSymbol(data[i-1][j-1])) {
        return 1;
    }
    //check left
    if (isSymbol(data[i][j-1])) {
        return 1;
    }
    //check right
    if (isSymbol(data[i][j+1])) {
        return 1;
    }
    //check down
    if (isSymbol(data[i+1][j])) {
        return 1;
    }
    //check down-right
    if (isSymbol(data[i+1][j+1])) {
        return 1;
    }
    //check down-up
    if (isSymbol(data[i+1][j-1])) {
        return 1;
    }

    return 0;
}

int main() {
     FILE *fp;

    int i = 0;
    int j = 0;
    char data[150][150];

    fp = fopen("../input.txt", "r");

    if (fp == NULL) {
        return 1;
    }

    //reading of input file
    while (fgets(data[i], 150, fp) != NULL) {
        while (data[i][j] != '\0') {
            data[i][j] = data[i][j];
            j++;
        }
        i++;
    }

    printf("adjacent at 1,37: %d\n", isAdjacent(data, 2, 16));

    return 0;
}
