#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre_abstrait.h"

/* Abbréviations:
 * n -> noeud
 * l -> liste
 */

l_expr *creerListeExpr(n_exp *exp)
{
	l_expr *liste = (l_expr *)malloc(sizeof(l_expr));
	liste->value = exp;
	liste->next = NULL;
	return liste;
}

l_expr *ajouterListe(l_expr *liste, n_exp *exp)
{
	l_expr *l = creerListeExpr(exp);
	l->next = liste;
	return l;
}

l_expr *ajouterListeElementList(l_expr *liste, l_expr *liste2)
{
	liste2->next = liste;
	return liste2;
}

l_parm *creerListeParm(n_parm *parm)
{
	l_parm *liste = (l_parm *)malloc(sizeof(l_parm));
	liste->value = parm;
	liste->next = NULL;
	return liste;
}

l_parm *ajouterListeParm(l_parm *liste, n_parm *parm)
{
	l_parm *l = creerListeParm(parm);
	l->next = liste;
	return l;
}


// affiche l'entier avec sa valeur après un certain nombres d'espaces et un retour à la ligne
void afficher(char *s, int indent)
{
	for (int i = 0; i < indent; i++)
	{
		printf(" ");
	}
	printf("%s\n", s);
}

// affiche l'entier avec sa valeur après un certain nombres d'espaces
void afficher_caractere(char c, int indent)
{
	for (int i = 0; i < indent; i++)
	{
		printf(" ");
	}
	printf("%c\n", c);
}

// affiche la chaine de caractère s après un certain nombres d'espaces
void afficher_entier(int valeur, int indent)
{
	for (int i = 0; i < indent; i++)
	{
		printf(" ");
	}
	printf("[Entier:%d]\n", valeur);
}

// affiche la chaine de caractère s après un certain nombres d'espaces
void afficher_identifiant(char *nom, int indent)
{
	for (int i = 0; i < indent; i++)
	{
		printf(" ");
	}
	printf("[Identifiant:%s]\n", nom);
}

// affiche la chaine de caractère s après un certain nombres d'espaces
void afficher_type(char *nom, int indent)
{
	for (int i = 0; i < indent; i++)
	{
		printf(" ");
	}
	printf("[Type:%s]\n", nom);
}

// affiche la chaine de caractère s après un certain nombres d'espaces
void afficher_booleen(int valeur, int indent)
{
	for (int i = 0; i < indent; i++)
	{
		printf(" ");
	}
	printf("[Booleen:%s]\n", valeur ? "Vrai" : "Faux");
}

void afficher_n_programme(n_programme *prog, int indent)
{
	afficher("<programme>", indent);
	afficher_n_l_instructions(prog->instructions, indent + 1);
	afficher("</programme>", indent);
}

void afficher_n_fonction(n_fonction *fonction, int indent)
{
	afficher("<fonction>", indent);
	afficher_type(fonction->type, indent + 1);
	afficher_identifiant(fonction->nom, indent + 1);
	if(fonction->parms != NULL)
		afficher_n_liste_parm(fonction->parms, indent + 1);
	afficher_n_l_instructions(fonction->instructions, indent + 1);
	afficher("</fonction>", indent);
}

void afficher_n_l_instructions(n_l_instructions *instructions, int indent)
{
	afficher("<liste_instuctions>", indent);

	if (instructions != NULL)
	{
		do
		{
			if (instructions->instruction != NULL)
			{
				afficher_n_instruction(instructions->instruction, indent + 1);
			}
			instructions = instructions->instructions;
		} while (instructions != NULL);
	}
	afficher("</liste_instructions>", indent);
}

