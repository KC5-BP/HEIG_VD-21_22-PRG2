/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.01-Substitutions.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : Exo 1.1
                     Indiquer ce que va afficher le code suivant

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define A 1
#define B 2
#define AB 3
#define F(X, Y) X##Y

int main(void) {
    int n = AB;

    ///printf("%<?>\n", n);

    ///printf("%<?>\n", "AB");

    ///printf("%<?>\n", F(A, B));

    return EXIT_SUCCESS;
}
