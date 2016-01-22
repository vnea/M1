%{
 #include "ensemble.h"
 #include "y.tab.h"
 #include <stdlib.h>
%}
OPER [-+*:\?]
ENTIER [0-9]{1,9}
IDENTIFICATEUR [a-zA-Z][a-zA-Z0-9_]{0,50}
%%
{ENTIER} {sscanf(yytext,"%d",&yylval.value); return ENT;}
{OPER} return yytext[0];
{IDENTIFICATEUR} {
			yylval.string = (char*)malloc(sizeof(strlen(yytext)+1));
			sscanf(yytext,"%s",yylval.string); 
			return ID;
		 }
[\(\)]	return yytext[0];
[\[\]]	return yytext[0];
:=	return AFF;
;	return ';';
[ ]	return ' ';
.	;
\n	;
