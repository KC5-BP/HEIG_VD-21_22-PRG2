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
#include <stdlib.h>
#include <inttypes.h>

#define ENDL(void) printf("\n")

uint16_t f(uint16_t a, uint8_t b) {
    const uint16_t MASK = 0x8000;
    while (b--)
        a = (uint16_t) (a << 1) | ((a & MASK) != MASK);
    return a;
}

void exo1(void) {
    {
        printf("%s", "Exo 1a)\n");
        #define double(d) d + d
        int n1 = -3;
        printf("%d\n", double(-3 == n1));
        #undef double

        #define CARRE(X) X * X
        int n2 = 3;
        printf("%d\n", CARRE(n2 - 1));
        #undef CARRE

        #define N 2
        #define STR(X)  #X
        #define F(N)  STR(Fichier_##N)
        int n = 3;
        printf("%s\n", F(n));
        #undef F
        #undef STR
        #undef N
    }
    {
        printf("%s", "Exo 1b)\n");
        printf("0x%#x\n", f(0x1234, 5));
    }
    {
        printf("%s", "Exo 1c)\n");
        #define PRINT_ADDRESS(ADR) printf("0x%" PRIxPTR "\n", (intptr_t) ADR)
        int64_t m[][4] = {{1}, {0,1}, {0,0,1}, {0,0,0,1}};
        PRINT_ADDRESS(m);
        PRINT_ADDRESS(*(m + 2) + (&m[2][-1] - 3[m]));
        #undef PRINT_ADDRESS
    }
}

void exo2(void) {
    printf("%s", "Exo 2)\n");
    printf("1) |%.5d|\n", 230);
    printf("2) |%-#5X|\n", 230);
    printf("3) |%f|\n", 12.345);
    printf("4) |%#.f|\n", 12.345);
    printf("5) |%2g|\n", 12.345);
    printf("6) |%+5.1f|\n", 0.157);
    printf("7) |%*.*E|\n", 8, 1, 0.01);
    printf("8) |%G|\n", 1e-4);
    printf("9) |%06.4g|\n", 123.456);
}

void exo3(void) {
    {
        printf("%s", "Exo 3a)\n");
        int t[] = {1, 2, 3, 5, 8, 13};
        int* tp[] = {t, t + 1, t + 2, t + 3, t + 4, t + 5};
        int** pp = tp + 3;

        printf("1) %d\n", --**pp);
        printf("2) %d\n", pp[1][-1]);
        printf("3) %d\n", (*pp++)[1]);
        printf("4) %d\n", ++**pp--);
        printf("5) %d\n", *++pp - *tp + 1);
    }
    {
        printf("%s", "Exo 3b)\n");
        char* t[] = {"Mars", "Avril", "Mai"};
        char** tp[] = {t, t + 1, t + 2};
        char** pp = (char**) t;

        printf("1) %s\n", ++t[0]);
        printf("2) %c\n", **(tp[1] - 1));
        printf("3) %c\n", *++*++pp);
        printf("4) %d (char : %c)\n", **tp[2] + 1, **tp[2] + 1);
        printf("5) %c\n", pp[0][1]);
    }
}

void exo4(void) {
    {
/*
 * 1) Parenthesis / Parentheses
 * 2) Pointer     / Pointeurs
 * 3) Array       / Tableau
 * 4) Function    / Fonction
 */
        char* const (* a(void))[3];
        const int *(* b) (void* (*)[3]);
    }
    {
/*
 * 1) Pointer     / Pointeurs
 * 2) Array       / Tableau
 * 3) Function    / Fonction
 */
        double* (* e(char * const))[3]; // Rename to e to avoid conflicting with f
        double (* (*t[3])(const int*))[10];
    }
}

void exo5(void) {

}

int main(void) {
    exo1(); ENDL();
    exo2(); ENDL();
    exo3(); ENDL();
    exo4(); ENDL();
    //exo5(); ENDL();
	return EXIT_SUCCESS;
}
