/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.08-PtrArith_2.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.08
                     Que va afficher le main ci-dessous ?

 Remarque(s)    : Memory view
                  (or simply look into Corr-2.06_to_2.09_2.12_2.14.pdf)
                      -1    0     1     2     3     4     5
                    .---. .---. .---. .---. .---. .---. .---.
                    |   | |   | |   | |   | |   | |   | |   |
                    '---' '---' '---' '---' '---' '---' '---'
                            ^                             ^
                          .-|-.                         .-|-.
                          | ° |                         | ° |
                          '---'                         '---'
                            t                             p

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int t[6], i, * p;

    for (p = &t[5]; p > &t[-1]; p--)    // Filling BACKWARD << t >>
        *p = (int) (p - t);

    for (i = 0; i < 6; i++)             // Print the content ONWARD of << t >>
        printf("%d ", t[i]);
    printf("\n");

    for (i = 0, ++p; i < 6; i++)        // Print the integer part of each pointed value
        printf("%d ", *p++ / 2);        // divided by 2 of << p >>
    printf("\n");                       // Detail(s) : We went to p > &t[-1], so to
                                        // start over from &t[0], p need an increase
                                        // before starting the loop => ++p; .

    return EXIT_SUCCESS;
}

// Output :
//0 1 2 3 4 5
//0 0 1 1 2 2
