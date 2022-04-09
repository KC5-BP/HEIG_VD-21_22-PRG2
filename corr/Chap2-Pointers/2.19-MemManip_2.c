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

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3

void afficher ... // Le code de la fonction afficher a volontairement été omis ici

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
