/*
 -----------------------------------------------------------------------------------
 Nom du fichier : <nom du fichier>.<x> (x = h ou c)
 Auteur(s)      : (\_/)
 Date creation  : <j .mm.aaaa>

 Description    : <� compl�ter>

 Remarque(s)    :
                  Reference card : https://users.ece.utexas.edu/~adnan/c-refcard.pdf

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

#define ENDL(void) printf("\n")

void exo1(void) {
    printf("%s", "Exo 1) ------------------------------\n");
    int a[] = {2, 4, 8, 16, 32};
    int* b[] = {a, a+1, a+2, a+3, a+4};
    int** c = b + 3;

    printf(" 1) %d\n", **b+1);   // 3
    printf(" 2) %d\n", b[1][1]); // 8
    printf(" 3) %d\n", --**c++); // 15
    printf(" 4) %d\n", c[0][-1]);// 15
    printf(" 5) %d\n", *--c-*(b+1)); // 2
    //      1)  *b = a => *a = 2
    //          2+1 = 3
    //      2)  b[1] = a+1
    //          (a+1)[1] <=> a[1][1] = 8
    //      3)  c++ = (b + 3)++     Will return b+3, but next time c = b+4
    //          *(b+3) = b[3] = a + 3
    //          *(a+3) = a[3] = 16
    //          --16 = 15           Leading to change the value in a[4]
    //      4)  c[0] = b[4] = a + 4                     Changed from 3)
    //          (a+4)[-1] = 15
    //      5)  --c = --(b + 4) = b + 3
    //          *(b+3) = a + 3
    //          *(b+1) = a + 1
    //          (a + 3) - (a - 1) = 2
    const char* d[] = {"Les", "Pointeurs", "c'est", "sympa"};
    const char** e[] = {d, d+1, d+2, d+3};
    const char*** f = &e[2];

    printf(" 6) %c\n", **d);        // 'L'
    printf(" 7) %c\n", *++d[3]);    // 'y'
    printf(" 8) %s\n", *e[1]);      // "pointeurs"
    printf(" 9) %s\n", *--*(e+1)+1);    // "es"
    printf("10) %c\n", *(f[-1][3]+2));  // 'p'
    //      6)  *d = "Les" => *"Les" = 'L'
    //      7)  d[3] = "sympa"
    //          ++"sympa" = "ympa"  Leading to change the value in d[3]
    //          *"ympa" = 'y'
    //      8)  e[1] = d + 1
    //          *(d+1) = "pointeurs"
    //      9)  *(e+1) = e[1] = d + 1
    //          --(d+1) = d         Leading to change the value in e[1]
    //          *d = "Les"
    //          "Les"+1 = "es"
    //      10) f[-1] = *((e+2) - 1) = *(e + 1) = d
    //          d[3] = "ympa"
    //          "ympa" + 2 = "pa"
    //          *"pa" = 'p'
}

// 2)
//int** difference(const int* tab1, size_t taille1,
int* difference(const int* tab1, size_t taille1,
                const int* tab2, size_t taille2) {
    assert(tab1 != NULL && tab2 != NULL);
    assert(taille1 <= INT_MAX);
    //int* tab = (int*) malloc(taille1 + 1, sizeof(int));
    int* tab = (int*) calloc(taille1 + 1, sizeof(int));
    if(tab) {
        *tab = (int) taille1;
        //memcpy(tab + 1, tab1, sizeof(int));
        memcpy(tab + 1, tab1, sizeof(int) * taille1);
        for (size_t i = 0; i < taille2; ++i) {
            size_t j = 0;   // Cette ligne ne contient pas d'erreur
            for (size_t k = 1; k <= (size_t) *tab; ++k) {
                if (tab[k] != tab2[i]) {
                    //tab[j++] = tab[k];
                    tab[++j] = tab[k];
                }
            }
            *tab = (int) j;
        }
        //realloc(tab, (size_t) *tab * sizeof(int));
        tab = realloc(tab, (size_t) (*tab + 1) * sizeof(int));
    }
    return tab;
}

void exo2(void) {
    printf("%s", "Exo 2) ------------------------------\n");
    printf("5 Erreurs dans la fonction.\n");
}

void exo3(void) {
    printf("%s", "Exo 3) ------------------------------\n");
    {   // 1)
        /*struct S {
            char c;
            float x = 1.5f; // Wrong, can't initialize value
                            // inside struct declaration
        } s;*/
    }
    {   // 2)
        /*struct S {
            const char C;
            float x;        // Wrong, const must be
        } s;                // initialize at var. creation.
        s = (struct S) {'A', 1.5f};*/

    }
    {   // 3)
        typedef struct {
            char c;          // Wrong, can't compare struct's
            int n;
        } S;
        S s1 = {'A', 1}, s2 = {65, 1};
        //printf("s1 == s2 ? %s\n", (s1 == s2 ? "oui" : "non"));
    }
    {   // 4)
        /*
        typedef struct {
            char c;
            static int n;   // Wrong, can't specify a static inside a struct
        } S;
        S s = {.c = 'A', .n = 1};
         */
    }
    {   // 5)
        struct S {
            const char C;
            float x;        // Correct, const must be
        } s = {'A', 1.5f};  // initialize at var. creation.
        printf("%c %f\n", s.C, s.x);
    }
    {   // 6)
        // typedef struct S {   // Would work with this, because struct
        typedef struct {        // is not nameless anymore
            char c;         // Wrong, struct is nameless and declaration use
            float x;        //  named struct's.
        } S;
        S s1;
        //S s2 = s1 = (struct S) {.c = 'A', .x = 1.5f};
        S s2 = s1 = (S) {.c = 'A', .x = 1.5f};  // <- Should be this
    }
    {   // 7)
        typedef struct {
            struct T* a;    // Correct, because it's like an
        } S;                // anticipated decla. Would be false if T* only
        struct T {
            S* b;           // S is known to this point, so correct
        };
    }
    {   // 8)
        struct S {
            enum E {A, B, C = 0} e;
        } s;                // Wrong, C++ format, not available in C.
        //s.e = E::B;
        //printf("%d\n", s.e);
    }
    {   // 9)
        /*typedef struct {
            T* a;           // Wrong, T unknown so far.
        } S;                // The only way to make it work is by making
        typedef struct {    // an anticipate declaration (see 7) )
            S* b;
        } T;*/
    }
    {   // 10)
        typedef union {
            int n;
            union V {       // Wrong, because without specifier, it's the first
                char c;     // element that is initialized. In this case,
                float x;    // it tries to set the union {.x = 1.5f} to n.
            } v;
        } U;
        //U u = {{.x = 1.5f}};
    }
    {   // 11)
        char s1[4];             // Wrong, can't assign another address to a cst ptr.
        const char* s2 = "ABC"; // s1 is a char* const
        //s1 = s2;
    }
    {   // 12)
        typedef char Chaine[];
        Chaine s1 = "ABC";      // Correct, s2 is a pointer on char cst.
        const char* s2 = s1;    // So its pointed address can change,
        printf("%s\n", s2);     // but not the content.
    }
}

