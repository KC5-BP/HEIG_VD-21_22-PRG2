/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.10-PtrArith_4.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.10
                     Que va afficher le main ci-dessous ?

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
   const char* c[] = {"comprendre", "les", "pointeurs", "c\'est", "difficile"};
   const char** cp[] = {c, c + 2, c + 4, c + 1, c + 3};
   const char*** cpp = cp;
   int i;

   for (i = 0; i < 3; i++)
      printf("%c", *(**cpp + i));
   printf("%c", *(*cp[0] + 2));
   printf("%s ", *cpp[2] + 8);
   printf("%s ", *++*++cpp);
   for (i = 1; i < 4; i++)
      printf("%c", *(cpp[-1][i % 3] + 2));
   printf("%c", **--*cpp);
   printf("%s\n", **++cpp + 7);

   return EXIT_SUCCESS;
}
