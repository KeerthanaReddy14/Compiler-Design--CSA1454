#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int countA = 0, countB = 0;
    
    printf("Enter a string in the form of a^n b^n: ");
    scanf("%s", input);
    
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == 'a') {
            countA++;
        } else if (input[i] == 'b') {
            countB++;
        } else {
            printf("Invalid input character\n");
            return 0;
        }
        
        if (countB > countA) {
            printf("String does not satisfy the grammar\n");
            return 0;
        }
    }
    
    if (countA != countB) {
        printf("String does not satisfy the grammar\n");
    } else {
        printf("String satisfies the grammar\n");
    }
    
    return 0;
}
