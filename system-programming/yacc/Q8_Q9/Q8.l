%{ 
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"  

%}

%%
"print"|"and"|"assert"|"break"|"class"|"else"|"except"|"for"|"from"|"global"|"if"|"import"|"in"|"is"|"break"|"class"|"bool"|"case" return (RARE);
"else"|"char"|"catch"|"const"|"return"|"try"|"while"|"not"|"or"|"pass"|"raise"|"return"|"try"|"while"|"double"|"auto" return (RARE);
"and"|"int"|"main"|"void"|"continue"|"return"|"short"|"sizeof"|"switch"|"this"|"typedef"|"delete"|"default"|"do" return (RARE);

[0-9]+ return NUMBER;
[_a-zA-Z][_a-zA-Z0-9]* return ID ;

[ \t] ;
\=   { return (EQ); }
\+   return (PLUS);
\-   return (MINUS);
\*   return (MUL);
\/   return (DIVIDE);
\(   return (LBRACKET);
\)   return (RBRACKET);
\;   return (SEMICOLON);
.    { printf("unidentified token:\t%s",yytext);};
%%