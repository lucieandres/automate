%{
#include <stdlib.h>
#include <stdio.h>
#include "arbre_abstrait.h"
#include "analyse_lexicale.h"


//n_programme* yyparse();
int yylex();
int yyerror(const char *s);
n_programme* arbre_abstrait;
%}

%union {
    int entier;
    n_programme* prog;
    n_l_instructions* l_inst;
    n_instruction* inst;
    l_expr* l_exp;
    n_exp* exp;
    n_parm* parm;
    l_parm* l_parm;
    char* string;
}


%define parse.error detailed
%define parse.lac full
//Symboles terminaux qui seront fournis par yylex(), ordre non important

%token <string> IDENTIFIANT
%token EGALE
%token PLUS
%token MOINS
%token DIFFERENT
%token FOIS
%token TYPE_ENTIER
%token PARENTHESE_OUVRANTE
%token PARENTHESE_FERMANTE
%token POINT_VIRGULE
%token SI
%token LE
%token GE
%token GT
%token EQ
%token OU
%token ET
%token RETOURNER
%token <entier> ENTIER
%token ECRIRE
%token LIRE
%token FIN 0
%token TYPE_BOOLEEN
%token VRAI
%token FAUX
%token TANTQUE
%token NON
%token DIVISER
%token MODULO
%token SINON
%token LT
%token BLOC_OUVRANT
%token BLOC_FERMANT
%token VIRGULE

%type <prog> prog
%type <l_inst> listeInstructions
%type <inst> instruction
%type <inst> ecrire
%type <exp> lire
%type <inst> affectation

%type <inst> fonction

%type <l_exp> liste_expr
%type <l_exp> conditionSi
%type <inst> cond 

%type <exp> expr
%type <exp> logique
%type <exp> comparaison
%type <exp> terme
%type <exp> produit
%type <inst> retourner
%type <exp> VRAI

%type <l_parm> list_parms 
%type <parm> parms 

%type <exp> facteur 
%type <string> type 

%type <inst> declarationVariable 

%left OU
%left ET
%left NON
%left EQ DIFFERENT
%left LT LE GT GE
%left PLUS MOINS
%left FOIS DIVISER MODULO

%%

prog: 
    listeInstructions { arbre_abstrait = creer_n_programme($1); }

listeInstructions: 
    instruction {
        $$ =creer_n_l_instructions($1 ,NULL);
    } 
    |   instruction listeInstructions {
        $$ =creer_n_l_instructions($1 ,$2);
    } 
    |   { $$ = NULL; }
;

instruction: 
        declarationVariable { $$ = $1; }
    |   fonction { $$ = $1; }
    |   affectation { $$ = $1; }
    |   ecrire { $$ =$1; }
    |   retourner { $$ = $1; }
    |   cond { $$ = $1; }
    |   expr POINT_VIRGULE { $$ = creer_n_exp($1); }

fonction:
    type IDENTIFIANT PARENTHESE_OUVRANTE list_parms PARENTHESE_FERMANTE BLOC_OUVRANT listeInstructions BLOC_FERMANT { $$ = creer_n_fonction($1, $2, $4, $7); }
;

declarationVariable:
        type IDENTIFIANT EGALE expr POINT_VIRGULE { $$ = creer_n_declaration($1, $2, $4); }
    |   type IDENTIFIANT POINT_VIRGULE { $$ = creer_n_declaration($1, $2, NULL); }
;

parms:
    type IDENTIFIANT { $$ = creer_parm($1, $2); }
;

list_parms:
        parms { $$ = creerListeParm($1); } 
    |   parms VIRGULE list_parms { $$ = ajouterListeParm($3, $1); } 
    |   { $$ = NULL; }
;

ecrire: ECRIRE PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE POINT_VIRGULE {
	
	$$ =creer_n_ecrire($3);
}

liste_expr:
        expr    { $$ = creerListeExpr($1); }
    |   expr VIRGULE liste_expr { $$ = ajouterListe($3, $1); }
    |   { $$ = NULL; }
;

lire : LIRE PARENTHESE_OUVRANTE PARENTHESE_FERMANTE { $$ = creer_n_lire(); }


