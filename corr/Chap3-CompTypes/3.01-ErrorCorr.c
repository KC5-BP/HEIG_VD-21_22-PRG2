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

struct S {
   int a;
   char b[3];
};

void afficher(struct S* s);

int main(void) {
   struct S s = {.a = 1, .b = "ABC"};
   afficher(&s);

   return EXIT_SUCCESS;
}

void afficher(struct S* s) {
   printf("a = %d, b = %s\n", s->a, s->b);
}
