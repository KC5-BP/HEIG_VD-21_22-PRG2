/*
 -----------------------------------------------------------------------------------
 Nom du fichier : <nom du fichier>.<x> (x = h ou c)
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : <� compl�ter>

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>

// 1B)
uint16_t f(uint16_t i, uint8_t j) {
   for (uint8_t k = 0; k < j; ++k)
      i = (uint16_t) ((i >> 1) | (i & 0x0001 ? 0x8000 : 0));
   return i;
}

// 5)
void initialiser(char* matrice, size_t n, char surDiag, char horsDiag);
void afficher(const char* matrice, size_t n);

// 6)
void inverser(void* debut, void* fin, size_t size);

#define ENDL() printf("\n")

int main(void) {
   {
      printf("%s", "Exo 1a)\n");
      #define double(d) d+d
      int ni = 1;
      printf("%g\n", double((double)(ni+2) / 5));
      #undef double
      #define ABS(a) ((a < 0) ? (-a) : (a))
      int nii = 5;
      printf("%d\n", ABS(nii^nii));
      #undef ABS
      ENDL();
   }
   {
      printf("%s", "Exo 1b)\n");
      printf("%#x\n", f(0x1234, 5));
      ENDL();
   }
   {
      printf("%s", "Exo 1c)\n");
      int32_t t[][4] = {{1}, {}, {2,3}};
      printf("%p\n", (void*) t);
      #define PRINT_ADDRESS(ADR) printf("0x%" PRIxPTR "\n", (intptr_t) (ADR))
      PRINT_ADDRESS(t[1] - (*(t+2) - &t[2][1]));   // Must result in t + 0x14
      #undef PRINT_ADDRESS
      ENDL();
   }
   {
      printf("%s", "Exo 2)\n");
      printf("1) |%2d|\n", 173);       // |173|
      printf("2) |%-3X|\n", 173);      // |AD |
      printf("3) |%#.5o|\n", 173);     // |00255|

      printf("4) |%f|\n", 0.2468);     // |0.246800|
      printf("5) |%+4.1f|\n", 0.2468); // |+0.2|
      printf("6) |%.2e|\n", 0.2468);   // |2.47*e-01|
      printf("7) |%g|\n", 0.2468);     // |0.2468|

      printf("8) |%#G|\n", .5E5);      // |50000.0|
      printf("9) |%05.3g|\n", 12.345); // |012.3|

      // On suppose que l'utilisateur entre la chaine : "(012) 3456789 - SOS"
      #define TAILLE_MAX 50
      char chaine[TAILLE_MAX + 1] = "";
      printf("Entrer une chaine de caractere (%u caract max) > %s\n",
                                                TAILLE_MAX, "\" (012) 3456789 - "
                                                            "SOS\"");
      //scanf("%*[( )]%[0123456789]", chaine);
      sscanf(" (012) 3456789 - SOS", "%*[( )]%[0123456789]", chaine);
      printf("10) |%s|\n", chaine);
      #undef TAILLE_MAX
      ENDL();
   }
   {
      printf("%s", "Exo 3a)\n");
      int a[] = {1, 3, 5, 7, 9};
      int* b[] = {a, a+1, a+2, a+3, a+4};
      int** c = &b[3];

      printf("1) %d\n", **b+1);
      printf("2) %d\n", c[-1][-1]);
      printf("3) %d\n", --**c);
      printf("4) %d\n", ++**c++);
      printf("5) %d\n", *c + 1 - *(b + 1));
      ENDL();
   }
   {
      printf("%s", "Exo 3b)\n");
      const char* a[] = {"Federer", "Nadal", "Djokovic"};
      const char** b[] = {a, a+1, a+2};
      const char*** c = b+2;

      printf("1) %c\n", **a);
      printf("2) %c\n", *a[1]);
      printf("3) %s\n", *b[2]);
      printf("4) %d (char : %c)\n", *(*--*(b + 1) + 1) + 1, *(*--*(b + 1) + 1) + 1);
      printf("5) %c\n", *++c[-1][1]);
      ENDL();
   }
   {
/*
 * 1) Parenthesis / Parentheses
 * 2) Pointer     / Pointeurs
 * 3) Array       / Tableau
 * 4) Function    / Fonction
 */
      printf("%s", "Exo 4a)\n");
      printf("%s", "int* (*a(char * const))[5];\n");
      printf("Est une fonction prenant un pointeur constant\n"
             "sur char et renvoyant un pointeur sur un tableau\n"
             "de 5 pointeurs sur int\n\n");
      int* (*a(char * const))[5];
      // ENG :
      // FR  :
      // Developpement :   3) :  (*a(char * const)) est un tableau de 5 pointeurs
      //                         sur int
      //                   1) :  *a(char * const) est un tableau de 5 pointeurs
      //                         sur int
      //                   2) :  a(char * const) est un pointeur sur un tableau
      //                         de 5 pointeurs sur int
      //                   4) :  a est une fonction prenant un pointeur constant
      //                         sur char et renvoyant un pointeur sur un tableau
      //                         de 5 pointeurs sur int
      printf("%s", "int (*(*b[5])(int))[10];\n");
      printf("Est un tableau de 5 pointeurs pointant chacun sur\n"
             "une fonction prenant un int et renvoyant un\n"
             "pointeur sur un tableau de 10 int\n");
      int (*(*b[5])(int))[10];
      // ENG :
      // FR  :
      // Developpement :   3) :  (*(*b[5])(int)) est un tableau de 10 int
      //                   1) :  *(*b[5])(int) est un tableau de 10 int
      //                   4) :  (*b[5]) est une fonction prenant un int et
      //                         renvoyant un pointeur sur un tableau de 10 int
      //                   1) :  *b[5] est une fonction prenant un int et
      //                         renvoyant un pointeur sur un tableau de 10 int
      //                   2) :  b[5] est un pointeur sur une fonction prenant un
      //                         int et renvoyant un pointeur sur un tableau de
      //                         10 int
      //                   3) :  b est un tableau de 5 pointeurs pointant chacun sur
      //                         une fonction prenant un int et renvoyant un
      //                         pointeur sur un tableau de 10 int
      ENDL();
   }
   {
/*
 * 1) Pointer     / Pointeurs
 * 2) Array       / Tableau
 * 3) Function    / Fonction
 */
      printf("%s", "Exo 4b)\n");
      printf("p est un pointeur sur une fonction prenant en parametre un pointeur\n"
             "sur un tableau de 5 int et livrant un pointeur sur \n"
             "double constant = ");
      printf("const double* (*p)(int (*) [5])\n\n");
      const double* (*p) (int (*) [5]);

      printf("f est une fonction sans parametre livrant un pointeur sur un \n"
             "tableau de 5 pointeurs constant sur double ="
             " ");
      printf("double* const (* f(void))[5];\n\n");
      double* const (* f4(void))[5];
      ENDL();
   }
   {
      printf("%s", "Exo 5)\n");
      #define TAILLE 5
      char matrice[TAILLE][TAILLE];

      initialiser((char*)matrice, TAILLE, 'X', '.');
      //initialiser(*matrice, TAILLE, 'X', '.');     // OR matrice[0]
      //initialiser(&matrice[0][0], TAILLE, 'X', '.');
      afficher((char*)matrice, TAILLE);
      //afficher(*matrice, TAILLE);                  // OR matrice[0]
      //afficher(&matrice[0][0], TAILLE);
      #undef TAILLE
      ENDL();
   }


	return EXIT_SUCCESS;
}

