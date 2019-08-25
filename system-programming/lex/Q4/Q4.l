%{
#include <stdio.h>
%}
NUMBER [0-9]+

%%
"//"(.)* { printf("SINGLE LINE COMMENT: %s\n",yytext); }

"/*"[^(\/\*)(\*\/)](.*\n*)*"*/" { printf("MULTI LINE COMMENT: \n%s\n",yytext); }

"and"|"int"|"main"|"void"|"continue"|"return"|"short"|"sizeof"|"static"|"struct"|"switch"|"template"|"this" { printf("KEYWORD: %s\n",yytext); }
"typedef"|"delete"|"default"|"do"|"double"|"auto"|"break"|"class"|"bool"|"case" { printf("KEYWORD: %s\n",yytext); }
"catch"|"char"|"compl"|"else"|"const"|"return"|"try"|"while" { printf("KEYWORD: %s\n",yytext); }

{NUMBER} { printf("INTEGER: %s\n",yytext); }
{NUMBER}\.{NUMBER} { printf("FLOAT: %s\n",yytext); }

[_a-zA-Z][_a-zA-Z0-9]* { printf("IDENTIFIER: %s\n",yytext); }

\=|\+|\-|\*|\/|\>|\<|"!="|">="|"<="|"=="   { printf("OPERATOR: %s\n",yytext); }

\(      { printf("Left BRACKET: %s\n",yytext); }
\)      { printf("Right BRACKET: %s\n",yytext); }
\{      { printf("Left curly BRACKET: %s\n",yytext); }
\}      { printf("Right curly BRACKET: %s\n",yytext); }
\;      { printf("SEMICOLON: %s\n",yytext); }

[ \t]+ ;
[\n]+  { printf("\n");}
.       { printf("unidentified token: %s\n",yytext); }
%%

int main()
{
    printf("\n--------------------- TOKENIZER ------------------------\n");
    printf("\nEnter filename : ");
    char str[20];
    scanf("%s",str);
    printf("\n");
    yyin=fopen(str,"r");
    yylex();
    printf("--------------------------------------------------------\n");
    return 0;
}
yywrap()
{ 
    return 1;
}   