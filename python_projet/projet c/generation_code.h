#ifndef __GENERATION_CODE__
#define __GENERATION_CODE__


void nasm_prog(n_programme *n);
void nasm_liste_variable_name(n_l_instructions *n);
void nasm_liste_instructions(n_l_instructions *n);
void nasm_instruction(n_instruction* n);
void nasm_exp(n_exp* n);
void nasm_operation(n_operation* n);
void nasm_condition(l_expr* n);
void nasm_lire();
int verif_type(n_operation* n);


#endif
