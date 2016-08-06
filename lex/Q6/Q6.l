%{
#include <stdio.h>
int num_words=0, num_char=0, num_spaces=0, num_lines=0 ;
%}

%%
[a-zA-Z]+ { num_words++; num_char+=yyleng; }

[ ] { num_spaces++; num_char++;  }
[\n]  { num_lines++; num_char++; }

.   { num_char++; }
%%

int main()
{
    printf("\nEnter filename : ");
    char str[20];
    scanf("%s",str);
    yyin=fopen(str,"r");
    yylex();
 
    printf("\nIn the file \"%s\" - \nThere are : \n%d words \n%d characters \n%d blank spaces \n%d lines \n\n",str,num_words,num_char,num_spaces,num_lines);
    return 0;
}

yywrap()
{ 
    return 1;
}   