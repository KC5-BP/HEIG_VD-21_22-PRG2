/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.07-PtrArith_1.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.07
                     Que va afficher le main ci-dessous ?

 Remarque(s)    : Memory view
                  (or simply look into Corr-2.06_to_2.09_2.12_2.14.pdf)
                    .----. .----. .----. .----. .----.
                a : | 10 | | 20 | | 30 | | 40 | | 50 |
                    '----' '----' '----' '----' '----'
                       ^      ^      ^      ^      ^
                    .--|-. .--|-. .--|-. .--|-. .--|-.
                p : |  ° | |  ° | |  ° | |  ° | |  ° |
                    '----' '----' '----' '----' '----'
                                     ^
                    .----.        .--|-.
                    |  ° |  --->  |  ° |
                    '----'        '----'
                     ppp            pp


 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <inttypes.h>
#include <stddef.h> // pour ptrdiff_t
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int a[] = {10, 20, 30, 40, 50};
    int* p[] = {a, a + 1, a + 2, a + 3, a + 4};
    int** pp = &p[2];
    int*** ppp = &pp;

    printf("1) %d\n", *a);
    printf("2) %d\n", **p);
    printf("3) %d\n", **pp++);  // After that, pp point on &p[3]
    printf("4) %d\n", ***ppp);
    pp = p;
    printf("5) %d\n", **++pp);
                                // pp => &p[0]
                                // ++pp => &p[1]
                                // *++pp => a + 1
                                // **++pp => 20
    pp = p;
    printf("6) %d\n", ++**pp);
                                // pp => &p[0]
                                // *pp => a
                                // **pp => 10
                                // ++**pp => 11
    pp = p;
    printf("7) %d\n", *pp[1]);
                                // pp => &p[0]
                                // pp[1] => a + 1
                                // *pp[1] => 20
    pp = p;
    printf("8) %" PRIdPTR "\n", (ptrdiff_t) (*(p + 1) - *pp));
                                // *(p+1) <=> p[1] => a + 1
                                //
                                // pp => &p[0]
                                // *pp => a
                                //
                                // a + 1 - a = 1

    return EXIT_SUCCESS;
}

// Output :
//1) 10
//2) 10
//3) 30
//4) 40
//5) 20
//6) 11
//7) 20
//8) 1
