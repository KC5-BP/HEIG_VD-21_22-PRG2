/*
 -----------------------------------------------------------------------------------
 Nom du fichier : <nom du fichier>.<x> (x = h ou c)
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : <� compl�ter>

 Remarque(s)    : Exo 1c + 3 to be made on paper and scanned.
                  Reference card : https://users.ece.utexas.edu/~adnan/c-refcard.pdf

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

#define ENDL(void) printf("\n")

// 1B)
// Process :    Inject to the right, the invert value of the lost MSB
//              after the shift.
//              Ex. :   0101 .. 0110 << 1 => 101x .. 110y
//                      Lost MSB : 0, so y will be 1 => 101x .. 1101
//                      101x .. 1101 << 1 => 01xx .. 101y
//                      Lost MSB : 1, so y will be 0 => 01xx .. 1010
//                      And so on ..
uint16_t f(uint16_t a, uint8_t b) {
    const uint16_t MASK = 0x8000;
    while (b--)
        a = (uint16_t) (a << 1) | ((a & MASK) != MASK);
    return a;
}

void exo1(void) {
    {
        printf("%s", "Exo 1a) -----------------------------\n");
        #define double(d) d + d
        int n1 = -3;
        printf("%d\n", double(-3 == n1));
        // Replace by : -3 == n1 + -3 == n1 where n1 is : -3 == -3 + -3 == -3
        //              -3 == (-3 + -3) == -3 => -3 == -6 == -3
        //              (-3 == -6) == -3 => 0 == -3 => 0
        // Due to operation priority, see reference card.
        #undef double

        #define CARRE(X) X * X
        int n2 = 3;
        printf("%d\n", CARRE(n2 - 1));
        // Replace by : n2 - 1 * n2 - 1 =where n2 is : 3 - 1 * 3 - 1
        //              0 - 1 => (-1)
        #undef CARRE

        #define N 2
        #define STR(X)  #X
        #define F(N)  STR(Fichier_##N)
        int n = 3;
        printf("%s\n", F(n));
        // Replace by : STR(Fichier_##n) => STR(Fichier_n)
        //              => #Fichier_n => "Fichier_n"
        #undef F
        #undef STR
        #undef N
    }
    {
        printf("%s", "Exo 1b) -----------------------------\n");
        printf("%#x\n", f(0x1234, 5));
        // After 5 iterations => 0x469d
    }
    {
        printf("%s", "Exo 1c) -----------------------------\n");
        #define PRINT_ADDRESS(ADR) printf("0x%" PRIxPTR "\n", (intptr_t) (ADR))
        int64_t m[][4] = {{1},
                          {0, 1},
                          {0, 0, 1},
                          {0, 0, 0, 1}};
        PRINT_ADDRESS(m);
        PRINT_ADDRESS(*(m + 2) + (&m[2][-1] - 3[m]));
        // Answer must be 0x18 away from origin (m in this case)
        #undef PRINT_ADDRESS
    }
}

void exo2(void) {
    printf("%s", "Exo 2) ------------------------------\n");
    printf("1) |%.5d|\n", 230);         // 1) |00123|
    printf("2) |%-#5X|\n", 230);        // 2) |0XE6 |
    printf("3) |%f|\n", 12.345);        // 3) |12.345000|
    printf("4) |%#.f|\n", 12.345);      // 4) |12.|
    printf("5) |%2g|\n", 12.345);       // 5) |12.345|
    printf("6) |%+5.1f|\n", 0.157);     // 6) | +0.2|
    printf("7) |%*.*E|\n", 8, 1, 0.01); // 7) | 1.0E-02|
    printf("8) |%G|\n", 1e-4);          // 8) |0.0001|
    printf("9) |%06.4g|\n", 123.456);   // 9) |0123.5|
    #define TAILLE_MAX 50
    char chaine[TAILLE_MAX + 1];
    printf("Entrez une chaine de caracteres (%u caract max) > "
           "\" (089) 123-45-67 : Paul\"\n", TAILLE_MAX);
    //scanf("%*[ ]%[(0123456789)]", chaine);
    sscanf(" (089) 123-45-67 : Paul", "%*[ ]%[(0123456789)]", chaine);
    printf("10) |%s|\n", chaine);       // 10) |(089))
    #undef TAILLE_MAX
}

void exo3(void) {
    {
        printf("%s", "Exo 3a) -----------------------------\n");
        int t[] = {1, 2, 3, 5, 8, 13};
        int* tp[] = {t, t + 1, t + 2, t + 3, t + 4, t + 5};
        int** pp = tp + 3;

        printf("1) %d\n", --**pp);          // 4
        printf("2) %d\n", pp[1][-1]);       // 4
        printf("3) %d\n", (*pp++)[1]);      // 8
        printf("4) %d\n", ++**pp--);        // 9
        printf("5) %d\n", *++pp - *tp + 1); // 5
        //      1)  *pp = tp[3] = t + 3
        //          *(t + 3) <=> t[3] = 5
        //          --t[3] = 4
        //      2)  pp[1] = tp[4] = t + 4
        //          (t + 4)[-1] <=> t[3] = 4
        //          Due to previous --t[3] in 1)
        //      3)  *pp = tp[3] = t + 3
        //          (t + 3)++ <=> t + 4 : Leading to change the pointer in tp[3]
        //          But post-increase, so : (t + 3)[1] = 8
        //      4)  pp = tp + 4
        //          pp-- => tp + 3 => Return tp + 4
        //          *(tp+4) <=> tp[4] = t + 4
        //          *(t+4) <=> t[4] = 8
        //          ++8 = 9
        //      5)  ++pp = tp + 4
        //          *(tp + 4) = tp[4] = t + 4
        //          t + 4 - *tp + 1 <=> t + 4 - t + 1 = 5
        //
        // Remark(s) : *pp-- => Firstly pp-- AND THEN *pp
    }
    {
        printf("%s", "Exo 3b) -----------------------------\n");
        char* t[] = {"Mars", "Avril", "Mai"};
        char** tp[] = {t, t + 1, t + 2};
        char** pp = (char**) t;

        printf("1) %s\n", ++t[0]);          // "ars"
        printf("2) %c\n", **(tp[1] - 1));   // 'a' of Mars
        printf("3) %c\n", *++*++pp);        // 'v'
        printf("4) %d (char : %c)\n", **tp[2] + 1, **tp[2] + 1);// 78 ('N') of Mai
        printf("5) %c\n", pp[0][1]);        // 'r' of Avril
        //      1)  t[0] = "Mars"
        //          ++"Mars" = "ars"
        //      2)  tp[1] = t + 1
        //          *(t + 1) = "ars" : Due to previous ++"Mars"
        //          *"ars" = 'a'
        //      3)  ++pp => t + 1
        //          *(t + 1) = "Avril"
        //          ++"Avril" = "vril"
        //          *"vril" = 'v'
        //      4)  tp[2] = t + 2
        //          *(t + 2) = "Mai"
        //          **(t + 2) = 'M'
        //          'M' + 1 => Conversion, so numeric value of 'N' = 78
        //      5)  pp[0] = t[1] = "vril" : Due to previous ++"Avril" in 3)
        //          "vril"[1] = 'r'
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
        printf("%s", "Exo 4a) -----------------------------\n");
        char* const (* a(void))[3];
        // ENG :
        // FR  :
        // Developpement :  3) :   (* a(void)) est un tableau de 3 pointeurs
        //                          constant sur char
        //                  1) :    * a(void) est un tableau de 3 pointeurs
        //                          constant sur char
        //                  4) :    a est une fonction sans paramètre retournant
        //                          un pointeur sur un tableau de 3 pointeurs
        //                          constants sur char.
        printf("%s", "char* const (* a(void))[3];\n");
        printf("Est une fonction sans paramètre retournant\n"
               "un pointeur sur un tableau de 3 pointeurs\n"
               "constants sur char\n\n");

        const int* (* b)(void* (*)[3]);
        // ENG :
        // FR  :
        // Developpement :  /) :    (* b)(void* (*)[3]) est un pointeur sur int
        //                          constant
        //                  4) :    (* b) est une fonction prenant un
        //                          "void* (*)[3]" et retournant un pointeur sur
        //                          int constant
        //                  1) :    * b est une fonction prenant un
        //                          "void* (*)[3]" et retournant un pointeur sur
        //                          int constant
        //                  2) :    b est un pointeur sur fonction prenant un
        //                          "void* (*)[3]" et retournant un pointeur sur
        //                          int constant
        //                  3) :    (*) est un tableau de 3 pointeurs sur void
        //                  1) :    * est un tableau de 3 pointeurs sur void
        //                  2) :    est un pointeur sur tableau de 3 pointeurs
        //                          sur void
        //                  /)      b est un pointeur sur fonction prenant en
        //                          paramètre un pointeur sur un tableau de 3
        //                          pointeurs sur void et retournant un pointeur
        //                          sur int constant
        printf("%s", "const int* (* b)(void* (*)[3]);\n");
        printf("Est un pointeur sur fonction prenant en\n"
               "paramètre un pointeur sur un tableau de 3\n"
               "pointeurs sur void et retournant un pointeur\n"
               "sur int constant\n\n");
    }
    {
/*
 * 1) Pointer     / Pointeurs
 * 2) Array       / Tableau
 * 3) Function    / Fonction
 */
        printf("%s", "Exo 4b) -----------------------------\n");
        printf("f est une fonction prenant en parametre un pointeur constant\n"
               "sur char et livrant un pointeur sur un tableau de 3 pointeurs sur\n"
               "double = ");
        printf("double* (* f(char* const))[3];\n\n");
        // Rename to e to avoid conflicting with f from 1b
        double* (* e(char* const))[3];

        printf("t est un tableau de 3 pointeurs pointant chacun sur une\n"
               "fonction prenant en paramètre un pointeur sur int constant et\n"
               "livrant un pointeur sur un tableau de 10 double = ");
        printf("double (* (* t[3])(const int*))[10];\n\n");
        double (* (* t[3])(const int*))[10];
    }
}

