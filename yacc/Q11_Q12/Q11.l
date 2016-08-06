%{ 
#include <stdio.h>
#include "y.tab.h"
%}
%%
a return (A);
b return (B);
\n  return (DELIM);
. { printf("\nunidentified token: %s  \n",yytext); return; }
%%