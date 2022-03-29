// Exo 1.9 : Donnee ;
//                  Qu'affiche les lignes suivantes :
/*
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