expr:
    logique { $$ = $1; }
    |   terme { $$ = $1; }
    |   IDENTIFIANT PARENTHESE_OUVRANTE liste_expr PARENTHESE_FERMANTE { $$ = creer_n_appel_fonction($1, creer_n_liste_expr($3)); }
    |   PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE { $$ = $2; }
    |   IDENTIFIANT { $$ = creer_n_identifiant($1); }
    |   expr PLUS terme { $$ = creer_n_operation("+", $1, $3); }
    |   expr MOINS terme { $$ = creer_n_operation("-", $1, $3); }
    ;

logique:
    NON logique { $$ = creer_n_non($2); }
    |   FAUX { $$ = creer_n_booleen(0); }
    |   VRAI { $$ = creer_n_booleen(1); }
    |   logique ET logique { $$ = creer_n_operation("ET", $1, $3); }
    |   logique OU logique { $$ = creer_n_operation("OU", $1, $3); }
    |   comparaison { $$ = $1; }
    ;
    

comparaison:
    comparaison LT terme { $$ = creer_n_operation("<", $1, $3); }
    | comparaison LE terme { $$ = creer_n_operation("<=", $1, $3); }
    | comparaison GT terme { $$ = creer_n_operation(">", $1, $3); }
    | comparaison GE terme { $$ = creer_n_operation(">=", $1, $3); }
    | comparaison EQ terme { $$ = creer_n_operation("==", $1, $3); }
    | comparaison DIFFERENT terme { $$ = creer_n_operation("!=", $1, $3); }
    | terme { $$ = $1; }
    ;

terme:
    terme PLUS produit { $$ = creer_n_operation("+", $1, $3); }
    |   terme MOINS produit { $$ = creer_n_operation("-", $1, $3); }
    |   produit { $$ = $1; }
    ;

produit:
    produit FOIS facteur { $$ = creer_n_operation("*", $1, $3); }
    | produit DIVISER facteur { $$ = creer_n_operation("/", $1, $3); }
    | produit MODULO facteur { $$ = creer_n_operation("%", $1, $3); }
    | facteur { $$ = $1; }
    ;

facteur:
    ENTIER { $$ = creer_n_entier($1); }
    | IDENTIFIANT { $$ = creer_n_identifiant($1); }
    | MOINS ENTIER { $$ = creer_n_entier(-$2); }
    | PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE { $$ = $2; }
    | IDENTIFIANT PARENTHESE_OUVRANTE liste_expr PARENTHESE_FERMANTE { $$ = creer_n_appel_fonction($1, creer_n_liste_expr($3)); }
    | lire { $$ = $1; }
    ;


affectation:
    IDENTIFIANT EGALE expr POINT_VIRGULE { $$ = creer_n_affectation($1, $3); }
;

conditionSi:
        SI PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE BLOC_OUVRANT listeInstructions BLOC_FERMANT { $$ = creerListeExpr(creer_n_condition(0, $3, $6)); }
    |   conditionSi SINON conditionSi { 
        $3->value->u.condition->type = 1;  // met le type a 1 pour dire que c'est un sinon si
        $$ = ajouterListeElementList($3, $1); 
    }
    |   conditionSi SINON BLOC_OUVRANT listeInstructions BLOC_FERMANT  { 
        $$ = creerListeExpr(creer_n_condition(2, NULL, $4)); // met le type a 2 pour dire que c'est un sinon
        $$ = ajouterListeElementList($$, $1);
    }
;

cond: 
        conditionSi { $$ = creer_n_cond($1); }
    |   TANTQUE PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE BLOC_OUVRANT listeInstructions BLOC_FERMANT {
        $$ = creer_n_cond(creerListeExpr(creer_n_condition(3, $3, $6)));
    }


retourner:
        RETOURNER expr POINT_VIRGULE { $$ = creer_n_retourner($2); }
    |   RETOURNER expr { $$ = creer_n_retourner($2); }
;

type	:	
	    TYPE_ENTIER     { $$ = "ENTIER"; }
    |   TYPE_BOOLEEN    { $$ = "BOOLEEN"; }
;


%%

int yyerror(const char *s) {
    printf("yyerror : %s\n",s);
    return 0;
}

