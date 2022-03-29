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

	printf("R1 : |%-4d|\n", n);   // |127 |
	printf("R2 : |%04d|\n", n);   // |0127|
	printf("R3 : |%x|\n", n);     // |7f|
	printf("R4 : |%#o|\n", n);    // |0177|
	printf("R5 : |%f|\n", x);     // |12.345600|
	printf("R6 : |%5.2f|\n", x);  // |12.35|
	printf("R7 : |%.2e|\n", x);   // |1.23e+01|
	printf("R8 : |%g|\n", x);     // |12.3456|

	return EXIT_SUCCESS;
}
