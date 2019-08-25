%{
#include <stdio.h>
int yydebug=1;

int regs[52];  // first 26 for capital letters , next 26 for small letters
int base;

%}

%start list

%token DIGIT LETTER

%left '+' '-'
%left '*' '/'

%%                   /* beginning of rules section */

list:     /*empty */
         |
        list stat '\n'
         |
        list error '\n'
         {
           yyerrok;
         }
         ;

stat:    expr
         {
           printf("%d\n",$1);
         }
         |
         LETTER '=' expr
         {
           regs[$1] = $3;
         }

         ;

expr:    '(' expr ')'
         {
           $$ = $2;
         }
         |
          expr '+' expr
         {
           $$ = $1 + $3;
         }
         | 
         expr '-' expr
         {
           $$ = $1 - $3;
         }
        |
         expr '*' expr
         {
           $$ = $1 * $3;
         }
         |
         expr '/' expr
         {
           $$ = $1 / $3;
         }
         |
         LETTER
         {
           $$ = regs[$1];
         }
         |
         DIGIT
         {
           $$ = $1;
         }
         ;

%%
main()
{
 return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}

yywrap()
{
  return(1);
}