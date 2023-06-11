#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre_abstrait.h"
#include "generation_code.h"
#include "table_symboles.h"

//pour afficher le code uniquement si l'option afficher_nasm vaut 1
#define printifm(format, ...) if(afficher_nasm){ printf(format, __VA_ARGS__); }
int labelgenerate = 0;
int isFonction = 1;
int indexFonction = -1;
static Symbole * symboles[MAX_SYMBOLES];
int nb_symboles = 0;

int afficher_nasm = 1;

/* fonction locale, permet d'afficher un commentaire */
void nasm_comment(char *comment) {
  if(comment != NULL) {
    printifm("\t\t ; %s", comment);//le point virgule indique le début d'un commentaire en nasm. Les tabulations sont là pour faire jolie.
  }
  printifm("%s","\n");
}

/*
Affiche une commande nasm sur une ligne
Par convention, les derniers opérandes sont nuls si l'opération a moins de 3 arguments.
*/
void nasm_commande(char *opcode, char *op1, char *op2, char *op3, char *comment) {
  printifm("\t%s", opcode);
  if(op1 != NULL) {
    printifm("\t%s", op1);
    if(op2 != NULL) {
      printifm(", %s", op2);
      if(op3 != NULL) {
        printifm(", %s", op3);
      }
    }
  }
  nasm_comment(comment);
}


void nasm_prog(n_programme *n)
{
  printifm("%%include\t'%s'\n","io.asm");
  printifm("%s","\nsection\t.bss\n");
  nasm_liste_variable_name(n->instructions);
  printifm("%s", "sinput:\tresb\t255\t;reserve a 255 byte space in memory for the users input string\n");
  printifm("%s","\nsection\t.text\n");
  printifm("%s","global _start\n");
  nasm_define_symbole(n->instructions);
  printifm("%s","_start:\n");
  nasm_liste_instructions(n->instructions);
  //pour quitter le programme
  nasm_commande("mov", "eax", "1" , NULL, "1 est le code de SYS_EXIT");
  nasm_commande("mov", "ebx", "0" , NULL, NULL);
  nasm_commande("int", "0x80", NULL, NULL, "exit");
}

void nasm_define_symbole(n_l_instructions *n) {
  do {
    if (n->instruction != NULL){
      if(n->instruction->type_instruction == i_fonction) {
        
        //printifm("%s","\nsection\t.text\n");
        n_fonction *func = n->instruction->u.fonction;
        
        char * func_name = malloc(strlen(func->nom) + 1);
        sprintf(func_name, "_%s", func->nom);
        //printifm("%s %s\n","global", func_name);
        if(strcmp(func->type, "ENTIER") == 0)
        {
          ajouter_symbole_entier(symboles, &nb_symboles, func->nom, func);
        }
        else if(strcmp(func->type, "BOOLEEN") == 0)
        {
          ajouter_symbole_booleen(symboles, &nb_symboles, func->nom, func);
        }
        else {
          printf("Erreur de type de variable");
          exit(1);
        }
      }
    }
    n = n->instructions;
  } while(n != NULL );
  nasm_define_all_fonction();
}

void nasm_define_all_fonction()
{
  for(int i = 0; i < nb_symboles; i++)
  {
    indexFonction = i;
    nasm_define_fonction(symboles[i]->n);
  }
}

void nasm_define_fonction(n_fonction *n)
{
  isFonction = 1;

  char * name = n->nom;
  char * func_name = malloc(strlen(name) + 2);
  sprintf(func_name, "_%s:", name);
  nasm_commande(func_name, NULL, NULL, NULL, "declaration de fonction");
  nasm_liste_instructions(n->instructions);
  isFonction = 0;
}

void nasm_appel_fonction(n_appel_fonction *n)
{
  int i = trouver_symbole(symboles, nb_symboles, n->nom);
  char * func_name = malloc(strlen(n->nom) + 1);
  sprintf(func_name, "_%s", n->nom);
  if(i!=-1) {
    if(symboles[i]->type == entier)
    {
      nasm_commande("call", func_name, NULL, NULL, "appel de fonction");
    }
    else if(symboles[i]->type == booleen)
    {
      nasm_commande("call", func_name, NULL, NULL, "appel de fonction");
    }
    else {
      printf("Erreur de type de variable");
      exit(1);
    }
  }
  else {
    printf("Erreur : fonction non déclarée");
    exit(1);
  }
}

