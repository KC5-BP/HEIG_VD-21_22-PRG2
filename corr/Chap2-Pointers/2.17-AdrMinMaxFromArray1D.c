/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.17-AdrMinMaxFromArray1D.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.17
                     Ecrire une fonction C qui prend en paramètre un tableau tab
                     1D de int de taille quelconque et qui renvoie en valeur de
                     retour les adresses du plus petit élément et du plus grand
                     élément1 de tab (ou NULL si tab vaut NULL ou si tab est vide).

                     Remarque :
                        Dans le cas où il y aurait plusieurs plus petits éléments
                        on renverra l'adresse de celui dont l'indice dans tab est
                        le plus petit (idem dans le cas du plus grand élément).

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARRAY_FIXED_SIZE 6
#define ARRAY_SIZE(ARRAY, ELEMENT_TYPE) sizeof(ARRAY) / sizeof(ELEMENT_TYPE)
#define ADDRESSES_TO_RECOVER 2
#define ENDL(void)  printf("\n")

typedef enum { MIN, MAX } MINIMAX;

const int* getAddressOfFirstMinimum(const int* tab, size_t tabSize);
const int* getAddressOfFirstMaximum(const int* tab, size_t tabSize);
const int** getAddressesOfMinAndMax(const int* tab, size_t tabSize);
void test(const int* tab, size_t tabSize);

int main(void) {
    {
        printf("--- CASE : Duplicated minimum -----\n");
        test((int[]) {4, 3, 1, 2, 5, 1}, ARRAY_FIXED_SIZE);
        ENDL();
    }
    {
        printf("--- CASE : Duplicated maximum -----\n");
        test((int[]) {4, 5, 3, 2, 5, 1}, ARRAY_FIXED_SIZE);
        ENDL();
    }
    {
        printf("--- CASE : Duplicated min & max ---\n");
        test((int[]) {1, 5, 3, 2, 5, 1}, ARRAY_FIXED_SIZE);
        ENDL();
    }
    {
        printf("--- CASE : Unique element ---------\n");
        int array[1] = {1};
        test(array, ARRAY_SIZE(array, array[0]));
        ENDL();
    }
    {
        printf("--- CASE : Empty ------------------\n");
        int array[0];
        test(array, ARRAY_SIZE(array, array[0]));
        ENDL();
    }

    return EXIT_SUCCESS;
}

const int* getAddressOfFirstMinimum(const int* tab, size_t tabSize) {
    if (tab != NULL && tabSize > 0) {
        const int* addrOfTheLowest = tab;
        int minimum = *tab;
        for (size_t i = 1; i < tabSize; ++i) {
            if (tab[i] < minimum) {
                minimum = tab[i];
                addrOfTheLowest = tab + i;
            }
        }
        return addrOfTheLowest;
    }
    return NULL;
}

const int* getAddressOfFirstMaximum(const int* tab, size_t tabSize) {
    if (tab != NULL && tabSize > 0) {
        const int* addrOfTheHighest = tab;
        int maximum = *tab;
        for (size_t i = 1; i < tabSize; ++i) {
            if (tab[i] > maximum) {
                maximum = tab[i];
                addrOfTheHighest = tab + i;
            }
        }
        return addrOfTheHighest;
    }
    return NULL;
}

const int** getAddressesOfMinAndMax(const int* tab, size_t tabSize) {
    if (tab != NULL && tabSize > 0) {
        const int** addresses = (const int**) malloc(sizeof(const int*) * 2);
        assert(addresses != NULL);
        addresses[MIN] = getAddressOfFirstMinimum(tab, tabSize);
        addresses[MAX] = getAddressOfFirstMaximum(tab, tabSize);
        return addresses;
    }
    return NULL;
}

void test(const int* tab, size_t tabSize) {
    int** addressesMinMax = (int**) malloc(sizeof(int*) * ADDRESSES_TO_RECOVER);
    assert(addressesMinMax != NULL);
    addressesMinMax = (int**) getAddressesOfMinAndMax(tab, tabSize);

    printf("Array is at\t\t: %p\n", (void*) tab);
    if (addressesMinMax != NULL) {
        if (addressesMinMax[MIN] != NULL)
            printf("Lowest is at\t: %p and is equal to : %d\n",
                   (void*) addressesMinMax[MIN], *addressesMinMax[MIN]);
        if (addressesMinMax[MAX] != NULL)
            printf("Highest is at\t: %p and is equal to : %d\n",
                   (void*) addressesMinMax[MAX], *addressesMinMax[MAX]);
    }
    free(addressesMinMax);
}