// 4a)
/*void adrDernierCaract(char* s, char* adr) {
    if (s == NULL && *s == '\0') {
        adr = NULL;
    }
    adr = s[strlen(s)];
}*/
void adrDernierCaract(const char* s, char** adr) {
    if (s == NULL || *s == '\0') {  // OR *s == 0 OR strlen(s) == 0
        *adr = NULL;                // OR !*s OR !strlen(s)
        return;                     // Forme compacte : if (!s || !*s)
    }   // OR using else statement instead of the return;
    *adr = (char*) (s + strlen(s) - 1);
    // *adr = &s[strlen(s) - 1];
    // *adr = strrchr(s, '\0') - 1;
}

// 4b) using STRTOD()
double gravite_sscanf(const char* s) {
    assert(s != NULL);
    static const double G = 6.6743E-11; // [m3 kg-1 s-2]
    double  masse,  // [kg]
            rayon_m;// [km]
    sscanf(s, "%lf %lf", &masse, &rayon_m);
    rayon_m *= 1E3; // [m]
    return G * masse / (rayon_m * rayon_m);
}
double gravite_strtod(const char* s) {
    assert(s != NULL);
    static const double G = 6.6743E-11; // [m3 kg-1 s-2]
    char* endp;
    double  masse   = strtod(s, &endp),
            rayon_m = strtod(endp, NULL) * 1000; // OR 1E3 OR 1e3
    return G * masse / (rayon_m * rayon_m); // [m s-2]
}

