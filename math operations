%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
[0-9]+      { printf("Number: %s\n", yytext); }
"+"         { printf("Addition Operator\n"); }
"-"         { printf("Subtraction Operator\n"); }
"*"         { printf("Multiplication Operator\n"); }
"/"         { printf("Division Operator\n"); }
"%"         { printf("Modulus Operator\n"); }
.|\n        ;

%%

int main() {
    printf("Enter a mathematical expression: ");
    yylex();
    return 0;
}
