// Exo 1.13 : Donnee ;
//                  1) Le code suivant, pourtant simple, comporte 3 erreurs majeurs
//                  Lesquels ?
//                  2) Reecrire le code en corrigeant les dites erreurs.
/*
#include <stdio.h>
#include <stdlib.h>
#define TAILLE_NOM 20
int main(void) {
    char nom[TAILLE_NOM + 1];
    printf("Entrez votre nom (%d caract. max) : ", TAILLE_NOM);
    scanf("%20s", nom);
    printf("Votre nom est \"%s\"\n", nom);
    system(PAUSE);
    return EXIT_SUCCESS;
}
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define TAILLE_NOM 20

int getNbrOfDigits(int n);
//#define RECURSIV 0
#ifdef RECURSIV
int getNbrOfDigits(int n) {
   if (n < 0)
      n = (n == INT_MIN) ? (INT_MAX) : (-n);
   if (n < 10) return 1;
   return 1 + getNbrOfDigits(n/10);
}
#else
int getNbrOfDigits(int n) {
   int d = 1;
   if (n < 0)
      n = (n == INT_MIN) ? (INT_MAX) : (-n);
   while (n > 9) {
      n /= 10;
      ++d;
   }
   return d;
}
#endif

const char* makeScanfFormat(int SIZE_MAX) {
   int d = getNbrOfDigits(SIZE_MAX);
   char* dAsStr = (char*)calloc((unsigned)(d+1), sizeof(char)); // + '\0'
   char* inputFormat = (char*)calloc((unsigned)(d+3+4), sizeof(char));
   //					                                 + '%' + 's' + '\0'
   //					                                 + '[' + '^' + '\n' + ']'
   sprintf(dAsStr, "%d", SIZE_MAX);
   strcat(inputFormat, "%");
   strcat(inputFormat, dAsStr);
   strcat(inputFormat, "[^\n]");

   return inputFormat;
}

int main(void) {
   char nom[TAILLE_NOM + 1] = {'\0'};  // 1) Pas initialisé par défaut. Donc si
                                       // tableau non rempli, peut afficher
                                       // n'importe quoi.
  int nbrOfCharRead;

   printf("Entrez votre nom (%d caract. max) : ", TAILLE_NOM);
   nbrOfCharRead = scanf(makeScanfFormat(TAILLE_NOM), nom);  // 2) Ne dépend pas de
   //                                                                   TAILLE_NOM
   printf("Votre nom est \"%s\"\n", nom);

#ifdef _WIN32
   system("pause");  // PAUSE instead "pause"
#elif __linux__
   system("sleep 5");   // PAUSE/SLEEP 5s.
#elif defined (_APPLE_)
   system("pause");  // PAUSE instead "pause"
#endif
   return EXIT_SUCCESS;
}
