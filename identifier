#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isValidIdentifier(char *identifier) {
    // Check if the identifier is empty
    if (*identifier == '\0')
        return false;
    if (!isalpha(*identifier) && *identifier != '_')
        return false;

    identifier++;
    while (*identifier != '\0') {
        if (!isalnum(*identifier) && *identifier != '_')
            return false;
        identifier++;
    }

    return true;
}

int main() {
    char identifier[50];

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier))
        printf("Valid identifier\n");
    else
        printf("Invalid identifier\n");

    return 0;
}
