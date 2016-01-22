%{
#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"
#include "ensemble.h"

cellule* table;
%}

%union {
	int value;
	char* string;
	ensemble* ens;
}

%token <value>ENT <string>ID AFF
%type <value>exp
%type <ens>ens
%type <ens>V
%left '-'
%left '+'
%left '*'
%left ':'
%nonassoc MOINSU
%nonassoc '?'
%start lines 

%%
lines: 
      | lines line
      ;

line: exp ';' {printf("%d\n",$1);}
     | ens ';' {afficherEnsemble($1);printf("\n"); free($1);}
     | affect ';'
     ;

affect: ID AFF ens {  cellule* c = rechercher(table, $1);
		       if(c == NULL) {
				inserer(&table, creerCellule($1, $3));
				free($1);
		       }
		       else
				c->ens = $3;
		    }
       ;

ens:  '[' ' ' V ']' {$$ = $3;}
     | ID {  cellule* c = rechercher(table, $1);
	     free($1);
	     if(c == NULL)
		 yyerror("La variable n'est affectee a aucune valeur");
	     else
		 $$ = copierEnsemble(c->ens);
    	  }
     | '(' ens ')'  {$$ = $2;}
     | ens '+' ens  {$$ = additionner($1, $3); free($1); free($3);}
     | ens '-' ens  {$$ = soustraire($1, $3); free($1); free($3);}
     | ens '*' ens  {$$ = multiplier($1, $3); free($1); free($3);}
     | exp ':' ens  {  ensemble* e = creerEnsemble($1);
		       $$ = additionner( e, $3); 
		       free(e); free($3);
		    } 
     ;

V:  exp ' ' V {  ensemble* e = creerEnsemble($1);
		 $$ = additionner( e, $3); 
		 free(e); free($3);
	      } 
   |  {$$ = NULL;}
   ;

exp: ENT
    | '(' exp ')'  {$$ = $2;}
    | exp '+' exp {$$ = $1 + $3;}
    | exp '-' exp {$$ = $1 - $3;}
    | exp '*' exp {$$ = $1 * $3;}
    | '-' exp %prec MOINSU {$$ = -$2;}
    | '?' ens {$$ = nbElements($2);}
    ;
%%
int yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }

int main(void) {
  yyparse();
  detruireListe(table);
}
