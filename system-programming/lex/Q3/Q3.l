%{
#include <stdio.h>
int max=0 ; char maxstr[100];
%}
%%
[a-zA-z]+  { if(yyleng>max) { max=yyleng; strcpy(maxstr,yytext); }  }
\n  ;
.   ;
%%

int main()
{
    printf("\nEnter filename : ");
    char str[20];
    scanf("%s",str);
    yyin=fopen(str,"r");
    yylex();
    printf("\nMaxlength is %d and string is : %s\n\n",max,maxstr);
    return 0;
}

yywrap()
{ 
    return 1;
}   