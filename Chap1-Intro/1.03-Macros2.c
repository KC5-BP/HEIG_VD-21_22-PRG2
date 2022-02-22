// Exo 1.3 : Donnee ;
//                  1) Que va afficher le programme suivant ..
//                  2) Expliquez en quoi le programme est problematique ?
//                  3) Est-il possible de recrire (sans utiliser la
//                      fonction abs de stdlib) la macro ABS de maniere
//                      a eviter les problemes du pt2 ?

#include <stdio.h>
#include <stdlib.h>

#define ABS(X) (((X) > 0) ? (X) : (-X))

int main(void) {
	int n;

	printf("1. %d\n", ABS(2));
	// 1) Will print 2
	printf("2. %d\n", ABS(-2));
	// 1) Will print 2
	printf("3. %d\n", ABS('A'));
	// 1) Will print 65

	n = -2;
	printf("4. %d\n", ABS(n+1));
	// (((n+1) > 0) ? (n+1) : (-n+1))
	// 1) Will print 3

	n = -2;
	printf("5. %d", ABS(n++)); printf(" %d\n", n);
	// (((n++) > 0) ? (n++) : (-n++))
	// After test : -1
	//      Will print 1 for first %d
	//          Will print 0 for second %d because of post increase before.
	// 1) 1 0

	n = -2;
	printf("6. %d", ABS(++n)); printf(" %d\n", n);
	// (((++n) > 0) ? (++n) : (-++n))
	// After test : -1
	//      Will print 0 for first %d because pre increase and negate after.
	//          Will print 0 for second %d.
	// 1) 0 0


	n = -2;
	printf("7. %d", abs(++n)); printf(" %d\n", n);
	// Will print 1 -1 by using abs from stdlib

	return EXIT_SUCCESS;
}
/*
 * 2) - Multiple increase instead of a simple one ("Effet de bord" on 5 & 6) .
 *    - False, because like the 4 shows us, we need to obtain 1.
 */

/*
 * 3) Yes, by creating a "generic" macros for an abs fn.
 *      Like so :
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
