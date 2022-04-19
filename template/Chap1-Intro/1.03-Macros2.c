/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.03-Macros2.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 1.03
                     1) Que va afficher le programme suivant
                     2) Expliquez en quoi le programme est problematique ?
                     3) Est-il possible de recrire (sans utiliser la
                        fonction abs de stdlib) la macro ABS de maniere
                        a eviter les problemes du pt2 ?

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define ABS(X) (((X) > 0) ? (X) : (-X))

int main(void) {
    int n;

    printf("1. %d\n", ABS(2));
    printf("2. %d\n", ABS(-2));
    printf("3. %d\n", ABS('A'));

    n = -2;
    printf("4. %d\n", ABS(n + 1));

    n = -2;
    printf("5. %d", ABS(n++));      printf(" %d\n", n);

    n = -2;
    printf("6. %d", ABS(++n));      printf(" %d\n", n);

    n = -2;
    printf("7. %d", abs(++n));      printf(" %d\n", n);

    return EXIT_SUCCESS;
}
