/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 4.03-strncpy.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 4.03
                    Proposez une implémentation de la fonction strncpy dont le
                    prototype et la sémantique sont donnés ci-dessous :
char* strncpy(char* to, const char* from, size_t size);

                    Semantique :
                        Recopie les size premiers caractères de la chaîne from dans
                        la chaîne to et retourne un pointeur sur to. De manière plus
                        précise :
                            • Si size <= strlen(from), size caractères sont copiés
                            dans to.
                            Attention : Aucune marque de fin de chaîne ('\0')
                            n'est copiée dans to
                            • Si size > strlen(from), strlen(from) caractères
                            ainsi que size - strlen(from) '\0' sont copiés dans to.

                    Ecrire aussi un petit programme permettant de tester votre
                    fonction.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define VARIANTE 1
#define PRINT(STR) printf(#STR " = %s\n", STR)

#if VARIANTE == 1
char* strncpy(char* to, const char* from, size_t size);

#elif VARIANTE == 2
char* strncpy(char* dest, const char* src, size_t num);

#endif

int main(void) {
    {
        const char* from = "AB";
        char to[] = "XXXXXX";
        for (size_t i = 0; i <= 3; ++i) {
            strncpy(to, from, i);
            PRINT(to);
        }
    }
    {
        const char* from = "AB";
        char to[] = "XXXXXX";
        const size_t TAILLE = 6;
        strncpy(to, from, 4);
        for (size_t i = 0; i <= TAILLE; ++i)
            printf("%d ", (int)to[i]);
        printf("\n");
    }
	return EXIT_SUCCESS;
}

#if VARIANTE == 1
char* strncpy(char* to, const char* from, size_t size) {
    size_t i;
    for (i = 0; i < size && from[i] != '\0'; ++i)
        to[i] = from[i];
    for ( ; i < size; ++i)
        to[i] = '\0';
    return to;
}

#elif VARIANTE == 2
char* strncpy(char* dest, const char* src, size_t num) {
    char* ret = dest;
    do {
        if (!num--)
            return ret;
    } while ((*dest++ = *src++));
    while (num--)
        *dest++ = '\0';
    return ret;
}

#endif

// Output :
//to = XXXXXX
//to = AXXXXX
//to = ABXXXX
//to = AB
//65 66 0 0 88 88 0
