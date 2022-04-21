/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.11-FormaPtrAndArray1D.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.11
                     Ecrire d'au moins 6 manières différentes, mais toujours en
                     utilisant le formalisme pointeur, une fonction C initialiser,
                     sans valeur de retour (void), permettant d'initialiser à une
                     valeur donnée (de type int), tous les éléments d'un tableau à
                     1 dimension (1D) de taille quelconque et composé d'entiers
                     (de type int).

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FN_DECLARATION_SELECTED 2
#define TAB_SIZE 10

void initialiser(int* tab, unsigned int tabSize, int initValue);
void printArray(int* tab, unsigned int tabSize);

int main(void) {
    //int tab[TAB_SIZE];    // Don't work with memset without : = {};
    int tab[TAB_SIZE] = {};

    initialiser(tab, TAB_SIZE, 0);
    printArray(tab, TAB_SIZE);

    return EXIT_SUCCESS;
}

#if FN_DECLARATION_SELECTED < 1
    void initialiser(int* tab, unsigned int tabSize, int initValue) {
        assert(tab != NULL && tabSize > 0);
        for (unsigned int i = 0; i < tabSize; ++i)
            tab[i] = initValue;
    }

#elif FN_DECLARATION_SELECTED == 1
    void initialiser(int* tab, unsigned int tabSize, int initValue) {
        assert(tab != NULL && tabSize > 0);
        for (int* p = tab + tabSize - 1; p > &tab[-1]; --p)
            *p = initValue;
    }

#elif FN_DECLARATION_SELECTED == 2
#include <string.h>
    void initialiser(int* tab, unsigned int tabSize, int initValue) {
        assert(tab != NULL && tabSize > 0);
        for(int* ptr = tab; ptr != tab + tabSize; ++ptr)
            memcpy(ptr, &initValue, sizeof(initValue));
    }

#elif FN_DECLARATION_SELECTED == 3
    void initialiser(int* tab, unsigned int tabSize, int initValue) {
        assert(tab != NULL && tabSize > 0);
    }

#elif FN_DECLARATION_SELECTED == 4
    void initialiser(int* tab, unsigned int tabSize, int initValue) {
        assert(tab != NULL && tabSize > 0);
    }

#elif FN_DECLARATION_SELECTED > 4
    void initialiser(int* tab, unsigned int tabSize, int initValue) {
        assert(tab != NULL && tabSize > 0);
    }

#endif

void printArray(int* tab, unsigned int tabSize) {
    for (unsigned int i = 0; i < tabSize; ++i) {
        if (i) printf(", ");
        printf("%d", tab[i]);
    }
}
