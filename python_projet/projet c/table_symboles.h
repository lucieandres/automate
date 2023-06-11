#ifndef __TABLE_SYMBOLES_H__
#define __TABLE_SYMBOLES_H__
#define MAX_SYMBOLES 100

#include "arbre_abstrait.h"


typedef struct {
    char nom[100];  // Nom du symbole
    char ** nom_p;
    enum { entier, booleen } type;  // Type du symbole
    n_fonction *n;
    int nb_params;
    enum { empty, entier_v, booleen_v } *type_p;
} Symbole;

typedef struct {
    char nom[100];
    enum { entier_va, booleen_va } type;
    int adresse;
} variable;

void ajouter_symbole(Symbole *symboles[], int* nb_symboles, const char* nom, n_fonction *n);
void ajouter_symbole_entier(Symbole *symboles[], int* nb_symboles, const char* nom, n_fonction *n);
void ajouter_symbole_booleen(Symbole *symboles[], int* nb_symboles, const char* nom, n_fonction *n);
int trouver_symbole(Symbole *symboles[], int nb_symboles, const char* nom);
int trouver_type_symbole(Symbole *symboles[], int nb_symboles, const char* nom);
void add_parameter_type_to_symbole(Symbole *symbole[], int pos, n_parm *param);

void add_variable(variable *variables[], int* nb_variables, const char* nom, int valeur);
int trouver_variable(variable *variables[], int nb_variables, const char* nom);
int trouver_adresse_variable(variable *variables[], int nb_variables, const char* nom);

#endif