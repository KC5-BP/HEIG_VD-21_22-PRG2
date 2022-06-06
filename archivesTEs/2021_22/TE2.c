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
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

#define ENDL(void) printf("\n")

void exo1(void) {
    {
        printf("%s", "Exo 1) ------------------------------\n");
        {
            char chaine[3] = "ABC"; // Wrong, needed chaine[4]
        }
        {
            char chaine[5];
            //chaine = "ABC";   // Wrong, chaine is a cst ptr!
                                // chaine[0] = 'A', chaine[1] = 'B',
        }                       // chaine[2] = 'C' to be correct
        {
            const char* chaine1;
            char chaine2[] = "ABC";
            chaine1 = chaine2;  // Correct, chaine1 is a cst ptr
        }                       // and not a ptr on cst
        {
            typedef char string[];  // Correct, it will be a : char[]
        }
        {
            /*
            struct S {
                int n = 1;
                double x = 2.5; // Wrong, can't initialize value
                                // inside struct declaration
            } s;
             */
        }
        {
            typedef struct {
                const int N;    // Correct, const must be
                double x;       // initialize at var. creation.
            } S;
            S s = {1, 2.5};
        }
        {
            /*
            struct S {
                const int N;    // Wrong, const must be
                double x;       // initialize at var. creation.
            } s;
            s = (struct S) {1, 2.5};
             */
        }
        {
            /*
            struct S {
                int n;
                static int m;   // Wrong, can't specify a static inside a struct
            };
            struct S s = {1, 2};
             */
        }
        {
            struct S {
                int n;          // Correct
                double x;
            };
            struct S s1 = {.x = 2.5};
            struct S s2 = s1;
        }
        {
            struct S {
                int n;          // Wrong, can't compare struct's
                double x;
            };
            struct S s1 = {1, 2.5};
            struct S s2 = {1, 2.5};
            //printf("s1 == s2 ? %s\n", (s1 == s2 ? "oui" : "non"));
        }
        {
            struct S {          // Correct, but careful, A starts at 0, so B = 1
                enum {A, B, C = 0} e;
            } s;
            s.e = B;
            printf("%d\n", s.e);
        }
        {
            struct S1 {         // Correct because it's a pointer, kind of
                struct S2* a;   // anticipated declaration
            };
            struct S2 {
                struct S1* a;
            };
        }
        {
            /*
            typedef struct S {
                int n;
                T* ptr;         // Wrong, T is not known until end of struct
            } T;                // declaration
            T t = {1, NULL};
             */
            // To make it possible :
            //struct T;
            //typedef struct S {
            //    int n;
            //    struct T* ptr;
            //} T;
            //T t = {1, NULL};
        }
        {
            union U {
                int n;
                double x;       // Wrong, because without specifier, it's the first
            };                  // var. that is initialized.
            union U u = {1.5};
            //union U u = {.x = 1.5};   // To be correct
            printf("u = %f\n", u.x);
        }
    }
}

void exo2(void) {
    printf("%s", "Exo 2a) -----------------------------\n");
    const char* t[] = {"Fiat", "Peugeot", "Ford", "Volvo", "Lancia", "Jeep"};
    const char** pt[] = {t, t + 1, t + 2, t + 3, t + 4, t + 5};

    printf("1) %d\n", *pt - pt[3]); // -3
    printf("2) %s\n", *pt[2]);      // "Ford"
    printf("3) %d (char : %c)\n", **(*pt+5) - 2, **(*pt+5) - 2);    // 72
    printf("4) %s\n", *t+2);        // "at"
    printf("5) %c\n", pt[++pt[3]-*(pt+3)][1][2]);   // 'u'
    //      1)  *pt = t
    //          pt[3] = t + 3
    //          t - (t + 3) = -3
    //      2)  pt[2] = t + 2
    //          *(t + 2) = "Ford"
    //      3)  *pt = t
    //          t + 5 => &"Jeep"
    //          **&"Jeep" = J
    //          'J' - 2 => Conversion, so numeric value of 'H' = 72
    //      4)  *t = "Fiat"
    //          "Fiat" + 2 => "at"
    //      5)  pt[3] = t + 3
    //          ++(t+3) = t + 4     Leading to change the pointer in pt[3]
    //          *(pt + 3) = t + 4
    //          t + 4 - (t + 4) = 0
    //          pt[0] = t => t[1] = "Peugeot" => "Peugeot"[2] = 'u'
    printf("%s", "Exo 2b) -----------------------------\n");
    char argv[6][20];
    int argc = sscanf("myprog -opt1=10 test.dat 20 -opt2=src", "%s %s %s %s %s",
                   argv[0], argv[1], argv[2], argv[3], argv[4]);
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; ++i)
        printf("argv[%d] : %s\n", i, argv[i]);
}

// 3b)
double imc_sscanf(const char* s) {
    double poids, taille;
    sscanf(s, "%lf%lf", &poids, &taille);
    return poids / (taille * taille);
}
double imc_strtod(const char* s) {
    char* end;
    const double
            POIDS = strtod(s, &end),
            TAILLE = strtod(end, NULL);
    return POIDS / (TAILLE * TAILLE);
}

