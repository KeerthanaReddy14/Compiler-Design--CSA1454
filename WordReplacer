%{
#include <stdio.h>
#include <string.h>
%}

%option noyywrap

%%

"old_word" { fprintf(yyout, "new_word"); }
.|\n       { fprintf(yyout, "%s", yytext); }

%%

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <old_word>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");
    if (!inputFile || !outputFile) {
        perror("Error opening files");
        return 1;
    }

    // Set the old word
    yyin = inputFile;
    yyout = outputFile;

    // Set the old word
    char old_word[100];
    strcpy(old_word, argv[3]);

    yylex();

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