void nasm_liste_variable_name(n_l_instructions *n)
{
	do {
		if (n->instruction != NULL)
    {
			if(n->instruction->type_instruction == i_declaration)
      {
        n_declaration *declaration = n->instruction->u.declaration;
        char *data = "dd 0";
        nasm_commande(declaration->nom, data, NULL, NULL, "declaration de variable");
      }
		}
		n = n->instructions;
	} while(n != NULL );
}

void nasm_liste_instructions(n_l_instructions *n) {
	do {
		if (n->instruction != NULL){
			nasm_instruction(n->instruction);
		}
		n = n->instructions;
	} while(n != NULL );
}

void nasm_instruction(n_instruction* n){
	if(n->type_instruction == i_ecrire){
		nasm_exp(n->u.exp);
		nasm_commande("pop", "eax", NULL, NULL, NULL); //on dépile la valeur d'expression sur eax
		nasm_commande("call", "iprintLF", NULL, NULL, NULL); //on envoie la valeur d'eax sur la sortie standard
	}
  else if(n->type_instruction == i_cond) {
    nasm_condition(n->u.conds);
  }
  else if(n->type_instruction == i_retourner) {
    if(isFonction == 1) {
      if((n->u.exp->type_exp == i_entier && symboles[indexFonction]->type == entier) || (n->u.exp->type_exp == i_booleen && symboles[indexFonction]->type == booleen)){
        nasm_exp(n->u.exp);
        nasm_commande("pop", "eax", NULL, NULL, NULL); //on dépile la valeur d'expression sur eax
        nasm_commande("ret", NULL, NULL, NULL, "retour de fonction");
      }
      else if(n->u.exp->type_exp == i_appel_fonction)
      {
        printf(";%d\n", trouver_symbole(symboles, nb_symboles, n->u.exp->u.appel_fonction->nom));
        printf(";%d\n", symboles[indexFonction]->type);
        if( trouver_symbole(symboles, nb_symboles, n->u.exp->u.appel_fonction->nom) == symboles[indexFonction]->type)
        {
          nasm_exp(n->u.exp);
          nasm_commande("pop", "eax", NULL, NULL, NULL); //on dépile la valeur d'expression sur eax
          nasm_commande("ret", NULL, NULL, NULL, "retour de fonction");
        }
        else {
          printf("Erreur : type de retour de fonction la fonction appelée est incorrect");
          exit(1);
        }
      }
      else {
        printf("Erreur : type de retour de fonction incorrect");
        exit(1);
      }
    }
    else {
      printf("Erreur : return en dehors d'une fonction");
      exit(1);
    }
  }
}

