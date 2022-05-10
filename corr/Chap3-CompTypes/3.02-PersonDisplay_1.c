/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 3.02-PersonDisplay_1.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 3.02
                    On suppose qu'une personne se caractérise par :
                        • son nom (20 caractères effectifs au maximum)
                        • sa taille en cm (type uint8_t)
                        • la couleur de ses yeux (type enum; couleurs possibles :
                                                    bleu, vert, gris, marron, noir)

                    Ecrire un programme C qui, dans un premier temps, déclare,
                    le plus proprement possible, tous les types nécessaires à la
                    modélisation d'une personne
                    (n'hésitez pas à faire usage de typedef) et qui, dans un
                    second temps, déclare/définit deux fonctions
                    (sans valeur de retour) afficher_1 et afficher_2, permettant
                    d'afficher l'ensemble des caractéristiques de la personne
                    passée en paramètre. L'argument de la fonction afficher_1 doit
                    être passé par valeur, celui de afficher_2, par adresse.

                    Testez le programme en considérant comme exemple de personne :
                    Toto qui mesure 180 cm et qui a les yeux bleus.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define TAILLE_NOM_MAX 20

typedef char Nom[TAILLE_NOM_MAX + 1];
typedef uint8_t Taille;
typedef enum {BLUE, VERT, GRIS, MARRON, NOIR} CouleurYeux;

typedef struct {
    Nom nom;
    Taille taille;
    CouleurYeux couleurYeux;
} Personne;

const char* const COULEURS_YEUX[] = {"blue", "vert", "gris", "marron", "noir"};

void afficher_1(Personne p);
void afficher_2(const Personne* p);

int main(void) {
    Personne p = {"Toto", 180, BLUE};
    //Personne p = {.nom = "Toto", .taille = 180, .couleurYeux = BLUE};
    //Personne p = (Personne) {"Toto", 180, BLUE};
    //Personne p = (Personne) {.nom = "Toto", .taille = 180, .couleurYeux = BLUE};

    afficher_1(p);
    printf("\n");
    afficher_2(&p);
    printf("\n");
	return EXIT_SUCCESS;
}

void afficher_1(Personne p) {
    afficher_2(&p);
}

void afficher_2(const Personne* p) {
    printf("Nom     : %s\n", p->nom);
    printf("Taille  : %" PRIu8 "[cm]\n", p->taille);
    printf("Couleur : %s\n", COULEURS_YEUX[p->couleurYeux]);
}