void exo4(void) {
    {
        printf("%s", "Exo 4a) -----------------------------\n");
        printf("Fn adrDernierCaract()\n");
        char str[] = "Hello B*tches!";
        char* adr = NULL;

        adrDernierCaract(str, &adr);

        printf("From string \"%s\"\n", str);
        printf("Last character : '%c' is @ %p\n", *adr, (void*) adr);
    }
    {
        printf("%s", "Exo 4b) -----------------------------\n");
        printf("Fn gravite()\n");
        typedef enum {MERCURE, TERRE, URANUS} Planetes;
        const char* const PLANETES[] = {"Mercure", "Terre", "Uranus"};
        // masse [kg] et rayon [km] des diverses planètes
        const char* const MASSE_ET_RAYON[] = {"3.303E23 2440.5",
                                              "5.976E24 6378",
                                              "8.686E25 25560"};
        for (Planetes p = MERCURE; p <= URANUS; ++p)
            printf("gravite sur %-7s = %.3g[m s-2]\n",
                   PLANETES[p], gravite_strtod(MASSE_ET_RAYON[p]));
    }
}

void exo5(void) {
    {
        printf("%s", "Exo 5a) -----------------------------\n");
        char argv[7][20];
        int argc = sscanf("myprog test.dat -opt1=10 src 10 -O2 20",
                          "%s %s %s %s %s %s %s",
                          argv[0], argv[1], argv[2], argv[3],
                          argv[4], argv[5], argv[6]);
        printf("argc = %d\n", argc);
        for (int i = 0; i < argc; ++i)
            printf("argv[%d] : %s\n", i, argv[i]);
        printf("argv has argc + 1 args, so : %d\n"
               "The last one being a NULL pointer.\n", argc + 1);
    }
    {
        printf("%s", "Exo 5b) -----------------------------\n");
        struct S {
            struct {
                uint32_t a;
                size_t b;
                char* c;
            } a;
            char b[3];
            uint16_t c;
            uint8_t d[7];
        } s;
// 32b :
/*
 * uint32_t a;          32b                 : One word
 * size_t b;            32b                 : One word
 * char* c;             32b                 : One word
 * unsigned char b[3];  3 * 8b = 24b
 * uint16_t c;          16b + 8b padding    : One word before c
 * uint8_t d[7];        7 * 8b              : 2 completing a word alongside c
 *                                          : 4 making another word
 *                                          : 1 alone, creating another word
 *                                            because align on the largest element.
 *                      Total : 32 * 7 = 224b = 28octets
 */
// 64b :
/*
 * uint32_t a;          32b
 * size_t b;            64b + 32b padding   : One word before b and One word for b
 * char* c;             64b                 : One word
 * unsigned char b[3];  3 * 8b = 24b
 * uint16_t c;          16b + 8b padding    :
 * uint8_t d[7];        7 * 8b              : 2 completing a word alongside c & b
 *                                          : 5 alone, creating another word
 *                                            because align on the largest element.
 *                      Total : 64 * 5 = 320b = 40octets
 */
        printf("Struct size : %zu[o]\n", sizeof(struct S));
    }
    {

    }
}

int main(void) {
    exo1(); ENDL();
    exo2(); ENDL();
    exo3(); ENDL();
    exo4(); ENDL();
    exo5(); ENDL();
    return EXIT_SUCCESS;
}
