/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.07-GetLowestBitPos.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 1.07
                     Sans if et en utilisant seulement operateurs de manip. de bits,
                     implementez la fn dont le prototype et la semantique sont
                     definis comme suit :
short lowestOrderSetBit(int n);

                     Semantique :
                        Retourne la position du bit a 1 le plus faible.
                        Retourne -1 si aucun bit n'est trouve.

                     Indication :
                        La pos '0' est la position du bit de poid faible.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0 
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

short lowestOrderSetBit(int n);

int main(void) {
    int array[] = {0, 1, 2, 4, 8, 16, 32, 64, 5, 48};
    for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
        printf("First bit set of %2d is at : %d\n", \
                                    array[i], lowestOrderSetBit(array[i]));
    return EXIT_SUCCESS;
}

short lowestOrderSetBit(int n) {
    return (-1);
}
