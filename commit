#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int isSingleLineComment(char *line) {
    return strstr(line, "//") == line;
}

int isMultiLineCommentStart(char *line) {
    return strstr(line, "/*") == line;
}

int isMultiLineCommentEnd(char *line) {
    return strstr(line, "*/") != NULL;
}

int main() {
    char line[MAX_LINE_LENGTH];

    printf("Enter a line of C code: ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    if (isSingleLineComment(line)) {
        printf("Single-line comment found: %s\n", line);
    } else if (isMultiLineCommentStart(line)) {
        printf("Potential multi-line comment found: %s\n", line);
        while (!isMultiLineCommentEnd(line)) {
            fgets(line, MAX_LINE_LENGTH, stdin);
            printf("%s", line);
        }
        printf("End of multi-line comment\n");
    } else {
        printf("Not a comment\n");
    }

    return 0;
}
