/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.11-FormaPtrAndArray1D.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.11
                     Ecrire d'au moins 6 manières différentes, mais toujours en
                     utilisant le formalisme pointeur, une fonction C initialiser,
                     sans valeur de retour (void), permettant d'initialiser à une
                     valeur donnée (de type int), tous les éléments d'un tableau à
                     1 dimension (1D) de taille quelconque et composé d'entiers
                     (de type int).

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 10

void initialiser(int* tab, unsigned int tabSize, int initValue) {
   /* ... */
}

void printArray(int* tab, unsigned int tabSize) {
   for (unsigned int i = 0; i < tabSize; ++i) {
      if ( i )  printf(", ");
      printf("%d", tab[i]);
   }
}

int main(void) {
   //int tab[TAB_SIZE];    // Don't work with memset without : = {};
   int tab[TAB_SIZE] = {};

   initialiser(tab, TAB_SIZE, 0);
   printArray(tab, TAB_SIZE);

   return EXIT_SUCCESS;
}
