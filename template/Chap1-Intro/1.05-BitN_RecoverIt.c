/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.05-BitN_RecoverIt.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 1.05
                     Sans if et en utilisant seulement operateurs de manip. de bits,
                     implementez la fn dont le prototype et la semantique sont
                     definis comme suit :
unsigned short getBit(unsigned short pos, int n);

                     Semantique :
                        Retourne la valeur du bit en position << pos >> dans la
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

unsigned short getBit(unsigned short pos, int n);

int main(void) {

    return EXIT_SUCCESS;
}

unsigned short getBit(unsigned short pos, int n) {
    return 1;
}
