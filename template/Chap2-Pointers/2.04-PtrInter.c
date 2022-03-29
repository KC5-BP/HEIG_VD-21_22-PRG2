/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.04-PtrInter.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.04
                     Traduire en Francais les declarations C suivantes

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * 1) Parenthesis / Parentheses
 * 2) Pointer     / Pointeurs
 * 3) Array       / Tableau
 * 4) Function    / Fonction
 */
int main(void) {
   char** a[10];
   double* (*b)(void);
   double (*c)(double*);
   int* d[10];
   int (*e)[10];
   int (*(*f[5])(void))[10];
   double (**g)[5];

	return EXIT_SUCCESS;
}
