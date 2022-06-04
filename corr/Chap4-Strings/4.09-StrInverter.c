/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 4.09-StrInverter.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 4.09
                    Proposer une implémentation pour chacune des fonctions
                    d'inversion d'une chaîne suivantes :
                        1. void  inverser_1(char* s);
                        2. char* inverser_2(const char* s);

                        Nota Bene :
                            Renvoie s en cas de problème

                    Ecrire aussi un petit programme permettant de tester les
                    deux fonctions. Lister les avantages/inconvénients respectifs
                    des 2 fonctions ci-dessus.

                    Nota Bene :
                        Hormis strlen, aucune autre fonction de string.h
                        ne doit être utilisée ici.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// N.B. Ne fait rien si s vaut NULL
void inverser_1(char* s);

// N.B. Renvoie NULL si s vaut NULL ou en cas de mémoire insuffisante
char* inverser_2(const char* s);

int main(void) {
	char s1[] = "ABCD"; // Attention : inverser_1 ne fonctionnerait pas avec :
                        // const char* s1 = "ABCD"; Car "ABCD" est une chaîne cste,
                        // et donc non modifiable.
    printf("s1 avant inversion = %s\n", s1);
    inverser_1(s1);
    printf("s1 apres inversion = %s\n", s1);

    const char* s2 = "ABCD";
    char* s3 = inverser_2(s2);
    printf("\ns2 avant inversion = %s\n", s2);
    printf("inverse de s2 = %s\n", s3);
    printf("s2 apres inversion = %s\n", s2);

    free(s3);

    inverser_1(NULL);   // Ne doit pas "planter" le programme
    inverser_2(NULL);   // Idem

	return EXIT_SUCCESS;
}

void inverser_1(char* s) {
    if (s != NULL) {
        char c, *ptr = s + strlen(s) - 1;
        while (s < ptr) {
            c = *s;
            *s++ = *ptr;
            *ptr-- = c;
        }
    }
}

char* inverser_2(const char* s) {
    if (s != NULL) {
        const size_t TAILLE = strlen(s);
        char* r = (char*) calloc(TAILLE, sizeof(char));
        if (r != NULL) {
            char* ptr = r + TAILLE - 1;
            for ( ; *s; s++)
                *ptr-- = *s;
            return r;
        }
    }
    return (char*)s;
}

// Output :
//s1 avant inversion = ABCD
//s1 apres inversion = DCBA
//
//s2 avant inversion = ABCD
//inverse de s2 = DCBA
//s2 apres inversion = ABCD
