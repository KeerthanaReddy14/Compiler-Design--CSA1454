%{
#include <stdio.h>
%}

%%
[<>=!]=     { printf("Relational Operator: %s\n", yytext); }
[a-zA-Z]+   { printf("Word: %s\n", yytext); }
.          ;

%%

int main() {
    yylex();
    return 0;
}
