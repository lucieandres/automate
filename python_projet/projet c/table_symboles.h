#ifndef __TABLE_SYMBOLES_H__
#define __TABLE_SYMBOLES_H__
#define MAX_SYMBOLES 100

#include "arbre_abstrait.h"


typedef struct {
    char nom[100];  // Nom du symbole
    enum { entier, booleen } type;  // Type du symbole
    n_fonction *n;
} Symbole;

void ajouter_symbole(Symbole *symboles[], int* nb_symboles, const char* nom, n_fonction *n);
void ajouter_symbole_entier(Symbole *symboles[], int* nb_symboles, const char* nom, n_fonction *n);
void ajouter_symbole_booleen(Symbole *symboles[], int* nb_symboles, const char* nom, n_fonction *n);
int trouver_symbole(Symbole *symboles[], int nb_symboles, const char* nom);
int trouver_type_symbole(Symbole *symboles[], int nb_symboles, const char* nom);

#endif