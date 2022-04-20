/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.09-PtrArith_3.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.09
                     Soit les declarations suivantes :
                        a) c[3][0]
                        b) (**d)[5]
                        c) (**e)[*d-c]
                        d) (d[3] - 3)[0][3]
                        e) **d + 5
                        f) *d[3] + 2
                        g) *(*e[-3] + 5)
                        h) **c
                        i) e[0][0][e-d] + 1
                        j) 0[c][0] - 'd' + 'B'
                     Selon les declarations du code ..

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char* c[] = {"elle", "mangera", "une", "petite", "tomme"};
    const char** d[] = {c + 1, c + 2, c + 3, c + 4, c};
    const char*** e = &d[3];

    printf("a) %\n", c[3][0]);

    printf("b) %\n", (**d)[5]);

    printf("c) %\n", (**e)[*d - c]);

    printf("d) %\n", (d[3] - 3)[0][3]);

    printf("e) %\n", **d + 5);

    printf("f) %\n", *d[3] + 2);

    printf("g) %\n", *(*e[-3] + 5));

    printf("h) %\n", **c);

    printf("i) %\n", e[0][0][e - d] + 1);

    printf("j) %\n", 0[c][0] - 'd' + 'B');

    return EXIT_SUCCESS;
}