void nasm_condition(l_expr* n) {
  Condition *condition = n->value->u.condition;
  if(condition->type == 3)
  { //tant que loop
    labelgenerate++;
    char *label_debut = malloc(sizeof(char) * 10);
    char *label_fin = malloc(sizeof(char) * 10);
    char *label_debut_p = malloc(sizeof(char) * 10);
    char *label_fin_p = malloc(sizeof(char) * 10);

    sprintf(label_debut_p, "loop%d :", labelgenerate);
    sprintf(label_fin_p, "endloop%d :", labelgenerate);
    sprintf(label_debut, "loop%d", labelgenerate);
    sprintf(label_fin, "endloop%d", labelgenerate);
    
    nasm_commande(label_debut_p, NULL, NULL, NULL, NULL);  // Label du début de la boucle
    nasm_exp(condition->condition);  // Évaluation de la condition
    nasm_commande("pop", "eax", NULL, NULL, NULL);  // Récupération de la valeur de la condition
    nasm_commande("cmp", "eax", "0", NULL, NULL);  // Comparaison de la valeur de la condition avec 0
    nasm_commande("je", label_fin, NULL, NULL, NULL);  // Saut à la fin de la boucle si la condition est fausse
    
    nasm_liste_instructions(condition->block);  // Exécution des instructions de la boucle
    nasm_commande("jmp", label_debut, NULL, NULL, NULL);  // Saut au début de la boucle
    
    nasm_commande(label_fin_p, NULL, NULL, NULL, NULL);  // Label de fin de la boucle
  }

  else if(condition->type == 0 || condition->type == 1)
  { //si
    labelgenerate++;
    char *label_debut = malloc(sizeof(char) * 10);
    char *label_fin = malloc(sizeof(char) * 10);
    char *label_debut_p = malloc(sizeof(char) * 10);
    char *label_fin_p = malloc(sizeof(char) * 10);

    sprintf(label_debut_p, "si%d :", labelgenerate);
    sprintf(label_fin_p, "endsi%d :", labelgenerate);
    sprintf(label_debut, "si%d", labelgenerate);
    sprintf(label_fin, "endsi%d", labelgenerate);
    setopcond(n->value, label_debut, label_fin);
    if(n->next && (n->next->value->u.condition->type == 1 || n->next->value->u.condition->type == 2))
    {
      nasm_condition(n->next);
    }
    nasm_commande("jmp", label_fin, NULL, NULL, NULL);
    nasm_commande(label_debut_p, NULL, NULL, NULL, NULL);
    nasm_liste_instructions(condition->block);
    nasm_commande(label_fin_p, NULL, NULL, NULL, NULL);
  }
  else if(condition->type == 2)
  { //else
    nasm_liste_instructions(condition->block);
  }
}

void setopcond(n_exp * n, char* label_debut, char* label_fin){
  if(n->u.condition->condition && n->u.condition->condition->type_exp == i_condition)
  {
    Condition * condition = n->u.condition;
    nasm_exp(condition->condition);  // Évaluation de la condition
    nasm_commande("pop", "eax", NULL, NULL, NULL);  // Récupération de la valeur de la condition
    nasm_commande("cmp", "eax", "0", NULL, NULL);  // Comparaison de la valeur de la condition avec 0
  }
  else if(n->u.condition->condition->type_exp == i_booleen) {
    nasm_exp(n->u.condition->condition);
    nasm_commande("pop", "eax", NULL, NULL, NULL);  // Récupération de la valeur de la condition
    nasm_commande("cmp", "eax", "1", NULL, NULL);  // Comparaison de la valeur de la condition avec 0
  }
  else {
    printf("Erreur : la condition doit être un booléen\n");
    exit(1);
  }
  nasm_commande("je", label_debut, NULL, NULL, NULL);
}

void nasm_exp(n_exp* n){
	if (n->type_exp == i_operation)
  {
		nasm_operation(n->u.operation);
	}
  else if(n->type_exp == i_lire)
  {
    nasm_lire();
  }
  else if (n->type_exp == i_non)
  {
    if(n->u.exp->type_exp != i_booleen)
    {
      if(n->u.exp->type_exp == i_operation)
      {
        verif_type(n->u.exp->u.operation);
      }
      else if(n->u.exp->type_exp == i_appel_fonction) {
        if(trouver_type_symbole(symboles, nb_symboles, n->u.exp->u.appel_fonction->nom) != booleen) 
        {
          printf("La fonction n'existe pas ou ne retourne pas de booleen\n");
          exit(1);
        }
      }
      else {
      printf("Erreur : le non logique ne peut s'appliquer qu'à des booléens\n");
      exit(1);
      }
    }
    nasm_exp(n->u.exp);
    nasm_commande("pop", "eax", NULL, NULL, NULL);
    nasm_commande("xor", "eax", "1", NULL, "NOT");
    nasm_commande("push", "eax", NULL, NULL, NULL);
  }
  else if (n->type_exp == i_entier)
  {
	  char buffer[10];
	  sprintf(buffer, "%d", n->u.valeur);
    nasm_commande("push", buffer, NULL, NULL, NULL) ;
	}
  else if (n->type_exp == i_booleen) {
    if (n->u.valeur == 1) {
      nasm_commande("push", "1", NULL, NULL, "VRAI") ;
    }
    else {
      nasm_commande("push", "0", NULL, NULL, "FAUX") ;
    }
  }
  else if( n->type_exp == i_appel_fonction) {
    nasm_appel_fonction(n->u.appel_fonction);
    nasm_commande("push", "eax", NULL, NULL, NULL);
  }

}



