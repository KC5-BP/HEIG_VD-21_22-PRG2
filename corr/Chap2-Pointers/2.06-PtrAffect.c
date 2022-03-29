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
   pi1 = pi2;  // pi1 points the same content as pi2
               // No problem here
   // 2)
   pd = pi1;   // pd points the same content as pi1
               // There will be a cast problem of an int* to double*
   // 3)
   pi1 = pd;   // pi1 points the same content as pd
               // There will be a cast problem of a double* to int*
   // 4)
   pv = pi1;   // pv points the same content as pi1
               // But the void* can't be use as so, it will need to be cast before
   // 5)
   pv = &i;    // pv points on i's address
               // Same issue as before
   // 6)
   pv = pi1;   // pv points the same content as pi1
   pi2 = pv;   // pi2 points the same content as pv
               // The content of pi2 will be unsure
   // 7)
   if (pi1 = pi2) ;  // Check if pi1 pointed address is equal to
                     // pi2 pointed address.
   return EXIT_SUCCESS;
}
