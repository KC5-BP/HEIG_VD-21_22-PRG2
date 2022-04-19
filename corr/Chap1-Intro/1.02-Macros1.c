/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.02-Macros1.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 1.02
                     Corriger la OU les erreurs dans ce qui suit pour qu'a
                     l'execution, le programme affiche : 25 -1

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define A 2
#define B (A + 1)
#define PLUS(X, Y) ( (X)+(Y) )
#define MOINS(X, Y) ( (X)-(Y) )

int main() {
    printf("%d %d\n", 5 * PLUS(A, B), MOINS(A + 1, B + 1));
    return EXIT_SUCCESS;
}

// Output :
// 25 -1
