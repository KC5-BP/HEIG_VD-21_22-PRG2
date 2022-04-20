/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.21-MatrixInit.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.21
                     Ecrire une fonction C sans valeur de retour (void) qui
                     initialise une matrice m x n de int avec des 1 sur les 4
                     "bords" et des 0 partout ailleurs.
                     Ecrire aussi un petit programme de test permettant de
                     vérifier le bon fonctionnement de votre fonction.

                               / 1 1 1 \
                     M(3x3) = |  1 0 1  |
                               \ 1 1 1 /

                               / 1 1 1 1 \
                              |  1 0 0 1  |
                     M(4x4) = |  1 0 0 1  |
                               \ 1 1 1 1 /

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short ushort;

void initialiser_1(int* adr, size_t m, size_t n);
void initialiser_2(int* adr, size_t m, size_t n);
void initialiser_3(int* adr, size_t m, size_t n);
void afficher(const int* adr, size_t m, size_t n);

int main(void) {
    int t1[3][3];
    int t2[3][3];
    int t3[3][3];
    int t4[3][4];
    int t5[3][4];
    int t6[3][4];
    

    initialiser_1((int*) t1, 3, 3);  // ou t1[0] ou &t1[0][0]
    initialiser_2((int*) t2, 3, 3);
    initialiser_3((int*) t3, 3, 3);
    initialiser_1((int*) t4, 3, 4);
    initialiser_2((int*) t5, 3, 4);
    initialiser_3((int*) t6, 3, 4);

    afficher((int*) t1, 3, 3);
    afficher((int*) t2, 3, 3);
    afficher((int*) t3, 3, 3);
    afficher((int*) t4, 3, 4);
    afficher((int*) t5, 3, 4);
    afficher((int*) t6, 3, 4);

    return EXIT_SUCCESS;
}

void initialiser_1(int* adr, size_t m, size_t n) {  // Approche peu efficace
    assert(adr != NULL);
    assert(m > 0);
    assert(n > 0);
    for (size_t i = 0; i < m; ++i)
        for (size_t j = 0; j < n; ++j)
            *adr++ = i == 0 || i == m - 1 || j == 0 || j == n - 1;
            // Autres variantes possibles :
            // *(adr + i * n + j) = i == 0 || i == m - 1 || j == 0 || j == n - 1;
            // adr[i * n + j] = i == 0 || i == m - 1 || j == 0 || j == n - 1;
}

void initialiser_2(int* adr, size_t m, size_t n) {  // Approche plus efficace
    assert(adr != NULL);
    assert(m > 0);
    assert(n > 0);
    // Mettre tous les éléments à 0
    memset(adr, 0, m * n * sizeof(int));
    // Mettre les "bords" sup et inf à 1
    for (size_t j = 0; j < n; ++j)
        adr[j] = adr[n * (m - 1) + j] = 1;
    // Mettre les "bords" gauche et droit à 1
    for (size_t i = 1; i < n - 1; ++i)
        adr[n * i] = adr[n * i + n - 1] = 1;
}

// L'avantage de l'approche ci-dessous est de pouvoir réutiliser [i][j]
void initialiser_3(int* adr, size_t m, size_t n) {
    assert(adr != NULL);
    assert(m > 0);
    assert(n > 0);
    // tableau de pointeurs sur les lignes de la matrice
    int** ad = (int**) calloc(m, sizeof(int*));
    assert(ad != NULL);
    for (size_t i = 0; i < m; ++i)
        ad[i] = &adr[i * n];    // ou adr + i * n car rappel :
                                // *(adr + i * n) = adr[i * n]
                                // => &adr[i * n] = adr + i * n
    // Mettre tous les éléments à 0
    memset(adr, 0, m * n * sizeof(int));
    // Mettre les "bords" sup et inf à 1
    for (size_t j = 0; j < n; ++j)
        ad[0][j] = ad[m - 1][j] = 1;
    // Mettre les "bords" gauche et droit à 1
    for (size_t i = 1; i < m - 1; ++i)
        ad[i][0] = ad[i][n - 1] = 1;
    // Restituer la mémoire allouée dynamiquement
    free(ad);
}

void afficher(const int* adr, size_t m, size_t n) {
    assert(adr != NULL);
    printf("[");
    for (size_t i = 0; i < m; ++i) {
        if (i > 0)
            printf("%s", ", ");
        printf("[");
        for (size_t j = 0; j < n; ++j) {
            if (j > 0)
                printf("%s", ", ");
            printf("%d", *adr++);
        }
        printf("]");
    }
    printf("]\n");
}

// Output :
//[[1, 1, 1], [1, 0, 1], [1, 1, 1]]
//[[1, 1, 1], [1, 0, 1], [1, 1, 1]]
//[[1, 1, 1], [1, 0, 1], [1, 1, 1]]
//[[1, 1, 1, 1], [1, 0, 0, 1], [1, 1, 1, 1]]
//[[1, 1, 1, 1], [1, 0, 0, 1], [1, 1, 1, 1]]
//[[1, 1, 1, 1], [1, 0, 0, 1], [1, 1, 1, 1]]
