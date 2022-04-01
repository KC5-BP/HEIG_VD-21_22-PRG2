/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.14-TabPtrFn.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.14
                     Que va afficher le code suivant ?

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

void f(int* p1, int p2);

int main(void) {
   int a = 5, b = 6;
   int t[2] = {3, 4};
   int *p = NULL, *q = NULL;

   f(&a, b);
   printf("1) %d, %d\n", a, b);

   p = &a;
   q = &b;
   f(q, *p);
   printf("2) %d, %d\n", *p, *q);

   f(t + 1, *t);
   printf("3) %d, %d\n", t[0], t[1]);

   f((int*)(&p), b);
   printf("4) %d, %d\n", a, b);

   return EXIT_SUCCESS;
}

void f(int* p1, int p2) {
   *p1 = 2 * p2;
}
// Outputs
//1) 12, 6
//2) 12, 24
//3) 3, 6
//4) 12, 24
