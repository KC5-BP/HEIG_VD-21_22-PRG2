/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.12-scanf.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 1.12
                    Le code suivant est pleins d'erreurs et maladresses,
                    corrigez les.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <cstdio.h>
#include <cstdlib.h>
using namespace std;

int main() {
    int n, char c;

    printf("Donnez un nombre entier et un caractere : ");
    scanf("%d%c", n, c);
    printf("n = %d, c = %c\n", n, c);

    return EXIT_SUCCESS;
}
