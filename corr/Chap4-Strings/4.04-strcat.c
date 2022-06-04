/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 4.04-strcat.c
 Auteur(s)      : (\_/)
 Date creation  : <j .mm.aaaa>

 Description    : 4.04
                    Proposez une implémentation de la fonction strcat dont le
                    prototype et la sémantique sont donnés ci-dessous :
char* strcat(char* to, const char* from);

                    Semantique :
                        Concatène la chaîne from à la suite de la chaîne to et
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

char* strcat(char* to, const char* from);

int main(void) {
    char to[10] = "";   // Nécessaire pour que le premier caractère de to soit '\0'.
                        // Aussi possible d'écrire {'\0'}.
    const char* from = "ABC";
    char* s;

    strcat(to, from);
    PRINT(to);

    s = strcat(to, "DEF");
    PRINT(to);
    PRINT(s);

	return EXIT_SUCCESS;
}

char* strcat(char* to, const char* from) {
    char* tmp = to;
    while (*to) to++;   // Se positionner sur '\0'
    while ((*to++ = *from++) != '\0');    // idem strcpy
    return tmp;
}

// Output :
//to = ABC
//to = ABCDEF
//s = ABCDEF
