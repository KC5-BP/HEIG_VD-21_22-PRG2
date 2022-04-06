/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.21-MatrixInit.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.21
                     Ecrire une fonction C sans valeur de retour (void) qui
                     initialise une matrice m x n de int avec des 1 sur les 4
                     "bords" et des 0 partout ailleurs.
                     Ecrire aussi un petit programme de test permettant de
                     vérifier le bon fonctionnement de votre fonction.

                               / 1 1 1 \
                     M(3x3) = |  1 0 1  |
                               \ 1 1 1 /

                               / 1 1 1 1 \
                              |  1 0 0 1  |
                     M(4x4) = |  1 0 0 1  |
                               \ 1 1 1 1 /

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void initialiser_1(int* adr, size_t m, size_t n);
void initialiser_2(int* adr, size_t m, size_t n);
void initialiser_3(int* adr, size_t m, size_t n);

void afficher(const int* adr, size_t m, size_t n);

int main(void) {
	// <code>
	return EXIT_SUCCESS;
}

void initialiser_1(int* adr, size_t m, size_t n) {
   assert(adr != NULL);
   assert(m > 0);
   assert(n > 0);
   for (size_t i = 0; i < m; ++i)
      for (size_t j = 0; j < n; ++j)
         *adr++ = i == 0 || i == m - 1 || j == 0 || j == n - 1;
         // OR *(adr + i * n + j) = i == 0 || i == m - 1 || j == 0 || j == n - 1;
         // OR adr[i * n + j] = i == 0 || i == m - 1 || j == 0 || j == n - 1;
}

void initialiser_2(int* adr, size_t m, size_t n) {
   assert(adr != NULL);
   assert(m > 0);
   assert(n > 0);
   // First : Init all to 0
   memset(adr, 0, m * n * sizeof(int));
   // Then  : Set UPPER and LOWER Lines to 1
   for (size_t j = 0; j < n; ++j)
      adr[j] = adr[n * (m - 1) + j] = 1;
   // Finally : Set OUTER Columns to 1
   for (size_t i = 1; i < n - 1; ++i)
      adr[n * i] = adr[n * i + n - 1] = 1;
}

void initialiser_3(int* adr, size_t m, size_t n) {
   assert(adr != NULL);
   assert(m > 0);
   assert(n > 0);
   int** ad = (int**) calloc(m, sizeof(int*));
   assert(adr != NULL);
   for (size_t i = 0; i < n; ++i)
      ad[i] = &adr[i * n]; // OR adr + i * n, because reminder :
                           // *(adr + i * n) = adr[i * n]
                           // => &adr[i * n] = adr + i * n
   // First : Init all to 0
   memset(adr, 0, m * n * sizeof(int));
   // Then  : Set UPPER and LOWER Lines to 1
   for (size_t j = 0; j < n; ++j)
      ad[0][j] = ad[m - 1][j] = 1;
   // Finally : Set OUTER Columns to 1
   for (size_t i = 1; i < n - 1; ++i)
      ad[i][0] = ad[i][n - 1] = 1;
   free(ad);
}

void afficher(const int* adr, size_t m, size_t n) {
   assert(adr != NULL);
   printf("[");
   for (size_t i = 0; i < m * n; ++i) {
      if (i > 0)
         printf("%s", ", ");
      printf("%d", adr[i]);
   }
   printf("]\n");
}