void nasm_operation(n_operation* n){
  verif_type(n);
    nasm_exp(n->exp1);
    nasm_exp(n->exp2);
    nasm_commande("pop", "ebx", NULL, NULL, "depile la seconde operande dans ebx");
    nasm_commande("pop", "eax", NULL, NULL, "depile la permière operande dans eax");
    if (strcmp(n->type_operation, "+") == 0)
    {
        nasm_commande("add", "eax", "ebx", NULL, "effectue l'opération +");
    }
    else  if (strcmp(n->type_operation, "-") == 0)
    {
        nasm_commande("sub", "eax", "ebx", NULL, "effectue l'opération -");
    }
    else if (strcmp(n->type_operation, "*") == 0)
    {
      nasm_commande("imul", "ebx", NULL, NULL, "effectue l'opération *");
    }
    else if (strcmp(n->type_operation, "/") == 0)
    {
      nasm_commande("cdq", NULL, NULL, NULL, "Étendre le signe du dividende à EDX");
      nasm_commande("idiv", "ebx", NULL, NULL, "effectue l'opération /");
    }
    else if (strcmp(n->type_operation, "%") == 0)
    {
      nasm_commande("cdq", NULL, NULL, NULL, "Étendre le signe du dividende à EDX");
      nasm_commande("idiv", "ebx", NULL, NULL, "effectue l'opération %");
      nasm_commande("mov", "eax", "edx", NULL, "déplace le reste dans eax");
    }
    else if (strcmp(n->type_operation, "OU") == 0)
    {
      nasm_commande("or", "eax", "ebx", NULL, "OU");
    }
    else if (strcmp(n->type_operation, "ET") == 0)
    {
      nasm_commande("and", "eax", "ebx", NULL, "ET");
    }
    else if (strcmp(n->type_operation, "<") == 0)
    {
      nasm_commande("cmp", "eax", "ebx", NULL, NULL);
      nasm_commande("setl", "al", NULL, NULL, "INF");
      nasm_commande("movzx", "eax", "al", NULL, NULL);
    }
    else if (strcmp(n->type_operation, ">") == 0)
    {
      nasm_commande("cmp", "eax", "ebx", NULL, NULL);
      nasm_commande("setg", "al", NULL, NULL, "SUP");
      nasm_commande("movzx", "eax", "al", NULL, NULL);
    }
    else if (strcmp(n->type_operation, "<=") == 0)
    {
      nasm_commande("cmp", "eax", "ebx", NULL, NULL);
      nasm_commande("setle", "al", NULL, NULL, "INFEG");
      nasm_commande("movzx", "eax", "al", NULL, NULL);
    }
    else if (strcmp(n->type_operation, ">=") == 0)
    {
      nasm_commande("cmp", "eax", "ebx", NULL, NULL);
      nasm_commande("setge", "al", NULL, NULL, "SUPEG");
      nasm_commande("movzx", "eax", "al", NULL, NULL);
    }
    else if (strcmp(n->type_operation, "==") == 0)
    {
      nasm_commande("cmp", "eax", "ebx", NULL, NULL);
      nasm_commande("sete", "al", NULL, NULL, "EG");
      nasm_commande("movzx", "eax", "al", NULL, NULL);
    }
    else if (strcmp(n->type_operation, "!=") == 0)
    {
      nasm_commande("cmp", "eax", "ebx", NULL, NULL);
      nasm_commande("setne", "al", NULL, NULL, "DIFF");
      nasm_commande("movzx", "eax", "al", NULL, NULL);
    }
  nasm_commande("push",  "eax" , NULL, NULL, "empile le résultat");  
}

void nasm_lire() {
  nasm_commande("mov", "eax", "sinput", NULL, "empile l'adresse de la chaine de caractère");
  nasm_commande("call", "readline", NULL, NULL, "lire une chaine de caractère");
  nasm_commande("call", "atoi", NULL, NULL, "converti la chaine de caractère en entier");
  nasm_commande("push", "eax", NULL, NULL, "empile le résultat");
}

