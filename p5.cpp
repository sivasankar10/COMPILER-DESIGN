#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isValidIdentifier(const char *identifier) {
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        return 0;
    }

    size_t identifierLength = strlen(identifier);
    for (size_t i = 1; i < identifierLength - 1; i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            return 0;
        }
    }

    return 1; // Valid identifier
}

int main() {
    char identifier[50]; // Increased size to accommodate larger identifiers

    printf("Enter an identifier: ");
    fgets(identifier, sizeof(identifier), stdin);

    // Remove the newline character from fgets, if present
    size_t length = strlen(identifier);
    if (identifier[length - 1] == '\n') {
        identifier[length - 1] = '\0';
    }

    if (isValidIdentifier(identifier)) {
        printf("Valid identifier\n");
    } else {
        printf("Invalid identifier\n");
    }

    return 0;
}

