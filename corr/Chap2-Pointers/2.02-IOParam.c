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

#include <stdio.h>
#include <stdlib.h>

void recoverSquareCube_Array(double x, double Res[]) {
   Res[0] = x * x;
   Res[1] = Res[0] * x;
}

struct SQUARE_CUBE {
   double square;
   double cube;
} x_Res;
void recoverSquareCube_Struct(double x, struct SQUARE_CUBE* Res) {
   Res->square = x * x;
   Res->cube = Res->square * x;
}

int main() {
   // Var. dec. : ----------------------------------------------------------------->
   double x = 2;
   double Res[2];

   // Code : ---------------------------------------------------------------------->
   recoverSquareCube_Array(x, &Res[0]);
   printf("Though ARRAY :\n");
   printf("x = %.2f | Square is %.2f | Cube is %.2f :\n", x, Res[0], Res[1]);

   x = 5;
   recoverSquareCube_Struct(x, &x_Res);
   printf("Though STRUCT :\n");
   printf("x = %.2f | Square is %.2f | Cube is %.2f :\n", x, x_Res.square, x_Res.cube);

   return EXIT_SUCCESS;
}
