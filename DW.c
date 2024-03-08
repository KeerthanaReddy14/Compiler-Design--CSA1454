#include <stdio.h>
#include <ctype.h>

#define IN_WORD 1
#define OUT_WORD 0

int main() {
    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0, state = OUT_WORD;

    printf("Enter text (Ctrl+D to end input on Unix/Linux, Ctrl+Z on Windows):\n");

    while ((ch = getchar()) != EOF) {
        charCount++;
        if (ch == '\n') {
            lineCount++;
        }

        if (isspace(ch)) {
            state = OUT_WORD;
        } else if (state == OUT_WORD) {
            state = IN_WORD;
            wordCount++;
        }
    }

    if (charCount > 0 && ch != '\n') {
        lineCount++;
    }

    printf("\nCharacter count: %d\n", charCount);
    printf("Word count: %d\n", wordCount);
    printf("Line count: %d\n", lineCount);
    return 0;
}
