/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.07-PtrArith_1.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.07
                     Que va afficher le main ci-dessous ?

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <inttypes.h>
#include <stddef.h> // pour ptrdiff_t
#include <stdlib.h>
#include <stdio.h>

int main(void) {
   int a[] = {10, 20, 30, 40, 50};
   int* p[] = {a, a+1, a+2, a+3, a+4};
   int** pp = &p[2];
   int*** ppp = &pp;

   printf("1) %d\n", *a);     // 1) 10
   printf("2) %d\n", **p);    // 2) 10
   printf("3) %d\n", **pp++); // 3) 30
                              // But now, pp point on &p[3]
   printf("4) %d\n", ***ppp); // 4) 40
   pp = p;
   printf("5) %d\n", **++pp); // 5) 20
                              // pp => &p[0]
                              // ++pp => &p[1]
                              // *++pp => a + 1
                              // **++pp => 20
   pp = p;
   printf("6) %d\n", ++**pp); // 6) 11
                              // pp => &p[0]
                              // *pp => a
                              // **pp => 10
                              // ++**pp => 11
   pp = p;
   printf("7) %d\n", *pp[1]); // 7) 20
                              // pp => &p[0]
                              // pp[1] => a + 1
                              // *pp[1] => 20
   pp = p;
   printf("8) %" PRIdPTR "\n", (ptrdiff_t) (*(p+1) - *pp)); // 8) 1
                                                            // *(p+1) <=> p[1]
                                                            //             => a + 1
                                                            //
                                                            // pp => &p[0]
                                                            // *pp => a
                                                            // a + 1 - a = 1

   return EXIT_SUCCESS;
}
