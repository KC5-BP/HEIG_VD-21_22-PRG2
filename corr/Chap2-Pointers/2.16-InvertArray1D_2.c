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
void afficher(const int* tab, size_t taille);
void test(const int* tab, size_t taille);

int main(void) {
   {
      const int TAB[] = {1};
      test(TAB, sizeof(TAB) / sizeof(int));
   }
   {
      const int TAB[] = {1, 2};
      test(TAB, sizeof(TAB) / sizeof(int));
   }
   {
      const int TAB[] = {1, 2, 3};
      test(TAB, sizeof(TAB) / sizeof(int));
   }
   {
      const int TAB[] = {1, 2, 3};
      test(TAB, 0);
   }
	return EXIT_SUCCESS;
}

int* inverser(const int* debut, const int* fin) {
   assert(debut != NULL);
   assert(fin != NULL);
   assert(fin == debut - 1 || debut <= fin);
   const size_t TAILLE = (size_t) (fin - debut + 1);
   int* ptr = (int*) calloc(TAILLE, sizeof(int));
   if (ptr)
      for (size_t i = 0; i < TAILLE; ++i)
         ptr[TAILLE - 1 - i] = debut[i];  // OR ptr[i] = *fin--;
   return ptr;
}

void afficher(const int* tab, size_t taille) {
   assert(tab != NULL);
   printf("[");
   for (size_t i = 0; i < taille; ++i) {
      if (i > 0)
         printf("%s", ", ");
      printf("%d", tab[i]);
   }
   printf("]\n");
}

void test(const int* tab, size_t taille) {
   printf("Avant inversion :\n");
   afficher(tab, taille);
   int* ptr = inverser(tab, tab + taille - 1);
   printf("Apres inversion :\n");
   afficher(ptr, taille);
   printf("\n");
   free(ptr);
}
// Output :
//Avant inversion :
//[1]
//Apres inversion :
//[1]
//
//Avant inversion :
//[1, 2]
//Apres inversion :
//[2, 1]
//
//Avant inversion :
//[1, 2, 3]
//Apres inversion :
//[3, 2, 1]
//
//Avant inversion :
//[]
//Apres inversion :
//[]
