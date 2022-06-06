/*
 -----------------------------------------------------------------------------------
 Nom du fichier : <nom du fichier>.<x> (x = h ou c)
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : <� compl�ter>

 Remarque(s)    : TE3 in the name, but equivalent to TE2 in PRG2
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
    printf("%s", "Exo 1) ------------------------------\n");
    {   // 1)
        char chaine[3] = "ABC"; // Wrong, needed chaine[4]
    }
    {   // 2)
        char chaine[10];
        //chaine = "ABC";   // Wrong, chaine is a cst ptr!
                            // chaine[0] = 'A', chaine[1] = 'B',
    }                       // chaine[2] = 'C' to be correct
    {   // 3)
        const char* chaine1;
        char chaine2[] = "ABC";
        chaine1 = chaine2;  // Correct, chaine1 is a cst ptr
    }                       // and not a ptr on cst
    {   // 4)
        typedef char string[];  // Correct, it will be a : char[]
    }
    {   // 5)
        /*
        struct S {
            int n = 1;
            double x = 2.5; // Wrong, can't initialize value
                            // inside struct declaration
        } s;
         */
    }
    {   // 6)
        typedef struct {
            const int N;    // Correct, const must be
            double x;       // initialize at var. creation.
        } S;
        S s = {1, 2.5};
    }
    {   // 7)
        /*
        struct S {
            int N;
            double x;
        };
        struct S s;
        s = (S) {1, 2.5};   // Wrong, Missing struct in init.
         */
    }
    {   // 8)
        struct S {
            int n;
            double x;       // Correct
        };
        struct S s1 = {1, 2.5};
        struct S s2 = s1;
    }
    {   // 9)
        struct S {
            int n;          // Wrong, can't compare struct's
            double x;
        };
        struct S s1 = {1, 2.5};
        struct S s2 = {1, 2.5};
        //printf("s1 == s2 ? %s\n", (s1 == s2 ? "oui" : "non"));
    }
    {   // 10)
        struct S {          // Correct, but careful, A starts at 0, so B = 1
            enum {A, B, C = 0} e;
        } s;
        s.e = A;
        printf("%d\n", s.e);
    }
    {   // 11)
        struct S1 {         // Correct because it's a pointer
            struct S2* a;   // But it will be Wrong if it missed
        };                  // the keyword struct
        struct S2 {
            struct S1* a;
        };
    }
    {   // 12)
        union U {
            int n;
            double x;       // Wrong, because without specifier, it's the first
        };                  // var. that is initialized.
        union U u = {1.5};
        //union U u = {.x = 1.5};   // To be correct
        printf("u = %f\n", u.x);
    }
}

// 2b)
void __2b(void) {
    int t[] = {3, 6, 9};
    int* p;
    for (int i = 0; i < 3; ++i) {
        p = &t[i];  // Hard way to obtain : (t + i)
        while (p < &t[3])   // Loop from the following index of t + i
            *p++ += *(t+i); // and add the value @ t + i
        for (int i = 0; i < 3; ++i) // Display all values each times
            printf("%d ", t[i]);
        printf("\n");
    }
}

void exo2(void) {
    printf("%s", "Exo 2a) -----------------------------\n");
    const char* t[] = {"matrice", ":", "tableau", "a", "2", "entrees"};
    const char** pt[] = {t + 6, t, t + 3, t + 1, t + 2, t + 4, t + 5};

    printf("1) %d\n", *pt - pt[3]); // 5
    printf("2) %s\n", *pt[2]);      // "a"
    printf("3) %d (char : %c)\n", **(*pt-3) + 2, **(*pt-3) + 2);    // 99
    printf("4) %s\n", t[0]+2);      // "trice"
    printf("5) %d (char : %1$c)\n", *pt[++pt[2]-*(pt+4) - 1][2] - 1);   // 115
    //      1)  *pt = t + 6
    //          pt[3] = t + 1
    //          t + 6 - (t + 1) = 5
    //      2)  pt[2] = t + 3
    //          *(t + 3) = "a"
    //      3)  *pt = t + 6
    //          t + 6 - 3 => &"a"
    //          **&"a" = 'a'
    //          'a' + 2 => Conversion, so numeric value of 'c' = 99
    //      4)  *t = t[0] = "matrice"
    //          "matrice" + 2 => "trice"
    //      5)  pt[2] = t + 3
    //          ++(t+3) = t + 4     Leading to change the pointer in pt[2]
    //          *(pt + 4) = t + 2
    //          t + 4 - (t + 2) - 1 = 1
    //          pt[1] = t => t[2] = "tableau" => *"tableau" = 't'
    //          't' - 1 = numeric value of 's' = 115
    printf("%s", "Exo 2b) -----------------------------\n");
    __2b();
    // 6 12 15
    // 6 24 39
    // 6 24 78
}

