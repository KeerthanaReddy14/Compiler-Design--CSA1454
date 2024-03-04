%{
#include <stdio.h>
%}

%%

[A-Z]+    { printf("Capital word: %s\n", yytext); }

.         ;

%%

int main() {
    yylex();
    return 0;
}
