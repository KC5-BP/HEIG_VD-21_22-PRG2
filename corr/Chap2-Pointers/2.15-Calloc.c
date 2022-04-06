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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int* initialiser(size_t nbr_elements, int initValue);
void afficher(const int* tab, size_t taille);

int main(void) {
	size_t SIZE = 10;
   int INIT_VALUE = 5;

   int* p = initialiser(SIZE, INIT_VALUE);
   afficher(p, SIZE);
   free(p);
	return EXIT_SUCCESS;
}

int* initialiser(size_t nbr_elements, int initValue) {
   assert(nbr_elements > 0);
   int* p = (int*) calloc(nbr_elements, sizeof(int));
   if (p)
      for (int* tmp = p; tmp < p + nbr_elements; *tmp++ = initValue);
   return p;
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
