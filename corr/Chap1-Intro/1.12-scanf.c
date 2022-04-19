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

#include <stdlib.h>
#include <stdio.h>

void clear_stdin(void);

int main(void) {
    int n;  char c;

    printf("%s", "Donnez un nombre entier et un caractere : ");

    if (scanf("%d %c", &n, &c) == 2)
        printf("n = %d, c = %c\n", n, c);
    clear_stdin();

    return EXIT_SUCCESS;
}

void clear_stdin(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

// Nota Bene : clear_stdin doesn't work if the buffer isn't initially empty.
// Alternative working in any case would be :
/*
void clear_stdin(void) {
   fseek(stdin, 0, SEEK_END);
}
 */

// Input :
//Donnez un nombre entier et un caractere : 3 c
// Output :
//n = 3, c = c
