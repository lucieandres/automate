#ifndef __ARBRE_ABSTRAIT__
#define __ARBRE_ABSTRAIT__

/* Abbréviations: 
  * n -> noeud
  * l -> liste
  * exp -> expression (arithmétique)
*/


typedef struct n_programme n_programme; /* Noeud du type programme */
typedef struct n_l_instructions n_l_instructions; /* Noeud du type liste d'instructions */
typedef struct n_instruction n_instruction; /* Noeud du type liste instruction */
typedef struct n_ecrire n_ecrire; /* Noeud du type instruction ecrire */
typedef struct n_exp n_exp; /* Noeud du type expression (arithmétique) */
typedef struct n_operation n_operation; /* Noeud du type operation (arithmétique) */
typedef struct n_declaration n_declaration; /* Noeud du type declaration (arithmétique) */

struct n_programme{   // pour le moment un programme est juste une liste d'instructions. Il faudra ajouter une liste de définitions de fonctions.
  n_l_instructions* instructions;	
};

struct n_l_instructions{
	n_instruction* instruction;
	n_l_instructions* instructions;
};

typedef struct n_parm{
  char *type;
  char *nom;
} n_parm;

typedef struct l_parm{
  n_parm* value;
  struct l_parm* next;
} l_parm;

typedef struct n_fonction{
  char *type;
  char *nom;
  l_parm *parms;
  n_l_instructions* instructions;
} n_fonction;

typedef struct n_appel_fonction{
  char *nom;
  n_exp* exp;
} n_appel_fonction;

typedef struct n_affectation{
  char *nom;
  n_exp* exp;
} n_affectation;


typedef struct l_expr{
  n_exp* value;
  struct l_expr* next;
} l_expr;


struct n_instruction{
  enum { 
    i_ecrire,
    i_declaration,
    i_fonction,
    i_cond,
    i_retourner,
    i_affectation
  } type_instruction; // pour le moment une instruction peut-être uniquement de type écrire. Il faudra ajouter affectation, exécution de fonction, si,sinon, etc...
  union{ 
    n_exp* exp; // pour ecrire(exp);
    n_declaration* declaration;
    n_fonction* fonction;
    l_expr* conds;
    n_affectation* affectation;
  }u;
};

typedef struct Condition{
  int type; // 0 = if, 1 = else if, 2 = else, // 3 = tantQue
  n_exp* condition;
  n_l_instructions* block;
} Condition;


struct n_exp{
  enum { 
    i_operation,
    i_entier,
    i_identifiant,
    i_booleen,
    i_liste_expr,
    i_appel_fonction,
    i_condition,
    i_non
  } type_exp; // pour le moment une expression  peut-être une opération ou un entier
  union{ 
    n_operation* operation;
    l_expr* liste_expr;
    n_appel_fonction* appel_fonction;
    Condition* condition;
    n_exp* exp;
    int valeur;
    char* nom;
  }u;
};

struct n_declaration {
  char *type_declaration;
  char *nom;
  n_exp* exp;
};

struct n_operation{
  char *type_operation;
  n_exp* exp1;
  n_exp* exp2;
};


l_expr * creerListeExpr(n_exp * exp);
l_expr * ajouterListe(l_expr * liste, n_exp * exp);
l_expr *ajouterListeElementList(l_expr *liste, l_expr *liste2);

l_parm *creerListeParm(n_parm *parm);
l_parm *ajouterListeParm(l_parm *liste, n_parm *exp);

void afficher_n_programme(n_programme* prog,int indent);
void afficher_n_fonction(n_fonction *fonction, int indent);
void afficher_n_l_instructions(n_l_instructions* instructions ,int indent);
void afficher_n_instruction(n_instruction* instruction ,int indent);
void afficher_n_ecrire(n_ecrire* ecrire,int indent);
void afficher_n_exp(n_exp* exp ,int indent);
void afficher_n_operation(n_operation* operation ,int indent);
void afficher_n_liste(l_expr *liste, int indent);
void afficher_n_appel_fonction(n_appel_fonction *appel_fonction, int indent);
void afficher_n_liste_parm(l_parm *liste, int indent);
void afficher_n_declaration(n_declaration *declaration, int indent);
void afficher_conds(l_expr *liste, int indent);
void afficher_cond(n_exp *exp, int indent);
void afficher_n_parm(n_parm *parm, int indent);

n_programme *creer_n_programme(n_l_instructions *instructions);
n_instruction *creer_n_fonction(char *type, char *nom, l_parm *parms, n_l_instructions *instructions);
n_l_instructions* creer_n_l_instructions(n_instruction* instruction ,n_l_instructions* instructions);
n_instruction *creer_n_declaration(char *type_declaration, char *nom, n_exp *exp);
n_instruction* creer_n_ecrire(n_exp* exp);
n_exp* creer_n_liste_expr(l_expr* liste);
n_exp *creer_n_appel_fonction(char *nom, n_exp *exp);
n_exp* creer_n_entier(int valeur);
n_exp* creer_n_identifiant(char *nom);
n_exp* creer_n_booleen(int valeur);
n_exp* creer_n_operation(char *type_operation, n_exp* exp1, n_exp* exp2);
n_parm * creer_parm(char *type, char *nom);
n_exp *creer_n_condition(int type, n_exp* condition, n_l_instructions *block);
n_instruction *creer_n_cond(l_expr *cond);
n_instruction *creer_n_retourner(n_exp *exp);
n_exp *creer_n_non(n_exp* exp);
n_instruction *creer_n_affectation(char *nom, n_exp* exp);

#endif
