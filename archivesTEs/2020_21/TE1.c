/*
 -----------------------------------------------------------------------------------
 Nom du fichier : <nom du fichier>.<x> (x = h ou c)
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : <� compl�ter>

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

uint16_t f(uint16_t i, uint8_t j) {
   for (uint8_t k = 0; k < j; ++k)
      i = (uint16_t) ((i >> 1) | (i & 0x0001 ? 0x8000 : 0));
   return i;
}

#define PRINT_ADDRESS(ADR) printf("0x%" PRIxPTR "\n", (intptr_t) (ADR))
#define ENDL() printf("\n")

int main(void) {
   {
      printf("%s", "Exo 1b)\n");
      printf("%#x\n", f(0x1234, 5));
      ENDL();
   }
   {
      printf("%s", "Exo 1c)\n");
      int32_t t[][4] = {{1}, {}, {2,3}};
      printf("%p\n", (void*) t);
      PRINT_ADDRESS(t[1] - (*(t+2) - &t[2][1]));   // Result must be t + 0x14
      ENDL();
   }
   {
      printf("%s", "Exo 3a)\n");
      int a[] = {1, 3, 5, 7, 9};
      int* b[] = {a, a+1, a+2, a+3, a+4};
      int** c = &b[3];

      printf("1) %d\n", **b+1);
      printf("2) %d\n", c[-1][-1]);
      printf("3) %d\n", --**c);
      printf("4) %d\n", ++**c++);
      printf("5) %d\n", *c + 1 - *(b + 1));
      ENDL();
   }
   {
      printf("%s", "Exo 3b)\n");
      const char* a[] = {"Federer", "Nadal", "Djokovic"};
      const char** b[] = {a, a+1, a+2};
      const char*** c = b+2;

      printf("1) %c\n", **a);
      printf("2) %c\n", *a[1]);
      printf("3) %s\n", *b[2]);
      printf("4) %d (char : %c)\n", *(*--*(b + 1) + 1) + 1, *(*--*(b + 1) + 1) + 1);
      printf("5) %c\n", *++c[-1][1]);
      ENDL();
   }


	return EXIT_SUCCESS;
}
