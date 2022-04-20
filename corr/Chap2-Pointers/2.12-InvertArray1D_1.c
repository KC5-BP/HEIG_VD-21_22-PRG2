/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.12-InvertArray1D.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.12
                     Implementer la fonction C dont le prototype et la semantique
                     sont donnes ci-suivi :
void inverser(int* debut, int* fin);

                     Semantique :
                        Inverse le contenu du tableau 1D défini par début et fin
                        où début, resp. fin, désigne l'adresse du premier, resp.
                        du dernier, élément du tableau à inverser.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void inverser(int* debut, int* fin);
void afficher(const int tab[], size_t taille);
void test(int tab[], size_t taille);

int main(void) {
    {
        int tab[] = {1};
        test(tab, sizeof(tab) / sizeof(int));
    }
    {
        int tab[] = {1, 2};
        test(tab, sizeof(tab) / sizeof(int));
    }
    {
        test((int[]) {1, 2, 3}, 3); // Autre manière de procéder
    }
    return EXIT_SUCCESS;
}

void inverser(int* debut, int* fin) {
    assert(debut != NULL);
    assert(fin != NULL);
    while (debut < fin) {
        int tampon = *debut;
        *debut++ = *fin;
        *fin-- = tampon;
    }
}

void afficher(const int tab[], size_t taille) {
    assert(tab != NULL);
    printf("[");
    for (size_t i = 0; i < taille; ++i) {
        if (i > 0)
            printf("%s", ", ");
        printf("%d", tab[i]);
    }
    printf("]\n");
}

void test(int tab[], size_t taille) {
    printf("Avant inverser : \n");
    afficher(tab, taille);
    inverser(tab, tab + taille - 1);
    printf("Apres inverser : \n");
    afficher(tab, taille);
}

// Output :
//Avant inverser :
//[1]
//Apres inverser :
//[1]
//Avant inverser :
//[1, 2]
//Apres inverser :
//[2, 1]
//Avant inverser :
//[1, 2, 3]
//Apres inverser :
//[3, 2, 1]
