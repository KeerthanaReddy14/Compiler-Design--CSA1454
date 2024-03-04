%{
int nmacro,nheader;
%}
%%
"#define" {nmacro++;}
"#include" {nheader++;}
.|\n {}
%%
int yywrap()
{
return 1;
}
int main()
{
printf("enter the string:\n");
yylex();
printf("Number of macros defined = %d\n Number of header files included =%d\n",nmacro,nheader);
}