void initialiser(char* matrice, size_t n, char surDiag, char horsDiag) {
   assert(matrice != NULL);
   assert(n > 0);
   memset(matrice, horsDiag, n * n);
   for (size_t i = 0; i < n; ++i)
      matrice[(n + 1) * i] = matrice[(n - 1) * (i + 1)] = surDiag;
      //*(matrice + (n + 1) * i) = *(matrice + (n - 1) * (i + 1)) = surDiag;
}

void afficher(const char* matrice, size_t n) {
   assert(matrice != NULL);
   for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n; ++j)
         printf("%c", *(matrice + i * n + j));  // OR matrice[i * n + i]
      ENDL();
   }
}

void inverser(void* debut, void* fin, size_t size) {
   assert(debut != NULL && fin != NULL);
   assert(size > 0);

   char* tmp = (char*) calloc(size, 1);   // calloc(size, sizeof(char));
                                          // calloc(size, sizeof(*tmp));
   assert(tmp != NULL);

   char* ptr1 = (char*) debut,
       * ptr2 = (char*) fin;

   while (ptr1 < ptr2) {
      memcpy(tmp, ptr1, size);
      memcpy(ptr1, ptr2, size);
      memcpy(ptr2, tmp, size);
      ptr1 += size;
      ptr2 -= size;
   }
   free(tmp);
}
