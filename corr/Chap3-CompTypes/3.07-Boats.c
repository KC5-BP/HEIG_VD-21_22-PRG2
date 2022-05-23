/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 3.07-Boats.
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 3.07
                    Modélisez des bateaux, plus précisément des voiliers et des
                    bateaux à moteur.
                    On dispose des informations suivantes :
                        • Tout bateau a un nom (de longueur quelconque)
                        • Si le bateau est un voilier, il faut enregistrer la surface
                        de la voilure en [m2] (type uint16_t) de celui-ci
                        • Les bateaux à moteur se divise en 2 catégories :
                        les bateaux de pêche et les bateaux de plaisance.
                        • Tout bateau à moteur se caractérise par la puissance totale
                        de ses moteurs, exprimée en [CV] (type uint16_t)
                        • Si le bateau est un bateau de pêche, il faut enregistrer
                        combien de tonnes de poisson celui-ci est autorisé à pêcher
                        (de type uint8_t)
                        • Si le bateau est un bateau de plaisance, il faut enregistrer
                        le nom de son propriétaire (de longueur quelconque)

                    Ecrire un programme C, qui, après avoir déclaré le plus
                    proprement possible les types nécessaires à la résolution de
                    notre problème, déclare/initialise les 3 bateaux suivants :
                        • "Alinghi", voilier ayant 300 [m2] de voilure
                        • "Espadon", bateau de pêche disposant de 2 moteurs de 500 [CV]
                        chacun et pouvant pêcher 20 tonnes de poisson
                        • "Farniente", bateau de plaisance disposant d’un moteur de
                        100 [CV] et appartenant à Monsieur James Lamer

                    Puis affiche à l'écran l'ensemble des caractéristiques de
                    chacun de ces 3 bateaux.

 Remarque(s)    : Was part of a laboratory

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef const char* nom_t;
typedef uint16_t voilure_t;
typedef uint16_t puissance_t;
typedef uint8_t poids_t;

typedef enum { VOILIER, MOTEUR  } TAG_BATEAU;
const char* const GENRE_BATEAU[] = {"Voilier", "Bateau"};
typedef enum { PECHE, PLAISANCE } TAG_MOTEUR;
const char* const GENRE_MOTEUR[] = {"de peche", "de plaisance"};

typedef struct {
    voilure_t voilure;  // en [m²]
} voilier_str;

typedef struct {
    poids_t poids;      // en [t]
} peche_str;

typedef struct {
    const char* proprietaire;
} plaisance_str;

typedef union {
    peche_str peche;
    plaisance_str plaisance;
} specificitesMoteur_u;

typedef struct {
    puissance_t puissance;  // totale en [CV]
    TAG_MOTEUR tagMoteur;
    specificitesMoteur_u specMoteur;
} bateauMoteur_str;

typedef union {
    voilier_str voilier;
    bateauMoteur_str bateauMoteur;
} specificitesBateau_u;

typedef struct {
    nom_t nom;
    TAG_BATEAU tagBateau;
    specificitesBateau_u specBateau;
} bateau_str;

bateau_str Voilier(nom_t nom, voilure_t voilure);
bateau_str Peche(nom_t nom, puissance_t puissance, poids_t poids);
bateau_str Plaisance(nom_t nom, puissance_t puissance, nom_t proprietaire);
void afficherBateau(bateau_str* bateau);

int main(void) {
    bateau_str alinghi   = Voilier("Alinghi", 300);
    bateau_str espadon   = Peche("Espadon", 1000, 20);
    bateau_str farniente = Plaisance("Farniente", 100, "James Lamer");

    afficherBateau(&alinghi);   printf("\n");
    afficherBateau(&espadon);   printf("\n");
    afficherBateau(&farniente);   printf("\n");
    return EXIT_SUCCESS;
}

bateau_str Voilier(nom_t nom, voilure_t voilure) {
    return (bateau_str) {.nom = nom, .tagBateau = VOILIER,
                         .specBateau.voilier.voilure = voilure};
}

bateau_str Peche(nom_t nom, puissance_t puissance, poids_t poids) {
    return (bateau_str) {
        .nom = nom, .tagBateau = MOTEUR,
        {.bateauMoteur = {
            .tagMoteur = PECHE, .puissance = puissance,
            .specMoteur = { .peche.poids = poids }
            }
        }
    };
}

bateau_str Plaisance(nom_t nom, puissance_t puissance, nom_t proprietaire) {
    return (bateau_str) {
        .nom = nom, .tagBateau = MOTEUR,
        {.bateauMoteur = {
            .tagMoteur = PLAISANCE, .puissance = puissance,
            .specMoteur = { .plaisance.proprietaire = proprietaire }
            }
        }
    };
}

void afficherBateau(bateau_str* bateau) {
    if (bateau != NULL) {
        printf("Nom          : %s\n", bateau->nom);
        if (bateau->tagBateau == VOILIER) {
            printf("Genre        : %s\n", GENRE_BATEAU[bateau->tagBateau]);
            printf("Voilure [m2] : %" PRIu16 "\n",
                   bateau->specBateau.voilier.voilure);
        } else if (bateau->tagBateau == MOTEUR) {
            printf("Genre        : %s %s\n", GENRE_BATEAU[bateau->tagBateau],
                   GENRE_MOTEUR[bateau->specBateau.bateauMoteur.tagMoteur]);
            printf("Moteurs [CV] : %" PRIu16 "\n",
                   bateau->specBateau.bateauMoteur.puissance);
            if (bateau->specBateau.bateauMoteur.tagMoteur == PECHE) {
                printf("Peche [t]    : %" PRIu8 "\n",
                       bateau->specBateau.bateauMoteur.specMoteur.peche.poids);
            } else if (bateau->specBateau.bateauMoteur.tagMoteur == PLAISANCE) {
                printf("Proprietaire : %s\n",
                       bateau->specBateau.bateauMoteur.specMoteur.plaisance.proprietaire);
            }
        }
    }
}