void exo3(void) {
    {
        printf("%s", "Exo 3a) -----------------------------\n");
        typedef struct {
            unsigned char a;
            uint16_t b;
            uint8_t c;
            size_t d;
            signed char e[2];
            uintptr_t f;
        } S;
// 32b :
/*
 * unsigned char a;     8b
 * uint16_t b;          16b + 8b padding
 * uint8_t c;           8b
 * size_t d;            32b + 24b padding
 * signed char e[2];    2 * 8b
 * uintptr_t f;         32b + 16b padding
 *                      Total : 32 * 5 = 160b = 20 octets
 */
// 64b :
/*
 * unsigned char a;     8b
 * uint16_t b;          16b + 8b padding
 * uint8_t c;           8b
 * size_t d;            64b + 24b padding
 * signed char e[2];    2 * 8b
 * uintptr_t f;         64b + 48b padding
 *                      Total : 64 * 4 = 256b = 32 octets
 */
        printf("Struct size : %zu[o]\n", sizeof(S));
    }
    {
        printf("%s", "Exo 3b) -----------------------------\n");
        const char* const POIDS_ET_TAILLE[] = {"95 1.81", // 98 = poids[kg]
                                                          // 1.81 = taille[m]
                                               "48.5 1.69",
                                               "103 1.9"};
        const size_t NB_ELEM = sizeof(POIDS_ET_TAILLE) / sizeof(char*);
        for (size_t i = 0; i < NB_ELEM; ++i)
            printf("imc[%" PRIuMAX "] = %.3g\n", i, imc_sscanf(POIDS_ET_TAILLE[i]));
    }
}

// 4b)
void inserer(char* to, const char* from, const size_t pos) {
    if (to && from) {                               // 1) (to && from && *from)
        const size_t STRLEN_TO = strlen(to);
        if (pos < STRLEN_TO) {                      // 2) (pos <= STRLEN_TO)
            if (pos == STRLEN_TO) {                 // Otherwise, never come here
                strcat(to, from);
            } else {
                char res[STRLEN_TO + strlen(from)]; // 3) [... + 1];
                if (pos == 0) {
                    strcpy(res, from);
                    strcat(res, to);
                } else {
                    strncpy(res, to, pos);
                    res[pos + 1] = '\0';            // 4) res[pos]
                    strcat(res, from);
                    strcat(res, to);                // 5) strcat(res, to + pos);
                }
                strcat(to, res);                    // 6) strcpy(to, res);
            }
        }
    }
}

void exo4(void) {
    {
        printf("%s", "Exo 4a) -----------------------------\n");
        char chaine1[] = "XXXXX";   // With implicite '\0' at the end
        char chaine2[5];
        const char* chaine3 = "ABC";
        strcpy(chaine2, chaine1);
        // After: chaine2 = "XXXXX", but chaine1 = "\0XXXX\0"
        strncpy(chaine2, chaine3, strlen(chaine2));
        // Before: strlen chaine2 = 5
        // After chaine2 = "ABC\0\0" and so strlen chaine2 = 3
        printf("%s\n", strncpy(chaine1 + 1, chaine3, strlen(chaine2)));
        // chaine1 = "\0ABCX\0"
        // chaine1 + 1, so return and display "ABCX"

        printf("%s", "Exo 4b) -----------------------------\n");
        printf("Total errors : 6\n");
    }
}

void exo5(void) {
    printf("%s", "Exo 5) ------------------------------\n");
    typedef enum { COMBAT, EXPLORATION } TYPE_VAISSEAU;
    #define MAX_EQUIPAGE 5

    typedef struct {
        const char* nom;
    } membre_str;

    typedef struct {
        size_t nbrMembres;
        membre_str equipage[MAX_EQUIPAGE];
    } equipage_str;

    typedef struct {
        unsigned poids; // en [kg]
        bool canons;
    } combat_str;

    typedef struct {
        double rayonDAction; // en milliard [km]
    } exploration_str;

    typedef union {
        combat_str combat;
        exploration_str exploration;
    } specsVaisseau_u;

    typedef struct {
        const char* nom;
        equipage_str equipage;
        TYPE_VAISSEAU tagVaisseau;
        specsVaisseau_u specsVaisseau;
    } vaisseau_str;
    #undef MAX_EQUIPAGE

    const vaisseau_str StarFighter = {"StarFighter", {2, {{"Joe"}, {"Jack"}}},
                                      COMBAT, {{2500, true}}};
    const vaisseau_str XWing = {"X-Wing", {0, {}}, EXPLORATION,
                                {.exploration = {63.2}}};
}

int main(void) {
    exo1(); ENDL();
    exo2(); ENDL();
    exo3(); ENDL();
    exo4(); ENDL();
    exo5(); ENDL();
    return EXIT_SUCCESS;
}
