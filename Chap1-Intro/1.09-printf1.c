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