void afficher_n_instruction(n_instruction *instruction, int indent)
{
	if (instruction->type_instruction == i_ecrire)
	{
		afficher("<ecrire>", indent);
		afficher_n_exp(instruction->u.exp, indent + 1);
		afficher("</ecrire>", indent);
	}
	else if (instruction->type_instruction == i_declaration)
	{
		afficher("<declaration>", indent);
		afficher_n_declaration(instruction->u.declaration, indent + 1);
		afficher("</declaration>", indent);
	}
	else if (instruction->type_instruction == i_fonction)
	{
		afficher_n_fonction(instruction->u.fonction, indent);
	}
	else if (instruction->type_instruction == i_cond)
	{
		afficher_conds(instruction->u.conds, indent);
	}
	else if (instruction->type_instruction == i_retourner)
	{
		afficher("<retourner>", indent);
		afficher_n_exp(instruction->u.exp, indent + 1);
		afficher("</retourner>", indent);
	}
	else if (instruction->type_instruction == i_affectation)
	{
		afficher("<affectation>", indent);
		afficher_identifiant(instruction->u.affectation->nom, indent + 1);
		afficher_n_exp(instruction->u.affectation->exp, indent + 1);
		afficher("</affectation>", indent);
	}
	else if (instruction->type_instruction == i_expression)
	{
		afficher("<expression>", indent);
		afficher_n_exp(instruction->u.exp, indent + 1);
		afficher("</expression>", indent);
	}
	else if (instruction->type_instruction == i_appel_fonction_ins)
	{
		afficher("<instruction>", indent);
		afficher_n_exp(instruction->u.exp, indent + 1);
		afficher("</instruction>", indent);
	}
}

void afficher_conds(l_expr *liste, int indent)
{
	l_expr *l = liste;

	afficher("<condition>", indent);
	while (l->next != NULL)
	{
		afficher_cond(l->value, indent + 1);
		l = l->next;
	}
	afficher_cond(l->value, indent + 1);
	afficher("</condition>", indent);
}

void afficher_cond(n_exp *exp, int indent)
{
	Condition *cond = exp->u.condition;

	if (cond->type == 0)
	{
		afficher("<si>", indent);
		afficher_n_exp(cond->condition, indent + 1);
		afficher("</si>", indent);
		afficher("<alors>", indent);
		afficher_n_l_instructions(cond->block, indent + 1);
		afficher("</alors>", indent);
	}
	else if (cond->type == 1)
	{
		afficher("<sinon_si>", indent);
		afficher_n_exp(cond->condition, indent + 1);
		afficher("</sinon_si>", indent);
		afficher("<alors>", indent);
		afficher_n_l_instructions(cond->block, indent + 1);
		afficher("</alors>", indent);
	}
	else if (cond->type == 2)
	{
		afficher("<sinon>", indent);
		afficher_n_l_instructions(cond->block, indent + 1);
		afficher("</sinon>", indent);
	}
	else if (cond->type == 3)
	{
		afficher("<tant_que>", indent);
		afficher_n_exp(cond->condition, indent + 1);
		afficher("</tant_que>", indent);
		afficher("<alors>", indent);
		afficher_n_l_instructions(cond->block, indent + 1);
		afficher("</alors>", indent);
	}
}

void afficher_n_exp(n_exp *exp, int indent)
{
	if (exp->type_exp == i_operation)
	{
		afficher_n_operation(exp->u.operation, indent);
	}
	else if (exp->type_exp == i_lire)
	{
		afficher("<lire>", indent);
		afficher("</lire>", indent);
	}
	else if (exp->type_exp == i_entier)
	{
		afficher_entier(exp->u.valeur, indent);
	}
	else if (exp->type_exp == i_identifiant)
	{
		afficher_identifiant(exp->u.nom, indent);
	}
	else if (exp->type_exp == i_booleen)
	{
		afficher_booleen(exp->u.valeur, indent);
	}
	else if (exp->type_exp == i_liste_expr)
	{
		if (exp->u.nom != NULL)
		{
			afficher_n_liste(exp->u.liste_expr, indent);
		}
	}
	else if (exp->type_exp == i_appel_fonction)
	{
		afficher_n_appel_fonction(exp->u.appel_fonction, indent);
	}
	else if (exp->type_exp == i_non)
	{
		afficher("<non>", indent);
		afficher_n_exp(exp->u.exp, indent + 1);
		afficher("</non>", indent);
	}
	else if (exp->type_exp == i_moins)
	{
		afficher("<moins>", indent);
		afficher_n_exp(exp->u.exp, indent + 1);
		afficher("</moins>", indent);
	}
}

