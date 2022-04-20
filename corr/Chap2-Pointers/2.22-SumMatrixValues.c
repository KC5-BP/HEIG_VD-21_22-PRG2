/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.22-SumMatrixValues.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.22
                     Ecrire une fonction C qui renvoie la somme des coefficients
                     de la matrice m x n de double passée en paramètre.

                     Ecrire aussi un petit programme de test permettant de
                     vérifier le bon fonctionnement de votre fonction sur la
                     matrice 3 x 4 suivante :
                          / 1 2 3 \
                     M = |  4 5 6  |
                          \ 7 8 9 /

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double somme_1(const double* adr, size_t m, size_t n);
double somme_2(const double* adr, size_t m, size_t n);
double somme_3(const double* adr, size_t m, size_t n);
double somme_4(const double* adr, size_t taille);

int main(void) {
    #define NB_LIGNES 3
    #define NB_COLONNES 4

    const double M[NB_LIGNES][NB_COLONNES] = {{1,   2.5, 3,   4},
                                              {5,   6,   7.5, 8},
                                              {9.5, 10,  11,  12}};

    printf("Somme 1a = %g\n", somme_1((double*) M, NB_LIGNES, NB_COLONNES));
    printf("Somme 1b = %g\n", somme_1(M[0], NB_LIGNES, NB_COLONNES));
    printf("Somme 1c = %g\n", somme_1(&M[0][0], NB_LIGNES, NB_COLONNES));
    printf("Somme 2 = %g\n", somme_2((double*) M, NB_LIGNES, NB_COLONNES));
    printf("Somme 3 = %g\n", somme_3((double*) M, NB_LIGNES, NB_COLONNES));
    printf("Somme 4 = %g\n", somme_4((double*) M, NB_LIGNES * NB_COLONNES));

    return EXIT_SUCCESS;
}

double somme_1(const double* adr, size_t m, size_t n) {
    assert(adr != NULL);
    double somme = 0.0;
    for (size_t i = 0; i < m; ++i)
        for (size_t j = 0; j < n; ++j)
            somme += *(adr + i * n + j);    // OR adr[i * n + j]
    return somme;
}

double somme_2(const double* adr, size_t m, size_t n) {
    assert(adr != NULL);
    double** ad = (double**) calloc(m, sizeof(double*));
    assert(ad != NULL); // assert car sinon que renvoyer en retour ?
    for (size_t i = 0; i < m; ++i)
        ad[i] = (double*) (adr + i * n);
    double somme = 0.0;
    for (size_t i = 0; i < m; ++i)
        for (size_t j = 0; j < n; ++j)
            somme += ad[i][j];
    free(ad);
    return somme;
}

double somme_3(const double* adr, size_t m, size_t n) {
    assert(adr != NULL);
    double somme = 0.0;
    for (size_t i = 0; i < m * n; ++i)
        somme += adr[i];  // OR *(adr + i) OR *adr++
    return somme;
}

double somme_4(const double* adr, size_t taille) {
    assert(adr != NULL);
    double somme = 0.0;
    for (size_t i = 0; i < taille; ++i)
        somme += adr[i];
    return somme;
}

// Output :
//Somme 1a = 79.5
//Somme 1b = 79.5
//Somme 1c = 79.5
//Somme 2 = 79.5
//Somme 3 = 79.5
//Somme 4 = 79.5
