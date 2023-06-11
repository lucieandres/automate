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

void add_parameter_type_to_symbole(Symbole *symbole[], int pos, n_parm *param) {
    if (symbole[pos]->type_p == NULL) {
        symbole[pos]->type_p = malloc(sizeof(int));
        symbole[pos]->nom_p = (char**) malloc(sizeof(char*));
    } else {
        //printf(";nb_params : %d\n", symbole[pos]->nb_params);
        symbole[pos]->type_p = realloc(symbole[pos]->type_p, sizeof(int) * (symbole[pos]->nb_params));
        symbole[pos]->nom_p = (char**) realloc(symbole[pos]->nom_p, sizeof(char*) * (symbole[pos]->nb_params+1));
    }
    
    symbole[pos]->nb_params+=1;
    symbole[pos]->nom_p[symbole[pos]->nb_params-1] = param->nom;
    //printf(";type : %s\n", param->type);
    if (strcmp(param->type, "ENTIER")==0) {
        symbole[pos]->type_p[symbole[pos]->nb_params-1] = entier_v;
    } else if (strcmp(param->type, "BOOLEEN")==0) {
        symbole[pos]->type_p[symbole[pos]->nb_params-1] = booleen_v;
    }
}


void add_variable(variable *variables[], int* nb_variables, const char* nom, int adresse) {
    if (*nb_variables >= MAX_SYMBOLES) {
        printf("Erreur : Capacité maximale de la table des variables atteinte.\n");
        return;
    }
    variables[*nb_variables] = malloc(sizeof(variable));
    strcpy(variables[*nb_variables]->nom, nom);
    variables[*nb_variables]->adresse = adresse;
    (*nb_variables)++;
}

int trouver_variable(variable *variables[], int nb_variables, const char* nom) {
    for (int i = 0; i < nb_variables; i++) {
        if (strcmp(variables[i]->nom, nom) == 0) {
            return i;
        }
    }
    return -1;  // Symbole non trouvé
}


int trouver_adresse_variable(variable *variables[], int nb_variables, const char* nom) {
    int i = trouver_variable(variables, nb_variables, nom);
    if (i == -1) {
        printf("Erreur : Variable %s non trouvé.\n", nom);
        return -1;
    }
    return variables[i]->adresse;
}