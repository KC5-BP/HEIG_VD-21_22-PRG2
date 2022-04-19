/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.09-printf1.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 1.09
                     Qu'affiche les lignes suivantes ..

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 127;
    double x = 12.3456;

    printf("R1 : |%-4d|\n", n);
    printf("R2 : |%04d|\n", n);
    printf("R3 : |%x|\n", n);
    printf("R4 : |%#o|\n", n);
    printf("R5 : |%f|\n", x);
    printf("R6 : |%5.2f|\n", x);
    printf("R7 : |%.2e|\n", x);
    printf("R8 : |%g|\n", x);

    return EXIT_SUCCESS;
}
