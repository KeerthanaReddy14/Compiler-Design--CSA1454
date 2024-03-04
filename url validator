%{
#include <stdio.h>
#include <string.h>
%}

%%
^https?://[-a-zA-Z0-9]+(\.[-a-zA-Z0-9]+)(\.[a-zA-Z]{2,})?(:\d+)?(/[^?#])?(\?[^#])?(#.)?$ {
    printf("Valid URL: %s\n", yytext);
}
.|\n ;

%%

int main() {
    printf("Enter a URL: ");
    yylex();
    return 0;
}
