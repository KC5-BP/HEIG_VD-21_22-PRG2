/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.23-SquareMatrixDiag.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.23
                     Ecrire une fonction C qui prend en paramètre une matrice n x
                     n de int et qui renvoie en valeur de retour le vecteur
                     correspondant aux éléments de la diagonale gauche de ladite
                     matrice.

                     Exemple :
                                / 1 2 3 \
                        Si M = |  4 5 6  |,
                                \ 7 8 9 /
                                                                / 1 \
                        la fonction doit renvoyer le vecteur = |  5  |
                                                                \ 9 /

                    Ecrire aussi un petit programme de test permettant de
                    vérifier le bon fonctionnement de votre fonction.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int* diagonale_1(const int* adr, size_t n);
int* diagonale_2(const int* adr, size_t n);

void afficher(const int* adr, size_t taille);

void test(int* (*f)(const int*, size_t), const int* adr, size_t n);

int main(void) {
   #define TAILLE 3

   const int M[TAILLE][TAILLE] = {  {1,2,3},
                                    {4,5,6},
                                    {7,8,9}  };

   test(diagonale_1, (int*) M, TAILLE);
   test(diagonale_2, (int*) M, TAILLE);

   #undef TAILLE
	return EXIT_SUCCESS;
}

int* diagonale_1(const int* adr, size_t n) {
   assert(adr != NULL);
   int* vecteur = (int*) calloc(n, sizeof(int));
   if (vecteur)
      for (size_t i = 0; i < n; ++i)
         vecteur[i] = adr[i * (n+1)];  // On ne garde que les termes i = j
   return vecteur;
}

int* diagonale_2(const int* adr, size_t n) {
   assert(adr != NULL);
   int* vecteur = (int*) calloc(n, sizeof(int));
   if (vecteur) {
      const int* const FIN = adr + n * n;
      for (size_t i = 0; adr < FIN; adr += n + 1, ++i)
         vecteur[i] = *adr;
   }
   return vecteur;
}

void afficher(const int* adr, size_t taille) {
   printf("[");
   if (adr)
      for (size_t i = 0; i < taille; ++i) {
         if (i > 0)
            printf("%s", ", ");
         printf("%d", adr[i]);   // ou *(adr + i)
      }
   printf("]\n");
}

void test(int* (*f)(const int*, size_t), const int* adr, size_t n) {
   assert(f != NULL);
   int* vecteur = f(adr, n);
   printf("Diagonale = ");
   afficher(vecteur, n);
   free(vecteur);
}
// Outputs
//Diagonale = [1, 5, 9]
//Diagonale = [1, 5, 9]
