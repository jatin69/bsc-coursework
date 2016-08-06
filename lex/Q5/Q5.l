%{
#include <stdio.h>
int num_id=0;
int i;
char str[100];
%}

keywords "and"|"main"|"void"|"continue"|"return"|"sizeof"|"struct"|"switch"|"template"|"this"|"const"|"return"|"try"|"while"|"typedef"|"delete"|"default"|"do"|"auto"|"break"|"class"|"bool"|"case"|"catch"|"compl"|"else"|"using"|"namespace"|"std"
types "char"|"int"|"float"|"double"
identifier [_a-zA-Z][_a-zA-Z0-9]*
id_dec {types}" "+{identifier}(,?{identifier})*";"

%%
{keywords}  { ; }
{id_dec}    {   strcpy(str,yytext);
                i=0;
                while(str[i]!='\0') {   if(str[i]==','){ num_id++;} i++; }
                num_id++;
            }
\n  { ; }
.   { ; }

%%


int main()
{
    printf("\nEnter filename : ");
    char str[20];
    scanf("%s",str);
    yyin=fopen(str,"r");
    yylex();
 
    printf("\nIn the file \"%s\" - \nThere are %d identifiers.\n\n",str,num_id);
    return 0;
}

yywrap()
{ 
    return 1;
}   
