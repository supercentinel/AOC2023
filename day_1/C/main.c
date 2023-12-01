#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fb;
    int sum = 0;
    int i = 0;

    char buffer[100];
    char dd[2];
    char sumstr[10];


    fb = fopen("../input.txt", "r");

    if(fb == NULL) return 0;

    while(fgets(buffer, 100, fb)) {

        while(buffer[i] != '\0') {

            if(buffer[i] >=49 && buffer[i] <= 57) {
                if(dd[0] == 0) {
                    dd[0] = buffer[i];
                }

                dd[1] = buffer[i];
            }

            switch (buffer[i]) {
                case 'o':
                    //one
                    if(buffer[i+1] == 'n' && buffer[i+2] == 'e') {
                        if(dd[0] == 0) {
                            dd[0] = '1';
                        }

                        dd[1] = '1';
                    }
                break;
                case 't':
                    //two
                    if(buffer[i+1] == 'w' && buffer[i+2] == 'o') {
                        if(dd[0] == 0) {
                            dd[0] = '2';
                        }

                        dd[1] = '2';
                    }
                    //three
                    if(buffer[i+1] == 'h'
                        && buffer[i+2] == 'r'
                        && buffer[i+3] == 'e'
                        &&buffer[i+4] == 'e') {
                        if(dd[0] == 0) {
                            dd[0] = '3';
                        }

                        dd[1] = '3';
                    }
                break;
                case 'f':
                    //four
                    if(buffer[i+1] == 'o'
                        && buffer[i+2] == 'u'
                        && buffer[i+3] == 'r') {
                        if(dd[0] == 0) {
                            dd[0] = '4';
                        }

                        dd[1] = '4';
                    }
                    //five
                    if(buffer[i+1] == 'i'
                        && buffer[i+2] == 'v'
                        && buffer[i+3] == 'e') {
                        if(dd[0] == 0) {
                            dd[0] = '5';
                        }

                        dd[1] = '5';
                    }
                break;
                case 's':
                    //six
                    if(buffer[i+1] == 'i'
                        && buffer[i+2] == 'x') {
                        if(dd[0] == 0) {
                            dd[0] = '6';
                        }

                        dd[1] = '6';
                    }
                    //seven
                    if(buffer[i+1] == 'e'
                        && buffer[i+2] == 'v'
                        && buffer[i+3] == 'e'
                        && buffer[i+4] == 'n') {
                        if(dd[0] == 0) {
                            dd[0] = '7';
                        }

                        dd[1] = '7';
                    }
                break;
                case 'e':
                    //eight
                    if(buffer[i+1] == 'i'
                        && buffer[i+2] == 'g'
                        && buffer[i+3] == 'h'
                        && buffer[i+4] == 't') {
                        if(dd[0] == 0) {
                            dd[0] = '8';
                        }

                        dd[1] = '8';
                    }
                break;
                case 'n':
                    //nine
                    if(buffer[i+1] == 'i'
                        && buffer[i+2] == 'n'
                        && buffer[i+3] == 'e') {
                        if(dd[0] == 0) {
                            dd[0] = '9';
                        }

                        dd[1] = '9';
                    }
                break;

            }

            i++;
        }

        sprintf(sumstr, "%c%c\n", dd[0], dd[1]);
        sum += atoi(sumstr);

        dd[0] = 0;
        dd[1] = 0;
        i = 0;
    }

    fclose(fb);

    printf("%d\n", sum);

    return 0;
}
