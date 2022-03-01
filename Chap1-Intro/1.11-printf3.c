// Exo 1.11 : Donnee ;
//                  Completer le code de telle maniere, qu'il affiche :
//                  i = 1
//                  j = 4294967295
/*
#include <stdio.h>
#include <stdlib.h>

<a completer>

int main(void) {
    size_t i = 1;
    uint32_t j = UINT32_MAX;

    <a completer>

    return EXIT_SUCCESS;
}
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define PRINT_VAR(VAR) (		\
	printf(#VAR " = %lu", VAR)	\
)
#define ENDL() (	\
	printf("\n")	\
)

int main(void) {
	size_t i = 1;
	uint32_t j = UINT32_MAX;

	PRINT_VAR(i);
	ENDL();
	PRINT_VAR(j);

	return EXIT_SUCCESS;
}
