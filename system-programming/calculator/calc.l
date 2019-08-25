%{ 
#include <stdio.h>
#include "y.tab.h"
int c;
extern int yylval;
%}
%%

" "       ;

[A-Z]   { c = yytext[0];  yylval = c - 'A';       return(LETTER); }

[a-z]   {  c = yytext[0]; yylval = c - 'a' + 26;  return(LETTER);  }

[0-9]+  { yylval =atoi(yytext);     return(DIGIT);  }

[^a-z0-9\b]    {  c = yytext[0];     return(c);      }

%%