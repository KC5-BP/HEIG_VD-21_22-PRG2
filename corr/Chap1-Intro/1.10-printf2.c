/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.10-printf2.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 1.10
                     Soit le squelette de code donne ..

                     Completer pour obtenir en sorti de programme :
                        0377
                        FF
                        +###255
                        1.235e+001
                        12.345
                        12.3450

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 255;
    double d = 12.345;

    printf("%#o\n", n);
    printf("%X\n", n);      // %x : lowercase | %X : UPPERCASE
    printf("+###%d\n", n);  // OR printf("+%s%d", "%%%", n);
                            // OR printf("%s%d", "+%%%", n);
    printf("%.3e\n", d);
    printf("%g\n", d);      // OR printf("%.3f\n", d);
                            // %g set the best representation to the value.
    printf("%#g\n", d);     // OR printf("%.4f\n", d);

    return EXIT_SUCCESS;
}

// Output :
//0377
//FF
//+###255
//1.235e+01
//12.345
//12.3450
