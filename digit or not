%{
#include<stdio.h>
%}
%%
[0-9]+|[0-9]*\.[0-9]+ { printf("\n%s is Digit", yytext);}
.+ {printf("\n%s is not a Digit", yytext);}
%%

int yywrap(){}

int main()
{
printf("Enter:");
yylex();
}
