/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.01-Substitutions.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : Exo 1.1
                     Indiquer ce que va afficher le code suivant

 Remarque(s)    :   F will concatenate the X symbol with the Y's, to create
                    the symbol XY.
                    F being a macro, it will then be replaced by the symbol XY.
                    So if the symbol YX doesn't exist, there will be an error.

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define A 1
#define B 2
#define AB 3
#define F(X, Y) X##Y

int main() {
    int n = AB;

    //printf("%<?>\n", n);
    printf("%d\n", n);

    //printf("%<?>\n", "AB");
    printf("%s\n", "AB");

    //printf("%<?>\n", F(A,B));
    printf("%d\n", F(A, B));

    return EXIT_SUCCESS;
}

// Output :
//3     :   Because N = AB = 3.
//AB    :   Because literally a string.
//3     :   Because F() will create the symbol AB
//          AB is a #define set as 3.