int verif_type(n_operation* n) {

  if (strcmp(n->type_operation, "OU") == 0 || strcmp(n->type_operation, "ET") == 0)
  {
    if(n->exp1->type_exp != i_booleen)
    {
      if(n->exp1->type_exp == i_operation)
        verif_type(n->exp1->u.operation);
      else if(n->exp1->type_exp == i_non)
      {
        if(n->exp1->u.exp->type_exp == i_operation)
        {
          verif_type(n->exp1->u.exp->u.operation);
        }
      }
      else if(n->exp1->type_exp == i_appel_fonction)
      {
          if(trouver_type_symbole(symboles, nb_symboles, n->exp1->u.appel_fonction->nom) != booleen)
          {
            printf("Erreur : les deux opérandes doivent être des booléens\n");
            exit(1);
          }
      }
      else {
        printf("Erreur : les deux opérandes doivent être des booléens\n");
        exit(1);
      }
    }
    if(n->exp2->type_exp != i_booleen)
    {
      if(n->exp2->type_exp == i_operation)
        verif_type(n->exp2->u.operation);
      else if(n->exp2->type_exp == i_non)
      {
        if(n->exp2->u.exp->type_exp == i_operation)
        {
          verif_type(n->exp2->u.exp->u.operation);
        }
      }
      else if(n->exp2->type_exp == i_appel_fonction)
      {
          if(trouver_type_symbole(symboles, nb_symboles, n->exp2->u.appel_fonction->nom) != booleen)
          {
            printf("Erreur : les deux opérandes doivent être des booléens\n");
            exit(1);
          }
      }
      else
      {
        printf("Erreur : les deux opérandes doivent être des booléens\n");
        exit(1);
      }
    }
  }
  else if (strcmp(n->type_operation, "+") == 0 || strcmp(n->type_operation, "-") == 0
  || strcmp(n->type_operation, "*") == 0 || strcmp(n->type_operation, "/") == 0 
  || strcmp(n->type_operation, "%") == 0
  || strcmp(n->type_operation, "<") == 0 || strcmp(n->type_operation, ">") == 0 || strcmp(n->type_operation, "<=") == 0 
  || strcmp(n->type_operation, ">=") == 0 || strcmp(n->type_operation, "==") == 0 || strcmp(n->type_operation, "!=") == 0)
  {
    if(n->exp1->type_exp != i_entier && n->exp1->type_exp != i_lire)
    {
      if(n->exp1->type_exp == i_operation)
        verif_type(n->exp1->u.operation);
      else if(n->exp1->type_exp == i_non)
      {
        if(n->exp1->u.exp->type_exp == i_operation)
        {
          verif_type(n->exp1->u.exp->u.operation);
        }
      }
      else if(n->exp1->type_exp == i_appel_fonction)
      {
          if(trouver_type_symbole(symboles, nb_symboles, n->exp1->u.appel_fonction->nom) != entier)
          {
            printf("Erreur : les deux opérandes doivent être des entiers\n");
            exit(1);
          }
      }
      else
      {
        printf("Erreur : les deux opérandes doivent être des entiers\n");
        exit(1);
      }
    }
    if(n->exp2->type_exp != i_entier && n->exp2->type_exp != i_lire)
    {
      if(n->exp2->type_exp == i_operation)
        verif_type(n->exp2->u.operation);
      else if(n->exp2->type_exp == i_non)
      {
        if(n->exp2->u.exp->type_exp == i_operation)
        {
          verif_type(n->exp2->u.exp->u.operation);
        }
      }
      else if(n->exp2->type_exp == i_appel_fonction)
      {
          if(trouver_type_symbole(symboles, nb_symboles, n->exp2->u.appel_fonction->nom) != entier)
          {
            printf("Erreur : les deux opérandes doivent être des entiers\n");
            exit(1);
          }
      }
      else
      {
        printf("Erreur : les deux opérandes doivent être des entiers\n");
        exit(1);
      }
    }
  }
  return 0;
}