/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.04-PtrInter.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.04
                     Traduire en Francais les declarations C suivantes

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * 1) Parenthesis / Parentheses
 * 2) Pointer     / Pointeurs
 * 3) Array       / Tableau
 * 4) Function    / Fonction
 */
int main(void) {
   char** a[10];
   // ENG : a is an array of 10 addresses pointing each on a char.
   // FR  : a est un tableau de 10 adresses(pointeurs) pointant chacune sur un char.
   // Developpement : 3 -> 2 -> 2

   double* (*b)(void);
   // ENG : b is a function pointer without argument, returning a pointer on double.
   // FR  : b est un pointeur sur une fonction sans parametre, qui retourne un
   //       pointeur sur un double.
   // Developpement : 4

   double (*c)(double*);
   // ENG : c is a function pointer with a ptr on double as argument and returning
   //       a double.
   // FR  : c est un pointeur sur une fonction a un parametre de type pointeur sur
   //       double et retournant un double.
   // Developpement : 1 -> 4 -> 2

   int* d[10];
   // ENG : d is an array of 10 addresses of int each
   // FR  : d est un tableau de 10 adresses(pointeurs) sur int.
   // Developpement : 3 -> 2

   int (*e)[10];
   // ENG : e is a pointeur on an array of 10 int
   // FR  : e est un pointeur sur un tableau de 10 int.
   // Developpement : 1 -> 3

   int (*(*f[5])(void))[10];
   // ENG :
   // FR  :
   // Developpement :   (*(*f[5])(void))  : est un tableau de 10 int : 3)
   //                   *(*f[5])(void)    : est un tableau de 10 int : 1)
   //                   (*f[5])(void)     : est un pointeur sur un tableau de 10 int
   //                                     : 2)
   //                   (*f[5])           : est une fonction sans parametre
   //                                       retournant un pointeur sur un tableau de
   //                                       10 int : 4)
   //                   *f[5]             : est une fonction sans parametre
   //                                       retournant un pointeur sur un tableau de
   //                                       10 int : 1)
   //                   f[5]              : est un pointeur sur une fonction sans
   //                                       parametre, retournant un tableau de 10
   //                                       int : 2)
   //                   f                 : est un tableau de 5 pointeurs
   //                                       pointant chacun sur une fonction sans
   //                                       parametre retournant un pointeur sur
   //                                       un tableau de 10 int : 1)

   double (**g)[5];
   // ENG :
   // FR  :
   // Developpement :   (**g)             : est un tableau de 5 double 3)
   //                   **g               : est un tableau de 5 double 1)
   //                   g                 : est un pointeur sur l'adresse d'un
   //                   tableau de 5 double 2 -> 2

	return EXIT_SUCCESS;
}
