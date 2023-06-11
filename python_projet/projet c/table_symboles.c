#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre_abstrait.h"
#include "generation_code.h"
#include "table_symboles.h"

#define MAX_SYMBOLES 100

void ajouter_symbole(Symbole *symboles[], int *nb_symboles, const char *nom, n_fonction *n) {
    if (*nb_symboles >= MAX_SYMBOLES) {
        printf("Erreur : Capacité maximale de la table des symboles atteinte.\n");
        return;
    }
    symboles[*nb_symboles] = malloc(sizeof(Symbole));
    strcpy(symboles[*nb_symboles]->nom, nom);
    symboles[*nb_symboles]->n = n;
    (*nb_symboles)++;
}

void ajouter_symbole_entier(Symbole *symboles[], int *nb_symboles, const char *nom, n_fonction *n) {
    ajouter_symbole(symboles, nb_symboles, nom, n);
    symboles[*nb_symboles - 1]->type = entier;
}

void ajouter_symbole_booleen(Symbole *symboles[], int *nb_symboles, const char *nom, n_fonction *n) {
    ajouter_symbole(symboles, nb_symboles, nom, n);
    symboles[*nb_symboles - 1]->type = booleen;
}

int trouver_symbole(Symbole *symboles[], int nb_symboles, const char *nom) {
    for (int i = 0; i < nb_symboles; i++) {
        if (strcmp(symboles[i]->nom, nom) == 0) {
            return i;
        }
    }
    return -1;  // Symbole non trouvé
}

int trouver_type_symbole(Symbole *symboles[], int nb_symboles, const char *nom) {
    int i = trouver_symbole(symboles, nb_symboles, nom);
    if (i == -1) {
        printf("Erreur : Symbole %s non trouvé.\n", nom);
        return -1;
    }
    return symboles[i]->type;
}
