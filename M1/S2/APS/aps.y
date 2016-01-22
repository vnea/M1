%union {
	int value;
	char* str;
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* terme;
FILE *file;
extern FILE * yyin;
%}

%token true false num not and or eq lt add sub mul eol
%type<str> true false not and or eq lt add sub mul Expr
%type<value> num
%start Prog
%%
Prog :
    Expr ';' { terme = strdup($1);}
    ;
    
Expr : 
    true { $$ = strdup("true");}
    | false { $$ = strdup("false");}
    | num {
            char s [50];
            sprintf(s, "%d", $1);
            $$ = strdup(s);
          }
    | not Expr  {
                    $$ = (char*)malloc(sizeof(char)*(strlen($2)+6));
                    strcpy($$, "not(");
                    strcat($$, $2);
                    strcat($$, ")");
                }
    | and Expr Expr { }
    | or Expr Expr { }
    | eq Expr Expr { }
    | lt Expr Expr { }
    | add Expr Expr { }
    | sub Expr Expr { }
    | mul Expr Expr { }

    ;
    
%%
int yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }

int main(int argc, char **argv) {
    if (argc != 2) {
        yyerror("Usage : Aps fichier");
        return 0;
    }

    if (!(file = fopen(argv[1], "r"))) {
        yyerror("Erreur ouverture fichier.");
        return 0;
    }
    
    yyin = file;
    
    yyparse();
    fclose(file);
    printf("%s\n", terme);
      return 0;
}

