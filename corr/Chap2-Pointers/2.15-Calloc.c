/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.15-Calloc.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.15
                     Ecrire une fonction C << initialiser >> permettant
                        1) De créer un tableau (à 1 dimension) de taille donnée,
                           composé d'entiers (de type int)
                        2) D'initialiser à une valeur donnée (de type int) tous
                        les éléments de ce tableau.

                     IMPORTANT :
                        La fonction ne doit comporter que 2 paramètres :
                           -  PREMIER fixant la taille (le nombre d'éléments)
                              du tableau à créer.
                           -  SECOND fixant la valeur à donner à tous les éléments
                              du tableau
                        Et n'utiliser que les services de la fonction calloc

                     Ecrire aussi un petit programme de test permettant de
                     vérifier le bon fonctionnement de votre fonction.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int* initialiser_1(size_t taille, int valeur);
int* initialiser_2(size_t taille, int valeur);
void afficher(const int* ptr, size_t taille);

int main(void) {
    {
        const size_t TAILLE = 3;
        int* p = initialiser_1(TAILLE, 1);
        afficher(p, TAILLE); // Affiche [1, 1, 1]
        free(p);
    }
    {
        const size_t TAILLE = 5;
        int* p = initialiser_2(TAILLE, 2);
        afficher(p, TAILLE); // Affiche [2, 2, 2, 2, 2]
        free(p);
    }
    return EXIT_SUCCESS;
}

int* initialiser_1(size_t taille, int valeur) {
    assert(taille > 0);
    int* p = (int*) calloc(taille, sizeof(int));
    if (p)
        for (int* tmp = p; tmp < p + taille; *tmp++ = valeur);
    return p;
}

int* initialiser_2(size_t taille, int valeur) {
    assert(taille > 0);
    int* p = (int*) calloc(taille, sizeof(int));
    if (p) {
        const int* const FIN = p + taille;
        for (; p < FIN; *p++ = valeur);
        p -= taille;
    }
    return p;
}

void afficher(const int* ptr, size_t taille) {
    assert(ptr != NULL);
    printf("[");
    for (size_t i = 0; i < taille; ++i) {
        if (i > 0)
            printf("%s", ", ");
        printf("%d", ptr[i]); // ou *(ptr + i)
    }
    printf("]\n");
}

// Output :
//[1, 1, 1]
//[2, 2, 2, 2, 2]
