#define MAX_SYMBOLES 255

typedef struct Symbole * symbole;
void ajouter_symbole(symbole symboles[], int* nb_symboles, const char* nom);
void ajouter_symbole_entier(symbole symboles[], int* nb_symboles, const char* nom);
void ajouter_symbole_booleen(symbole symboles[], int* nb_symboles, const char* nom);
int trouver_symbole(const symbole symboles[], int nb_symboles, const char* nom);