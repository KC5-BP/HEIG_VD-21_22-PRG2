/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.16-InvertArray1D.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.16
                     Implementer la fonction C dont le prototype et la semantique
                     sont donnes ci-suivi :
int* inverser(const int* debut, const int* fin);

                     Semantique :
                        Renvoie le contenu du tableau 1D défini par début et fin
                        où début, resp. fin, désigne l'adresse du premier, resp.
                        du dernier, élément du tableau à inverser.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* inverser(const int* debut, const int* fin);
void afficher(const int tab[], size_t taille);

int main(void) {
	// <code>
	return EXIT_SUCCESS;
}

int* inverser(const int* debut, const int* fin) {
   assert(debut != fin);

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
