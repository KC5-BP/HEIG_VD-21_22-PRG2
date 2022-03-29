/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.04-BitOperator.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 1.04
                     Que valent chacune des expressions suivantes
                        1)    22 | 11
                        2)    0 ^ 19
                        3)    2 << 3
                        4)    30 & 14
                        5)    8 >> 2
                        6)    4 & 29
                        7)    9 << 4
                        8)    31 ^ 27
                        9)    23 | 3
                        10)   -1 >> 1
                        11)   -5 >> 1
                        12)   3 & ~2
                        13)   6 | 5 & 4

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("1) %d\n", 22 | 11);
	// After Exec. :
	printf("2) %d\n", 0 ^ 19);
	// After Exec. :
	printf("3) %d\n", 2 << 3);
	// After Exec. :
	printf("4) %d\n", 30 & 14);
	// After Exec. :
	printf("5) %d\n", 8 >> 2);
	// After Exec. :
	printf("6) %d\n", 4 & 29);
	// After Exec. :
	printf("7) %d\n", 9 << 4);
	// After Exec. :
	printf("8) %d\n", 31 ^ 27);
	// After Exec. :
	printf("9) %d\n", 23 | 3);
	// After Exec. :
	printf("10) %d\n", -1 >> 1);
	// After Exec. :
	printf("11) %d\n", -5 >> 1);
	// After Exec. :
	printf("12) %d\n", 3 & ~2);
	// After Exec. :
	printf("13) %d\n", 6 | 5 & 4);
	// After Exec. :

	return EXIT_SUCCESS;
}
