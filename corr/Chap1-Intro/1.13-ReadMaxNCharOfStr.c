/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.13-ReadMaxNCharOfStr.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 1.13
                     1) Le code suivant, pourtant simple, comporte 3 erreurs majeurs
                        Lesquels ?
                     2) Reecrire le code en corrigeant les dites erreurs.

 Remarque(s)    : 1)
                       i)  Program don't work if input has spaces.
                      ii)  %20s hard written. It will be better to build the format
                           from value.
                     iii)  Input buffer is not cleared.
                  2) See code below

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define TAILLE_NOM 20

void clear_stdin(void);

int main(void) {
   char nom[TAILLE_NOM + 1];
   char format[10];

   sprintf(format, " %%%d[^\n]", TAILLE_NOM);
   printf("Entrez votre nom (%d caract. max) : ", TAILLE_NOM);
   scanf(format, nom);
   clear_stdin();

   printf("Votre nom est \"%s\"\n", nom);

   return EXIT_SUCCESS;
}

/*
void clear_stdin(void) {
   int c;
   do {
      c = getchar();
   } while (c != '\n' && c != EOF);
}
 */

void clear_stdin(void) {
   fseek(stdin, 0, SEEK_END);
}
