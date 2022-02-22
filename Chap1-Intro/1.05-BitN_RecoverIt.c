// Exo 1.5 : Donnee ;
//                  Sans if et en utilisant seulement operateurs de manip. de bits,
//                  implementez la fn dont le prototype et la semantique
//                  sont definis comme suit :
//                                  unsigned short getBit(unsigned short pos, int n);
//                  Semantique :
//                                  Retourne la valeur du bit en position << pos >>
//                                  dans la representation binaire du nbr << n >>.
//                      Indication : La pos '0' est la position du bit de poid faible.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // After seeing Teacher's correction :

/*
unsigned short getBit(unsigned short pos, int n) {
	return (n & (1 << pos)) >> pos;
}
 */
// After seeing Teacher's correction :
#define INT_BIT_SIZE sizeof(int) * 8
unsigned short getBit(unsigned short pos, int n) {
	assert(pos < INT_BIT_SIZE);
	return n >> pos & 1;
}

int main(void) {
	const int ENTIER_A_ANALYSER = 5;

	printf("%d => 0b", ENTIER_A_ANALYSER);
	for(unsigned short i = INT_BIT_SIZE-1; i >= 0; --i) {	// NOLINT
		printf("%d", getBit(i, ENTIER_A_ANALYSER));

		if( (i != 0) && ((i % 4) == 0) )
			printf(" ");

		if(i == 0)
			break;
	}
	return EXIT_SUCCESS;
}

/*
 * First attempt of display :
 * for(unsigned short i = 0; i < INT_BIT_SIZE; ++i) {	// NOLINT
		printf("getBit(%2d,5)=%d", i+1, getBit(i, ENTIER_A_ANALYSER));
      if(i != INT_BIT_SIZE)
			printf("; ");
		if( (i != 0) && (((i+1) % 4) == 0) )
			printf("\n");
	}
 */
