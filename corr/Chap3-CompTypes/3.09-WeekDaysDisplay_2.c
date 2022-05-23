/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 3.09-WeekDaysDisplay_2.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 3.09
                    Même exercice que le 3.8, mais cette fois :
                        • l'utilisateur doit pouvoir saisir le nom d'un jour en
                        minuscules et/ou majuscules avec d'éventuels espaces
                        blancs devant et derrière
                        • le programme doit inviter l'utilisateur à refaire sa
                        saisie si celle-ci n'est pas correcte

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Passe la chaîne passée en paramètre en minuscule.
void toLower(char* s);

//
int lireChaine(const char* const tab[], size_t n,
               const char* msgInvite, const char* msgErreur);

// Affiche (cycliquement) les chaînes contenues dans tab, en commençant par celle
// en position pos.
void afficher(const char* const tab[], size_t n, size_t pos);

void clear_stdin(void);

int main(void) {
    typedef enum { LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE } Jour;

    const char* const JOURS[] = {"lundi", "mardi", "mercredi", "jeudi",
                                 "vendredi", "samedi", "dimanche"};
    const size_t NB_JOURS = sizeof(JOURS) / sizeof(char*);

    const char* MSG_INVITE =
        "Donnez un jour de la semaine en toutes lettres et en minuscule : ";
    const char* MSG_ERREUR =
        "Saisie incorrecte. Veuillez SVP recommencer.";

    // Saisie, par l'utilisateur, d'un jour de la semaine
    Jour jour = (Jour) lireChaine(JOURS, NB_JOURS, MSG_INVITE, MSG_ERREUR);

    // Affichage (cyclique) des jours de la semaine à partir du jour saisi
    afficher(JOURS, NB_JOURS, jour);

    printf("\n");
	return EXIT_SUCCESS;
}

void toLower(char* s) {
    if (s != NULL) {
        const size_t TAILLE = strlen(s);
        for (size_t i = 0; i < TAILLE; ++i)
            s[i] = (char) tolower(s[i]);
    }
}

int lireChaine(const char* const tab[], size_t n,
               const char* msgInvite, const char* msgErreur) {
    #define TAILLE_MAX_CHAINE 8
    char chaineDeControle[4];
    sprintf(chaineDeControle, "%%%ds", TAILLE_MAX_CHAINE);
    char chaine[TAILLE_MAX_CHAINE + 1];
    do {
        puts(msgInvite);
        scanf(chaineDeControle, chaine);
        clear_stdin();
        toLower(chaine);
        // Vérifier si chaîne corresond à l'un des noms de jour
        for (size_t i = 0; i < n; ++i)
            if (strcmp(chaine, tab[i]) == 0)
                return (int) i;
        puts(msgErreur);
    } while (true);
}

void afficher(const char* const tab[], size_t n, size_t pos) {
    for (size_t i = 0; i < n; ++i)
        puts(tab[(pos + i) % n]);   // printf("%s\n", tab[(pos + i) % n]);
}

void clear_stdin() {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
