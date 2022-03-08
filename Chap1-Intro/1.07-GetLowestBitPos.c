// Exo 1.7 : Donnee ;
//                  Sans if et en utilisant seulement operateurs de manip. de bits,
//                  implementez la fn dont le prototype et la semantique
//                  sont definis comme suit :
//                                  short lowestOrderSetBit(int n);
//                  Semantique :
//                                  Retourne la position du bit a 1 le plus faible.
//                                  Retourne -1 si aucun bit n'est trouve.
//                      Indication : La pos '0' est la position du bit de poid faible.

#include <stdio.h>
#include <stdlib.h>

short lowestOrderSetBit(int n) {
   if (n == 0) return (-1);
   short pos = 0;
   while ( !(n >> pos & 1) )  ++pos;
   return pos;
}

int main(void) {
   int array[] = {0, 1, 2, 4, 8, 16, 32, 64, 5, 48};
   for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
      printf("First bit set of %2d is at : %d\n", \
                                    array[i], lowestOrderSetBit(array[i]));
	return EXIT_SUCCESS;
}
