/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 4.02-strcpy.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 4.02
                    Proposez une implémentation de la fonction strcpy dont le
                    prototype et la sémantique sont donnés ci-dessous :
char* strcpy(char* to, const char* from);

                    Semantique :
                        Recopie la chaîne from dans la chaîne to et
                        retourne un pointeur sur to.

                    Ecrire aussi un petit programme permettant de tester votre
                    fonction.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define PRINT(STR) printf(#STR " = %s\n", STR)

char* strcpy(char* to, const char* from);

int main(void) {
    char s1[10];
    char* s2;
    const char* s3;

    s2 = strcpy(s1, "");
    PRINT(s1);
    PRINT(s2);

    strcpy(s1, "ABC");
    PRINT(s1);
    PRINT(s2);

    s3 = "DEF";
    strcpy(s1, s3);
    PRINT(s1);

    strcpy(s1, strcpy(s1, "ABC"));
    PRINT(s1);

    //char* msg = "ABC";
    //strcpy(msg, "");    // Provoquerait un crash à l'exécution, car msg pointe
                        // sur la chaîne constante ("ABC"), donc non modifiable
	return EXIT_SUCCESS;
}

char* strcpy(char* to, const char* from) {
    char* tmp = to;
    while ((*to++ = *from++) != '\0');
    return tmp;
}

// Output :
//s1 =
//s2 =
//s1 = ABC
//s2 = ABC
//s1 = DEF
//s1 = ABC
