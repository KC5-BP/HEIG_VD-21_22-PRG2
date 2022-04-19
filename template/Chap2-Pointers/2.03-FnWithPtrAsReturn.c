/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.03-FnWithPtrAsReturn.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.03
                     Que va produire a l'execution le programme ci dessous

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int *carres(const int tab[]);

int main() {
    int tab[] = {1, 2, 3};
    const size_t N = sizeof(tab) / sizeof(int);
    int *ptr = carres(tab);

    for (size_t i = 0; i < N; ++i)
        printf("%d ", ptr[i]);

    printf("\n");
    return EXIT_SUCCESS;
}

int *carres(const int tab[]) {
    const size_t N = sizeof(tab) / sizeof(int);
    int copie[N];

    for (size_t i = 0; i < N; ++i)
        copie[i] = tab[i] * tab[i];

    return copie;
}
