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

 Remarque(s)    : Results of i & j should be in integer because of the numerical
                  promotion while operating with

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char* c[] = {"elle", "mangera", "une", "petite", "tomme"};
    const char** d[] = {c + 1, c + 2, c + 3, c + 4, c};
    const char*** e = &d[3];

    printf("a) %c\n", c[3][0]);
    printf("b) %c\n", (**d)[5]);
    printf("c) %c\n", (**e)[*d - c]);
                                        // *e => c + 4
                                        // **e => "tomme"
                                        //
                                        // *d => c+1
                                        // *d - c => 1
                                        // "tomme"[1] => 'o'
    printf("d) %c\n", (d[3] - 3)[0][3]);
                                        // (d[3]) - 3 => (c + 4) - 3 => c + 1
                                        //
                                        // [0] => "mangera"
                                        // [0][3] => 'g'
    printf("e) %s\n", **d + 5);
                                        // *d => c + 1
                                        // **d => "mangera"
                                        // **d + 5 => "ra"
    printf("f) %s\n", *d[3] + 2);
                                        // d[3] => c + 4
                                        // *d[3] => "tomme"
                                        // *d[3] + 2 => "mme"
    printf("g) %c\n", *(*e[-3] + 5));
                                        // e[-3] => d[0] => c + 1
                                        // *e[-3] => "mangera"
                                        // *e[-3] + 5 => "ra"
                                        // *(*e[-3] + 5) => 'r'
    printf("h) %c\n", **c);
                                        // *c => "elle"
                                        // **c => 'e'
    printf("i) %d (or %c as char)\n", e[0][0][e - d] + 1, e[0][0][e - d] + 1);
                                        // e[0] => d[3] => c + 4
                                        // e[0][0] => "tomme"
                                        //
                                        // [e-d] = 3
                                        // e[0][0][e-d] => 'm'
                                        // 'm' + 1 => valeur ASCII de 'n'
    printf("j) %d (or %c as char)\n\n", 0[c][0] - 'd' + 'B', 0[c][0] - 'd' + 'B');
                                        // 0[c][0] <=> c[0][0]
                                        // 0[c][0] => 'e'
                                        // 'e' - 'd' => 1
                                        // 1 + 'B' => valeur ASCII de 'C'

    printf("Message is : %c%c%c%c%s%s%c%c%c%c\n", c[3][0],
                                                   (**d)[5],
                                                   (**e)[*d - c],
                                                   (d[3] - 3)[0][3],
                                                   **d + 5,
                                                   *d[3] + 2,
                                                   *(*e[-3] + 5),
                                                   **c,
                                                   e[0][0][e - d] + 1,
                                                   0[c][0] - 'd' + 'B');
    return EXIT_SUCCESS;
}

// Ouput :
//a) p
//b) r
//c) o
//d) g
//e) ra
//f) mme
//g) r
//h) e
//i) 110 (or n as char)
//j) 67 (or C as char)
//
//Message is : programmerenC
