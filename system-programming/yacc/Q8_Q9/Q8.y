%{
#include <stdio.h>
#define border printf("\n---------------------------------------------------------------------------------\n")
int yydebug=1;
int YYERROR_VERBOSE=1;
int yyerrstatus = 1;    
%}

%token ID NUMBER RARE EQ PLUS MINUS MUL DIVIDE LBRACKET RBRACKET SEMICOLON

/// set precedence
%right EQ
%left PLUS MINUS
%left MUL DIVIDE
%%

start : arithmetic_stmt SEMICOLON { printf("\nThis is a valid expression"); border; return ;}

arithmetic_stmt: identifier EQ expr

identifier: ID
        | keyword { yyerror("\nkeyword can't be used as a identifier\n"); border; return; }
        
keyword:    RARE 

expr: expr PLUS expr
     |expr MINUS expr
     |expr MUL expr
     |expr DIVIDE expr
     | factor
     |LBRACKET expr RBRACKET
     | SIGN factor

SIGN: PLUS
    | MINUS

factor: identifier     
     | NUMBER

%%

main() {
printf("\n--------------------------- ARITHMETIC EXPRESSION PARSER ---------------------------\n");
char ch;
do{
printf("\nEnter a  expression :\n");
yyparse();
printf("\nDo you wanna continue :  (y/n)\n");
scanf(" %c", &ch);
}while(ch=='y'||ch=='Y');
printf("\n--------------------------- USER REQUESTED EXIT ---------------------------\n\n");

}

yyerror(s)
char *s;
{
printf("\n%s \n", s);
border;
}
yywrap()
{
  return(1);
}
