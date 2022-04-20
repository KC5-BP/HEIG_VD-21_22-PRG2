/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.18-MemManip_1.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.18
                     Ecrire un programme C qui :
                        1) Déclare et initialise un tableau tab1 à une dimension
                           de int
                        2) Copie (sans utiliser de boucle) le contenu de tab1 dans
                           un autre tableau tab2
                        3) Affiche tab1 et tab2
                        4) Se termine

                     Nota Bene :
                        Prévoir une fonction dédiée à l'affichage d'un tableau
                        sous la forme [valeur1, valeur2,...].
                        Ecrire cette fonction en utilisant exclusivement le
                        formalisme pointeur.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afficher(const int* adr, size_t n);

int main(void) {
    int tab1[] = {1, 2, 3};
    const size_t SIZE = sizeof(tab1) / sizeof(int);

    afficher(tab1, SIZE);
    int* tab2 = (int*) calloc(SIZE, sizeof(int));
    if (tab2) {
        memcpy(tab2, tab1, sizeof(tab1));
        afficher(tab2, SIZE);
        free(tab2);
    }
    
    return EXIT_SUCCESS;
}

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

// Output :
//[1, 2, 3]
//[1, 2, 3]
