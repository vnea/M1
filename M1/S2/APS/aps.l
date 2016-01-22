%{
  #include "y.tab.h"
  #include <stdio.h>

%}

num [0-9]+

%%

{num} {yylval.value = atoi(yytext); return num;}
"false" {return false;}
"true" {return true;}
"not" {return not;}
"and" {return and;}
"or" {return or;}
"eq" {return eq;}
"lt" {return lt;}
"add" {return add;}
"sub" {return sub;}
"mul" {return mul;}
[ \t] ;
. {return yytext[0];}
"\n" {return eol;}

%%
