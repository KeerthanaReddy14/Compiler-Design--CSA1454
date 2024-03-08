#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROD 10

void eliminateLeftRecursion(char nonTerminal, int numProd, char productions[MAX_PROD][100]) {
    int i, j, k;
    int newProdIndex = numProd;
    char newProductions[MAX_PROD][100];

    for (i = 0; i < numProd; i++) {
        if (productions[i][0] == nonTerminal) {
            char alphaProd[100], betaProd[100];

            strcpy(alphaProd, productions[i] + 1);

            for (j = 0; j < numProd; j++) {
                if (productions[j][0] != nonTerminal) {
                    char temp[100];

                    strcpy(temp, productions[j]);
                    strcat(temp, alphaProd);
                    strcpy(newProductions[newProdIndex++], temp);
                }
            }

            strcpy(betaProd, productions[i] + 1);

            for (j = 0; j < numProd; j++) {
                if (productions[j][0] == nonTerminal) {
                    char temp[100];

                    strcpy(temp, productions[j] + 1);
                    strcat(temp, alphaProd);
                    strcpy(newProductions[newProdIndex++], temp);
                }
            }
        }
    }

    for (i = 0; i < newProdIndex; i++) {
        printf("%c->%s\n", nonTerminal, newProductions[i]);
    }
}

int main() {
    char nonTerminal;
    int numProd, i;
    char productions[MAX_PROD][100];

    printf("Enter the non-terminal symbol: ");
    scanf("%c", &nonTerminal);

    printf("Enter the number of productions: ");
    scanf("%d", &numProd);

    for (i = 0; i < numProd; i++) {
        printf("Enter production %d: ", i + 1);
        scanf("%s", productions[i]);
    }

    eliminateLeftRecursion(nonTerminal, numProd, productions);

    return 0;
}
