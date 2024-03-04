%{
#include <stdio.h>
%}

EMAIL [a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}

%%

^({EMAIL})$  { printf("Valid email: %s\n", yytext); }
.            { printf("Invalid email\n"); }

%%

int main() {
    yylex();
    return 0;
}
