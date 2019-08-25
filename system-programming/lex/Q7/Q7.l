%{
#include <stdio.h>
int i,j;
%}
%%
[a-zA-Z]+   {   printf("\n");
                for(i=yyleng; i>0 ; i--)          // take loop from i=yyleng to i>0 ,as printed string should have atleast 1 char, so i>0
                {
                    for(j=0;j<=i-1;j++)  { printf("%c", yytext[j]); }       // print string from 0 to (size-1) 
                    printf("\n");
                }
            }

%%

int main()
{
    printf("\n--------------- Pattern print -------------------\n");
    yylex();
    return 0;
}

yywrap()
{ 
    return 1;
}   