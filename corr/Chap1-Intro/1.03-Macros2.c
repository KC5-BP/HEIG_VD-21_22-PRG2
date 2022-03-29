/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.03-Macros2.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 1.03
                     1) Que va afficher le programme suivant
                     2) Expliquez en quoi le programme est problematique ?
                     3) Est-il possible de recrire (sans utiliser la
                        fonction abs de stdlib) la macro ABS de maniere
                        a eviter les problemes du pt2 ?

 Remarque(s)    : 1) See code below
                  2) ° Change the waz of working if not -(X) like seen with 4
                     ° And multiple increase instead of a simple one
                        ("Side effect" / "Effet de bord" on 5 & 6) .
                  3) ° Yes, by creating a "generic" macros for an abs fn.

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Uncomment to see the correct output after pt3 has been done.
//#define PT3_CORRECTED 0
#ifndef PT3_CORRECTED

      #define PT2_CORRECTED 0
      #ifndef PT2_CORRECTED
         #define ABS(X) (((X) > 0) ? (X) : (-X))
      #else
         #define ABS(X) (((X) > 0) ? (X) : -(X))
      #endif   // END PT2_CORRECTED

   int main(void) {
      int n;

      printf("1. %d\n", ABS(2));
      // 1) Will print 2
      printf("2. %d\n", ABS(-2));
      // 2) Will print 2
      printf("3. %d\n", ABS('A'));
      // 3) Will print 65

      n = -2;
      printf("4. %d\n", ABS(n+1));
      // (((n+1) > 0) ? (n+1) : (-n+1))
      // 4) Will print 3

      n = -2;
      printf("5. %d", ABS(n++)); printf(" %d\n", n);
      // (((n++) > 0) ? (n++) : (-n++))
      // After test : -1
      //      Will print 1 for first %d
      //          Will print 0 for second %d because of post increase before.
      // 5) 1 0

      n = -2;
      printf("6. %d", ABS(++n)); printf(" %d\n", n);
      // (((++n) > 0) ? (++n) : (-++n))
      // After test : -1
      //      Will print 0 for first %d because pre increase and negate after.
      //          Will print 0 for second %d.
      // 6) 0 0


      n = -2;
      printf("7. %d", abs(++n)); printf(" %d\n", n);
      // 7) Will print 1 -1 by using abs from stdlib

      return EXIT_SUCCESS;
   }

#else // PT3 defined

   #define GENERIC_ABS(type)					\
   type abs_##type(type input) {				\
      return input < 0 ? -input : input;	\
   }
   GENERIC_ABS(int)

   int main(void) {
      int n;

      printf("1. %d\n", abs_int(2));
      // 1) Will print 2
      printf("2. %d\n", abs_int(-2));
      // 2) Will print 2
      printf("3. %d\n", abs_int('A'));
      // 3) Will print 65

      n = -2;
      printf("4. %d\n", abs_int(n+1));
      // 4) Will print 1

      n = -2;
      printf("5. %d", abs_int(n++)); printf(" %d\n", n);
      // 5) 2 -1

      n = -2;
      printf("6. %d", abs_int(++n)); printf(" %d\n", n);
      // 6) 1 -1

      n = -2;
      printf("7. %d", abs(++n)); printf(" %d\n", n);
      // 7) 1 -1

      return EXIT_SUCCESS;
   }
#endif   // END PT3_CORRECTED

/*
 * Side note(s) :
#define GENERIC_ABS(type)					\
type abs_##type(type input) {				\
	return input > 0 ? input : -input;	\
}
 * And used as :
GENERIC_ABS(int) // Creating the fn : int abs_int(int input) { ... }

 * Note(s) :	abs_##type() OR type##_abs()
							'-------------'---> '#' Concatenate the value as a name
														instead of copying it like a simple define do.
 * 				We can use the '#' into a define to print a var name :
#define VIEW_VAR(a) printf(#a " = %d", (a))
 * 				That will print : <varName> = %d
 * 				We call that : Stringizing in english / Stringification en francais.
 * 				Usage only possible in macros.
 */
