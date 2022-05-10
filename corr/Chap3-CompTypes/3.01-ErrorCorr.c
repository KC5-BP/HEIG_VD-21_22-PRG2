/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 3.01-ErrorCorr.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 3.01
                     Réécrire complètement le code ci-dessous de telle sorte à
                     corriger tous les maladresses et erreurs qu’il contient.
                     Une fois dûment corrigé le programme devrait afficher à
                     l’exécution :
                        a = 1, b = "ABC"

                     Nota Bene :
                        Aucune ligne de code ne doit être ajoutée ou supprimée.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define VARIANTE 1

#if VARIANTE == 1
struct S {
    int a;
    char b[4];
};

void afficher(const struct S* s);

int main(void) {
    struct S s = {.a = 1, .b = "ABC"};
    afficher(&s);

    return EXIT_SUCCESS;
}

void afficher(const struct S* s) {
    printf("a = %d, b = \"%s\"\n", s->a, s->b);
}

#elif VARIANTE == 2
typedef struct {
    int a;
    char b[4];
} S;

void afficher(const S* s);

int main(void) {
    S s = { 1, "ABC"};
    afficher(&s);

    return EXIT_SUCCESS;
}

void afficher(const S* s) {
    printf("a = %d, b = \"%s\"\n", s->a, s->b);
}

#endif
