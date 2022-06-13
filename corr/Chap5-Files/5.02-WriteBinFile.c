/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 5.02-WriteBinFile.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 5.02
                    Écrire un programme C permettant de stocker dans un fichier
                    binaire nommé personnes.dat des données relatives à des
                    personnes.
                    - Son nom    (20 caract. max)
                    - Son prénom (15 caract. max)
                    - Son âge    (unsigned short)

                    Les données des diverses personnes doivent être saisies par
                    l'utilisateur. On conviendra que la saisie se termine dès lors
                    que l'utilisateur entre un nom de personne vide.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOM_FICHIER "personnes.dat"

#define TAILLE_MAX_NOM    20
#define TAILLE_MAX_PRENOM 15

typedef char Nom[TAILLE_MAX_NOM + 1];
typedef char Prenom[TAILLE_MAX_PRENOM + 1];
typedef unsigned short Age;

typedef struct {
    Nom nom;
    Prenom prenom;
    Age age;
} Personne;

void saisie(char* chaine, size_t taille);

#define CLEAR_STDIN_LOOP  0
#define CLEAR_STDIN_FSEEK 1
#define CLEAR_STDIN CLEAR_STDIN_LOOP
void clear_stdin(void);

int main(void) {
    FILE* file = fopen(NOM_FICHIER, "wb");
    if (!file) {
        printf("Desole! Le fichier \"%s\" n'a pas pu etre ouvert.\n", NOM_FICHIER);
        return EXIT_FAILURE;
    }
    Personne p;
    printf("--- Pour finir la saisie, donnez un nom 'vide' ---\n");
    do {
        printf("\nNom: ");
        saisie(p.nom, TAILLE_MAX_NOM);
        if (strlen(p.nom) == 0)
            break;
        printf("Prenom: ");
        saisie(p.prenom, TAILLE_MAX_PRENOM);
        printf("Age: ");
        scanf("%hu", &p.age);
        clear_stdin();
        fwrite(&p, sizeof(Personne), 1, file);
    } while(1);

    fclose(file);
	return EXIT_SUCCESS;
}

void saisie(char* chaine, size_t taille) {
    fgets(chaine, (int) taille + 1, stdin);
    clear_stdin();
    for (size_t i = 0; i < taille; ++i)
        if (chaine[i] == '\n') {
            chaine[i] = '\0';
            break;
        }
}

#if CLEAR_STDIN == CLEAR_STDIN_LOOP
void clear_stdin(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

#elif CLEAR_STDIN == CLEAR_STDIN_FSEEK
void clear_stdin(void) {
    fseek(stdin, 0, SEEK_END);
}

#endif
