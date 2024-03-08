#include <stdio.h>

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {
    char input;
    
    printf("Enter an operator: ");
    scanf("%c", &input);
    
    if (isOperator(input)) {
        printf("Valid operator: %c\n", input);
    } else {
        printf("Not a valid operator\n");
    }

    return 0;
}