// 5)
int** getMatrixEdges(const int* adr, size_t n, size_t m) {
    assert(adr && n && m);
    int** res = (int**) calloc(4, sizeof(int*));
    if (res) {
        res[0] = (int*) adr;
        res[1] = (int*) (adr + m - 1);
        res[2] = (int*) (adr + n * m - m);
        res[3] = (int*) (adr + n * m - 1);
    }
    return res;
}

#define PRINT_ADDRESS(ADR) printf("0x%" PRIxPTR, (intptr_t) (ADR))
void afficher(int** addresses, size_t n) {
    printf("%s", "[");
    for (size_t i = 0; i < n; ++i, (n-i) && printf(", ")) {
        PRINT_ADDRESS(addresses[i]);
    }
    printf("%s", "]");
}

void exo5(void) {
    printf("%s", "Exo 5) ------------------------------\n");
    printf("%s", "Ecrire de la maniere la plus simple et efficace possible,\n"
                 "une fonction C qui prend en parametre une matrice n(lignes) et\n"
                 "m(colonnes) de int et qui livre en retour un tableau contenant\n"
                 "les adresses des quatres elements constituant les coins de\n"
                 "la matrice.\n");
    printf("%s", "IMPORTANT : \n"
                 "- Traduire dans la fonction le fait que le(s) parametre(s) sont "
                 "supposes valides.\n"
                 "- Les adresses sont a renvoyer dans l\'ordre suivant : \n"
                 "\t\t1) Coin Superieur Gauche | 2) Coin Superieur Droit\n"
                 "\t\t3) Coin Inferieur Gauche | 4) Coin Inferieur Droit\n\n");
    #define LINES   3
    #define COLUMNS 4
    const int M[][COLUMNS] = {  { 1, 2, 3, 4},
                                { 5, 6, 7, 8},
                                { 9,10,11,12}	};
    PRINT_ADDRESS(&M[0][0]);    ENDL();
    PRINT_ADDRESS(&M[0][3]);    ENDL();
    PRINT_ADDRESS(&M[2][0]);    ENDL();
    PRINT_ADDRESS(&M[2][3]);    ENDL();

    int** edges = getMatrixEdges((int*) M, LINES, COLUMNS);
    afficher(edges, 4); ENDL();

    printf("Highest corners LEFT\t\t Highest corners RIGHT\n");
    printf("\t 0x%" PRIxPTR " : %2d %2d : 0x%" PRIxPTR "\n",
           (intptr_t) edges[0], *edges[0],
           *edges[1], (intptr_t) edges[1]);
    printf("\t 0x%" PRIxPTR " : %2d %2d : 0x%" PRIxPTR "\n",
           (intptr_t) edges[2], *edges[2],
           *edges[3], (intptr_t) edges[3]);
    printf(" Lowest corners LEFT\t\t Lowest corners RIGHT\n");
    free(edges);
    #undef LINES
    #undef COLUMNS
}
#undef PRINT_ADDRESS

int main(void) {
    exo1(); ENDL();
    exo2(); ENDL();
    exo3(); ENDL();
    exo4(); ENDL();
    exo5(); ENDL();
    return EXIT_SUCCESS;
}
