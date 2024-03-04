%{
#include <stdio.h>
#include <string.h>
int word_count = 0;
char target_word[100];
%}

%%
{WORD} {
    if(strcmp(yytext, target_word) == 0) {
        word_count++;
    }
}
.|\n ;

%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <target_word>\n", argv[0]);
        return 1;
    }

    // Set the target word
    strcpy(target_word, argv[1]);

    yylex();

    printf("Frequency of '%s': %d\n", target_word, word_count);

    return 0;
}
