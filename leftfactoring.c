#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eliminateLeftFactoring(char production[], char nonTerminal) {
    printf("\nOriginal Production:\n%s\n", production);

    int length = strlen(production);
    int i = 0, j = 0;

    while (production[i] != '|') {
        i++;
    }

    int commonPrefixLength = 0;
    while (production[j] == production[i]) {
        commonPrefixLength++;
        j++;
        i++;
    }

    if (commonPrefixLength == 0) {
        printf("\nNo Left Factoring\n");
        return;
    }

    char newNonTerminal = 'A';
    while (nonTerminal == newNonTerminal || strchr(production + i, newNonTerminal) != NULL) {
        newNonTerminal++;
    }

    char prefix[commonPrefixLength + 2];
    strncpy(prefix, production, commonPrefixLength);
    prefix[commonPrefixLength] = '\0';

    char newProduction[100];
    sprintf(newProduction, "%c'->%s%c|\u03B5", nonTerminal, prefix, newNonTerminal);
    printf("\nUpdated Production:\n%s\n", newProduction);

    i = 0;
    while (production[i] != '|') {
        i++;
    }

    memmove(production + commonPrefixLength, production + i + 1, length - i - commonPrefixLength + 1);
    production[length - commonPrefixLength] = newNonTerminal;
    printf("\nUpdated Production after eliminating left factoring:\n%s\n", production);
}

int main() {
    char production[100] = "S->abS|abCd|ef";
    char nonTerminal = 'S';

    eliminateLeftFactoring(production, nonTerminal);

    return 0;
}
