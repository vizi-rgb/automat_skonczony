#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void anim(int a) {
    /*
    for (int col = 0; col < 4; col++) { 

        if (col == 0 || col == 4) {
            for (int row = 0; row < 16; row++) {

                if (a == 0 && row < 4) {
                    printf("----");
                    row = 4;
                } else if (row == 8) {
                    printf("%d", col == 0 ? 0 : 1);
                } else if (a == 1 && row > 11) {
                    printf("%s", row != 15 ? "-" : "-\n");
                } else {
                    printf("%c", row != 15 ? ' ' : '\n');
                }

            }
        }


        if (col == 2 || col == 3) {
            for (int row = 0; row < 16; row++) {

                if (a == 0 && row < 4) {
                    printf("=%s=", col != 3 ? "q0" : "  ");
                    row = 4;
                } else if (row == 7) {
                    printf("%s", col != 3 ? "->" : "<-");
                    row = 8;
                } else if (a == 1 && row > 11) {
                    printf("=%s=\n", col != 3 ? "q1" : "  ");
                    row = 15;
                } else {
                    printf("%c", row != 15 ? ' ' : '\n');
                }
                
            } 
        }

    }
    */

    if (a == 0) {
        printf("START\n");
        printf(" |\n");
        printf(" v \n");
        printf("----    0       \n"
               "=q0=   -->   q1 \n"
               "====   <--      \n"
               "----    1       \n\n"
               "1 |^ 0    0 ^||0\n"
               "  ||         || \n"
               "  v|         |v \n\n"
               "        1       \n"
               " q2    <--   q3 \n" 
               "       -->      \n"
               "        1       \n\n\n"
              );
        
     } else if (a == 1) {
        printf("START\n");
        printf(" |\n");
        printf(" v \n");
        printf("        0   ----\n"
               " q0    -->  =q1=\n"
               "       <--  ====\n"
               "        1   ----\n\n"
               "1 |^ 0    0 ^||0\n"
               "  ||         || \n"
               "  v|         |v \n\n"
               "        1       \n"
               " q2    <--   q3 \n" 
               "       -->      \n"
               "        1       \n\n\n"
              );

     } else if (a == 2) {
        printf("START\n");
        printf(" |\n");
        printf(" v \n");
        printf("        0       \n"
               " q0    -->   q1 \n"
               "       <--      \n"
               "        1       \n\n"
               "1 |^ 0    0 ^||0\n"
               "  ||         || \n"
               "  v|         |v \n\n"
               "----    1       \n"
               "=q2=   <--   q3 \n" 
               "====   -->      \n"
               "----    1       \n\n\n"
              );

     } else {
        printf("START\n");
        printf(" |\n");
        printf(" v \n");
        printf("        0       \n"
               " q0    -->   q1 \n"
               "       <--      \n"
               "        1       \n\n"
               "1 |^ 0    0 ^||0\n"
               "  ||         || \n"
               "  v|         |v \n\n"
               "        1   ----\n"
               " q2    <--  =q3=\n" 
               "       -->  ====\n"
               "        1   ----\n\n\n"
              );

     }

    



}


int main(int argc, char **argv) {
    /* 
    states =    q0 -> q1 : q2
                q1 -> q3 : q0
                q2 -> q0 : q3 
                q3 -> q1 : q2
    */

                
    int states[4][2] = {1, 2,		
                        3, 0,
                        0, 3,
                        1, 2};

    char *state_names[4] = {"q0", "q1", "q2", "q3"};
    int actual_state = 0;
    int desired_state = 0;
    int c;
    FILE *we = argc == 2 ? fopen(argv[1], "r") : stdin;

    if (we == NULL) {
        fprintf(stderr, "Nie udalo sie otworzyc pliku.\n");
        return 1;
    }


    while ( (c=fgetc(we)) != EOF)  {
        if (c == ' ' || c == '\n') 
            continue;
        if (c != '0' && c != '1') {
            fprintf(stderr, "Zla wartosc wejsciowa\n");
            return 2;
        }	

        // printf("%s -> %s \t%d\n", state_names[actual_state], state_names[ states[actual_state][c - '0'] ], c -'0'); 
        actual_state = states[actual_state][c-'0'];
    }

    if (actual_state == desired_state) {
        printf("Dane wejsciowe zostaly zaakceptowane\n");
    } else {
        printf("Dane wejsciowe nie zostaly zaakceptowane\n");
    } 

    printf("\n");
    anim(actual_state);


    return 0;
}
