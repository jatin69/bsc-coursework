%{
#include <stdio.h>
int num_lines=0, num_char=0;
%}
%%
\n  { num_lines++; num_char++; }
.   { num_char++; }
%%

int main()
{
    printf("\nEnter filename : ");
    char str[20];
    scanf("%s",str);
    yyin=fopen(str,"r");
    yylex();
 
    printf("\nIn the file \"%s\" - \nThere are %d lines and %d characters.\n\n",str,num_lines,num_char);
    return 0;
}

yywrap()
{ 
    return 1;
}   
