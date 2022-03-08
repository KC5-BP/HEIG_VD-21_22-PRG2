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
   while (n >> pos & 1)
      ++pos;
   return pos;
}

int main(void) {
   int n = 5;
   printf("First bit set is at : %d\n", lowestOrderSetBit(n));
	return EXIT_SUCCESS;
}
