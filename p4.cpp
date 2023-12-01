#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    int whitespaceCount = 0, newlineCount = 0;

    printf("Enter a string (Ctrl+Z to end input):\n");

    while ((c = getchar()) != EOF) {
        if (isspace(c)) {
            if (c == '\n') {
                newlineCount++;
            } else {
                whitespaceCount++;
            }
        }
    }

    printf("\nNumber of whitespaces: %d\n", whitespaceCount);
    printf("Number of newline characters: %d\n", newlineCount);

    return 0;
}
