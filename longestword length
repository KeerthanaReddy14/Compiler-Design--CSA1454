%{
#include <stdio.h>
int max_length = 0;
%}

%%
[a-zA-Z]+ {
    if (yyleng > max_length) {
        max_length = yyleng;
    }
}

\n {
    printf("Length of longest word: %d\n", max_length);
    max_length = 0;
}

. {}

%%

int main() {
    yylex();
    return 0;
}
