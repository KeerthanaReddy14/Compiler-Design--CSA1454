#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int precedence(char op) {
    switch(op) {
        case '(':
        case ')':
            return 1;
        case '^':
            return 2;
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 4;
        default:
            return -1;
    }
}

int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return a ^ b;
    }
    return -1;
}

int evaluateExpression(char* exp) {
    int i;
    int len = strlen(exp);

    char operatorStack[len];
    int operandStack[len];
    int operatorTop = -1;
    int operandTop = -1;

    for (i = 0; i < len; i++) {
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            operandStack[++operandTop] = num;
            i--;
        } else if (exp[i] == '(') {
            operatorStack[++operatorTop] = exp[i];
        } else if (exp[i] == ')') {
            while (operatorTop != -1 && operatorStack[operatorTop] != '(') {
                int b = operandStack[operandTop--];
                int a = operandStack[operandTop--];
                char op = operatorStack[operatorTop--];
                operandStack[++operandTop] = applyOp(a, b, op);
            }
            if (operatorTop != -1 && operatorStack[operatorTop] == '(') {
                operatorTop--;
            }
        } else {
            while (operatorTop != -1 && precedence(operatorStack[operatorTop]) <= precedence(exp[i])) {
                int b = operandStack[operandTop--];
                int a = operandStack[operandTop--];
                char op = operatorStack[operatorTop--];
                operandStack[++operandTop] = applyOp(a, b, op);
            }
            operatorStack[++operatorTop] = exp[i];
        }
    }

    while (operatorTop != -1) {
        int b = operandStack[operandTop--];
        int a = operandStack[operandTop--];
        char op = operatorStack[operatorTop--];
        operandStack[++operandTop] = applyOp(a, b, op);
    }

    return operandStack[operandTop];
}

int main() {
    char exp[100];

    printf("Enter the expression: ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';

    int result = evaluateExpression(exp);
    printf("Result after evaluating the expression: %d\n", result);

    return 0;
}
