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

// Output :
//R1 : |127 |
//R2 : |0127|
//R3 : |7f|
//R4 : |0177|
//R5 : |12.345600|
//R6 : |12.35|
//R7 : |1.23e+01|
//R8 : |12.3456|
