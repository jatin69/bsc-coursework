%{
#include <stdio.h>
%}
%%
[a-z] { char ch=yytext[0];
        ch+=3;
        if(ch>'z') { ch= ch-26; }
        printf("%c",ch);
    }

[A-Z] { char ch=yytext[0];
        ch+=3;
        if(ch>'Z') { ch= ch- ('Z'+1-'A' ); }
        printf("%c",ch);
    }

%%

int main()
{
    printf("\n--------------- Caesar cipher -------------------\n");
    yylex();
    return 0;
}

yywrap()
{ 
    return 1;
}   