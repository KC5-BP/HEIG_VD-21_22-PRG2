/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.19-MemManip_2.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.19
                     Sans utiliser de boucle, compléter la partie notée
                     <à compléter> dans le programme C ci- dessous de telle sorte
                     que celui-ci affiche à l'exécution :
                        [0, 0, 0]
                        [1, 1, 1]
                        [2, 2, 2]

 Remarque(s)    : "afficher" function from 2.18 to check the output

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define SIZE 3

void afficher(const int* adr, size_t n) {
    assert(adr != NULL);
    printf("[");
    for (size_t i = 0; i < n; ++i) {
        if (i > 0)
            printf(", ");
        printf("%d", *(adr + i));
    }
    printf("]\n");
}

int main(void) {
    int tab[SIZE] = {0};

    afficher(tab, SIZE);

    for (size_t i = 0; i < SIZE; ++i)
        tab[i]++;

    afficher(tab, SIZE);

    memset(tab, 0, SIZE * sizeof(int));
    // OR memset(tab, 0, sizeof(tab));

    for (size_t i = 0; i < SIZE; ++i)
        tab[i] += 2;

    afficher(tab, SIZE);

    return EXIT_SUCCESS;
}

// Output :
//[0, 0, 0]
//[1, 1, 1]
//[2, 2, 2]