void afficher_n_liste(l_expr *liste, int indent)
{
	l_expr *l = liste;

	afficher("<liste>", indent);
	while (l->next != NULL)
	{
		afficher_n_exp(l->value, indent + 1);
		l = l->next;
	}
	afficher_n_exp(l->value, indent + 1);
	afficher("</liste>", indent);
}

void afficher_n_liste_parm(l_parm *liste, int indent)
{
	l_parm *l = liste;

	afficher("<liste_parametres>", indent);
	while (l->next != NULL)
	{
		afficher_n_parm(l->value, indent + 1);
		l = l->next;
	}
	afficher_n_parm(l->value, indent + 1);
	afficher("</liste_parametres>", indent);
}

void afficher_n_parm(n_parm *parm, int indent)
{
	afficher("<parametre>", indent);
	afficher_type(parm->type, indent + 1);
	afficher_identifiant(parm->nom, indent + 1);
	afficher("</parametre>", indent);
}

void afficher_n_operation(n_operation *operation, int indent)
{
	afficher("<operation>", indent);
	afficher(operation->type_operation, indent + 1);
	afficher_n_exp(operation->exp1, indent + 1);
	afficher_n_exp(operation->exp2, indent + 1);
	afficher("</operation>", indent);
}

void afficher_n_appel_fonction(n_appel_fonction *appel_fonction, int indent)
{
	afficher("<appel_fonction>", indent);
	afficher_identifiant(appel_fonction->nom, indent + 1);
	afficher_n_exp(appel_fonction->exp, indent + 1);
	afficher("</appel_fonction>", indent);
}

void afficher_n_declaration(n_declaration *declaration, int indent)
{
	afficher_type(declaration->type_declaration, indent + 1);
	afficher_identifiant(declaration->nom, indent + 1);
	if(declaration->exp != NULL)
		afficher_n_exp(declaration->exp, indent + 1);
}

n_programme *creer_n_programme(n_l_instructions *instructions)
{
	n_programme *n = malloc(sizeof(n_programme));
	n->instructions = instructions;
	return n;
}

n_l_instructions *creer_n_l_instructions(n_instruction *instruction, n_l_instructions *instructions)
{
	n_l_instructions *n = malloc(sizeof(n_l_instructions));
	n->instruction = instruction;
	n->instructions = instructions;
	return n;
}

n_instruction *creer_n_ecrire(n_exp *exp)
{
	n_instruction *n = malloc(sizeof(n_instruction));
	n->type_instruction = i_ecrire;
	n->u.exp = exp;
	return n;
}

n_exp *creer_n_lire()
{
	n_exp *n = malloc(sizeof(n_exp));
	n->type_exp = i_lire;
	return n;
}

n_instruction *creer_n_affectation(char *nom, n_exp *exp)
{
	n_affectation *aff = (n_affectation *)malloc(sizeof(n_affectation));
	aff->nom = nom;
	aff->exp = exp;

	n_instruction *n = malloc(sizeof(n_instruction));
	n->type_instruction = i_affectation;
	n->u.affectation = aff;
	return n;
}

n_instruction *creer_n_exp(n_exp *exp)
{
	n_instruction *ni = malloc(sizeof(n_exp));
	ni->u.exp = exp;
	ni->type_instruction = i_expression;
	return ni;
}

n_instruction *creer_n_fonction(char *type, char *nom, l_parm *parms, n_l_instructions *instructions)
{
	n_fonction *n = malloc(sizeof(n_fonction));
	n->type = type;
	n->nom = nom;
	n->parms = parms;
	n->instructions = instructions;

	n_instruction *ni = malloc(sizeof(n_instruction));
	ni->type_instruction = i_fonction;
	ni->u.fonction = n;
	return ni;
}

