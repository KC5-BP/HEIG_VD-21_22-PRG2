// Exo 1.1 : Donnee ;
//                   Indiquer ce que va afficher le code suivant :
/*
#include <stdio.h>
#include <stdlib.h>

#define A 1
#define B 2
#define AB 3
#define F(X,Y) X##Y

int main(void) {
   int n = AB;
   printf("%<?>\n", n);
   printf("%<?>\n", "AB");
   printf("%<?>\n", F(A, B));

   return EXIT_SUCCESS;
}
 */
#include <stdio.h>
#include <stdlib.h>

#define A 1
#define B 2
#define AB 3
#define F(X,Y) X##Y
//  F will concatenate the X symbol with the Y's,
//      to create the symbol XY.
//          (See example below)

int main() {
	// Code First : -------------------------------------------------------------------->
	printf("Au diable \"Hello World !\" !!\n");
	printf("Wait ...\n");
	printf("God DAMMIT, MORTY !\n\n");

	// Code : -------------------------------------------------------------------------->
	int n = AB;

	//printf("%<?>\n", n);
	printf("%d\n", n);
	//      Will print 3, car n = AB = 3

	//printf("%<?>\n", "AB");
	printf("%s\n", "AB");
	//      Will print AB

	//printf("%<?>\n", F(A,B));
	printf("%d\n", F(A,B));
	// F() will create the symbol AB,
	//      that will be replaced by the value
	//          of the defined symbol AB => So will print 3.

	return EXIT_SUCCESS;
}
