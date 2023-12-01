#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidSentence(const char *input) {
    int len = strlen(input);

    if (len < 2 || input[len - 1] != '.') {
        return 0; // Invalid if string is too short or doesn't end with a period
    }

    if (!isupper(input[0])) {
        return 0; // Invalid if the first character is not uppercase
    }

    for (int i = 1; i < len - 1; i++) {
        if (!islower(input[i]) && !isspace(input[i])) {
            return 0; // Invalid if any character other than lowercase or space after the first character
        }
        if (isspace(input[i]) && !isupper(input[i + 1])) {
            return 0; // Invalid if space is followed by a character other than uppercase
        }
    }

    return 1; // Valid sentence
}

int main() {
    char input[100];

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character added by fgets, if present
    int length = strlen(input);
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    if (isValidSentence(input)) {
        printf("The sentence follows the grammar rules.\n");
    } else {
        printf("The sentence does not follow the grammar rules.\n");
    }

    return 0;
}