n_instruction *creer_n_declaration(char *type_declaration, char *nom, n_exp *exp)
{
	n_instruction *n = malloc(sizeof(n_instruction));
	n_declaration *n_de = malloc(sizeof(n_declaration));
	n->type_instruction = i_declaration;
	n->u.declaration = n_de;
	n_de->type_declaration = type_declaration;
	n_de->nom = nom;
	n_de->exp = exp;
	return n;
}

n_instruction *creer_n_cond(l_expr *cond)
{
	n_instruction *n = malloc(sizeof(n_instruction));
	n->type_instruction = i_cond;
	n->u.conds = cond;
	return n;
}

n_instruction *creer_n_retourner(n_exp *exp)
{
	n_instruction *n = malloc(sizeof(n_instruction));
	n->type_instruction = i_retourner;
	n->u.exp = exp;
	return n;
}

n_parm *creer_parm(char *type, char *nom)
{
	n_parm *parm = (n_parm *)malloc(sizeof(n_parm));
	parm->type = type;
	parm->nom = nom;
	return parm;
}

n_exp *creer_n_liste_expr(l_expr *liste)
{
	n_exp *n = malloc(sizeof(n_exp));
	n->type_exp = i_liste_expr;
	n->u.liste_expr = liste;
	return n;
}

n_exp *creer_n_moins(n_exp *exp)
{

	n_exp *n = malloc(sizeof(n_exp));
	n->type_exp = i_moins;
	n->u.exp = exp;
	return n;
}

n_exp *creer_n_condition(int type, n_exp *condition, n_l_instructions *block)
{

	Condition *c = malloc(sizeof(Condition));
	c->type = type;
	c->condition = condition;
	c->block = block;

	n_exp *n = malloc(sizeof(n_exp));
	n->type_exp = i_condition;
	n->u.condition = c;
	return n;
}

n_exp *creer_n_entier(int valeur)
{
	n_exp *n = malloc(sizeof(n_exp));
	n->type_exp = i_entier;
	n->u.valeur = valeur;
	return n;
}

n_exp *creer_n_non(n_exp *exp)
{
	n_exp *n = malloc(sizeof(n_exp));
	n->type_exp = i_non;
	n->u.exp = exp;
	return n;
}

n_exp *creer_n_appel_fonction(char *nom, n_exp *exp)
{

	n_appel_fonction *n_af = malloc(sizeof(n_appel_fonction));
	n_af->nom = nom;
	n_af->exp = exp;

	n_exp *n = malloc(sizeof(n_exp));
	n->type_exp = i_appel_fonction;
	n->u.appel_fonction = n_af;
	return n;
}

n_instruction *creer_n_instruction(n_exp *exp)
{
	n_instruction *n_ins = malloc(sizeof(n_instruction));
	n_ins->type_instruction = i_appel_fonction_ins;
	n_ins->u.exp = exp;

	return n_ins;
}

n_exp *creer_n_identifiant(char *nom)
{
	n_exp *n = malloc(sizeof(n_exp));
	n->type_exp = i_identifiant;
	n->u.nom = nom;
	return n;
}

n_exp *creer_n_booleen(int valeur)
{
	n_exp *n = malloc(sizeof(n_exp));
	n->type_exp = i_booleen;
	n->u.valeur = valeur;
	return n;
}

n_exp *creer_n_operation(char *type_operation, n_exp *exp1, n_exp *exp2)
{
	n_exp *n = malloc(sizeof(n_exp));
	n_operation *n_op = malloc(sizeof(n_operation));
	n->u.operation = n_op;
	n->type_exp = i_operation;
	n_op->type_operation = type_operation;
	n_op->exp1 = exp1;
	n_op->exp2 = exp2;
	return n;
}
