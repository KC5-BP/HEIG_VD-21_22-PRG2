/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 3.03-PeopleDisplay.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 3.03
                    Même exercice que précédemment, mais en affichant non pas une
                    mais plusieurs personnes.
                    Plus précisément, il est demandé :
                        • de modéliser le concept de Personne en s’affranchissant
                        de la contrainte des 20 caractères max pour le nom
                        • de déclarer un tableau contenant les 3 personnes
                        suivantes :
                            o Paul qui mesure 180 cm et avec les yeux bleus
                            o Pierre qui mesure 175 cm et avec les yeux verts
                            o Jean-Jacques qui mesure 182 cm et avec les yeux marron
                        • d'écrire :
                            o une fonction permettant l'affichage d'une personne
                            (passée par adresse)
                            o une fonction permettant l'affichage d'un tableau
                            de personnes

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef const char* Nom;
typedef uint8_t Taille;
typedef enum { BLUE, VERT, GRIS, MARRON, NOIR } CouleurYeux;

typedef struct {
    Nom nom;
    Taille taille;  // en cm
    CouleurYeux couleurYeux;
} Personne;

const char* const COULEURS_YEUX[] = {"blue", "vert", "gris", "marron", "noir"};

void afficherPersonne(const Personne* p);
void afficherPersonnes(const Personne tab[], size_t n);

int main(void) {
    const Personne PERSONNES[] = {{"Paul",        180, BLUE},
                                  {"Pierre",      175, VERT},
                                  {"Jean-Jaques", 182, MARRON}};
    const size_t TAILLE = sizeof(PERSONNES) / sizeof(Personne);

    afficherPersonnes(PERSONNES, TAILLE);

    return EXIT_SUCCESS;
}

void afficherPersonne(const Personne* p) {
    printf("Nom     : %s\n", p->nom);
    printf("Taille  : %" PRIu8 "\n", p->taille);
    printf("Couleur : %s\n", COULEURS_YEUX[p->couleurYeux]);
}

void afficherPersonnes(const Personne tab[], size_t n) {
    for (size_t i = 0; i < n; ++i) {
        afficherPersonne(tab + i);    // OU &tab[i]
        printf("\n");
    }
}

// Ouput :
//Nom     : Paul
//Taille  : 180
//Couleur : blue
//
//Nom     : Pierre
//Taille  : 175
//Couleur : vert
//
//Nom     : Jean-Jaques
//Taille  : 182
//Couleur : marron
