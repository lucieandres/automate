#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre_abstrait.h"
#include "generation_code.h"
#include "table_symboles.h"


typedef struct {
    char nom[100];  // Nom du symbole
    enum {entier, booleen} type;  // Type du symbole
} Symbole;

void ajouter_symbole(Symbole symboles[], int* nb_symboles, const char* nom) {
    if (*nb_symboles >= MAX_SYMBOLES) {
        printf("Erreur : Capacité maximale de la table des symboles atteinte.\n");
        return;
    }
    strcpy(symboles[*nb_symboles].nom, nom);
    (*nb_symboles)++;
}

void ajouter_symbole_entier(Symbole symboles[], int* nb_symboles, const char* nom) {
    ajouter_symbole(symboles, nb_symboles, nom);
    symboles[*nb_symboles - 1].type = entier;
}

void ajouter_symbole_booleen(Symbole symboles[], int* nb_symboles, const char* nom) {
    ajouter_symbole(symboles, nb_symboles, nom);
    symboles[*nb_symboles - 1].type = booleen;
}

int trouver_symbole(const Symbole symboles[], int nb_symboles, const char* nom) {
    for (int i = 0; i < nb_symboles; i++) {
        if (strcmp(symboles[i].nom, nom) == 0) {
            return i;
        }
    }
    return -1;  // Symbole non trouvé
}