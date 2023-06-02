/*
 * Analyseur lexical du compilateur L en FLEX
 */
%{
#include "arbre_abstrait.h"
#include "symboles.h"
%}
%option yylineno
%option nounput
%option noinput


entier               ([1-9][0-9]*|0)
chiffre              [0-9]
lettre               [a-zA-Z]
alphanum             ({lettre}|{chiffre})
espace               [ \t\r\n]

%%
"#".*                { /* Ignorer commentaires */  }
{espace}+            { /* Ignorer espaces */       }
"+"                  { return PLUS;                }
"-"                  { return MOINS;                }
"*"                  { return FOIS;                }
"/"                  { return DIVISER;                }
"%"                  { return MODULO;                }
"("                  { return PARENTHESE_OUVRANTE; }
")"                  { return PARENTHESE_FERMANTE; }
"{"                  { return BLOC_OUVRANT; }
"}"                  { return BLOC_FERMANT; }
"ecrire"             { return ECRIRE;              }
";"                  { return POINT_VIRGULE;       }
"entier"             { return TYPE_ENTIER;       }
"booleen"            { return TYPE_BOOLEEN;       }
"Vrai"            { return VRAI;       }
"Faux"            { return FAUX;       }
"si"                 { return SI;       }
"<="                 { return LE;       }
">"                 { return GT;       }
"<"                 { return LT;       }
">="                 { return GE;       }
"ou"                 { return OU;       }
"et"                 { return ET;       }
"sinon"                 { return SINON;       }
"retourner"                 { return RETOURNER;       }
"="                  { return EGALE; }
"tantQue"                  { return TANTQUE; }
","                  { return VIRGULE; }
"non"                 { return NON;       }
{entier}             { yylval.entier=atoi(yytext); return ENTIER;}
{lettre}{alphanum}*  { yylval.string=strdup(yytext); return IDENTIFIANT; }
<<EOF>>              { return FIN; }  /* Fin de fichier */
.                    {                                /* Erreur, autre caractètre quelconque */
                       fprintf( stderr, "Ligne %d: caractère invalide: %s\n", yylineno,yytext ); \
                       exit(-1); 
                     } 
%%
int yywrap(){
  return 1;
}

/*******************************************************************************
 * Fonction auxiliaire qui donne le nom des différents tokens
 ******************************************************************************/

int token_fermes[] = {
  PLUS,
  MOINS,
  FOIS,
  DIVISER,
  MODULO,
  PARENTHESE_OUVRANTE,
  PARENTHESE_FERMANTE,
  BLOC_OUVRANT,
  BLOC_FERMANT,
  ECRIRE,
  POINT_VIRGULE,
  TYPE_ENTIER,
  TYPE_BOOLEEN,
  VRAI,
  FAUX,
  SI,
  LE,
  GT,
  LT,
  GE,
  OU,
  ET,
  SINON,
  RETOURNER,
  EGALE,
  TANTQUE,
  VIRGULE,
  NON
};
char *str_token[] = {
  "+",
  "-",
  "*",
  "/",
  "%",
  "(",
  ")",
  "{",
  "}",
  "ECRIRE",
  ";",
  "ENTIER",
  "BOOLEEN",
  "VRAI",
  "FAUX",
  "SI",
  "<=",
  "<",
  ">",
  ">=",
  "OU",
  "ET",
  "SINON",
  "RETOURNER",
  "EGALE",
  "TANTQUE",
  ",",
  "NON"
};

int nbMotsClefs = 28;

void nom_token( int token, char *nom, char *valeur ) {   

  for(int i = 0; i < nbMotsClefs;i++){
  	if(token == token_fermes[i]){
  	  strcpy( nom, "symbole" );
  	  strcpy( valeur, str_token[i]);
  	  return;
  	}
  }
  
  if( token == ENTIER ) {
    strcpy( nom, "entier" );
    strcpy( valeur, yytext );
  }
  else if( token == IDENTIFIANT ) {
    strcpy( nom, "identifiant" );  
    strcpy( valeur, yytext );      
  }
}

/*******************************************************************************
 * Fonction auxiliaire appelée par le compilateur en mode -l pour tester l'analyse
 * lexicale. Le fichier source doit être indiqué dans la variable globale yyin.
 * Cette fonction imprime le résultat de l'analyse lexicale sur la sortie standard.
 ******************************************************************************/
void afficher_analyse_lexicale() {
  int uniteCourante;
  char nom[100];
  char valeur[100]; 
    uniteCourante = yylex();  
  while (uniteCourante != FIN) {
    nom_token( uniteCourante, nom, valeur );
    printf("%s\t%s\t%s\n", yytext, nom, valeur);
    uniteCourante = yylex(); 
  } 
}
