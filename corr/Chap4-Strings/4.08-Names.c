/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 4.08-Names.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 4.08
                    Ecrire une fonction C qui prend en paramètres un prénom et
                    un nom et qui retourne une nouvelle chaîne sous la forme
                    "prénom nom".

                    Exemple :
                        "James" + "Bond" => "James Bond".

                    Ecrire aussi un petit programme de test qui, après avoir
                    demandé à l'utilisateur d'entrer un prénom, puis un nom,
                    affiche à l'écran, en utilisant les services de la
                    fonction ci-dessus :
                        La chaine "prenom nom" comporte n caracteres.
                    Soit, dans notre exemple :
                        La chaine "James Bond" comporte 10 caracteres.

 Remarque(s)    : Both solutions have a common problem, being additionnal blanks



 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	// strlen(), strcpy(), strcat()

#define VARIANTE 1

#if VARIANTE == 1
char* concat(const char* prenom, const char* nom);
void clear_stdin(void);

int main(void) {
	#define TAILLE_MAX_PRENOM 20
	#define TAILLE_MAX_NOM 30
	char prenom[TAILLE_MAX_PRENOM + 1];
	char nom[TAILLE_MAX_NOM + 1];

	#define TAILLE_MAX_CHAINE_CONTROLE 15
	char chaineControlePrenom[TAILLE_MAX_CHAINE_CONTROLE + 1];
	char chaineControleNom[TAILLE_MAX_CHAINE_CONTROLE + 1];

	const char* const MOTIF = "%%%d[^\n]";
	sprintf(chaineControlePrenom, MOTIF, TAILLE_MAX_PRENOM);
	sprintf(chaineControleNom, MOTIF, TAILLE_MAX_NOM);

	printf("Entrez le prenom (max %u caract.) : ", TAILLE_MAX_PRENOM);
	scanf(chaineControlePrenom, prenom);
	clear_stdin();

	printf("Entrez le nom (max %u caract.) : ", TAILLE_MAX_NOM);
	scanf(chaineControleNom, nom);
	clear_stdin();

	char* prenom_nom = concat(prenom, nom);
	if (prenom_nom) {
		printf("La chaine \"%s\" comporte %u caracteres.\n",
			   prenom_nom, (unsigned) strlen(prenom_nom));
	}
	free(prenom_nom);
	return EXIT_SUCCESS;
}

char* concat(const char* prenom, const char* nom) {
	// Construire un tableau dynamique de la taille nécessaire au
	// stockage du prénom, d'un espace, du nom et du caractère '\0'
	char* resultat = (char*) calloc(strlen(prenom) + strlen(nom) + 2, sizeof(char));
	if (resultat) {
		strcpy(resultat, prenom);
		strcat(resultat, " ");
		strcat(resultat, nom);
	}
	return resultat;
}

void clear_stdin(void) {
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

#elif VARIANTE == 2	// using fgets
void saisie(char* chaine, size_t taille);
char* concat(const char* prenom, const char* nom);
void clear_stdin(void);

int main(void) {
	#define TAILLE_MAX_PRENOM 20
	#define TAILLE_MAX_NOM 30
	char prenom[TAILLE_MAX_PRENOM + 1];
	char nom[TAILLE_MAX_NOM + 1];

	printf("Entrez le prenom (max %u caract.) : ", TAILLE_MAX_PRENOM);
	saisie(prenom, TAILLE_MAX_PRENOM);

	printf("Entrez le nom (max %u caract.) : ", TAILLE_MAX_NOM);
	saisie(nom, TAILLE_MAX_NOM);

	char* prenom_nom = concat(prenom, nom);
	if (prenom_nom) {
		printf("La chaine \"%s\" comporte %u caracteres.\n",
			   prenom_nom, (unsigned) strlen(prenom_nom));
	}
	free(prenom_nom);
	return EXIT_SUCCESS;
}

void saisie(char* chaine, size_t taille) {
	fgets(chaine, (int)taille + 1, stdin);
	clear_stdin();
	// Remplace la marque de fin de ligne ('\n') évidemment présente dans la chaîne
	// par une marque de fin de chaîne ('\0')
	for (size_t i = 0; i < taille; ++i)
		if (chaine[i] == '\n') {
			chaine[i] = '\0';
			break;
		}
}

char* concat(const char* prenom, const char* nom) {
	// Construire un tableau dynamique de la taille nécessaire au
	// stockage du prénom, d'un espace, du nom et du caractère '\0'
	char* resultat = (char*) calloc(strlen(prenom) + strlen(nom) + 2, sizeof(char));
	if (resultat) {
		strcpy(resultat, prenom);
		strcat(resultat, " ");
		strcat(resultat, nom);
	}
	return resultat;
}

void clear_stdin(void) {
	fseek(stdin, 0, SEEK_END);
}

#endif

// Output :
//Entrez le prenom (max 20 caract.) :     Jean
//Entrez le nom (max 30 caract.) :    de la Fontaine
//La chaine "    Jean    de la Fontaine " comporte 27 caracteres.
