/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 3.05-StructSize.c
 Auteur(s)      : (\_/)
 Date creation  : <j .mm.aaaa>

 Description    : 3.05
                    a) Soit la structure S1 suivante : (Voir code ci-dessous)
                        Quelle est la taille en bytes de S1
                            1) en architecture 32 bits ?
                            2) en architecture 64 bits ?

                    b) Soit la structure S2 suivante : (Voir code ci-dessous)
                        Quelle est la taille en bytes de S2
                            1) en architecture 32 bits ?
                            2) en architecture 64 bits ?

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

struct S1 {
    int* ptr;
    int32_t a;
    int64_t b;
};

struct S2 {
    int8_t a;
    int16_t b;
    char c;
    double* ptr;
};

int main(void) {
	return EXIT_SUCCESS;
}
