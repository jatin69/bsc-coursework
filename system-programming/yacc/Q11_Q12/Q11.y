%{
#include <stdio.h>
int yydebug=1;
%}

%token A B DELIM
%%
start: anbn DELIM { printf("It is a valid AnBm\n\n"); return 0; }

anbn: an bm

an: A 
  | A an
  
bm: 
  | B bm
  
%%
main()
{
printf("\n--------------------------- AnBm PARSER ---------------------------\n");
printf("\nPlease enter a AnBm : \n");
 return(yyparse());
}

yyerror(s)
char *s;
{
printf("%s, This is not a valid AnBm\n\n", s);
}

yywrap()
{
  return(1);
}