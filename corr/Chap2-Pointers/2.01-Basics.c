/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.01-Basics.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.01
                     Ecrire un programme C qui :
                        1) Declare une variable n de type int et l'initialise a 1
                        2) Declare un pointeur ptr pointant sur n
                        3) Affiche a l'ecran la valeur de l'objet pointe par ptr
                        4) Affiche a l'ecran l'adresse contenue dans ptr
                        5) Affiche l'adresse de ptr

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
   // Var. dec. : ----------------------------------------------------------------->
   int n = 1;
   int *ptr = &n;

   // Code : ---------------------------------------------------------------------->
   printf("3) Valeur pointee  : %d\n", *ptr);
   printf("4) Address pointee (with ptr) : %p\n", (void*)ptr);
   printf("   Validation      (with  n ) : %p\n", (void*)&n);
   printf("5) Address pointer            : %p\n", (void*)&ptr);

   return EXIT_SUCCESS;
}
