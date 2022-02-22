// Exo 1.6 : Donnee ;
//                  Sans if et en utilisant seulement operateurs de manip. de bits,
//                  implementez la fn dont le prototype et la semantique
//                  sont definis comme suit :
//                                  int* setBit(unsigned short pos, unsigned short bitValue, int n);
//                  Semantique :
//                                  Fixe la valeur du bit en position << pos >>
//                                  dans la representation binaire du nbr << n >>.
//                      Indication : La pos '0' est la position du bit de poid faible.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // After seeing Teacher's correction :

// After seeing Teacher's correction :
#define INT_BIT_SIZE sizeof(int) * 8

int* setBit(unsigned short pos, unsigned short bitValue, int* n) {
	assert(pos < INT_BIT_SIZE);
	assert(bitValue <= 1);

	*n ^= (-bitValue ^ *n) & (1 << pos);    // NOLINT
	return n;
}

int main(void) {
	int n = 0;

	setBit(2, 1, &n);   printf("%d\n", n);
	setBit(8, 1, &n);   printf("%d\n", n);
	setBit(0, 1, &n);   printf("%d\n", n);
	// OR just :
	printf("%d\n", *setBit(8, 0, &n));

	return EXIT_SUCCESS;
}
