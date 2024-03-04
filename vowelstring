%{
#include <stdio.h>
%}

%%
^[aeiouAEIOU][a-zA-Z]*$   { printf("Valid string: %s\n", yytext); }
.|\n                     ;

%%

int main() {
    printf("Enter a string starting with a vowel: ");
    yylex();
    return 0;
}
