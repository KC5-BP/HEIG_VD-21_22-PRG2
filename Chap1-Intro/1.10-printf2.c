// Exo 1.10 : Donnee ;
//                  Soit les valeurs :
//                      int n = 255;
//                      double x = 12.345;
//                  Completer le code pour afficher :
//                      0377
//                      FF
//                      +###255
//                      1.235e+001
//                      12.345
//                      12.3450

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n = 255;
	double d = 12.345;
	printf("%04o\n", n);	// OR printf("0%o\n", n);
	printf("%X\n", n);		// %x : lowercase | %X : UPPERCASE
	printf("+###%d\n", n);	//
	printf("%.4e\n", d);
	printf("%g\n", d); // OR printf("%2.3f\n", d);
	printf("%2.4f\n", d);
	return EXIT_SUCCESS;
}
