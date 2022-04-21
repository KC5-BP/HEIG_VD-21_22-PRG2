/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.13-Meli_Melo.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.13
                     Que va afficher le code suivant (

                     Remarque : Suppose que la machine est d'une architecture 32bits

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int i = 1, j = 2;
   int *p = &i, *q = &j;

   *p = (int) q;
   *q = (int) p;
   p = (int*) *p;
   q = (int*) *q;

   i = 3, j = 4;
   printf("*p = %d *q = %d\n", *p, *q);

   return EXIT_SUCCESS;
}

// Output :
//Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)
//Caused while printing ...
