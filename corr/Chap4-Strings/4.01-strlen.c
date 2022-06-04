/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 4.01-strlen.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 4.01
                    Proposez une implémentation de la fonction strlen dont le
                    prototype et la sémantique sont donnés ci-dessous :
size_t strlen(const char* s);

                    Semantique :
                        Renvoie le nombre de caractères de la chaîne s
                        (le '\0' final n'est pas comptabilisé)

                    Ecrire aussi un petit programme permettant de tester votre
                    fonction.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define PRINT(STR, LEN) printf(#STR " = %s and its length is : %zu\n", STR, LEN)

size_t strlen(const char* s);

int main(void) {
    {
        const char* str = "";
        PRINT(str, strlen(str));
    }
    {
        const char* str = "1";
        PRINT(str, strlen(str));
    }
    {
        const char* str = "AB";
        PRINT(str, strlen(str));
    }
    {
        const char* str = "1234567890";
        PRINT(str, strlen(str));
    }
    return EXIT_SUCCESS;
}

size_t strlen(const char* s) {
    const char* p = s;
    while (*p) ++p;
    return (size_t) (p - s);
}

// Output :
//str =  and its length is : 0
//str = 1 and its length is : 1
//str = AB and its length is : 2
//str = 1234567890 and its length is : 10
