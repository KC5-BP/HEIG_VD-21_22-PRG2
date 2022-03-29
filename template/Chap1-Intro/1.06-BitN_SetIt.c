/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.06-BitN_SetIt.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 1.06
                     Sans if et en utilisant seulement operateurs de manip. de bits,
                     implementez la fn dont le prototype et la semantique sont
                     definis comme suit :
int* setBit(unsigned short pos, unsigned short bitValue, int* n);

                     Semantique :
                        Fixe la valeur du bit en position << pos >> dans la
                        representation binaire du nbr << n >>.

                     Indication :
                        La pos '0' est la position du bit de poid faible.

                     Exemples :
                        getBit(0, 5) = 1; getBit(1, 5) = 0; getBit(2, 5) = 1

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>

int* setBit(unsigned short pos, unsigned short bitValue, int* n);

int main(void) {
	int n = 0;

	setBit(2, 1, &n);   printf("%d\n", n);
	setBit(8, 1, &n);   printf("%d\n", n);
	setBit(0, 1, &n);   printf("%d\n", n);
	// OR just :
	printf("%d\n", *setBit(8, 0, &n));

	return EXIT_SUCCESS;
}

int* setBit(unsigned short pos, unsigned short bitValue, int* n) {
   return n;
}
