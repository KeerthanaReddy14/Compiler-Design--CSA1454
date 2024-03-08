#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isNonTerminal(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool parseE(char* input, int* pos);

bool parseT(char* input, int* pos);

bool parseF(char* input, int* pos);

bool parseE(char* input, int* pos) {
    if (!parseT(input, pos)) {
        return false;
    }

    if (input[*pos] == '+') {
        (*pos)++;
    } else {
        return false;
    }

    if (!parseE(input, pos)) {
        return false;
    }

    return true;
}

bool parseT(char* input, int* pos) {
    if (!parseF(input, pos)) {
        return false;
    }

    if (input[*pos] == '*') {
        (*pos)++;
    } else {
        return false;
    }

    if (!parseT(input, pos)) {
        return false;
    }

    return true;
}

bool parseF(char* input, int* pos) {
    if (input[*pos] == '(') {
        (*pos)++;

        if (!parseE(input, pos)) {
            return false;
        }

        if (input[*pos] == ')') {
            (*pos)++;
        } else {
            return false;
        }
    } else if (isalpha(input[*pos])) {
        (*pos)++;
    } else {
        return false;
    }

    return true;
}

bool isValidString(char* input) {
    int pos = 0;
    return parseE(input, &pos) && (strlen(input) == pos);
}

int main() {
    char input[100];

    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (isValidString(input)) {
        printf("Input string satisfies the grammar!\n");
    } else {
        printf("Input string does not satisfy the grammar!\n");
    }

    return 0;
}
