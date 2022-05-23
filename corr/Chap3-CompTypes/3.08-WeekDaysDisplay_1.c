/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 3.08-WeekDaysDisplay_1.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 3.08
                    En utilisant le concept de type énuméré, écrire un programme C
                    qui :
                        1) demande à l'utilisateur de saisir, en toutes lettres et
                        entièrement en minuscules, un jour de la semaine*
                        2) affiche, entièrement en minuscules et à raison d'un nom
                        par ligne, tous les jours de la semaine, en commençant par
                        celui saisi par l'utilisateur
                        3) se termine
                        * Il n'est pas demandé ici de vérifier la saisie utilisateur.

 Remarque(s)    : Teacher uses fflush(stdin) for clearing the input buffer in
                    lireChaine(). This is unsafe & will only work on specific OSes
                    only (mostly Microsoft ones) and I recommend you to use the
                    "traditional" clear_stdin() like shown here.
                    TODO Ask about the warning on l.62
                    >> Format string is not a string literal (potentially insecure)

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lireChaine(const char* const tab[], size_t n, const char* msgInvite);

void clear_stdin(void);

int main(void) {
    typedef enum { LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE } Jour;

    const char* const JOURS[] = {"lundi", "mardi", "mercredi", "jeudi",
                                 "vendredi", "samedi", "dimanche"};
    const size_t NB_JOURS = sizeof(JOURS) / sizeof(char*);

    const char* MSG_INVITE =
        "Donnez un jour de la semaine en toutes lettres et en minuscule : ";

    // Saisie, par l'utilisateur, d'un jour de la semaine,
    // ATTENTION! Saisie non contrôlée.
    Jour jour = (Jour) lireChaine(JOURS, NB_JOURS, MSG_INVITE);

    if ((int) jour != -1)
        // Affichage
        for (size_t i = 0; i < NB_JOURS; ++i)
            printf("%s\n", JOURS[(jour + i) % 7]);
    else
        printf("Saisie incorrecte. Desole!\n");

    return EXIT_SUCCESS;
}

int lireChaine(const char* const tab[], size_t n, const char* msgInvite) {
    #define TAILLE_MAX_CHAINE 8
    char chaineDeControle[4];
    sprintf(chaineDeControle, "%%%ds", TAILLE_MAX_CHAINE);
    char chaine[TAILLE_MAX_CHAINE + 1];
    printf(msgInvite);
    scanf(chaineDeControle, chaine);
    // Vider le buffer
    clear_stdin();
    for (size_t i = 0; i < n; ++i)
        if (strcmp(chaine, tab[i]) == 0)
            return (int) i;
    #undef TAILLE_MAX_CHAINE
    return (-1);
}

void clear_stdin() {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

// Output :
//Donnez un jour de la semaine en toutes lettres et en minuscule : samedi
//samedi
//dimanche
//lundi
//mardi
//mercredi
//jeudi
//vendredi
