/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.22-SumMatrixValues.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.22
                     Ecrire une fonction C qui renvoie la somme des coefficients
                     de la matrice m x n de double passée en paramètre.

                     Ecrire aussi un petit programme de test permettant de
                     vérifier le bon fonctionnement de votre fonction sur la
                     matrice 3 x 4 suivante :
                          / 1 2 3 \
                     M = |  4 5 6  |
                          \ 7 8 9 /

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   #define NB_LIGNES 3
   #define NB_COLONNES 3

   const double M[NB_LIGNES][NB_COLONNES] = {   { 1, 2, 3},
                                                { 4, 5, 6},
                                                { 7, 8, 9}  };

   // CODE HERE

	return EXIT_SUCCESS;
}
