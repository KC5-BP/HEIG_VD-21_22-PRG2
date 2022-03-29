/*
 -----------------------------------------------------------------------------------
 Nom du fichier : <nom du fichier>.<x> (x = h ou c)
 Auteur(s)      : K. BOUGNON-PEIGNE
 Date creation  : <jj.mm.aaaa>

 Description    : <� compl�ter>

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * 1) Parenthesis
 * 2) Pointer
 * 3) Array
 * 4) Function
 */
int main(void) {
   char** a[10];              // Array of 10 pointer on char pointing on char
   double* (*b)(void);        // Pointer on function returning a pointer on double
                              // without argument.
   double (*c)(double*);
   int* d[10];
   int (*e)[10];
   int (*(*f[5])(void))[10];
   double (**g)[5];

	return EXIT_SUCCESS;
}
