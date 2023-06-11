#ifndef __GENERATION_CODE__
#define __GENERATION_CODE__

#include "table_symboles.h"

void nasm_prog(n_programme *n);
void nasm_liste_variable_name(n_l_instructions *n);
void nasm_liste_instructions(n_l_instructions *n);
void nasm_instruction(n_instruction* n);
void nasm_exp(n_exp* n);
void nasm_operation(n_operation* n);
void nasm_condition(l_expr* n);
void nasm_lire();
int verif_type(n_operation* n);
void setopcond(n_exp* n, char *label_debut, char *label_fin);
void nasm_define_symbole(n_l_instructions *n);
void nasm_define_fonction(n_fonction *n);
void nasm_appel_fonction(n_appel_fonction *n);
void nasm_define_all_fonction();
char* toStringType(int type);
char* toString(Symbole * s);

#endif
