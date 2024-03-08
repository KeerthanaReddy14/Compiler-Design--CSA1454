#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char* key;
    int value;
} Entry;

Entry entries[MAX_ENTRIES];
int size = 0;

void insert(char* key, int value) {
    if (size < MAX_ENTRIES) {
        entries[size].key = strdup(key);
        entries[size].value = value;
        size++;
    } else {
        printf("Symbol table is full, cannot insert more entries.\n");
    }
}

int search(char* key) {
    for (int i = 0; i < size; i++) {
        if (strcmp(entries[i].key, key) == 0)
            return entries[i].value;
    }
    return -1;
}

int main() {
    char input[1000];
    printf("Enter key-value pairs separated by spaces: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    while (token != NULL) {
        char key[100];
        int value;
        sscanf(token, "%s:%d", key, &value);
        insert(key, value);
        token = strtok(NULL, " ");
    }

    char keyToSearch[100];
    printf("Enter key to search: ");
    scanf("%s", keyToSearch);
    int value = search(keyToSearch);
    if (value != -1)
        printf("%s found with value %d\n", keyToSearch, value);
    else
        printf("%s not found\n", keyToSearch);

    return 0;
}
