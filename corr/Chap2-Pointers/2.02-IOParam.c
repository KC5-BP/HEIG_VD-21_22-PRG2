/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.02-IOParam.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : Ecrire une fonction C sans valeur de retour (void) qui prend comme
                  parametre entree un pointeur sur un nombre reel x (double) et
                  qui renvoie, par parametre d'entree-sortie, le carre et le cube
                  de x.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <float.h>
#include <stdio.h>
#include <stdlib.h>

void carre_et_cube(double x, double* carre, double* cube);
void test(double x);

int main(void) {
   test(-1);
   test(0);
   test(1);
   test(2);
   test(2.5);
   test(DBL_MAX);

   return EXIT_SUCCESS;
}

void carre_et_cube(double x, double* carre, double* cube) {
   *carre = x * x;
   *cube = *carre * x;
}

void test(double x) {
   double carre, cube;
   carre_et_cube(x, &carre, &cube);
   printf("carre(%g) = %g, cube(%g) = %g\n", x, carre, x, cube);
}
// carre(-1) = 1, cube(-1) = -1
// carre(0) = 0, cube(0) = 0
// carre(1) = 1, cube(1) = 1
// carre(2) = 4, cube(2) = 8
// carre(2.5) = 6.25, cube(2.5) = 15.625
// carre(1.79769e+308) = inf, cube(1.79769e+308) = inf
