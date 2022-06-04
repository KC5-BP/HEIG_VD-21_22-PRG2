// A tester avec 4294967314
// Avec un traitement standard afficherait "Valeur saisie = 18"
// Avec la version proposée ici détecte bien que 4294967314 n'est pas correct

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void viderBuffer(void);

int lireInt(const char* msgInvite, const char* msgErreur,
            int borneInf, int borneSup);

int main(void) {

    const char* const MSG_INVITE = "Entrez un entier";
    const char* const MSG_ERREUR = "Saisie incorrecte. Veuillez SVP recommencer.";

    const int BORNE_INF = 10;
    const int BORNE_SUP = 20;

    printf("Valeur saisie = %d", lireInt(MSG_INVITE, MSG_ERREUR, BORNE_INF, BORNE_SUP));

    return EXIT_SUCCESS;
}

void viderBuffer(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int lireInt(const char* msgInvite, const char* msgErreur,
            int borneInf, int borneSup) {
    assert(msgInvite != NULL);
    assert(msgErreur != NULL);
    assert(borneInf < borneSup);
    int n;
    char s1[20], s2[20];
    do {
        printf("%s [%d - %d] : ", msgInvite, borneInf, borneSup);
        scanf("%s", s1);
        sscanf(s1, "%d", &n);
        sprintf(s2, "%d", n);
        viderBuffer();
        if (strcmp(s1, s2) == 0 && n >= borneInf && n <= borneSup) {
            break;
        } else {
            printf("%s\n", msgErreur);
        }
    } while (true);
    return n;
}
