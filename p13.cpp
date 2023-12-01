#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0, inWord = 0;

    printf("Enter text (Ctrl+D or Ctrl+Z to end input on Unix or Windows):\n");

    // Read characters from the user input
    while ((ch = getchar()) != EOF) {
        charCount++;

        // Check for newline character to count lines
        if (ch == '\n') {
            lineCount++;
        }

        // Check for space, tab, or newline to determine word boundaries
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            inWord = 0; // Not in a word
        } else if (!inWord) {
            inWord = 1; // Start of a new word
            wordCount++;
        }
    }

    // Output the results
    printf("\nNumber of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);

    return 0;
}

