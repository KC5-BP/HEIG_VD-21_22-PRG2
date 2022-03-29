/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.06-PtrAffect.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.06
                     Soient les déclarations suivantes :
                        ...
                     Quel sera dans un programme l'effet
                     des instructions suivantes :
                        ...

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
   // Var. dec. : ----------------------------------------------------------------->
   int i = 1, j = 2;

   int* pi1 = &i;
   int* pi2 = &j;

   double x = 3.0;
   double* pd = &x;

   void* pv;

   // Code : ---------------------------------------------------------------------->
   // 1)
   pi1 = pi2;

   // 2)
   pd = pi1;

   // 3)
   pi1 = pd;

   // 4)
   pv = pi1;

   // 5)
   pv = &i;

   // 6)
   pv = pi1;
   pi2 = pv;

   // 7)
   if (pi1 = pi2) ;

	return EXIT_SUCCESS;
}