// 3)
int** matriceTriangleInferieur(const int* matrice, size_t n) {
    int** resultat = /*TODO*/ (int**) calloc(n, sizeof(int*));
    if (resultat) {
        for (size_t i = 0; i < n; ++i) {
            resultat[i] = /*TODO*/ (int*) calloc(i + 1, sizeof(int));
            if (resultat[i]) {
                /*TODO*/ memcpy(resultat[i], matrice + i * n, (i + 1) * sizeof(int));
            } else {
                /*TODO*/
                for (i += 1; i > 0; --i)
                    free(resultat[i - 1]);
                free(resultat);
                resultat = NULL;
                break;
            }
        }
    }
    return resultat;
}

void exo3(void) {
    printf("%s", "Exo 3) ------------------------------\n");
    printf("%s", "Matrice\n");
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j)  printf(", ");
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    int** lowerTri = matriceTriangleInferieur(*matrix, 3);
    if (lowerTri) {
        printf("%s", "Lower Triangle\n");
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                if (j) printf(", ");
                printf("%d", lowerTri[i][j]);
            }
            printf("\n");
        }
        for (int i = 3; i > 0; --i)
            free(lowerTri[i - 1]);
        free(lowerTri);
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

// 4)
typedef int Info;
typedef struct element {
    Info info;
    struct element* suivant;
} Element;
typedef Element* Liste;

bool insererEnQueue(Liste *liste, const Info *info) {
    // Alloue la taille nécessaire à un nouvel élément
    Element *nouveau = (Element*) calloc(1, sizeof(Element));
    if (liste && info && nouveau) {
        // Si calloc memoire ok + adresses fournies valides
        if ( !*liste) { // Liste vide
            // Premier nouvel objet repointant sur le début alors lui-même
            *nouveau = (Element) {*info, nouveau};
            *liste = nouveau;   // Accroche le premier élément au pointeur liste
        } else {        // Liste pas vide
            // Recherche du dernier élément pointant sur le début
            Element* last = *liste;
            while (last->suivant != *liste)
                last = last->suivant;
            // Nouvel objet repointant sur le début du buffer circulaire
            *nouveau = (Element) {*info, *liste};
            // Dernier élément pointe sur le nouvel élément créé
            last->suivant = nouveau;
        }
        return true;
    }
    // Si calloc mémoire pas ok
    free(nouveau);
    return false;
}
void afficherListe(const Liste* liste) {
    printf("[");
    for (Element* p = *liste; p; p = p->suivant) {
        printf("%d", p->info);
        if (p->suivant != *liste)
            printf(", ");
        else
            break;
    }
    printf("]\n");
}

void libereListe(Liste* liste) {
    if (!*liste)    return;
    if ((*liste)->suivant == *liste) {  // Un unique élément
        free(*liste);
        *liste = NULL;
    } else {
        Element* saved = *liste;
        for (Element* p = saved; p; p = (saved == *liste ? NULL : saved)) {
            saved = saved->suivant;
            free(p);
        }
    }
}

void exo4(void) {
    printf("%s", "Exo 4) ------------------------------\n");
    Liste l = NULL;
    for (Info info = 5; info < 10; ++info)
        insererEnQueue(&l, &info);
    afficherListe(&l);
    libereListe(&l);
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
