/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 3.06-PersonDisplay_2.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 3.06
                    Modélisez des personnes, certaines de nationalité suisse,
                    d'autres pas.
                    On suppose que toute personne (qu'elle soit suisse ou non)
                    se caractérise par un nom (20 caractères effectifs max).
                    Pour les personnes de nationalité suisse, on souhaite
                    (en plus du nom) aussi enregistrer le taux d'activité exercé
                    (entier exprimé en %).
                    Pour les personnes de nationalité étrangère, on souhaite
                    (en plus du nom) aussi enregistrer le type de permis de
                    travail dont elle dispose (permis A, B ou C;
                    à implémenter en tant que type énuméré).

                    Ecrire un programme C, qui, après avoir déclaré le plus
                    proprement possible les types nécessaires à la résolution de
                    notre problème, déclare/initialise les 2 personnes suivantes :
                        • "Toto", suisse travaillant à 80%
                        • "Titi", étranger avec permis C

                    Puis affiche à l'écran l'ensemble des caractéristiques de
                    chacune de ces 2 personnes.

 Remarque(s)    :
                     p2 = {"Toto", SUISSE, {C}}, // wrong, because : C will
                     initialize the first value of the union instead of the wished
                     one.

                     With tag "nationalite"

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define VARIANTE 2

#if VARIANTE == 1

    #define TAILLE_MAX_NOM 20

    typedef char Nom[TAILLE_MAX_NOM + 1];
    typedef enum {SUISSE, ETRANGER} Nationalite;
    typedef enum {A, B, C} TypePermis;

    const char* const NATIONNALITE[] = {"Suisse", "Etranger"};
    const char* const TYPES_PERMIS[] = {"A", "B", "C"};

    typedef union {
       uint8_t tauxActivites;
       TypePermis typePermis;
    } Specificites;

    typedef struct {
       Nom nom;
       Nationalite nationalite;
       Specificites specificites;
    } Personne;

    void afficher(const Personne* p);

    int main(void) {
       Personne
          p1 = {"Toto", SUISSE, {.tauxActivites = 80}},
             // p1 = {"Toto", SUISSE, {80}}, // possible
          p2 = {"Titi", ETRANGER, {.typePermis = C}};
             // p2 = {"Toto", SUISSE, {C}}, // pas correct!

       afficher(&p1); printf("\n");
       afficher(&p2); printf("\n");

       return EXIT_SUCCESS;
    }

    void afficher(const Personne* p) {
       printf("Nom           : %s\n", p->nom);
       printf("Nationalite   : %s\n", NATIONNALITE[p->nationalite]);
       if (p->nationalite == SUISSE)
          printf("Taux activite : %" PRIu8 "%%\n", p->specificites.tauxActivites);
       else
          printf("Type permis   : %s\n", TYPES_PERMIS[p->specificites.typePermis]);
    }

#else

    #include <string.h>

    #define TAILLE_MAX_NOM 20

    typedef char Nom[TAILLE_MAX_NOM + 1];
    typedef enum { SUISSE, ETRANGER } Nationalite;
    typedef enum { A, B, C } TypePermis;

    const char* const NATIONNALITE[] = {"Suisse", "Etranger"};
    const char* const TYPES_PERMIS[] = {"A", "B", "C"};

    typedef struct {
        uint8_t tauxActivite;
    } Suisse;

    typedef struct {
        TypePermis typePermis;
    } Etranger;

    typedef union {   // Variante plus claire et plus évolutive que précédemment
        Suisse suisse;
        Etranger etranger;
    } Specificites;

    typedef struct {
        Nom nom;
        Nationalite nationalite;
        Specificites specificites;
    } Personne;

    void afficher(const Personne* p);
    Personne suisse(const char* nom, uint8_t tauxActivite);
    Personne etranger(const char* nom, TypePermis typePermis);

    int main(void) {
        Personne
            p1 = suisse("Toto", 80),
            p2 = etranger("Titi", C);

        afficher(&p1);
        printf("\n");
        afficher(&p2);
        printf("\n");

        return EXIT_SUCCESS;
    }

    void afficher(const Personne* p) {
        printf("Nom           : %s\n", p->nom);
        printf("Nationalite   : %s\n", NATIONNALITE[p->nationalite]);
        if (p->nationalite == SUISSE)
            printf("Taux activite : %" PRIu8 "%%\n",
                   p->specificites.suisse.tauxActivite);
        else
            printf("Type permis   : %s\n",
                   TYPES_PERMIS[p->specificites.etranger.typePermis]);
    }

    Personne suisse(const char* nom, uint8_t tauxActivite) {
        Personne p = {"", SUISSE, {.suisse = {tauxActivite}}};
        // Autres variantes possibles :
        // Personne p = {"", SUISSE, {{tauxActivite}}};
        // Personne p = (Personne) {"", SUISSE, {.suisse = {tauxActivite}}};
        // Personne p = (Personne) {"", SUISSE, {{tauxActivite}}};
        strncpy(p.nom, nom, TAILLE_MAX_NOM);
        return p;
    }

    Personne etranger(const char* nom, TypePermis typePermis) {
        Personne p = {"", ETRANGER, {.etranger = {typePermis}}};
        // Autres variantes possibles :
        // Personne p = {"", ETRANGER, {{typePermis}}};
        // Personne p = (Personne) {"", ETRANGER, {.ETRANGER = {typePermis}}};
        // Personne p = (Personne) {"", ETRANGER, {{typePermis}}};
        strncpy(p.nom, nom, TAILLE_MAX_NOM);
        return p;
    }

#endif

// Ouput :
//Nom           : Toto
//Nationalite   : Suisse
//Taux activite : 80%
//
//Nom           : Titi
//Nationalite   : Etranger
//Type permis   : C
